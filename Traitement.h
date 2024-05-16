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
#include <list>
#include "util/Sensor.h"
#include "util/Attribute.h"
#include "util/Measurement.h"
#include "util/Cleaner.h"
#include "util/CoordGPS.h"
#include "util/Date.h"
#include "util/AirMeasurement.h"

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
    AirMeasurement calculateAirQualite(CoordGPS coords, Date date);
    // Mode d'emploi :
    //
    // Contrat :
    //

    AirMeasurement calculateMeanAirQualite(CoordGPS coords, Date date);
    // Mode d'emploi :
    //
    // Contrat :
    //

    AirMeasurement calculateMeanAirQualite(CoordGPS coords, int radius, Date dateDebut, Date dateFin);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool analyzeFunctionalState(Sensor sensor);
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
    void chargerDonnees();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //----------------------------------------------------- Attributs protégés
    list<Sensor> sensors;
    list<Attribute> typeMesures;
    list<Measurement> measurements;
    list<Cleaner> cleaners;
};

//-------------------------------- Autres définitions dépendantes de <Traitement>

#endif // TRAITEMENT_H
