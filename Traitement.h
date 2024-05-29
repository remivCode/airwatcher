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
#include "Sensor.h"
#include "Attribute.h"
#include "Measurement.h"
#include "Cleaner.h"
#include "CoordGPS.h"
#include "Date.h"
#include "AirMeasurement.h"
#include "User.h"

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

    static AirMeasurement calculateAirQualite(CoordGPS coords, Date date);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static User connexion(string login, string password);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static AirMeasurement calculateMeanAirQualite(CoordGPS coords, int radius, Date dateDebut, Date dateFin);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static Sensor *findSensorById(string id);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static bool analyzeFunctionalState(Sensor sensor);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static vector<Measurement> getMeasurementsBySensor(Sensor sensor);
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

    //----------------------------------------------------- Attributs protégés
    static vector<Sensor> sensors;
    static vector<Attribute> typeMesures;
    static vector<Measurement> measurements;
    static vector<Cleaner> cleaners;
    static vector<User> users; // à rajouter dans le diagramme de classes
};

//-------------------------------- Autres définitions dépendantes de <Traitement>

#endif // TRAITEMENT_H
