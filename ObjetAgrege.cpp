/*************************************************************************
                           ObjetAgrege  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <ObjetAgrege> (fichier ObjetAgrege.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
#include <list>
#include <set>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ObjetAgrege.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ObjetAgrege::Translater( int dx, int dy )
//Algorithme :
// Déplace tous les objets présents dans l'objet Agrégé
{
	for ( list< EltGeo * >::iterator iter = listObjet.begin( ); iter != listObjet.end( ); iter++ )
	{
		( *iter )->Translater( dx, dy );
	}
}

bool ObjetAgrege::IsAgrege( )
//Algorithme
//
{
	return true;
}


void ObjetAgrege::AddElement( EltGeo * element )
{
	listObjet.push_back( element );
	commande += " " + element->GetName();
}

string ObjetAgrege::DeleteElement( string objetASupprimer )
//Algorithme
//
{
	bool isInObject = false;
	commande = "OA " + name;
	for ( list< EltGeo * >::iterator iter = listObjet.begin( ); iter != listObjet.end( ); )
	{
		if ( ( *iter )->GetName( ) == objetASupprimer )
		{
			iter = listObjet.erase( iter ); //Supprime l'iterateur courant et passe au suivant
			isInObject= true;
		}
		else
		{
			commande += " " + ( *iter )->GetName( );//Modification de la commande pour
			//y retirer l'element supprimé.
			iter++;
		}
	}
	string temp;
	return temp = ( isInObject ) ? " " + name : "";//Renvoie le nom de l'objet ou rien
	//selon si l'objet à supprimer etait dans la liste de l'objet courant
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


ObjetAgrege::ObjetAgrege ( list< EltGeo * > flistObjet, string fname, string fcommande ) : EltGeo( fname, fcommande ), listObjet( flistObjet )
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
