/*************************************************************************
                           User  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type User::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string User::GetID(void) const
{
    return this->userID;
}

string User::GetLogin(void) const
{
    return this->login;
}

string User::GetPassword(void) const
{
    return this->password;
}

void User::SetID(string id)
{
    this->userID = id;
}

void User::SetLogin(string login)
{
    this->login = login;
}

void User::SetPassword(string password)
{
    this->password = password;
}

//------------------------------------------------- Surcharge d'opérateurs
User &User::operator=(const User &unUser)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
User::User(const User &unUser)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <User>" << endl;
#endif
} //----- Fin de User (constructeur de copie)

User::User()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif
} //----- Fin de User

User::User(string id, string login, string password)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif
    this->userID = id;
    this->login = login;
    this->password = password;
} //----- Fin de User

User::~User()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <User>" << endl;
#endif
} //----- Fin de ~User

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
