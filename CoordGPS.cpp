/*************************************************************************
                           CoordGPS  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <CoordGPS> (fichier CoordGPS.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "CoordGPS.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CoordGPS::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
CoordGPS &CoordGPS::operator=(const CoordGPS &unCoordGPS)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
CoordGPS::CoordGPS(const CoordGPS &unCoordGPS)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CoordGPS>" << endl;
#endif
} //----- Fin de CoordGPS (constructeur de copie)

CoordGPS::CoordGPS()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CoordGPS>" << endl;
#endif
} //----- Fin de CoordGPS

CoordGPS::~CoordGPS()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CoordGPS>" << endl;
#endif
} //----- Fin de ~CoordGPS

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
