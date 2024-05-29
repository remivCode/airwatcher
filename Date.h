/*************************************************************************
                           Date  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Date> (fichier Date.h) ----------------
#if !defined(DATE_H)
#define DATE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Date>
//
//
//------------------------------------------------------------------------

class Date
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    int GetAnnee(void) const;
    int GetMois(void) const;
    int GetJour(void) const;
    int GetHeure(void) const;
    void SetAnnee(int a);
    void SetMois(int m);
    void SetJour(int j);
    void SetHeure(int h);

    //------------------------------------------------- Surcharge d'opérateurs
    Date &operator=(const Date &unDate);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur

    Date(const Date &unDate);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Date(int annee, int mois, int jour, int heure);
    // Mode d'emploi (constructeur avec paramètres) :
    //
    // Contrat :
    //

    Date();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Date();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    int annee;
    int mois;
    int jour;
    int heure;
};

//-------------------------------- Autres définitions dépendantes de <Date>

#endif // DATE_H
