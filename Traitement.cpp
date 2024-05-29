/*************************************************************************
                           Traitement  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Traitement> (fichier Traitement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Traitement.h"
#include "Provider.h"
#include "PrivateIndividual.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

vector<Sensor> Traitement::sensors;
vector<Attribute> Traitement::typeMesures;
vector<Measurement> Traitement::measurements;
vector<Cleaner> Traitement::cleaners;
vector<User> Traitement::users;

//----------------------------------------------------- Méthodes publiques
void Traitement::chargerDonnees()
// Algorithme :
//
{
    ////////////////////////////////////////////////// Chargement attribut
    ifstream attributes("data/attributes.csv");
    string line;
    getline(attributes, line);
    while (getline(attributes, line))
    {
        stringstream lineStream(line);
        string id;
        getline(lineStream, id, ';');
        string unit;
        getline(lineStream, unit, ';');
        string desc;
        getline(lineStream, desc, ';');
        Attribute *a = new Attribute(id, unit, desc);
        typeMesures.push_back(*a);
    }

    ////////////////////////////////////////////////// Chargement cleaners
    ifstream clean("data/cleaners.csv");
    getline(clean, line);
    while (getline(clean, line))
    {
        stringstream lineStream(line);
        string id;
        getline(lineStream, id, ';');
        string la;
        getline(lineStream, la, ';');
        float lat = stof(la);
        string ln;
        getline(lineStream, ln, ';');
        float lng = stof(ln);
        CoordGPS *gps = new CoordGPS(lat, lng);

        string a;
        getline(lineStream, a, '-');
        int anneeDebut = stoi(a);
        string m;
        getline(lineStream, m, '-');
        int moisDebut = stoi(a);
        string j;
        getline(lineStream, j, ' ');
        int jourDebut = stoi(j);
        string h;
        getline(lineStream, h, ':');
        int heureDebut = stoi(h);
        Date *debut = new Date(anneeDebut, moisDebut, jourDebut, heureDebut);
        string temp;
        getline(lineStream, temp, ';');

        getline(lineStream, a, '-');
        int anneeFin = stoi(a);
        getline(lineStream, m, '-');
        int moisFin = stoi(a);
        getline(lineStream, j, ' ');
        int jourFin = stoi(j);
        getline(lineStream, h, ':');
        int heureFin = stoi(h);
        Date *fin = new Date(anneeFin, moisFin, jourFin, heureFin);
        Cleaner *c = new Cleaner(id, *gps, *debut, *fin, NULL);
        cleaners.push_back(*c);
    }

    ////////////////////////////////////////////////// Chargement providers
    ifstream provid("data/providers.csv");
    getline(provid, line);
    while (getline(provid, line))
    {
        stringstream lineStream(line);
        string id;
        getline(lineStream, id, ';');
        string idCleaner;
        getline(lineStream, idCleaner, ';');
        Provider *p = new Provider(id, NULL, NULL);
        users.push_back(*p);

        Cleaner c;
        for (int i = 0; i < cleaners.size(); i++)
        {
            if (cleaners[i].getCleanerID() == idCleaner)
            {
                cleaners[i].setProvider(p);
            }
        }
    }

    ////////////////////////////////////////////////// Chargement sensors
    ifstream sens("data/sensors.csv");
    getline(sens, line);
    while (getline(sens, line))
    {
        stringstream lineStream(line);
        string id;
        getline(lineStream, id, ';');
        string la;
        getline(lineStream, la, ';');
        float lat = stof(la);
        string ln;
        getline(lineStream, ln, ';');
        float lng = stof(ln);
        CoordGPS *gps = new CoordGPS(lat, lng);
        Sensor *s = new Sensor(id, *gps, NULL);
        sensors.push_back(*s);
    } //----- Fin de Méthode

    ////////////////////////////////////////////////// Chargement users
    ifstream user("data/users.csv");
    getline(user, line);
    while (getline(user, line))
    {
        stringstream lineStream(line);
        string id;
        getline(lineStream, id, ';');
        string sensorId;
        getline(lineStream, sensorId, ';');
        PrivateIndividual *p = new PrivateIndividual(id, NULL, NULL);
        users.push_back(*p);
        for (int i = 0; i < sensors.size(); i++)
        {
            if (sensors[i].GetSensorID() == sensorId)
            {
                sensors[i].SetUser(p);
            }
        }
    } //----- Fin de Méthode
}

bool Traitement::analyzeFunctionalState(Sensor sensor)
    // Algorithme :
    //
    {
    map<int, Sensor> nearest = Traitement::findSensorByCoord(sensor.GetCoord());
    float ozone = 0;
    float sulfur = 0;
    float nitrogen = 0;
    float particules = 0;

    int i = 0;
    for (const pair<int, Sensor> el : nearest)
    {
        if (i < 3)
        {
            AirMeasurement am = Traitement::calculateAirQualite(el.second.GetCoord(), measurements.back().getTimestamp());
        }
        i++;
    }
} //----- Fin de Méthode

Sensor *Traitement::findSensorById(string id)
// Algorithme :
//
{
    for (int i = 0; i < sensors.size(); i++)
    {
        if (sensors[i].GetSensorID() == id)
        {
            return &sensors[i];
        }
    }

    return NULL;
} //----- Fin de Méthode

map<int, Sensor> Traitement::findSensorByCoord(CoordGPS coordonnees)
{
    map<int, Sensor> *sensorDistMap = new map<int, Sensor>;
    int i;
    float lat;
    float lng;
    int d;
    for (i = 0; i < sensors.size(); i++)
    {
        lat = sensors[i].GetCoord().GetLat();
        lng = sensors[i].GetCoord().GetLng();
        d = (int)sqrt(pow(lat - coordonnees.GetLat(), 2) + pow(lng - coordonnees.GetLng(), 2));
        sensorDistMap->insert(make_pair(d, sensors[i]));
    }
    return *sensorDistMap;
}

AirMeasurement Traitement::calculateAirQualite(CoordGPS coords, Date date)
// Algorithme :
//
{
    Sensor sensor = findSensorByCoord(coords).begin()->second; //récupérer le sensor le plus proche

    int i;
    float measureO3 = -1;
    float measureNO2 = -1;
    float measureSO2 = -1;
    float measurePM = -1;
    for (i=measurements.size()-1 ; (i>=0) && (measureO3*measureNO2*measureSO2*measurePM<0) ; i--){
        if ((measurements[i].getSensor().GetSensorID() == sensor.GetSensorID()) && (measurements[i].getTimestamp() == date)) {
            if ((measurements[i].getAttribute().getAttributeID() == "O3") && (measureO3 < 0)) {
                measureO3 = measurements[i].getValue();
            }
            if ((measurements[i].getAttribute().getAttributeID() == "SO2") && (measureSO2 < 0)) {
                measureSO2 = measurements[i].getValue();
            }
            if ((measurements[i].getAttribute().getAttributeID() == "NO2") && (measureNO2 < 0)) {
                measureNO2 = measurements[i].getValue();
            }
            if ((measurements[i].getAttribute().getAttributeID() == "PM") && (measurePM < 0)) {
                measurePM = measurements[i].getValue();
            }
        }
    }

    AirMeasurement mesurement = AirMeasurement(measureO3, measureSO2, measureNO2, measurePM);

    return mesurement;
} //----- Fin de Méthode

AirMeasurement Traitement::calculateMeanAirQualite(CoordGPS coords, int radius, Date dateDebut, Date dateFin)
// Algorithme :
//
{
    int i;
    int day;
    int month;
    int year;
    Date date = dateDebut;
    int counter = 0;
    AirMeasurement mean = *(new AirMeasurement());
    AirMeasurement sum;

    map<int, Sensor> DistSensor = findSensorByCoord(coords);

    for (auto it = DistSensor.begin(); it != DistSensor.end(); it++) {
        if (it->first < radius) {
            for (year = dateDebut.GetAnnee(); year<=dateFin.GetAnnee() ; year++) {
                date.SetAnnee(year);
                for (month = dateDebut.GetMois(); month<=dateFin.GetMois(); month++) {
                    date.SetMois(month);
                    for (day=dateDebut.GetJour(); day<=dateFin.GetJour(); day++) {
                        date.SetJour(day);
                        sum = sum + calculateAirQualite(it->second.GetCoord(),date);
                        ++counter;
                    }
                }
            }
            
        }
    }
    
    mean = sum/counter;
    return mean;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Traitement &Traitement::operator=(const Traitement &unTraitement)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Traitement::Traitement(const Traitement &unTraitement)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Traitement>" << endl;
#endif
} //----- Fin de Traitement (constructeur de copie)

Traitement::Traitement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Traitement>" << endl;
#endif
} //----- Fin de Traitement

Traitement::~Traitement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Traitement>" << endl;
#endif
} //----- Fin de ~Traitement

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
