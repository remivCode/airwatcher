/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Cleaner.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Cleaner::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

// Getters
string Cleaner::getCleanerID() const
{
    return cleanerID;
}

CoordGPS Cleaner::getCoord() const
{
    return coord;
}

Date Cleaner::getTimestampStart() const
{
    return timestamp_start;
}

Date Cleaner::getTimestampStop() const
{
    return timestamp_stop;
}

Provider *Cleaner::getProvider() const
{
    return provider;
}

// Setters
void Cleaner::setCleanerID(const std::string &id)
{
    cleanerID = id;
}

void Cleaner::setCoord(const CoordGPS &gps)
{
    coord = gps;
}

void Cleaner::setTimestampStart(const Date &start)
{
    timestamp_start = start;
}

void Cleaner::setTimestampStop(const Date &stop)
{
    timestamp_stop = stop;
}

void Cleaner::setProvider(Provider *prov)
{
    provider = prov;
}

//------------------------------------------------- Surcharge d'opérateurs
Cleaner &Cleaner::operator=(const Cleaner &unCleaner)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner(const Cleaner &unCleaner)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cleaner>" << endl;
#endif
} //----- Fin de Cleaner (constructeur de copie)

Cleaner::Cleaner()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
} //----- Fin de Cleaner

Cleaner::Cleaner(string id, CoordGPS coordonnee, Date debut, Date fin, Provider *provid)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
    this->cleanerID = id;
    this->coord = coordonnee;
    this->timestamp_start = debut;
    this->timestamp_stop = fin;
    this->provider = provid;
} //----- Fin de Cleaner

Cleaner::~Cleaner()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif
} //----- Fin de ~Cleaner

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
