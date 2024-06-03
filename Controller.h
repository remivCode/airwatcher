/*************************************************************************
                           Controller  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Controller> (fichier Controller.h) ----------------
#if !defined(CONTROLLER_H)
#define CONTROLLER_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <algorithm>
using namespace std;
#include "User.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Controller>
//
//
//------------------------------------------------------------------------

class Controller
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    static void recupererSaisieMenu(int saisie);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static void connexion(string login, string password);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static void chargerMenu();
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
    Controller &operator=(const Controller &unController);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Controller(const Controller &unController);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Controller();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Controller();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    static void MesureAirQuality();
    // Mode d'emploi :
    //
    // Contrat :
    //

    static void MesureMeanAirQuality();
    // Mode d'emploi :
    //
    // Contrat :
    //

    static void CheckSensorFunctional();
    // Mode d'emploi :
    //
    // Contrat :
    //

    static void RankBySimilarity();
    // Mode d'emploi :
    //
    // Contrat :
    //

    static void ConsultPoints();
    // Mode d'emploi :
    //
    // Contrat :
    //

    static void ImpactAirCleaners();
    // Mode d'emploi :
    //
    // Contrat :
    //

    static void CheckPrivateIndividual();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //----------------------------------------------------- Attributs protégés
    static User *user;
};

//-------------------------------- Autres définitions dépendantes de <Controller>

#endif // CONTROLLER_H
