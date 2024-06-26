/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Measurement> (fichier Measurement.h) ----------------
#if !defined(MEASUREMENT_H)
#define MEASUREMENT_H

//--------------------------------------------------- Interfaces utilisées
#include "Date.h"
#include "Attribute.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Measurement>
//
//
//------------------------------------------------------------------------

class Measurement
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Attribute *getAttribute(void) const;
    float getValue(void) const;
    Date *getTimestamp(void) const;

    //------------------------------------------------- Surcharge d'opérateurs
    Measurement &operator=(const Measurement &unMeasurement);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Measurement(const Measurement &unMeasurement);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Measurement();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Measurement(Date *date, float val, Attribute *attribut);
    // Mode d'emploi (constructeur avec paramètres):
    //
    // Contrat :
    //

    virtual ~Measurement();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    Date *timestamp;
    float value;
    Attribute *attribut;
};

//-------------------------------- Autres définitions dépendantes de <Measurement>

#endif // MEASUREMENT_H
