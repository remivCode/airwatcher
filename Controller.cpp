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
#include "util/User.h"
#include "util/CoordGPS"
#include "util/Date"
#include "util/AirMeasurement"
#include "util/Sensor"
#include "util/GovernmentAgencyEmployee"
#include "util/PrivateIndividual"
#include "util/Provider"

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
            if ((abs(coordGPS.getLatitude() > 90.0)) or (abs(coordGPS.getLongitude() > 180))){
                View::afficherErreur("The latitude must be between -90 and 90 and the longitude must be between -180 and 180\r\n") ;
                break ;
            }

            Date date = View::entrerDate("Enter the date : \r\n") ;
            int an = date.getAnnee() ;
            int mois = date.getMois() ;
            int jour = date.getJour() ; 
            int heure = date.getHeure() ;

            if ((mois<0) or (mois>12)){
                View::afficherErreur("Months must be between 1 and 12 included\r\n") ;
                break ;
            }

            if(jour<0){
                View::afficherErreur("Days must be positive\r\n") ;
                break ;
            }

            if ((heure<0) or (heure>23)){
                View::afficherErreur("Hours must be between 0 and 23 included\r\n") ;
                break ;
            }

            if (mois==2){
                if (((an%4)==0) and (jour>29)){
                    View::afficherErreur("February has only 29 days on bissextile years\r\n") ;
                    break ;
                }
                if (((an%4)!=0) and (jour>28)){
                    View::afficherErreur("February has only 28 days on not bissextile years\r\n") ;
                    break ;
                }
            }

            if ((mois%2==1) and (jour>31))){
                View::afficherErreur("Days must not exceed 31\r\n") ;
                break ;
            }
            if ((mois%2==0) and (mois!=2) and (jour>30)){
                View::afficherErreur("Days of some months must not exceed 30\r\n") ;
                break ;
            }

            AirMeasurement airMeasurement = Traitement::calculateAirQuality(coordGPS, date) ;

            View::afficherMesureAirQuality(airMeasurement) ;

            break ;

        case caseMesureMeanAirQuality :
            CoordGPS coordGPS = View::entrerCoord("Enter the GPS coordinates of the center of the area : \r\n") ;
            if ((abs(coordGPS.getLatitude() > 90.0)) or (abs(coordGPS.getLongitude() > 180))){
                View::afficherErreur("The latitude must be between -90 and 90 and the longitude must be between -180 and 180\r\n") ;
                break ;
            }

            int radius = View::entrerNombre("Enter the radius (in km) : \r\n") ;
            if ((radius <= 0) or (radius > 200)){
                View::afficherErreur("The radius must be strictly positive and must not exceed 200\r\n") ;
                break ;
            }

            Date dateBeginning = View::entrerDate("Enter the date 1 (beginning) : \r\n") ;
            int an1 = dateBeginning.getAnnee() ;
            int mois1 = dateBeginning.getMois() ;
            int jour1 = dateBeginning.getJour() ; 
            int heure1 = dateBeginning.getHeure() ;
            Date dateEnd = View::enterDate("Enter the date 2 (end) : \r\n") ;
            int an2 = dateEnd.getAnnee() ;
            int mois2 = dateEnd.getMois() ;
            int jour2 = dateEnd.getJour() ; 
            int heure2 = dateEnd.getHeure() ;

            if ((mois1<0) or (mois1>12) or (mois2<0) or (mois2>12)){
                View::afficherErreur("Months must be between 1 and 12 included\r\n") ;
                break ;
            }

            if((jour1<0) or (jour2<0)){
                View::afficherErreur("Days must be positive\r\n") ;
                break ;
            }

            if ((heure1<0) or (heure1>23) or (heure2<0) or (heure2>23)){
                View::afficherErreur("Hours must be between 0 and 23 included\r\n") ;
                break ;
            }

            if (mois1==2){
                if (((an1%4)==0) and (jour1>29)){
                    View::afficherErreur("February has only 29 days on bissextile years\r\n") ;
                    break ;
                }
                if (((an1%4)!=0) and (jour1>28)){
                    View::afficherErreur("February has only 28 days on not bissextile years\r\n") ;
                    break ;
                }
            }
            if (mois2==2){
                if (((an2%4)==0) and (jour2>29)){
                    View::afficherErreur("February has only 29 days on bissextile years\r\n") ;
                }
                if (((an2%4)!=0) and (jour2>28)){
                    View::afficherErreur("February has only 28 days on not bissextile years\r\n") ;
                    break ;
                }
            }

            if (((mois1%2==1) and (jour1>31)) or ((mois2%2==1) and (jour2>31))){
                View::afficherErreur("Days must not exceed 31\r\n") ;
                break ;
            }
            if (((mois1%2==0) and (mois1!=2) and (jour1>30)) or ((mois2%2==0) and (mois2!=2)and (jour2>30))){
                View::afficherErreur("Days of some months must not exceed 30\r\n") ;
                break ;
            }

            AirMeasurement airMeasurement = Traitement::calculateMeanAirQuality(coordGPS, radius, dateBeginning, dateEnd) ;

            View::afficherMesureAirQuality(airMeasurement) ;

            break ;
        
        case caseCheckSensorFunctional :
            string sensorID = View::entrerNombre("Enter the sensor ID : \r\n") ;

            Sensor sensor = Traitement::findSensorById(sensorID) ;
            bool functional = Traitement::analyzeFunctionalState(sensor) ;
            View::afficherBool(functional) ;

            break ;

        case caseRankSensorSimilarity :
            /*
            string sensorID = View::entrerNombre("Enter the sensor ID : \r\n") ;
            Date dateBeginning = View::entrerDate("Enter the date 1 (beginning) : \r\n") ;
            Date dateEnd = View::entrerDate("Enter the date 2 (end) : \r\n") ;

            Sensor sensor = Traitement::findSensorById(sensorID) ;
            vector<Sensor> vectSensor = Traitement::rankingBySimilarity(sensor, dateBeginning, dateEnd) ;

            View::afficherListe(vectSensor) ;
            */
            
            break ;

        case caseDeconnexion :
            this.user = NULL ;

            break ;
        
        default :

    }
    
    chargerMenu();

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
