
/*************************************************************************
                           DeleteCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <DeleteCommand> (fichier DeleteCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include<string>
#include<sstream>
#include <cstdlib>
#include <map>
#include <iterator>
using namespace std;

//------------------------------------------------------ Include personnel
#include "DeleteCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void DeleteCommand::Execute ( Modele& fmodele )
// Algorithme : Supprime les objets dont le nom est stockées dans mapElt
//
{
	fmodele.SupprimerCommande( mapElt );
}


void DeleteCommand::Undo ( Modele& fmodele )
// Algorithme : Recrée les commandes stockées dans mapElt
//Appel d'ObjetExistant inutile car retour à l'état juste avant appel a DELETE
//
{
	map< string, string > temp;
	for ( map< string, string >::iterator iter = mapElt.begin( ); iter != mapElt.end( ); iter++ )
	{
		//Decoupe la commande en parametre et ressort chaque mots dans un vecteur de string : mots
		istringstream ss( iter->first );
		istream_iterator< string > begin( ss );
		istream_iterator< string > end;
		vector<string> mots(begin, end);
		if ( mots[0] == "C" )
		{
			fmodele.AjouterCercle( mots[1], iter->first, atoi( mots[2].c_str( ) ), atoi( mots[3].c_str( ) ), atoi( mots[4].c_str( ) ) );
		}
		else if ( mots[0] == "R" )
		{
			fmodele.AjouterRectangle( mots[1], iter->first, atoi( mots[2].c_str() ), atoi( mots[3].c_str( ) ), atoi( mots[4].c_str( ) ), atoi( mots[5].c_str( ) ) );
		}//
		else if ( mots[0] == "L" )
		{
			fmodele.AjouterLigne( mots[1], iter->first, atoi( mots[2].c_str( ) ), atoi( mots[3].c_str( ) ), atoi( mots[4].c_str( ) ), atoi( mots[5].c_str( ) ) );
		}
		else if ( mots[0] == "PL" )
		{
			vector< pair< long int, long int > > lignes;
			pair< long int, long int > l;
			for ( unsigned int i = 3; i < mots.size( ); i += 2 )
			{
				l.first = atoi( mots[i-1].c_str( ) );
				l.second = atoi( mots[i].c_str( ) );
				lignes.push_back( l );
			}
			fmodele.AjouterPolyligne( mots[1], iter->first, lignes );
		}
		else if ( mots[0] == "OA" )
		{
			set< string > agrege;
			for ( unsigned int i = 2; i < mots.size( ); i++ )
			{
				agrege.insert( mots[i] );
			}
			fmodele.AjouterObjetAgrege( mots[1], iter->first, agrege );
		}
		istringstream ss2( iter->second );
		istream_iterator< string > begin2(ss2);
		istream_iterator< string > end2;
		vector< string > agrege( begin2, end2 );
		for ( unsigned int i = 0; i < agrege.size( ); i++ )
		{
			fmodele.AddAgrege( mots[1], agrege[i] );
		}
		temp[mots[1]] = "";
	}
	mapElt.clear( );
	mapElt = temp;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
DeleteCommand::DeleteCommand ( map< string, string > fname ) : mapElt( fname )
//Algorithme
//
{
}

DeleteCommand::~DeleteCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DeleteCommand>" << endl;
#endif
} //----- Fin de ~DeleteCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
