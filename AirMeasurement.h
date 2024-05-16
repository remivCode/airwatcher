/*************************************************************************
                           AirMeasurement  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <AirMeasurement> (fichier AirMeasurement.h) ----------------
#if !defined(AIRMEASUREMENT_H)
#define AIRMEASUREMENT_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AirMeasurement>
//
//
//------------------------------------------------------------------------

class AirMeasurement
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
    AirMeasurement &operator=(const AirMeasurement &unAirMeasurement);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    AirMeasurement(const AirMeasurement &unAirMeasurement);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AirMeasurement();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AirMeasurement();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <AirMeasurement>

#endif // AIRMEASUREMENT_H
