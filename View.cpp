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
#ifdef _WIN32
#include <windows.h> // For Windows color support
#else
#include <unistd.h>
#endif
using namespace std;

//------------------------------------------------------ Include personnel
#include "View.h"

//------------------------------------------------------------- Constantes
bool View::end = false;
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
    return *this;
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

void View::setColor(int color)
{
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#else
    if (color == 0)
        cout << "\033[0m"; // Reset to default color
    else
        cout << "\033[1;" << color << "m";
#endif
}

void View::afficherMesureAirQuality(const AirMeasurement &mesure)
{
    // Algorithme :
    setColor(32); // Green color
    cout << "----- Air Quality Measurement -----" << endl;
    setColor(36); // Cyan color
    cout << "ATMO Index: " << mesure.GetAtmoIndex() << endl;
    cout << "O3: " << mesure.GetO3() << endl;
    cout << "SO2: " << mesure.GetSO2() << endl;
    cout << "NO2: " << mesure.GetNO2() << endl;
    cout << "PM10: " << mesure.GetPM10() << endl;
    setColor(0); // Reset to default color
}

void View::afficherListe(const std::vector<Sensor> &liste)
{
    // Algorithme :
    setColor(32); // Green color
    cout << "----- List of Sensors -----" << endl;
    setColor(36); // Cyan color
    int i = 1;
    for (const Sensor &sensor : liste)
    {
        cout << "Sensor ID: " << sensor.GetSensorID()
             << "\tCoordinates: (" << sensor.GetCoord()->GetLat()
             << ", " << sensor.GetCoord()->GetLng()
             << ")\tRank: " << i << endl;
        i++;
    }
    setColor(0); // Reset to default color
}

void View::afficherErreur(const string &message)
{
    setColor(31); // Red color
    cout << "Error: " << message << endl;
    setColor(0); // Reset to default color
}

void View::afficherBool(const bool &state)
{
    if (state)
    {
        setColor(32); // Green color
        cout << "The sensor is perfectly working." << endl;
    }
    else
    {
        setColor(31); // Red color
        cout << "The sensor is not functional" << endl;
    }
    setColor(0); // Reset to default color
}

void View::afficherTpsExec(const string &prompt, const std::chrono::microseconds &temps)
{

    ofstream outFile("timing_results.txt", std::ios::app);
    if (outFile.is_open())
    {
        outFile << prompt << " | Execution time: " << temps.count() << " microseconds" << std::endl;
        outFile.close();
    }
    else
    {
        std::cerr << "Unable to open file for writing" << std::endl;
    }
}

Date *View::entrerDate(const string &prompt)
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
    Date *d = new Date(annee, mois, jour, heure);
    return d;
}

int View::entrerNombre(const string &prompt)
{
    int nombre;
    cout << prompt << endl;
    cout << "Enter a number: ";
    cin >> nombre;
    return nombre;
}

CoordGPS *View::entrerCoord(const string &prompt)
{
    float lat, lng;
    cout << prompt << endl;
    cout << "Enter latitude: ";
    cin >> lat;
    cout << "Enter longitude: ";
    cin >> lng;
    CoordGPS *coord = new CoordGPS(lat, lng);
    return coord;
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
    int choice;
    while (!end)
    {
        cout << "----- AUTHENTIFICATION PHASE -----\n\n"
             << "0. End" << endl
             << "1. Authentification" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            end = true;
            return;
        case 1:
            cout << "If you already have an account, please enter your username and your password:\n"
                 << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            cout << endl;

            Controller::connexion(username, password);
            break;
        default:
            setColor(31);
            cout << "Veuillez entrer un nombre valide" << endl;
            setColor(0);
            break;
        }
    }
}
void View::MenuPrincipalGovernmentAgency()
{
    cout << "----- Government Agency Menu -----\n"
         << "1: Analyze Sensors data\n"
         << "2: Private Sensors data\n"
         << "3: Sensors similarity\n"
         << "4: Sensors statistics\n"
         << "5: Air quality\n"
         << "6: Air Cleaners impact\n"
         << "0: End\n";
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    Controller::recupererSaisieMenu(choice);
    return;
}
void View::MenuPrincipalPrive()
{
    cout << "----- Private Individual Menu -----\n"
         << "1: Mean of air quality in an area\n"
         << "2: Ranking on similarity\n"
         << "3: Air quality at a precise location\n"
         << "4: Consult points\n"
         << "0: End\n";
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    Controller::recupererSaisieMenu(choice);
    return;
}
void View::MenuPrincipalProvider()
{
    cout << "----- Provider Menu -----\n"
         << "1: Air Cleaners impact\n"
         << "0: End\n";
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    Controller::recupererSaisieMenu(choice);
    return;
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
