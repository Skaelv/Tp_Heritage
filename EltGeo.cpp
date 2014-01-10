/*************************************************************************
                           EltGeo  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <EltGeo> (fichier EltGeo.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "EltGeo.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type EltGeo::Méthode ( liste des paramètres )
void EltGeo::Translater(int fdx, int fdy)
// Algorithme :
//
{
} //----- Fin de Méthode

string EltGeo::GetCommande()
// Algorithme :
//
{
	return commande;
} //----- Fin de Méthode

string EltGeo::GetName()
// Algorithme :
//
{
	return name;
} //----- Fin de Méthode


bool EltGeo::IsAgrege()
//Algorithme :
//
{
}

string EltGeo::DeleteElement(string objetASupprimer)
//Algorithme :
//
{
}

void EltGeo::AddElement(EltGeo * objetAInserer)
//Algorithme :
//
{
}


//------------------------------------------------- Surcharge d'opérateurs
EltGeo & EltGeo::operator = ( const EltGeo & unEltGeo )
// Algorithme :
//
{ return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
EltGeo::EltGeo ( const EltGeo & unEltGeo )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <EltGeo>" << endl;
#endif
} //----- Fin de EltGeo (constructeur de copie)


EltGeo::EltGeo ( string fname,string fcommande ):name(fname),commande(fcommande)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <EltGeo>" << endl;
#endif
} //----- Fin de EltGeo



EltGeo::~EltGeo ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <EltGeo>" << endl;
#endif
} //----- Fin de ~EltGeo


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
