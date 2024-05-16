/*************************************************************************
                           AirMeasurement  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <AirMeasurement> (fichier AirMeasurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "AirMeasurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type AirMeasurement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
AirMeasurement &AirMeasurement::operator=(const AirMeasurement &unAirMeasurement)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
AirMeasurement::AirMeasurement(const AirMeasurement &unAirMeasurement)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AirMeasurement>" << endl;
#endif
} //----- Fin de AirMeasurement (constructeur de copie)

AirMeasurement::AirMeasurement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AirMeasurement>" << endl;
#endif
} //----- Fin de AirMeasurement

AirMeasurement::~AirMeasurement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AirMeasurement>" << endl;
#endif
} //----- Fin de ~AirMeasurement

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
