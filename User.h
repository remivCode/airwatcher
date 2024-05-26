/*************************************************************************
                           User  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#if !defined(USER_H)
#define USER_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <User>
//
//
//------------------------------------------------------------------------

class User
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetID(void) const;
    string GetLogin(void) const;
    string GetPassword(void) const;

    void SetID(int id);
    void SetLogin(string login);
    void SetPassword(string password);

    //------------------------------------------------- Surcharge d'opérateurs
    User &operator=(const User &unUser);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    User(const User &unUser);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    User();
    // Mode d'emploi :
    //
    // Contrat :
    //

    User(string id, string login, string password);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~User();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string userID;
    string login;
    string password;
};

//-------------------------------- Autres définitions dépendantes de <User>

#endif // USER_H
