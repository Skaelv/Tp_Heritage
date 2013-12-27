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
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Modele>
//
//
//------------------------------------------------------------------------
typedef pair<string, EltGeo*> pairStringEltGeo_type;
typedef pair<string,pairStringEltGeo_type> pairMap_type;
typedef map<string, pairStringEltGeo_type >::iterator map_it_type;


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

	bool Sauvegarder ( string fichier );
	// Mode d'emploi :
    //		Sauvegarde le modèle courant avec les informations passées en paramètre
    // Contrat :
    //

	bool Charger(string fichier);
	// Mode d'emploi :
    //		Charge le modèle contenu dans le fichier passé en paramètre dans commande
    // Contrat :
    //

	bool Vider();
	// Mode d'emploi : Vide le modele courant
    // Contrat :
    //


	void AjouterCercle(string name,string command, int fx,int fy, int fr);
	// Mode d'emploi :Creation d'un cercle stocké dans listeEltGeo
    // Contrat :
    //

	void SupprimerCommande(vector<string> &nameObjet);
	// Mode d'emploi :Supprime les objets et leurs commandes
	//Renvoie par reference les commandes de creation
    // Contrat :
    //

	void SupprimerObjet(string name);
	//Mode d'emploi :Supprime un objet unique
    // Contrat :
    //
	void EnumererCommande();
	// Mode d'emploi : Liste les commandes des objets stockés dans le modele courant
    // Contrat :
    //

	bool ObjetExistant(string objet);
	// Mode d'emploi : Retourne true si l'objet existe dans listeEltGeo
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

    Modele ( );
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
	map < string , pairStringEltGeo_type> listeEltGeo;
};

//--------------------------- Autres définitions dépendantes de <Modele>

#endif // MODELE_H_
