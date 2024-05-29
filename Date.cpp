/*************************************************************************
                           Date  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Date> (fichier Date.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Date.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Date::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

 // Getters
    int Date::GetAnnee() const {
        return annee;
    }

    int Date::GetMois() const {
        return mois;
    }

    int Date::GetJour() const {
        return jour;
    }

    int Date::GetHeure() const {
        return heure;
    }

    // Setters
    void Date::SetAnnee(int a) {
        annee = a;
    }

    void Date::SetMois(int m) {
        mois = m;
    }

    void Date::SetJour(int j) {
        jour = j;
    }

    void Date::SetHeure(int h) {
        heure = h;
    }

//------------------------------------------------- Surcharge d'opérateurs
Date &Date::operator=(const Date &unDate)
// Algorithme :
//
{
} //----- Fin de operator =

bool Date::operator==(const Date &unDate) const {
    return (this->annee == unDate.annee) &&
           (this->mois == unDate.mois) &&
           (this->jour == unDate.jour);
}

//-------------------------------------------- Constructeurs - destructeur
Date::Date(const Date &unDate)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Date>" << endl;
#endif
} //----- Fin de Date (constructeur de copie)

Date::Date(int annee, int mois, int jour, int heure)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Date>" << endl;
#endif

    this->annee = annee;
    this->mois = mois;
    this->jour = jour;
    this->heure = heure;
} //----- Fin de Date

Date::Date()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Date>" << endl;
#endif
} //----- Fin de Date

Date::~Date()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Date>" << endl;
#endif
} //----- Fin de ~Date

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
