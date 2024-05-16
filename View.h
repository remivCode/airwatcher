/*************************************************************************
                           View  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if !defined(VIEW_H)
#define VIEW_H

//--------------------------------------------------- Interfaces utilisées
#include "AirMeasurement.h"
#include "CoordGPS.h"
#include "Sensor.h"
#include "Controller.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <vVew>
//
//
//------------------------------------------------------------------------

class View
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    View &operator=(const View &unView);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    View(const View &unView);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    View();
    // Mode d'emploi :
    //
    // Contrat :
    //
    static void afficherMesureAirQuality(const AirMeasurement& mesure);
    // Mode d'emploi :
    //
    // Contrat :
    //
    static void afficherListe(const vector<Sensor>& liste);
    // Mode d'emploi :
    //
    // Contrat :
    //
    static void afficherErreur(const string& message);
    // Mode d'emploi :
    //
    // Contrat :
    //
    static void afficherBool(const string& message);
    // Mode d'emploi :
    //
    // Contrat :
    //
    static void afficherTpsExec(const string& temps);
    // Mode d'emploi :
    //
    // Contrat :
    //
    static std::string entrerDate(const string& prompt);
    // Mode d'emploi :
    //
    // Contrat :
    //
    static int entrerNombre(const string& prompt);
    // Mode d'emploi :
    //
    // Contrat :
    //
    CoordGPS entrerCoord(const string& prompt);
    // Mode d'emploi :
    //
    // Contrat :
    //
    static void MenuConnexion();
    // Mode d'emploi :
    //
    // Contrat :
    //
    static void MenuPrincipalPrive();
    // Mode d'emploi :
    //
    // Contrat :
    //
    static void MenuPrincipalGovernmentAgency();
    // Mode d'emploi :
    //
    // Contrat :
    //
    static void MenuPrincipalProvider();
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual ~View();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <View>

#endif // VIEW_H
