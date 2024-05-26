/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Provider.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Provider::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Provider &Provider::operator=(const Provider &unProvider)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Provider::Provider(const Provider &unProvider)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Provider>" << endl;
#endif
} //----- Fin de Provider (constructeur de copie)

Provider::Provider()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
} //----- Fin de Provider

Provider::Provider(string id, string login, string password) : User(id, login, password)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
} //----- Fin de Provider

Provider::~Provider()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
} //----- Fin de ~Provider

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
