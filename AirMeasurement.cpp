/*************************************************************************
                           AirMeasurement  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <AirMeasurement> (fichier AirMeasurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "AirMeasurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type AirMeasurement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
int AirMeasurement::GetAtmoIndex() const
{
    return atmoIndex;
}

float AirMeasurement::GetO3() const
{
    return o3;
}

float AirMeasurement::GetSO2() const
{
    return so2;
}

float AirMeasurement::GetNO2() const
{
    return no2;
}

float AirMeasurement::GetPM10() const
{
    return pm10;
}

//------------------------------------------------- Surcharge d'opérateurs
AirMeasurement &AirMeasurement::operator=(const AirMeasurement &unAirMeasurement)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
AirMeasurement::AirMeasurement(const AirMeasurement &unAirMeasurement)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AirMeasurement>" << endl;
#endif
} //----- Fin de AirMeasurement (constructeur de copie)

AirMeasurement::AirMeasurement(float o3, float so2, float no2, float pm10)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AirMeasurement>" << endl;
#endif
    this->o3 = o3;
    this->so2 = so2;
    this->no2 = no2;
    this->pm10 = pm10;

    int indexo3;
    int indexso2;
    int indexno2;
    int indexpm;
    if ((o3 <= 29) && (o3>=0)){
        indexo3 = 1;}
    if ((o3 <= 54) && (o3>=30)){
        indexo3 = 2;}
    if ((o3 <= 79) && (o3>=55)){
        indexo3 = 3;}
    if ((o3 <= 104) && (o3>=80)){
        indexo3 = 4;}
    if ((o3 <= 129) && (o3>=105)){
        indexo3 = 5;}
    if ((o3 <= 149) && (o3>=130)){
        indexo3 = 6;}
    if ((o3 <= 179) && (o3>=150)){
        indexo3 = 7;}
    if ((o3 <= 209) && (o3>=180)){
        indexo3 = 8;}
    if ((o3 <= 239) && (o3>=210)){
        indexo3 = 9;}
    if (o3>=240){
        indexo3 = 10;}

    if((so2 >= 0) && (so2 <= 39)){
        indexso2 = 1;}
    if((so2 >= 40) && (so2 <= 79)){
        indexso2 = 2;}
    if((so2 >= 80) && (so2 <= 119)){
        indexso2 = 3;}
    if((so2 >= 120) && (so2 <= 159)){
        indexso2 = 4;}
    if((so2 >= 160) && (so2 <= 199)){
        indexso2 = 5;}
    if((so2 >= 200) && (so2 <= 249)){
        indexso2 = 6;}
    if((so2 >= 250) && (so2 <= 299)){
        indexso2 = 7;}
    if((so2 >= 300) && (so2 <= 399)){
        indexso2 = 8;}
    if((so2 >= 400) && (so2 <= 499)){
        indexso2 = 9;}
    if(so2 >= 500){
        indexso2 = 10;}

    if((no2 >= 0) && (no2 <= 29)){
        indexno2 = 1;}
    if((no2 >= 30) && (no2 <= 54)){
        indexno2 = 2;}
    if((no2 >= 55) && (no2 <= 84)){
        indexno2 = 3;}
    if((no2 >= 85) && (no2 <= 109)){
        indexno2 = 4;}
    if((no2 >= 110) && (no2 <= 134)){
        indexno2 = 5;}
    if((no2 >= 135) && (no2 <= 164)){
        indexno2 = 6;}
    if((no2 >= 165) && (no2 <= 199)){
        indexno2 = 7;}
    if((no2 >= 200) && (no2 <= 274)){
        indexno2 = 8;}
    if((no2 >= 275) && (no2 <= 399)){
        indexno2 = 9;}
    if(no2 >= 400){
        indexno2 = 10;}

    if((pm10 >= 0) && (pm10 <= 6)){
        indexpm = 1;}
    if((pm10 >= 7) && (pm10 <= 13)){
        indexpm = 2;}
    if((pm10 >= 14) && (pm10 <= 20)){
        indexpm = 3;}
    if((pm10 >= 21) && (pm10 <= 27)){
        indexpm = 4;}
    if((pm10 >= 28) && (pm10 <= 34)){
        indexpm = 5;}
    if((pm10 >= 35) && (pm10 <= 41)){
        indexpm = 6;}
    if((pm10 >= 42) && (pm10 <= 49)){
        indexpm = 7;}
    if((pm10 >= 50) && (pm10 <= 64)){
        indexpm = 8;}
    if((pm10 >= 65) && (pm10 <= 79)){
        indexpm = 9;}
    if(pm10 >= 80){
        indexpm = 10;}



} //----- Fin de AirMeasurement

AirMeasurement::AirMeasurement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AirMeasurement>" << endl;
#endif
} //----- Fin de AirMeasurement

AirMeasurement::~AirMeasurement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AirMeasurement>" << endl;
#endif
} //----- Fin de ~AirMeasurement

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
