/*************************************************************************
                           Traitement  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Traitement> (fichier Traitement.h) ----------------
#if !defined(TRAITEMENT_H)
#define TRAITEMENT_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <map>
#include "Sensor.h"
#include "Attribute.h"
#include "Measurement.h"
#include "Cleaner.h"
#include "CoordGPS.h"
#include "Date.h"
#include "AirMeasurement.h"
#include "User.h"
#define _USE_MATH_DEFINES
#include <math.h>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Traitement>
//
//
//------------------------------------------------------------------------

class Traitement
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    static void chargerDonnees();
    // Mode d'emploi :
    //
    // Contrat :
    //

    static void chargerDonneesTest();
    // Mode d'emploi :
    //
    // Contrat :
    //

    static map<float, Sensor *> findSensorByCoord(CoordGPS *coordonnees);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static AirMeasurement *calculateAirQualite(CoordGPS *coords, Date *date);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static User connexion(string login, string password);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static AirMeasurement *calculateMeanAirQualite(CoordGPS *coords, int radius, Date *dateDebut, Date *dateFin);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static map<AirMeasurement, Sensor *> rankingBySimilarity(Sensor *sensor, Date *dateDebut, Date *dateFin);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static Sensor *findSensorById(string id);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static Attribute *findAttributeById(string id);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static bool analyzeFunctionalState(Sensor *sensor);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static void clean();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    Traitement &operator=(const Traitement &unTraitement);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Traitement(const Traitement &unTraitement);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Traitement();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Traitement();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    static float dist(float lat1, float lon1, float lat2, float lon2);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //----------------------------------------------------- Attributs protégés
    static vector<Sensor *> sensors;
    static vector<Attribute *> typeMesures;
    static vector<Cleaner *> cleaners;
    static vector<User *> users; // à rajouter dans le diagramme de classes
};

//-------------------------------- Autres définitions dépendantes de <Traitement>

#endif // TRAITEMENT_H
