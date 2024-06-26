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
#include <cmath>
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

    friend AirMeasurement abs(const AirMeasurement &measurement);

    int GetAtmoIndex(void) const;
    float GetO3(void) const;
    float GetSO2(void) const;
    float GetNO2(void) const;
    float GetPM10(void) const;

    //------------------------------------------------- Surcharge d'opérateurs
    AirMeasurement &operator=(const AirMeasurement &unAirMeasurement);
    // Mode d'emploi :
    //
    // Contrat :
    //

    AirMeasurement operator+(const AirMeasurement &unAirMeasurement) const;

    AirMeasurement operator/(int diviseur) const;

    //-------------------------------------------- Constructeurs - destructeur
    AirMeasurement(const AirMeasurement &unAirMeasurement);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AirMeasurement(float o3, float so2, float no2, float pm10);
    // Mode d'emploi (constructeur avec paramètres) :
    //
    // Contrat :
    //

    bool operator<(const AirMeasurement &other) const;
    // Mode d'emploi (constructeur avec paramètres) :
    //
    // Contrat :
    //

    AirMeasurement operator-(const AirMeasurement &unAirMeasurement) const;
    // Mode d'emploi (constructeur avec paramètres) :
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
    int atmoIndex;
    float o3;
    float so2;
    float no2;
    float pm10;
};

//-------------------------------- Autres définitions dépendantes de <AirMeasurement>

#endif // AIRMEASUREMENT_H
