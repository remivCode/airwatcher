/*************************************************************************
                           GovernmentAgencyEmployee  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <GovernmentAgencyEmployee> (fichier GovernmentAgencyEmployee.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GovernmentAgencyEmployee.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type GovernmentAgencyEmployee::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
GovernmentAgencyEmployee &GovernmentAgencyEmployee::operator=(const GovernmentAgencyEmployee &unGovernmentAgencyEmployee)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
GovernmentAgencyEmployee::GovernmentAgencyEmployee(const GovernmentAgencyEmployee &unGovernmentAgencyEmployee)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GovernmentAgencyEmployee>" << endl;
#endif
} //----- Fin de GovernmentAgencyEmployee (constructeur de copie)

GovernmentAgencyEmployee::GovernmentAgencyEmployee()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GovernmentAgencyEmployee>" << endl;
#endif
} //----- Fin de GovernmentAgencyEmployee

GovernmentAgencyEmployee::GovernmentAgencyEmployee(int id, string login, string password) : User(id, login, password)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GovernmentAgencyEmployee>" << endl;
#endif
} //----- Fin de GovernmentAgencyEmployee

GovernmentAgencyEmployee::~GovernmentAgencyEmployee()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GovernmentAgencyEmployee>" << endl;
#endif
} //----- Fin de ~GovernmentAgencyEmployee

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
