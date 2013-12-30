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
	//Effacer dynamiquement les EltGeo crées stockés dans la map listeEltGeo(pointeurs)
	listeEltGeo.clear();
	return true;
} //----- Fin de Méthode



void Modele::AjouterCercle(string name,string commande, int fx,int fy, int fr)
//Algorithme
{
	pairStringEltGeo_type element;
	element.first = commande;
	element.second = new Cercle(name,fx,fy,fr);
	listeEltGeo[name] = element;
	cout << "OK"<< endl << "# New Object : "<< name <<endl;
}

void Modele::AjouterRectangle(string name,string commande, int fx1,int fy1, int fx2,int fy2)
//Algorithme
{
	pairStringEltGeo_type element;
	element.first = commande;
	element.second = new Rectangle(name,fx1,fy1,fx2,fy2);
	listeEltGeo[name] = element;
	cout << "OK"<< endl << "# New Object : "<< name <<endl;
}

void Modele::AjouterLigne(string name,string commande, int fx1,int fy1, int fx2,int fy2)
//Algorithme
{
	pairStringEltGeo_type element;
	element.first = commande;
	element.second = new Ligne(fx1,fy1,fx2,fy2,name);
	listeEltGeo[name] = element;
	cout << "OK"<< endl << "# New Object : "<< name <<endl;
}

void Modele::AjouterPolyligne(string name,string commande, vector<pair<int,int> > fligne)
//Algorithme
{
	pairStringEltGeo_type element;
	element.first = commande;
	element.second = new Polyligne(name,fligne);
	listeEltGeo[name] = element;
	cout << "OK"<< endl << "# New Object : "<< name <<endl;
}

void Modele::AjouterObjetAgrege(string name,string commande, vector<string> nameObjet)
//Algorithme
{
}


void Modele::SupprimerCommande(vector<string>& nameObjet)
//Algorithme
{
	vector<string> temp;
//TODO Probleme de suppression ...Bug du programme
	for (vector<string>::iterator iter=nameObjet.begin();iter<nameObjet.end(); iter++)
	{
		temp.push_back(listeEltGeo.find(iter->c_str())->second.first);//
		delete (listeEltGeo.find(iter->c_str())->second.second);
		listeEltGeo.erase(listeEltGeo.find(iter->c_str()));
	}
	nameObjet = temp;//Passage par reference : renvoie le tableau des commandes
	//servant à créer les objets que l'on vient de supprimer
}

void Modele::SupprimerObjet(string name)
//Algorithme Efface dynamiquement le pointeur *EltGeo avant d'effacer
//la ligne de la map
{
	delete (listeEltGeo.find(name)->second.second);
	listeEltGeo.erase(listeEltGeo.find(name));
}

void Modele::EnumererCommande()
//Algorithme
{

	for(map_it_type iterator = listeEltGeo.begin(); iterator != listeEltGeo.end(); iterator++)
	{
	cout << iterator->second.first << endl;
	}

}

bool Modele::ObjetExistant(string objet)
//Algorithme
{
	return (listeEltGeo.find(objet)!=listeEltGeo.end()) ? true : false;
}


void Modele::Translater(int dx,int dy)
//Algorithme
{

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
