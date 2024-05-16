/*************************************************************************
                           GovernmentAgencyEmployee  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <GovernmentAgencyEmployee> (fichier GovernmentAgencyEmployee.h) ----------------
#if !defined(GOVERNMENTAGENCYEMPLOYEE_H)
#define GOVERNMENTAGENCYEMPLOYEE_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GovernmentAgencyEmployee>
//
//
//------------------------------------------------------------------------

class GovernmentAgencyEmployee : public User
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    GovernmentAgencyEmployee &operator=(const GovernmentAgencyEmployee &unGovernmentAgencyEmployee);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    GovernmentAgencyEmployee(const GovernmentAgencyEmployee &unGovernmentAgencyEmployee);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GovernmentAgencyEmployee();
    // Mode d'emploi :
    //
    // Contrat :
    //

    GovernmentAgencyEmployee(int id, string login, string password);
    // Mode d'emploi (constructeur avec paramètres) :
    //
    // Contrat :
    //

    virtual ~GovernmentAgencyEmployee();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <GovernmentAgencyEmployee>

#endif // GOVERNMENTAGENCYEMPLOYEE_H
