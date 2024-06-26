/*************************************************************************
                           Controller  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Controller> (fichier Controller.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Controller.h"
#include "Traitement.h"
#include "View.h"
#include "User.h"
#include "CoordGPS.h"
#include "Date.h"
#include "AirMeasurement.h"
#include "Sensor.h"
#include "GovernmentAgencyEmployee.h"
#include "PrivateIndividual.h"
#include "Provider.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

User *Controller::user;

//----------------------------------------------------- Méthodes publiques
// type Controller::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Controller::recupererSaisieMenu(int saisie)
// Algorithme :
//
{
    if (GovernmentAgencyEmployee *u = dynamic_cast<GovernmentAgencyEmployee *>(user))
    {
        switch (saisie)
        {
        case 1:
        {
            CheckSensorFunctional();
            break;
        }

        case 2:
        {
            CheckPrivateIndividual();
            break;
        }

        case 3:
        {
            RankBySimilarity();
            break;
        }

        case 4:
        {
            MesureMeanAirQuality();
            break;
        }

        case 5:
        {
            MesureAirQuality();
            break;
        }

        case 6:
        {
            ImpactAirCleaners();
            break;
        }

        case 0:
        {
            delete user;
            user = nullptr;
            break;
        }

        default:
        {
            View::afficherErreur("Veuillez entrer un nombre valide.");
            break;
        }
        }
    }

    else if (PrivateIndividual *u = dynamic_cast<PrivateIndividual *>(user))
    {
        switch (saisie)
        {
        case 1:
        {
            MesureMeanAirQuality();
            break;
        }

        case 2:
        {
            RankBySimilarity();
            break;
        }

        case 3:
        {
            MesureAirQuality();
            break;
        }

        case 4:
        {
            ConsultPoints();
            break;
        }

        case 0:
        {
            delete user;
            user = nullptr;
            break;
        }

        default:
        {
            View::afficherErreur("Veuillez entrer un nombre valide.");
            break;
        }
        }
    }

    else if (Provider *u = dynamic_cast<Provider *>(user))
    {
        switch (saisie)
        {
        case 1:
        {
            ImpactAirCleaners();
            break;
        }

        case 0:
        {
            delete user;
            user = nullptr;
            break;
        }

        default:
        {
            View::afficherErreur("Veuillez entrer un nombre valide.");
            break;
        }
        }
    }
    chargerMenu();
    return;

} //----- Fin de Méthode

void Controller::connexion(string login, string password)
// Algorithme :
//
{
    string id = "A1"; // Fake id, same for everyone

    // The user chooses which type of user he is
    const int caseGovernment = 1;
    const int casePrivate = 2;
    const int caseProvider = 3;

    int userType = View::entrerNombre("Enter the user (1: Government, 2: Private, 3: Provider)");

    switch (userType)
    {

    case caseGovernment:
        user = new GovernmentAgencyEmployee(id, login, password);
        Controller::chargerMenu();
        break;

    case casePrivate:
        user = new PrivateIndividual(id);
        Controller::chargerMenu();
        break;

    case caseProvider:
        user = new Provider(id);
        Controller::chargerMenu();
        break;

    default:
        View::afficherErreur("Veuillez entrer un nombre valide.");
        View::MenuConnexion();
    }
    return;
} //----- Fin de Méthode

void Controller::chargerMenu()
// Algorithme :
//
{
    if (!user)
    {
        View::MenuConnexion();
    }

    else
    {
        if (GovernmentAgencyEmployee *u = dynamic_cast<GovernmentAgencyEmployee *>(user))
        {
            View::MenuPrincipalGovernmentAgency();
        }
        else if (PrivateIndividual *u = dynamic_cast<PrivateIndividual *>(user))
        {
            View::MenuPrincipalPrive();
        }
        else if (Provider *u = dynamic_cast<Provider *>(user))
        {
            View::MenuPrincipalProvider();
        }
    }
    return;

} //----- Fin de Méthode

void Controller::clean()
// Algorithme :
//
{
    std::ofstream outFile("timing_results.txt", std::ios::trunc);
    delete user;
} //----- Fin de ~Controller

//------------------------------------------------- Surcharge d'opérateurs
Controller &Controller::operator=(const Controller &unController)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Controller::Controller(const Controller &unController)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Controller>" << endl;
#endif
} //----- Fin de Controller (constructeur de copie)

Controller::Controller()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Controller>" << endl;
#endif
    user = nullptr;
} //----- Fin de Controller

Controller::~Controller()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Controller>" << endl;
#endif
    delete user;
} //----- Fin de ~Controller

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Controller::MesureAirQuality()
// Algorithme :
//
{
    CoordGPS *coordGPS = View::entrerCoord("Enter the GPS coordinates");
    if ((abs(coordGPS->GetLat() > 90.0)) or (abs(coordGPS->GetLng() > 180)))
    {
        View::afficherErreur("The latitude must be between -90 and 90 and the longitude must be between -180 and 180");
        return;
    }

    Date *date = View::entrerDate("Enter the date");
    int an = date->GetAnnee();
    int mois = date->GetMois();
    int jour = date->GetJour();
    int heure = date->GetHeure();

    if ((mois < 0) or (mois > 12))
    {
        View::afficherErreur("Months must be between 1 and 12 included");
        return;
    }

    if (jour < 0)
    {
        View::afficherErreur("Days must be positives");
        return;
    }

    if ((heure < 0) or (heure > 23))
    {
        View::afficherErreur("Hours must be between 0 and 23 included");
        return;
    }

    if (mois == 2)
    {
        if (((an % 4) == 0) and (jour > 29))
        {
            View::afficherErreur("February has only 29 days on bissextile years");
            return;
        }
        if (((an % 4) != 0) and (jour > 28))
        {
            View::afficherErreur("February has only 28 days on not bissextile years");
            return;
        }
    }

    if ((mois % 2 == 1) and (jour > 31))
    {
        View::afficherErreur("Days must not exceed 31");
        return;
    }
    if ((mois % 2 == 0) and (mois != 2) and (jour > 30))
    {
        View::afficherErreur("Days of some months must not exceed 30");
        return;
    }
    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    AirMeasurement *airMeasurement = Traitement::calculateAirQualite(coordGPS, date);
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    View::afficherTpsExec("calculateAirQualite", duration);
    if (airMeasurement->GetO3() == -1 && airMeasurement->GetNO2() == -1 && airMeasurement->GetSO2() == -1 && airMeasurement->GetPM10() == -1)
    {
        View::afficherErreur("No data for the specified date.");
    }
    else
    {
        View::afficherMesureAirQuality(*airMeasurement);
    }
}

void Controller::MesureMeanAirQuality()
// Algorithme :
//
{
    CoordGPS *coordGPS = View::entrerCoord("Enter the GPS coordinates of the center of the area");
    if ((abs(coordGPS->GetLat() > 90.0)) or (abs(coordGPS->GetLng() > 180)))
    {
        View::afficherErreur("The latitude must be between -90 and 90 and the longitude must be between -180 and 180");
        return;
    }

    int radius = View::entrerNombre("Enter the radius (in km)");
    if ((radius <= 0) or (radius > 200))
    {
        View::afficherErreur("The radius must be strictly positive and must not exceed 200");
        return;
    }

    Date *dateBeginning = View::entrerDate("Enter the date 1 (beginning)");
    int an1 = dateBeginning->GetAnnee();
    int mois1 = dateBeginning->GetMois();
    int jour1 = dateBeginning->GetJour();
    int heure1 = dateBeginning->GetHeure();
    Date *dateEnd = View::entrerDate("Enter the date 2 (end)");
    int an2 = dateEnd->GetAnnee();
    int mois2 = dateEnd->GetMois();
    int jour2 = dateEnd->GetJour();
    int heure2 = dateEnd->GetHeure();

    if ((mois1 < 0) or (mois1 > 12) or (mois2 < 0) or (mois2 > 12))
    {
        View::afficherErreur("Months must be between 1 and 12 included");
        return;
    }

    if ((jour1 < 0) or (jour2 < 0))
    {
        View::afficherErreur("Days must be positive");
        return;
    }

    if ((heure1 < 0) or (heure1 > 23) or (heure2 < 0) or (heure2 > 23))
    {
        View::afficherErreur("Hours must be between 0 and 23 included");
        return;
    }

    if (mois1 == 2)
    {
        if (((an1 % 4) == 0) and (jour1 > 29))
        {
            View::afficherErreur("February has only 29 days on bissextile years");
            return;
        }
        if (((an1 % 4) != 0) and (jour1 > 28))
        {
            View::afficherErreur("February has only 28 days on not bissextile years");
            return;
        }
    }
    if (mois2 == 2)
    {
        if (((an2 % 4) == 0) and (jour2 > 29))
        {
            View::afficherErreur("February has only 29 days on bissextile years");
        }
        if (((an2 % 4) != 0) and (jour2 > 28))
        {
            View::afficherErreur("February has only 28 days on not bissextile years");
            return;
        }
    }

    if (((mois1 % 2 == 1) and (jour1 > 31)) or ((mois2 % 2 == 1) and (jour2 > 31)))
    {
        View::afficherErreur("Days must not exceed 31\r\n");
        return;
    }
    if (((mois1 % 2 == 0) and (mois1 != 2) and (jour1 > 30)) or ((mois2 % 2 == 0) and (mois2 != 2) and (jour2 > 30)))
    {
        View::afficherErreur("Days of some months must not exceed 30\r\n");
        return;
    }

    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    AirMeasurement *airMeasurement = Traitement::calculateMeanAirQualite(coordGPS, radius, dateBeginning, dateEnd);
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    View::afficherTpsExec("calculateMeanAirQualite", duration);
    if (airMeasurement->GetO3() == 0 && airMeasurement->GetNO2() == 0 && airMeasurement->GetPM10() == 0 && airMeasurement->GetSO2() == 0)
    {
        View::afficherErreur("No sensor in the specified area or no data for the specified dates.");
    }
    else
    {
        View::afficherMesureAirQuality(*airMeasurement);
    }
}

void Controller::CheckSensorFunctional()
// Algorithme :
//
{
    string sensorID = View::entrerString("Enter the sensor ID");
    std::chrono::_V2::system_clock::time_point start;
    std::chrono::_V2::system_clock::time_point end;

    Sensor *sensor = Traitement::findSensorById(sensorID);
    if (!sensor)
    {
        View::afficherErreur("The specified sensor doesn't exist.");
    }
    else
    {
        start = std::chrono::high_resolution_clock::now();
        bool functional = Traitement::analyzeFunctionalState(sensor);
        end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        View::afficherBool(functional);
        View::afficherTpsExec("analyzeFunctionalState", duration);
    }
}

void Controller::RankBySimilarity()
// Algorithme :
//
{
    string sensorID = View::entrerString("Enter the sensor ID : \r\n");
    Date *dateBeginning = View::entrerDate("Enter the date 1 (beginning) : \r\n");
    Date *dateEnd = View::entrerDate("Enter the date 2 (end) : \r\n");

    Sensor *sensor = Traitement::findSensorById(sensorID);

    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    map<AirMeasurement, Sensor *> mapSensor = Traitement::rankingBySimilarity(sensor, dateBeginning, dateEnd);
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    View::afficherTpsExec("analyzeFunctionalState", duration);

    vector<Sensor> vectSensor;

    // Utilisation de std::for_each pour copier les valeurs de la map dans le vecteur
    for_each(mapSensor.begin(), mapSensor.end(),
             [&vectSensor](const pair<AirMeasurement, Sensor *> &pair)
             {
                 vectSensor.push_back(*pair.second);
             });

    View::afficherListe(vectSensor);
}

void Controller::ConsultPoints()
// Algorithme :
//
{
    cout << "consult points" << endl; // temporaire
}

void Controller::ImpactAirCleaners()
// Algorithme :
//
{
    cout << "impact cleaners" << endl; // temporaire
}

void Controller::CheckPrivateIndividual()
// Algorithme :
//
{
    cout << "private individual fiability" << endl; // temporaire
}