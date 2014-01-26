/*************************************************************************
                           Polyligne  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <Polyligne> (fichier Polyligne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Polyligne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Polyligne::AjouterLigne ( Ligne fligne )
// Algorithme :
//
{
	lignes.push_back( fligne );
	return true;
} //----- Fin de Méthode

void Polyligne::Translater ( long int dx, long int dy )
// Algorithme :
//
{
	commande = "PL " + name;
	for ( vector< Ligne >::iterator iter = lignes.begin( ); iter < lignes.end( ); iter++ )
	{
		if ( iter == lignes.begin( ) )
		{
			commande += iter->GetP1( ).Translater( dx, dy );
		}
		iter->Translater( dx, dy );
		commande += iter->GetP2( ).Translater( 0, 0 );
	}
} //----- Fin de Méthode

bool Polyligne::IsAgrege( )
//Algorithme
//
{
	return false;
}


//------------------------------------------------- Surcharge d'opérateurs
Polyligne & Polyligne::operator = ( const Polyligne & unPolyligne )
// Algorithme :
//
{
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Polyligne::Polyligne ( const Polyligne & unPolyligne )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Polyligne>" << endl;
#endif
} //----- Fin de Polyligne (constructeur de copie)


Polyligne::Polyligne ( vector< pair< long int, long int > > flignes, string fname, string fcommande ) : EltGeo( fname, fcommande )
// Algorithme :
//
{
	long int x1;
	long int x2;
	long int y1;
	long int y2;
	vector< pair< long int, long int > >::iterator iter;
	for ( iter = flignes.begin( ); iter < flignes.end( )-1; )
	{
		//Impossible d'injecter iter-> directement dans ligne
		//car l'incrementation d'iter ne se fait qu'a la fin de l'instruction
		x1 = iter->first;
		y1 = iter->second;
		iter++;
		x2 = iter->first;
		y2 = iter->second;
		Ligne ligne = Ligne( x1, y1, x2, y2 );
		this->AjouterLigne( ligne );
	}
	Translater( 0, 0 );//Réecrit la commande (Evite les nombres à virgules et les espaces multiples)
#ifdef MAP
    cout << "Appel au constructeur de <Polyligne>" << endl;
#endif
} //----- Fin de Polyligne


Polyligne::~Polyligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Polyligne>" << endl;
#endif
} //----- Fin de ~Polyligne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
