/*************************************************************************
                           ObjetAgrege  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <ObjetAgrege> (fichier ObjetAgrege.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ObjetAgrege.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ObjetAgrege::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Translater(int dx, int dy)
//Algorithme :
//
{

}

//------------------------------------------------- Surcharge d'opérateurs
ObjetAgrege & ObjetAgrege::operator = ( const ObjetAgrege & unObjetAgrege )
// Algorithme :
//
{
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ObjetAgrege::ObjetAgrege ( const ObjetAgrege & unObjetAgrege )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ObjetAgrege>" << endl;
#endif
} //----- Fin de ObjetAgrege (constructeur de copie)


ObjetAgrege::ObjetAgrege ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ObjetAgrege>" << endl;
#endif
} //----- Fin de ObjetAgrege


ObjetAgrege::~ObjetAgrege ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ObjetAgrege>" << endl;
#endif
} //----- Fin de ~ObjetAgrege


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
