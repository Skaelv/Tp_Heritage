/*************************************************************************
                           Modele  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <Modele> (fichier Modele.h) ------
#if ! defined ( MODELE_H_ )
#define MODELE_H_

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include "EltGeo.h"
#include "Point.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Ligne.h"
#include "Polyligne.h"
#include "ObjetAgrege.h"
#include <string>
#include <stack>
#include <vector>
#include <set>
#include "Command.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Modele>
//
//
//------------------------------------------------------------------------
typedef pair<string, EltGeo *> pairStringEltGeo_type;
typedef map<string, EltGeo * >::iterator map_it_type;
typedef pair<string, string> pairString;


class Modele
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	void AjouterCercle(string name,string command, long int fx,long int fy, long int fr);
	// Mode d'emploi :Creation d'un cercle stocké dans listeEltGeo
    // Contrat :
    //

	void AjouterRectangle(string name,string commande, long int fx1,long int fy1, long int fx2,long int fy2);
	// Mode d'emploi :Creation d'un rectangle stocké dans listeEltGeo
    // Contrat :
    //

	void AjouterLigne(string name,string commande, long int fx1,long int fy1,long int fx2,long int fy2);
	// Mode d'emploi :Creation d'une ligne stocké dans listeEltGeo
    // Contrat :
    //

	void AjouterPolyligne(string name,string commande, vector<pair<long int,long int> > fligne);
	// Mode d'emploi :Creation d'une polyligne stocké dans listeEltGeo
    // Contrat :
    //

	void AjouterObjetAgrege(string name,string commande, set<string> nameObjet);
	// Mode d'emploi :Creation d'un objetagrege stocké dans listeEltGeo
    // Contrat :
    //

	void SupprimerCommande(map<string,string>  &nameObjet);
	// Mode d'emploi :Supprime les objets et leurs commandes
	//Renvoie par reference les commandes de creation
    // Contrat :
    //

	void SupprimerObjet(string name);
	//Mode d'emploi :Supprime un objet unique
    // Contrat :
    //

	string DeleteAgrege(string objetASupprimer);
	//Mode d'emploi :Parcoure la liste d'objet et appelle la methode DeleteElement
	//si l'objet est un objet agregé afin qu'il supprime l'element si il est dans
	//sa propres liste
    // Contrat :
    //

	void AddAgrege(string nameObject,string nameAgrege);
	// Mode d'emploi : ajoute nameObject a l'objet nameAgrege
    // Contrat : Methode utilisée par la commande DeleteCommand pour reconstituer l'objet agrege
    //


	void EnumererCommande();
	// Mode d'emploi : Liste les commandes des objets stockés dans le modele courant
    // Contrat :
    //

	bool ObjetExistant(string fname);
	// Mode d'emploi : Retourne true si l'objet existe dans listeEltGeo
    // Contrat :
    //

	void Translater(long int dx,long int dy,  string fname);
	// Mode d'emploi : Retourne true si l'objet existe dans listeEltGeo
    // Contrat :
    //



	void Execute(Command *command);
	// Mode d'emploi : Execute la commande et la stocke dans la pile Undo
    // Contrat :
    //


	//------------------------------------------------- Surcharge d'opérateurs
    Modele & operator = ( const Modele & unModele );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Modele ( const Modele & unModele );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Modele ( );//Command *command = 0
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Modele ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	map < string , EltGeo *> listeEltGeo;

};

//--------------------------- Autres définitions dépendantes de <Modele>

#endif // MODELE_H_
