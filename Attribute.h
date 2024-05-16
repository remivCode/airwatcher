/*************************************************************************
                           Attribute  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Attribute> (fichier Attribute.h) ----------------
#if !defined(ATTRIBUTE_H)
#define ATTRIBUTE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribute>
//
//
//------------------------------------------------------------------------

class Attribute
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
    Attribute &operator=(const Attribute &unAttribute);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Attribute(const Attribute &unAttribute);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Attribute();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Attribute();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Attribute>

#endif // ATTRIBUTE_H
