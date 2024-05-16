/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
#if !defined(CLEANER_H)
#define CLEANER_H

//--------------------------------------------------- Interfaces utilisées
#include "Provider.h"
#include "Date.h"
#include "CoordGPS.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cleaner>
//
//
//------------------------------------------------------------------------

class Cleaner
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
    Cleaner &operator=(const Cleaner &unCleaner);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Cleaner(const Cleaner &unCleaner);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cleaner();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cleaner();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string cleanerID;
    CoordGPS coord;
    Date timestamp_start;
    Date timestamp_stop;
    Provider provider;
};

//-------------------------------- Autres définitions dépendantes de <Cleaner>

#endif // CLEANER_H
