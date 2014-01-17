/*************************************************************************
                           Controller  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <Controller> (fichier Controller.h) ------
#if ! defined ( CONTROLLER_H_ )
#define CONTROLLER_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <fstream>
#include "Modele.h"
#include "Command.h"
#include "DeleteCommand.h"
#include "Command.h"
#include "TranslaterCommand.h"
#include "AjouterCercleCommand.h"
#include "AjouterRectangleCommand.h"
#include "AjouterLigneCommand.h"
#include "AjouterPolyligneCommand.h"
#include "AjouterObjetAgregeCommand.h"
#include "ClearCommand.h"
#include "ChargerCommand.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Controller>
//
//
//------------------------------------------------------------------------


class Controller
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	bool ObjetExistant(string objet);
    // Mode d'emploi :
    //Renvoie true si l'objet est dans le modele courant
    // Contrat :Sous traite a la methode de l'attribut modele
    //

	void ExecuterCommand ( Command *command );
    // Mode d'emploi :
    //Execute la commande passé en parametre
    // Contrat :
    //

	void Redo();
    // Mode d'emploi :
    //Execute la commande passé en parametre
    // Contrat :
    //

	void Undo();
    // Mode d'emploi :
    //Execute la commande passé en parametre
    // Contrat :
    //

	void ClearRedo();
	//Mode d'emploi :
	// Efface les commandes qui ne pourront plus être recrée car risque de conflit
	//Contrat :
	//
	void EnumererObjet();
    // Mode d'emploi :
    //
    // Contrat :
    //

	void Translater(Command *command);
    // Mode d'emploi :
    //
    // Contrat :
    //

	bool Validation ( string commande );
	// Mode d'emploi :
    //		Retourne true, si commande passée en paramètre est valable
	//		False sinon
    // Contrat :
    //

	void Vider();
	// Mode d'emploi :
    //Vide le modele courant
    // Contrat : sous traite à la fonction vider du modele
    //

	void Charger(string url);
	// Mode d'emploi :
    //Vide le modele courant et charge le modele dont l'url est envoyé en parametre
    // Contrat : sous traite à la fonction vider du modele
    //

	void Sauvegarder(string url);
	// Mode d'emploi :
    //Sauvegarde le modele courant dans un nouveau fichier dont l'url est envoyé en parametre
    // Contrat : sous traite à la fonction vider du modele
    //
//------------------------------------------------- Surcharge d'opérateurs
    Controller & operator = ( const Controller & unController );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Controller ( const Controller & unController );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Controller ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Controller ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Modele modele;
	list<Command *> cmd;
	list<Command *>::iterator cmdIter;
};

//--------------------------- Autres définitions dépendantes de <Controller>

#endif // CONTROLLER_H_
