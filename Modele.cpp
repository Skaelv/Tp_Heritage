/*************************************************************************
                           Modele  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <Modele> (fichier Modele.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

//------------------------------------------------------ Include personnel
#include "Modele.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Modele::Sauvegarder ( string fichier )
// Algorithme :
{
	return true;
} //----- Fin de Méthode

bool Modele::Charger(string fichier)
// Algorithme :
{
	return true;
} //----- Fin de Méthode

bool Modele::Vider()
// Algorithme :
{
	//Effacer dynamiquement les EltGeo crées
	listeEltGeo.clear();
	return true;
} //----- Fin de Méthode



void Modele::AjouterCercle(string name,string commande, int fx,int fy, int fr)
//Algorithme
{
	pairMap_type objet;
	pairStringEltGeo_type element;
	element.first = commande;
	element.second = new Cercle(name,fx,fy,fr);
	objet.first = name;
	objet.second = element;
	listeEltGeo.insert(objet);
}

void Modele::SupprimerCommande(vector<string> &nameObjet)
//Algorithme
{
	vector<string> cmd;
	for (unsigned int i=1;i<nameObjet.size(); ++i)
	{
		//Renvoie la commande stocké dans une paire dans la map
		cmd[i-1] = listeEltGeo.find(nameObjet[i])->first;
		cout << cmd[i-1] << endl;
		listeEltGeo.erase(listeEltGeo.find(nameObjet[i]));
	}
	nameObjet = cmd;//Passage par reference : renvoie le tableau des commandes
	//servant à créer les objets que l'on vient de supprimer
}

void Modele::SupprimerObjet(string name)
//Algorithme
{
	listeEltGeo.erase(listeEltGeo.find(name));
}

void Modele::EnumererCommande()
//Algorithme
{
	cout << "Modele::EnumererObjet" <<endl;
	for(map_it_type iterator = listeEltGeo.begin(); iterator != listeEltGeo.end(); iterator++)
	{
		cout << "Entree dans le for" <<endl;
	cout << iterator->first << endl;
	}

}

bool Modele::ObjetExistant(string objet)
//Algorithme
{
	return (listeEltGeo.find(objet)!=listeEltGeo.end()) ? true : false;
}


//------------------------------------------------- Surcharge d'opérateurs
Modele & Modele::operator = ( const Modele & unModele )
// Algorithme :
//
{
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Modele::Modele ( const Modele & unModele )
// Algorithme :
//
{
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
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Modele>" << endl;
#endif
} //----- Fin de ~Modele


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
