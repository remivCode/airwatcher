/*************************************************************************
                           View  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <View> (fichier View.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "View.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type View::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
View &View::operator=(const View &unView)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
View::View(const View &unView)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <View>" << endl;
#endif
} //----- Fin de View (constructeur de copie)

View::View()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <View>" << endl;
#endif
} //----- Fin de View

void View::afficherMesureAirQuality(const AirMeasurement &mesure)
{
    // Algorithme :
    cout << mesure.GetAtmoIndex() << endl;
    cout << mesure.GetO3() << endl;
    cout << mesure.GetSO2() << endl;
    cout << mesure.GetNO2() << endl;
    cout << mesure.GetPM10() << endl;
}
void View::afficherListe(const std::vector<Sensor> &liste)
{
    // Algorithme :
    cout << "List of Sensors:" << endl;
    for (const Sensor &sensor : liste)
    {
        cout << "Sensor ID: " << sensor.GetSensorID()
             << ", Coordinates: (" << sensor.GetCoord().GetLat()
             << ", " << sensor.GetCoord().GetLng()
             << "), Fiability: " << (sensor.GetFiability() ? "True" : "False")
             << endl;
    }
}

void View::afficherErreur(const string &message)
{
    cerr << "Error: " << message << endl;
}

void View::afficherBool(const bool &state)
{
    if (state)
    {
        cout << "The sensor is perfectly working." << endl;
    }
    else
    {
        cout << "The sensor is not functional" << endl;
    }
}

void View::afficherTpsExec(const string &temps)
{
    cout << "Execution time: " << temps << endl;
}

Date View::entrerDate(const string &prompt)
{
    int annee, mois, jour, heure;
    cout << prompt << endl;
    cout << "Enter year: ";
    cin >> annee;
    cout << "Enter month: ";
    cin >> mois;
    cout << "Enter day: ";
    cin >> jour;
    cout << "Enter hour: ";
    cin >> heure;

    return Date(annee, mois, jour, heure);
}

int View::entrerNombre(const string &prompt)
{
    int nombre;
    cout << prompt;
    cin >> nombre;
    return nombre;
}

CoordGPS View::entrerCoord(const string &prompt)
{
    float lat, lng;
    cout << prompt << endl;
    cout << "Enter latitude: ";
    cin >> lat;
    cout << "Enter longitude: ";
    cin >> lng;
    return CoordGPS(lat, lng);
}

string View::entrerString(const string &prompt)
{
    string str;
    cout << prompt << endl;
    cout << "Enter une chaine de caractère: ";
    cin >> str;
    return str;
}

void View::MenuConnexion()
{
    string username, password;
    cout << "AUTHENTIFICATION PHASE:\n\n"
         << "If you already have an account, please enter your username and your password:\n"
         << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    cout << "if you don't have an account yet, create one:\n"
         << "(NB: for a first connexion as a member of the gov agency, please contact the HR to have your connexion's informations)\n"
         << "/*an imaginary button*/\n"
         << "New member\n";
    Controller::connexion(username, password);
}
void View::MenuPrincipalGovernmentAgency()
{
    cout << "Government Agency Menu:\n"
         << "1: Analyze Sensors data\n"
         << "2: Private Sensors data\n"
         << "3: Sensors similarity\n"
         << "4: Sensors statistics\n"
         << "5: Air quality\n"
         << "6: Air Cleaners impact\n"
         << "0: End\n";
    int choice;
    cin >> choice;
    Controller::recupererSaisieMenu(choice);
}
void View::MenuPrincipalPrive()
{
    cout << "private Individual Menu:\n"
         << "1: Mean of air quality in an area\n"
         << "2: Ranking on similarity\n"
         << "3: Air quality at a precise location\n"
         << "4: Consult points\n"
         << "0: End\n";
    int choice;
    cin >> choice;
    Controller::recupererSaisieMenu(choice);
}
void View::MenuPrincipalProvider()
{
    cout << "Provider Menu:\n"
         << "1: Air Cleaners impact\n"
         << "0: End\n";
    int choice;
    cin >> choice;
    Controller::recupererSaisieMenu(choice);
}

View::~View()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <View>" << endl;
#endif
} //----- Fin de ~View

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
