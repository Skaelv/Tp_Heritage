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
	this->Vider();
	//TODO chargement d'un fichier
	//Methode : renvoyer un vecteur de string(commandes) au controlleur qui
	//appellera pour chaque commande : this->Validation
	return true;
} //----- Fin de Méthode

bool Modele::Vider()
// Algorithme :
{
	for(map_it_type iterator = listeEltGeo.begin(); iterator != listeEltGeo.end(); iterator++)
	{
		delete iterator->second;
	}
	listeEltGeo.clear();
	return true;
} //----- Fin de Méthode



void Modele::AjouterCercle(string name,string commande, int fx,int fy, int fr)
//Algorithme
{
	listeEltGeo[name] =  new Cercle(fx,fy,fr,name,commande);
	cout << "# New Object : "<< name <<endl;
}

void Modele::AjouterRectangle(string name,string commande, int fx1,int fy1, int fx2,int fy2)
//Algorithme
{
	listeEltGeo[name] = new Rectangle(fx1,fy1,fx2,fy2,name,commande);
	cout << "# New Object : "<< name <<endl;
}

void Modele::AjouterLigne(string name,string commande, int fx1,int fy1, int fx2,int fy2)
//Algorithme
{
	listeEltGeo[name] = new Ligne(fx1,fy1,fx2,fy2,name,commande);
	cout  << "# New Object : "<< name <<endl;
}

void Modele::AjouterPolyligne(string name,string commande, vector<pair<int,int> > fligne)
//Algorithme
{
	listeEltGeo[name] = new Polyligne(fligne,name,commande);
	cout << "# New Object : "<< name <<endl;
}

void Modele::AjouterObjetAgrege(string name,string commande, vector<string> nameObjet)
//Algorithme
{
	list<EltGeo *> objetAg;
	for (vector<string>::iterator iter=nameObjet.begin();iter<nameObjet.end(); iter++)
		{
		objetAg.push_back(listeEltGeo.find(iter->c_str())->second);
		}
	listeEltGeo[name] = new ObjetAgrege(objetAg,name,commande);
	cout<< "# New Object : "<< name <<endl;
}


void Modele::SupprimerCommande(map<string,string>  &nameObjet)
//Algorithme
{
	map<string,string> temp;
	for (map<string,string>::iterator iter=nameObjet.begin();iter!=nameObjet.end(); iter++)
	{
		//La commande suivante stocke la commande et la liste des objets agreges auquel l'objet appartenait
		temp[listeEltGeo.find(iter->first)->second->GetCommande()]=this->DeleteAgrege(iter->first);
		delete (listeEltGeo.find(iter->first)->second);
		listeEltGeo.erase(listeEltGeo.find(iter->first));
	}
	nameObjet = temp;//Passage par reference : renvoie le tableau des commandes
	//servant à créer les objets que l'on vient de supprimer
}

void Modele::SupprimerObjet(string name)
//Algorithme Efface dynamiquement le pointeur *EltGeo avant d'effacer
//la ligne de listeEltGeo
{
	delete (listeEltGeo.find(name)->second);
	listeEltGeo.erase(listeEltGeo.find(name));
}

string Modele::DeleteAgrege(string objetASupprimer)
//Algorithme : Envoie objetASupprimer a tous les objetAgreges pour qu'ils vérifient
//si l'objet est dans leur liste et le retirent si tel est le cas avant suppression dans la memoire
{

	string listAgrege="";
	for(map_it_type iterator = listeEltGeo.begin(); iterator != listeEltGeo.end(); iterator++)
	{
		if(iterator->second->IsAgrege())
		{
			listAgrege+= iterator->second->DeleteElement(objetASupprimer);
		}
	}
	return listAgrege;

}

void Modele::AddAgrege(string nameObject,string nameAgrege)
{
	listeEltGeo.find(nameAgrege)->second->AddElement(listeEltGeo.find(nameObject)->second);
}

void Modele::EnumererCommande()
//Algorithme
{

	for(map_it_type iterator = listeEltGeo.begin(); iterator != listeEltGeo.end(); iterator++)
	{
	cout << iterator->second->GetCommande() << endl;
	}

}

bool Modele::ObjetExistant(string fname)
//Algorithme
{
	return (listeEltGeo.find(fname)!=listeEltGeo.end()) ? true : false;
}


void Modele::Translater(int dx,int dy, string fname)
//Algorithme
{
	listeEltGeo.find(fname)->second->Translater(dx,dy);
	cout <<"# "<< fname << " has been moved"<<endl;
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
	for(map_it_type iterator = listeEltGeo.begin(); iterator != listeEltGeo.end(); iterator++)
	{
		delete iterator->second;
	}

#ifdef MAP
    cout << "Appel au destructeur de <Modele>" << endl;
#endif
} //----- Fin de ~Modele


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
