/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Sensor::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Sensor::GetSensorID(void) const
{
    return this->sensorID;
}

CoordGPS *Sensor::GetCoord(void) const
{
    return this->coord;
}

void Sensor::addMeasurement(Measurement *m)
{
    measurements.push_back(m);
}

bool Sensor::GetFiability(void) const
{
    return this->fiability;
}

User *Sensor::GetUser(void) const
{
    return this->user;
}

vector<Measurement *> Sensor::getMeasurements(void) const
{
    return this->measurements;
}

void Sensor::SetSensorID(string id)
{
    this->sensorID = id;
}

void Sensor::SetCoord(CoordGPS *coord)
{
    this->coord = coord;
}

void Sensor::SetFiability(bool fiab)
{
    this->fiability = fiab;
}

void Sensor::SetUser(User *u)
{
    this->user = u;
}

//------------------------------------------------- Surcharge d'opérateurs
Sensor &Sensor::operator=(const Sensor &unSensor)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor(const Sensor &unSensor)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
    sensorID = unSensor.sensorID;
    if (unSensor.coord != nullptr)
    {
        coord = new CoordGPS(*unSensor.coord);
    }
    else
    {
        coord = nullptr;
    }
    fiability = unSensor.fiability;
    if (unSensor.user != nullptr)
    {
        user = new User(*unSensor.user);
    }
    else
    {
        user = nullptr;
    }

    for (const auto &measurement : unSensor.measurements)
    {
        if (measurement != nullptr)
        {
            measurements.push_back(measurement);
        }
    }
} //----- Fin de Sensor (constructeur de copie)

Sensor::Sensor()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
} //----- Fin de Sensor

Sensor::Sensor(string id, CoordGPS *coordonnee, User *u)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
    sensorID = id;
    coord = coordonnee;
    user = u;
} //----- Fin de Sensor

Sensor::~Sensor()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
    delete coord;
} //----- Fin de ~Sensor

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
