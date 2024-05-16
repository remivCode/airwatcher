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
#include "../util/User.h"
#include "../util/CoordGPS"
#include "../util/Date"
#include "../util/AirMeasurement"
#include "../util/Sensor"
#include "../util/GovernmentAgencyEmployee"
#include "../util/PrivateIndividual"
#include "../util/Provider"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

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
    int caseMesureAirQuality = 1;
    int caseMesureMeanAirQuality = 2;
    int caseCheckSensorFunctional = 3 ;
    int caseRankSensorSimilarity = 4 ;
    int caseDeconnexion = 5 ;

    switch (saisie){

        case caseMesureAirQuality :
            CoordGPS coordGPS = View::entrerCoord("Enter the GPS coordinates : \r\n") ;
            Date date = View::entrerDate("Enter the date : \r\n") ;

            AirMeasurement airMeasurement = Traitement::calculateAirQuality(coordGPS, date) ;

            View::afficherMesureAirQuality(airMeasurement) ;

            break ;

        case caseMesureMeanAirQuality :
            CoordGPS coordGPS = View::entrerCoord("Enter the GPS coordinates : \r\n") ;
            int radius = View::entrerNombre("Enter the radius : \r\n") ;
            Date dateBeginning = View::entrerDate("Enter the date 1 (beginning) : \r\n") ;
            Date dateEnd = View::enterDate("Enter the date 2 (end) : \r\n") ;

            AirMeasurement airMeasurement = Traitement::calculateMeanAirQuality(coordGPS, radius, dateBeginning, dateEnd) ;

            View::afficherMesureAirQuality(airMeasurement) ;

            break ;
        
        case caseCheckSensorFunctional :
            int sensorID = View::entrerNombre("Enter the sensor ID : \r\n") ;

            Sensor sensor = Traitement::findSensorById(sensorID) ;
            bool functional = Traitement::analyzeFunctionalState(sensor) ;
            View::afficherBool(functional) ;

            break ;

        case caseRankSensorSimilarity :
            chargerMenu() ;
            /*
            int sensorID = View::entrerNombre("Enter the sensor ID : \r\n") ;
            Date dateBeginning = View::entrerDate("Enter the date 1 (beginning) : \r\n") ;
            Date dateEnd = View::entrerDate("Enter the date 2 (end) : \r\n") ;

            Sensor sensor = Traitement::findSensorById(sensorID) ;
            vector<Sensor> vectSensor = Traitement::rankingBySimilarity(sensor, dateBeginning, dateEnd) ;

            View::afficherListe(vectSensor) ;

            */
            break ;

        case caseDeconnexion :
            this.user = NULL ;
            chargerMenu() ;

            break ;
        
        default :
            chargerMenu() ;

    }

} //----- Fin de Méthode

bool Controller::connexion(string login, string password)
// Algorithme :
//
{
    //The user chooses which type of user he is
    int caseGovernment = 1 ;
    int casePrivate = 2 ;
    int caseProvider = 3 ;

    int userType = View::entrerNombre("Enter the user : \r\n") ;

    switch (userType){
        
        case caseGovernment :
            this.user = GovernmentAgencyEmployee() ;
            break;

        case casePrivate:
            this.user = PrivateIndividual() ;
            break;

        case caseProvider:
            this.user = Provider() ;
            break;

        default:
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

void Controller::chargerMenu() const
// Algorithme :
//
{
    if (!this.user){
        View::MenuConnexion() ;
    }

    else {
        // créer méthode getUserType pour récupérer le type du User dans chaque classe (sinon jsp comment faire)
        
        string userType = this.user.getUserType() ;
        if (strcmp(userType, "Government")){
            View::MenuPrincipalGovernmentAgency() ;
        }
        else if (strcmp(userType, "Private")){
            View::MenuPrincipalPrive() ;
        }
        else if (strcmp(userType, "Provider")){
            View::MenuPrincipalProvider() ;
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
    this.user = NULL ;
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
