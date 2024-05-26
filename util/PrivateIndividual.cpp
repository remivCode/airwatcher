/*************************************************************************
                           PrivateIndividual  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <PrivateIndividual> (fichier PrivateIndividual.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "PrivateIndividual.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type PrivateIndividual::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

int PrivateIndividual::GetPoints(void) const
{
    return this->numberOfPoints;
}

bool PrivateIndividual::GetFiability(void) const
{
    return this->fiability;
}

void PrivateIndividual::SetPoints(int points)
{
    this->numberOfPoints = points;
}

void PrivateIndividual::SetFiability(bool fiab)
{
    this->fiability = fiab;
}

void PrivateIndividual::IncrementerNbPoints()
{
    this->numberOfPoints++;
}

//------------------------------------------------- Surcharge d'opérateurs
PrivateIndividual &PrivateIndividual::operator=(const PrivateIndividual &unPrivateIndividual)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
PrivateIndividual::PrivateIndividual(const PrivateIndividual &unPrivateIndividual)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PrivateIndividual>" << endl;
#endif
} //----- Fin de PrivateIndividual (constructeur de copie)

PrivateIndividual::PrivateIndividual()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PrivateIndividual>" << endl;
#endif
} //----- Fin de PrivateIndividual

PrivateIndividual::PrivateIndividual(string id, string login, string password) : User(id, login, password)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PrivateIndividual>" << endl;
#endif
} //----- Fin de PrivateIndividual

PrivateIndividual::~PrivateIndividual()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PrivateIndividual>" << endl;
#endif
} //----- Fin de ~PrivateIndividual

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
