/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if !defined(SENSOR_H)
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include "CoordGPS.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
//
//
//------------------------------------------------------------------------

class Sensor
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetSensorID(void) const;
    CoordGPS GetCoord(void) const;
    bool GetFiability(void) const; 
    string GetUserID(void) const;

    void SetSensorID(string id); 
    void SetCoord(CoordGPS coordonnes);
    void SetFiability(bool fiab);
    void SetUserID(string id); 

    //------------------------------------------------- Surcharge d'opérateurs
    Sensor &operator=(const Sensor &unSensor);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Sensor(const Sensor &unSensor);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Sensor();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Sensor(string id, CoordGPS coordonnee, string idUser = NULL);
    // Mode d'emploi (constructeur avec paramètres):
    //
    // Contrat :
    //

    virtual ~Sensor();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string sensorID;
    CoordGPS coord;
    bool fiability = true;
    string userID;

};

//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // SENSOR_H
