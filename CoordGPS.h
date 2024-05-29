/*************************************************************************
                           CoordGPS  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <CoordGPS> (fichier CoordGPS.h) ----------------
#if !defined(COORDGPS_H)
#define COORDGPS_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CoordGPS>
//
//
//------------------------------------------------------------------------

class CoordGPS
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    float GetLat(void) const;
    float GetLng(void) const;
    void SetLat(float lat);
    void SetLng(float lng);

    //------------------------------------------------- Surcharge d'opérateurs
    CoordGPS &operator=(const CoordGPS &unCoordGPS);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    CoordGPS(const CoordGPS &unCoordGPS);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CoordGPS(float lat, float lng);
    // Mode d'emploi (constructeur avec paramètres):
    //
    // Contrat :
    //

    CoordGPS();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CoordGPS();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    float latitude;
    float longitude;
};

//-------------------------------- Autres définitions dépendantes de <CoordGPS>

#endif // COORDGPS_H
