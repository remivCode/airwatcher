/*************************************************************************
                           PrivateIndividual  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <PrivateIndividual> (fichier PrivateIndividual.h) ----------------
#if !defined(PRIVATEINDIVIDUAL_H)
#define PRIVATEINDIVIDUAL_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PrivateIndividual>
//
//
//------------------------------------------------------------------------

class PrivateIndividual : public User
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void IncrementerNbPoints();
    // Incrementer le nb de points

    int GetPoints(void) const;
    bool GetFiability(void) const;

    void SetPoints(int points);
    void SetFiability(bool fiab);

    //------------------------------------------------- Surcharge d'opérateurs
    PrivateIndividual &operator=(const PrivateIndividual &unPrivateIndividual);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    PrivateIndividual(const PrivateIndividual &unPrivateIndividual);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PrivateIndividual();
    // Mode d'emploi :
    //
    // Contrat :
    //

    PrivateIndividual(string id);
    // Mode d'emploi (constructeur avec paramètres):
    //
    // Contrat :
    //

    virtual ~PrivateIndividual();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    int numberOfPoints = 0;
    bool fiability = true;
};

//-------------------------------- Autres définitions dépendantes de <PrivateIndividual>

#endif // PRIVATEINDIVIDUAL_H
