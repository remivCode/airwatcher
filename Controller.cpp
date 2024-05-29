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

bool Controller::recupererSaisieMenu(int saisie)
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
            user = NULL;
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
            user = NULL;
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
            user = NULL;
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

} //----- Fin de Méthode

bool Controller::connexion(string login, string password)
// Algorithme :
//
{
    string id = "A1"; // Fake id, same for everyone

    // The user chooses which type of user he is
    const int caseGovernment = 1;
    const int casePrivate = 2;
    const int caseProvider = 3;

    int userType = View::entrerNombre("Enter the user : \r\n");

    switch (userType)
    {

    case caseGovernment:
        user = new GovernmentAgencyEmployee(id, login, password);
        Controller::chargerMenu();
        break;

    case casePrivate:
        user = new PrivateIndividual(id, login, password);
        Controller::chargerMenu();
        break;

    case caseProvider:
        user = new Provider(id, login, password);
        Controller::chargerMenu();
        break;

    default:
        View::afficherErreur("Veuillez entrer un nombre valide.");
        View::MenuConnexion();
    }

    // If there are logins and passwords
    /*
    this.user = Traitement::connexion(login, password) ;
    if (this.user){
        return true ;
    }
    else{
        return false ;
    }
    */
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

} //----- Fin de Méthode

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
    user = NULL;
} //----- Fin de Controller

Controller::~Controller()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Controller>" << endl;
#endif
} //----- Fin de ~Controller

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Controller::MesureAirQuality()
// Algorithme :
//
{
    CoordGPS coordGPS = View::entrerCoord("Enter the GPS coordinates : \r\n");
    if ((abs(coordGPS.GetLat() > 90.0)) or (abs(coordGPS.GetLng() > 180)))
    {
        View::afficherErreur("The latitude must be between -90 and 90 and the longitude must be between -180 and 180\r\n");
        return;
    }

    Date date = View::entrerDate("Enter the date : \r\n");
    int an = date.GetAnnee();
    int mois = date.GetMois();
    int jour = date.GetJour();
    int heure = date.GetHeure();

    if ((mois < 0) or (mois > 12))
    {
        View::afficherErreur("Months must be between 1 and 12 included\r\n");
        return;
    }

    if (jour < 0)
    {
        View::afficherErreur("Days must be positive\r\n");
        return;
    }

    if ((heure < 0) or (heure > 23))
    {
        View::afficherErreur("Hours must be between 0 and 23 included\r\n");
        return;
    }

    if (mois == 2)
    {
        if (((an % 4) == 0) and (jour > 29))
        {
            View::afficherErreur("February has only 29 days on bissextile years\r\n");
            return;
        }
        if (((an % 4) != 0) and (jour > 28))
        {
            View::afficherErreur("February has only 28 days on not bissextile years\r\n");
            return;
        }
    }

    if ((mois % 2 == 1) and (jour > 31))
    {
        View::afficherErreur("Days must not exceed 31\r\n");
        return;
    }
    if ((mois % 2 == 0) and (mois != 2) and (jour > 30))
    {
        View::afficherErreur("Days of some months must not exceed 30\r\n");
        return;
    }

    AirMeasurement airMeasurement = Traitement::calculateAirQualite(coordGPS, date);

    View::afficherMesureAirQuality(airMeasurement);
}

void Controller::MesureMeanAirQuality()
// Algorithme :
//
{
    CoordGPS coordGPS = View::entrerCoord("Enter the GPS coordinates of the center of the area : \r\n");
    if ((abs(coordGPS.GetLat() > 90.0)) or (abs(coordGPS.GetLng() > 180)))
    {
        View::afficherErreur("The latitude must be between -90 and 90 and the longitude must be between -180 and 180\r\n");
        return;
    }

    int radius = View::entrerNombre("Enter the radius (in km) : \r\n");
    if ((radius <= 0) or (radius > 200))
    {
        View::afficherErreur("The radius must be strictly positive and must not exceed 200\r\n");
        return;
    }

    Date dateBeginning = View::entrerDate("Enter the date 1 (beginning) : \r\n");
    int an1 = dateBeginning.GetAnnee();
    int mois1 = dateBeginning.GetMois();
    int jour1 = dateBeginning.GetJour();
    int heure1 = dateBeginning.GetHeure();
    Date dateEnd = View::entrerDate("Enter the date 2 (end) : \r\n");
    int an2 = dateEnd.GetAnnee();
    int mois2 = dateEnd.GetMois();
    int jour2 = dateEnd.GetJour();
    int heure2 = dateEnd.GetHeure();

    if ((mois1 < 0) or (mois1 > 12) or (mois2 < 0) or (mois2 > 12))
    {
        View::afficherErreur("Months must be between 1 and 12 included\r\n");
        return;
    }

    if ((jour1 < 0) or (jour2 < 0))
    {
        View::afficherErreur("Days must be positive\r\n");
        return;
    }

    if ((heure1 < 0) or (heure1 > 23) or (heure2 < 0) or (heure2 > 23))
    {
        View::afficherErreur("Hours must be between 0 and 23 included\r\n");
        return;
    }

    if (mois1 == 2)
    {
        if (((an1 % 4) == 0) and (jour1 > 29))
        {
            View::afficherErreur("February has only 29 days on bissextile years\r\n");
            return;
        }
        if (((an1 % 4) != 0) and (jour1 > 28))
        {
            View::afficherErreur("February has only 28 days on not bissextile years\r\n");
            return;
        }
    }
    if (mois2 == 2)
    {
        if (((an2 % 4) == 0) and (jour2 > 29))
        {
            View::afficherErreur("February has only 29 days on bissextile years\r\n");
        }
        if (((an2 % 4) != 0) and (jour2 > 28))
        {
            View::afficherErreur("February has only 28 days on not bissextile years\r\n");
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

    AirMeasurement airMeasurement = Traitement::calculateMeanAirQualite(coordGPS, radius, dateBeginning, dateEnd);

    View::afficherMesureAirQuality(airMeasurement);
}

void Controller::CheckSensorFunctional()
// Algorithme :
//
{
    string sensorID = View::entrerString("Enter the sensor ID : \r\n");

    Sensor *sensor = Traitement::findSensorById(sensorID);
    bool functional = Traitement::analyzeFunctionalState(*sensor);
    View::afficherBool(functional);
}

void Controller::RankBySimilarity()
// Algorithme :
//
{
    /*
        string sensorID = View::entrerNombre("Enter the sensor ID : \r\n") ;
        Date dateBeginning = View::entrerDate("Enter the date 1 (beginning) : \r\n") ;
        Date dateEnd = View::entrerDate("Enter the date 2 (end) : \r\n") ;

        Sensor sensor = Traitement::findSensorById(sensorID) ;
        vector<Sensor> vectSensor = Traitement::rankingBySimilarity(sensor, dateBeginning, dateEnd) ;

        View::afficherListe(vectSensor) ;
        */
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