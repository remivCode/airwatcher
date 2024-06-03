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
using namespace std;
#include <map>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "Traitement.h"
#include "Provider.h"
#include "PrivateIndividual.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

vector<Sensor *> Traitement::sensors;
vector<Attribute *> Traitement::typeMesures;
// vector<Measurement *> Traitement::measurements;
vector<Cleaner *> Traitement::cleaners;
vector<User *> Traitement::users;

//----------------------------------------------------- Méthodes publiques
void Traitement::chargerDonnees()
// Algorithme :
//
{
    ////////////////////////////////////////////////// Chargement attribut
    ifstream attributes("../data/attributes.csv");
    if (!attributes.is_open())
    {
        cerr << "Erreur lors de l'ouverture de attributes.csv" << endl;
        return;
    }
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
        typeMesures.push_back(a);
    }

    ////////////////////////////////////////////////// Chargement cleaners
    ifstream clean("../data/cleaners.csv");
    if (!clean.is_open())
    {
        cerr << "Erreur lors de l'ouverture de cleaners.csv" << endl;
        return;
    }
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
        Cleaner *c = new Cleaner(id, gps, debut, fin, nullptr);
        cleaners.push_back(c);
    }

    ////////////////////////////////////////////////// Chargement providers
    ifstream provid("../data/providers.csv");
    if (!provid.is_open())
    {
        cerr << "Erreur lors de l'ouverture de providers.csv" << endl;
        return;
    }
    getline(provid, line);
    while (getline(provid, line))
    {
        stringstream lineStream(line);
        string id;
        getline(lineStream, id, ';');
        string idCleaner;
        getline(lineStream, idCleaner, ';');
        Provider *p = new Provider(id);
        users.push_back(p);

        for (int i = 0; i < cleaners.size(); i++)
        {
            if (cleaners[i]->getCleanerID() == idCleaner)
            {
                cleaners[i]->setProvider(p);
            }
        }
    }

    ////////////////////////////////////////////////// Chargement sensors
    ifstream sens("../data/sensors.csv");
    if (!sens.is_open())
    {
        cerr << "Erreur lors de l'ouverture de sensors.csv" << endl;
        return;
    }
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
        Sensor *s = new Sensor(id, gps, nullptr);
        sensors.push_back(s);
    } //----- Fin de Méthode

    ////////////////////////////////////////////////// Chargement users
    ifstream user("../data/users.csv");
    if (!user.is_open())
    {
        cerr << "Erreur lors de l'ouverture de users.csv" << endl;
        return;
    }
    getline(user, line);
    while (getline(user, line))
    {
        stringstream lineStream(line);
        string id;
        getline(lineStream, id, ';');
        string sensorId;
        getline(lineStream, sensorId, ';');
        PrivateIndividual *p = new PrivateIndividual(id);
        users.push_back(p);
        for (int i = 0; i < sensors.size(); i++)
        {
            if (sensors[i]->GetSensorID() == sensorId)
            {
                sensors[i]->SetUser(p);
            }
        }
    }

    ////////////////////////////////////////////////// Chargement measurements
    ifstream meas("../data/measurements.csv");
    if (!meas.is_open())
    {
        cerr << "Erreur lors de l'ouverture de measurements.csv" << endl;
        return;
    }
    while (getline(meas, line))
    {
        stringstream lineStream(line);
        string a;
        string m;
        string j;
        string h;
        getline(lineStream, a, '-');
        int annee = stoi(a);
        getline(lineStream, m, '-');
        int mois = stoi(m);
        getline(lineStream, j, ' ');
        int jour = stoi(j);
        getline(lineStream, h, ':');
        int heure = stoi(h);
        Date *date = new Date(annee, mois, jour, heure);
        string temp;
        getline(lineStream, temp, ';');

        string sensorId;
        getline(lineStream, sensorId, ';');
        string attId;
        getline(lineStream, attId, ';');
        string v;
        getline(lineStream, v, ';');
        float value = stof(v);
        Sensor *s = Traitement::findSensorById(sensorId);
        Attribute *att = Traitement::findAttributeById(attId);
        Measurement *me = new Measurement(date, value, att);
        s->addMeasurement(me);
    }
}

bool Traitement::analyzeFunctionalState(Sensor *sensor)
// Algorithme :
//
{
    if (!sensor)
    {
        cerr << "Erreur : le pointeur de capteur est nul." << endl;
        return false;
    }
    map<float, Sensor *> nearest = Traitement::findSensorByCoord(sensor->GetCoord());
    if (nearest.empty())
    {
        cerr << "Erreur : aucun capteur proche trouvé." << endl;
        return false;
    }
    float ozone = 0;
    float sulfur = 0;
    float nitrogen = 0;
    float particules = 0;

    int i = 0;
    for (const pair<int, Sensor *> el : nearest)
    {
        if (i == 0)
        {
            i++;
            continue;
        }
        if (i < 4)
        {
            vector<Measurement *> m = el.second->getMeasurements();
            AirMeasurement *am = Traitement::calculateAirQualite(el.second->GetCoord(), m.back()->getTimestamp());
            ozone = ozone + am->GetO3();
            sulfur = sulfur + am->GetSO2();
            nitrogen = nitrogen + am->GetNO2();
            particules = particules + am->GetPM10();
            delete am;
        }
        i++;
    }
    float ozoneMean = ozone / 3;
    float sulfurMean = sulfur / 3;
    float nitrogenMean = nitrogen / 3;
    float particulesMean = particules / 3;

    vector<Measurement *> m = sensor->getMeasurements();
    AirMeasurement *am = Traitement::calculateAirQualite(sensor->GetCoord(), m.back()->getTimestamp());
    bool res = true;
    if (abs((ozoneMean - am->GetO3()) / am->GetO3()) > 0.5)
    {
        res = false;
    }
    if (abs((sulfurMean - am->GetSO2()) / am->GetSO2()) > 0.5)
    {
        res = false;
    }
    if (abs((nitrogenMean - am->GetNO2()) / am->GetNO2()) > 0.5)
    {
        res = false;
    }
    if (abs((particulesMean - am->GetPM10()) / am->GetPM10()) > 0.5)
    {
        res = false;
    }
    delete am;
    return res;
} //----- Fin de Méthode

Sensor *Traitement::findSensorById(string id)
// Algorithme :
//
{
    for (int i = 0; i < sensors.size(); i++)
    {
        if (sensors[i]->GetSensorID() == id)
        {
            return sensors[i];
        }
    }

    return nullptr;
} //----- Fin de Méthode

Attribute *Traitement::findAttributeById(string id)
// Algorithme :
//
{
    for (int i = 0; i < typeMesures.size(); i++)
    {
        if (typeMesures[i]->getAttributeID() == id)
        {
            return typeMesures[i];
        }
    }

    return nullptr;
} //----- Fin de Méthode

map<float, Sensor *> Traitement::findSensorByCoord(CoordGPS *coordonnees)
{
    map<float, Sensor *> sensorDistMap;
    int i;
    float lat;
    float lng;
    float d;
    for (i = 0; i < sensors.size(); i++)
    {
        lat = sensors[i]->GetCoord()->GetLat();
        lng = sensors[i]->GetCoord()->GetLng();
        d = (float)sqrt(pow(lat - coordonnees->GetLat(), 2) + pow(lng - coordonnees->GetLng(), 2));
        sensorDistMap.insert(make_pair(d, sensors[i]));
    }
    return sensorDistMap;
}

AirMeasurement *Traitement::calculateAirQualite(CoordGPS *coords, Date *date)
// Algorithme :
//
{
    Sensor *sensor = findSensorByCoord(coords).begin()->second; // récupérer le sensor le plus proche

    int i;
    float measureO3 = -1;
    float measureNO2 = -1;
    float measureSO2 = -1;
    float measurePM = -1;
    vector<Measurement *> m = sensor->getMeasurements();
    for (i = m.size() - 1; i >= 0; i--)
    { // On boucle trop longtemps, une fois qu'on a passé les 4 valeurs avec la bonne date on retrouvera
        // jamais la date donc ça sert à rien de continuer à boucler. Je pense pas qu'ils aient mis d'erreur
        // il y aura toujours les 4 valeurs en vrai
        if (*m[i]->getTimestamp() == *date)
        {
            // if ((m[i]->getAttribute()->getAttributeID() == "O3") && (measureO3 < 0))
            if (m[i]->getAttribute()->getAttributeID() == "O3")
            {
                measureO3 = m[i]->getValue();
            }
            // else if ((m[i]->getAttribute()->getAttributeID() == "SO2") && (measureSO2 < 0))
            else if (m[i]->getAttribute()->getAttributeID() == "SO2")
            {
                measureSO2 = m[i]->getValue();
            }
            // else if ((m[i]->getAttribute()->getAttributeID() == "NO2") && (measureNO2 < 0))
            else if (m[i]->getAttribute()->getAttributeID() == "NO2")
            {
                measureNO2 = m[i]->getValue();
            }
            // else if ((m[i]->getAttribute()->getAttributeID() == "PM") && (measurePM < 0))
            else if (m[i]->getAttribute()->getAttributeID() == "PM10")
            {
                measurePM = m[i]->getValue();
            }
        }
    }

    AirMeasurement *mesurement = new AirMeasurement(measureO3, measureSO2, measureNO2, measurePM);

    return mesurement;
} //----- Fin de Méthode

AirMeasurement *Traitement::calculateMeanAirQualite(CoordGPS *coords, int radius, Date *dateDebut, Date *dateFin)
// Algorithme :
//
{
    int i;
    int day;
    int month;
    int year;
    Date *date = new Date();
    date->SetHeure(12);
    int counter = 0;
    AirMeasurement *mean = new AirMeasurement();
    AirMeasurement sum;

    map<float, Sensor *> DistSensor = findSensorByCoord(coords);

    for (auto it = DistSensor.begin(); it != DistSensor.end(); it++)
    {
        if (it->first <= radius)
        {
            for (year = dateDebut->GetAnnee(); year <= dateFin->GetAnnee(); year++)
            {
                date->SetAnnee(year);
                for (month = 0; month <= abs(dateDebut->GetMois() - dateFin->GetMois()); month++)
                {
                    date->SetMois(dateDebut->GetMois() + month);
                    for (day = 0; day <= abs(dateDebut->GetJour() - dateFin->GetJour()); day++)
                    {
                        date->SetJour(dateDebut->GetJour() + day);
                        AirMeasurement *am = calculateAirQualite(it->second->GetCoord(), date);
                        if (!(am->GetO3() == -1 || am->GetNO2() == -1 || am->GetSO2() == -1 || am->GetPM10() == -1))
                        {
                            sum = sum + *am;
                            ++counter;
                        }
                    }
                }
            }
        }
    }

    *mean = sum / counter;
    return mean;
} //----- Fin de Méthode

map<AirMeasurement, Sensor *> Traitement::rankingBySimilarity(Sensor *sensor, Date *dateDebut, Date *dateFin)
// Algorithme :
//
{
    map<AirMeasurement, Sensor *> classified;
    AirMeasurement *sensorMean = Traitement::calculateMeanAirQualite(sensor->GetCoord(), 0, dateDebut, dateFin);

    AirMeasurement *empty = new AirMeasurement();
    classified.insert(make_pair(*empty, sensor));

    for (int i = 0; i < sensors.size(); i++)
    {
        if (sensors[i]->GetSensorID() != sensor->GetSensorID())
        {
            AirMeasurement *mean = Traitement::calculateMeanAirQualite(sensors[i]->GetCoord(), 0, dateDebut, dateFin);
            classified.insert(make_pair(abs(*sensorMean - *mean), sensors[i]));
        }
    }
    classified.erase(classified.begin()); // Pour supprimer le capteur lui-même
    return classified;
} //----- Fin de Méthode

void Traitement::clean()
// Algorithme :
//
{
    for (Sensor *s : sensors)
    {
        for (Measurement *m : s->getMeasurements())
        {
            delete m;
        }
        delete s;
    }
    for (Attribute *a : typeMesures)
    {
        delete a;
    }
    for (Cleaner *c : cleaners)
    {
        delete c;
    }
    for (User *u : users)
    {
        delete u;
    }
} //----- Fin de ~Traitement

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
    for (Sensor *s : sensors)
    {
        for (Measurement *m : s->getMeasurements())
        {
            delete m;
        }
        delete s;
    }
    for (Attribute *a : typeMesures)
    {
        delete a;
    }
    for (Cleaner *c : cleaners)
    {
        delete c;
    }
    for (User *u : users)
    {
        delete u;
    }
} //----- Fin de ~Traitement

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
