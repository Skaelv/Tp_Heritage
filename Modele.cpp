/*************************************************************************
						Modele  -  description
						-------------------
	début                : 20 déc. 2013
	copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <Modele> (fichier Modele.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <iterator>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Modele.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Modele::AjouterCercle( string name, string commande, long int fx, long int fy, long int fr )
//Algorithme
{
	listeEltGeo[name] = new Cercle( fx, fy, fr, name, commande );
	cout << "# New Object : " << name << endl;
}

void Modele::AjouterRectangle( string name, string commande, long int fx1, long int fy1, long int fx2, long int fy2 )
//Algorithme
{
	listeEltGeo[name] = new Rectangle( fx1, fy1, fx2, fy2, name, commande );
	cout << "# New Object : " << name << endl;
}

void Modele::AjouterLigne( string name, string commande, long int fx1, long int fy1, long int fx2, long int fy2 )
//Algorithme
{
	listeEltGeo[name] = new Ligne( fx1, fy1, fx2, fy2, name, commande );
	cout  << "# New Object : " << name << endl;
}

void Modele::AjouterPolyligne( string name, string commande, vector< pair< long int, long int > > fligne )
//Algorithme
{
	listeEltGeo[name] = new Polyligne( fligne, name, commande );
	cout << "# New Object : " << name << endl;
}

void Modele::AjouterObjetAgrege( string name, string commande, set< string > nameObjet )
//Algorithme
{
	list< EltGeo * > objetAg;
	ostringstream oss;
	oss << "OA " << name;
	for ( set< string >::iterator iter = nameObjet.begin( ); iter != nameObjet.end( ); iter++ )
	{
		objetAg.push_back( listeEltGeo.find( iter->c_str( ) )->second );
		oss << " " << iter->c_str( );
	}
	commande = oss.str( );

	listeEltGeo[name] = new ObjetAgrege( objetAg, name, commande );
	cout<< "# New Object : " << name << endl;
}


void Modele::SupprimerCommande( map< string, string > &nameObjet )
//Algorithme
{
	map< string, string > temp;
	for ( map< string, string >::iterator iter = nameObjet.begin( ); iter != nameObjet.end( ); iter++ )
	{
		//La commande suivante stocke la commande et la liste des objets agreges auquel l'objet appartenait
		temp[listeEltGeo.find( iter->first )->second->GetCommande( )] = this->DeleteAgrege( iter->first );
		delete ( listeEltGeo.find( iter->first )->second );
		listeEltGeo.erase( listeEltGeo.find( iter->first ) );
	}
	nameObjet = temp;//Passage par reference : renvoie le tableau des commandes
	//servant à créer les objets que l'on vient de supprimer
}

void Modele::SupprimerObjet( string name )
//Algorithme Efface dynamiquement le pointeur *EltGeo avant d'effacer
//la ligne de listeEltGeo
{
	delete listeEltGeo.find( name )->second;
	listeEltGeo.erase( listeEltGeo.find( name ) );
}

string Modele::DeleteAgrege( string objetASupprimer )
//Algorithme : Envoie objetASupprimer a tous les objetAgreges pour qu'ils vérifient
//si l'objet est dans leur liste et le retirent si tel est le cas avant suppression dans la memoire
{
	string listAgrege = "";
	for( map_it_type iterator = listeEltGeo.begin( ); iterator != listeEltGeo.end( ); iterator++ )
	{
		if( iterator->second->IsAgrege( ) )
		{
			listAgrege += iterator->second->DeleteElement( objetASupprimer );
		}
	}
	return listAgrege;
}

void Modele::AddAgrege( string nameObject, string nameAgrege )
//Algorithme : 
{
	listeEltGeo.find( nameAgrege )->second->AddElement( listeEltGeo.find( nameObject )->second );
}

void Modele::EnumererCommande( )
//Algorithme
{
	for( map_it_type iterator = listeEltGeo.begin( ); iterator != listeEltGeo.end( ); iterator++ )
	{
		cout << iterator->second->GetCommande( ) << endl;
	}
}

bool Modele::ObjetExistant( string fname )
//Algorithme
{
	return ( listeEltGeo.find( fname ) != listeEltGeo.end( ) ) ? true : false;
}

void Modele::Translater( long int dx, long int dy, string fname )
//Algorithme
{
	listeEltGeo.find( fname )->second->Translater( dx, dy );
	cout << "# " << fname << " has been moved" << endl;
}

//------------------------------------------------- Surcharge d'opérateurs
Modele & Modele::operator = ( const Modele & unModele )
	// Algorithme :
	// Réalise une copie de la liste des éléments géométriques de unModele
{
	if( &(*this) != &unModele )
	{
		string type;
		listeEltGeo.clear( );
		for( map< string, EltGeo * >::const_iterator iterator = unModele.listeEltGeo.begin( ); iterator != unModele.listeEltGeo.end( ); iterator++ )
		{
			//Pour chaque objet de la unModele.map
			//Recréer des objets grâce à la commande
			istringstream ss( iterator->second->GetCommande( ) );
			istream_iterator< string > begin(ss);
			istream_iterator< string > end;
			vector< string > mots( begin, end );
			if ( mots[0] == "OA" )
			{
				list< EltGeo * > objetAg;
				for ( vector< string >::iterator iter = mots.begin( ); iter != mots.end( ); iter++ )
				{
					objetAg.push_back( listeEltGeo.find( iter->c_str( ) )->second );
				}
				listeEltGeo[iterator->first] = new ObjetAgrege( objetAg, iterator->first, iterator->second->GetCommande( ) );
			}
			else if ( mots[0] == "C" )
			{
				listeEltGeo[iterator->first] = new Cercle( atoi( mots[2].c_str( ) ), atoi( mots[3].c_str( ) ), atoi( mots[4].c_str( ) ), mots[1], iterator->second->GetCommande( ) );
			}
			else if ( mots[0] == "R" )
			{
				listeEltGeo[iterator->first] = new Rectangle( atoi( mots[2].c_str( ) ), atoi( mots[3].c_str( ) ), atoi( mots[4].c_str( ) ), atoi( mots[5].c_str( ) ), mots[1], iterator->second->GetCommande( ));
			}
			else if ( mots[0] == "L" )
			{
				listeEltGeo[iterator->first] = new Ligne( atoi( mots[2].c_str( ) ), atoi( mots[3].c_str( ) ), atoi( mots[4].c_str( ) ), atoi( mots[5].c_str( ) ), mots[1], iterator->second->GetCommande( ) );
			}
			else if ( mots[0] == "PL" )
			{
				vector< pair< long int, long int > > lignes;
				pair< int, int > l;
				for ( unsigned int i = 3; i < mots.size( ); i += 2 )
				{
					l.first = atoi( mots[i-1].c_str( ) );
					l.second = atoi( mots[i].c_str( ) );
					lignes.push_back( l );
				}
				listeEltGeo[iterator->first] = new Polyligne( lignes, mots[1], iterator->second->GetCommande( ) );
			}
		}
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Modele::Modele ( const Modele & unModele )
	// Algorithme :
	//
{
	string type;
	listeEltGeo.clear( );
	for( map< string, EltGeo * >::const_iterator iterator = unModele.listeEltGeo.begin( ); iterator != unModele.listeEltGeo.end( ); iterator++ )
	{
		//Pour chaque objet de la unModele.map
		//Recréer des objets grâce à la commande
		istringstream ss( iterator->second->GetCommande( ) );
		istream_iterator< string > begin(ss);
		istream_iterator< string > end;
		vector< string > mots( begin, end );
		if ( mots[0] == "OA" )
		{
			list< EltGeo * > objetAg;
			for ( vector< string >::iterator iter = mots.begin( ); iter != mots.end( ); iter++ )
			{
				objetAg.push_back( listeEltGeo.find( iter->c_str( ) )->second );
			}
			listeEltGeo[iterator->first] = new ObjetAgrege( objetAg, iterator->first, iterator->second->GetCommande( ) );
		}
		else if ( mots[0] == "C" )
		{
			listeEltGeo[iterator->first] = new Cercle( atoi( mots[2].c_str( ) ), atoi( mots[3].c_str( ) ), atoi( mots[4].c_str( ) ), mots[1], iterator->second->GetCommande( ) );
		}
		else if ( mots[0] == "R" )
		{
			listeEltGeo[iterator->first] = new Rectangle( atoi( mots[2].c_str( ) ), atoi( mots[3].c_str( ) ), atoi( mots[4].c_str( ) ), atoi( mots[5].c_str( ) ), mots[1], iterator->second->GetCommande( ));
		}
		else if ( mots[0] == "L" )
		{
			listeEltGeo[iterator->first] = new Ligne( atoi( mots[2].c_str( ) ), atoi( mots[3].c_str( ) ), atoi( mots[4].c_str( ) ), atoi( mots[5].c_str( ) ), mots[1], iterator->second->GetCommande( ) );
		}
		else if ( mots[0] == "PL" )
		{
			vector< pair< long int, long int > > lignes;
			pair< int, int > l;
			for ( unsigned int i = 3; i < mots.size( ); i += 2 )
			{
				l.first = atoi( mots[i-1].c_str( ) );
				l.second = atoi( mots[i].c_str( ) );
				lignes.push_back( l );
			}
			listeEltGeo[iterator->first] = new Polyligne( lignes, mots[1], iterator->second->GetCommande( ) );
		}
	}
#ifdef MAP
	cout << "Appel au constructeur de copie de <Modele>" << endl;
#endif
} //----- Fin de Modele (constructeur de copie)


Modele::Modele ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Modele>" << endl;
#endif
} //----- Fin de Modele


Modele::~Modele ( )
// Algorithme :
//Suppression dynamique des Elements Geo
{
	for( map_it_type iterator = listeEltGeo.begin( ); iterator != listeEltGeo.end( ); iterator++ )
	{
		if( iterator->second != NULL ){
			delete iterator->second;
		}
	}
#ifdef MAP
	cout << "Appel au destructeur de <Modele>" << endl;
#endif
} //----- Fin de ~Modele

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
