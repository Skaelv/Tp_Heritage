/*************************************************************************
                           ChargerCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <ChargerCommand> (fichier ChargerCommand.h) ------
#if ! defined ( CHARGER_COMMAND_H_ )
#define CHARGER_COMMAND_H_

//--------------------------------------------------- Interfaces utilisées
#include "Modele.h"
#include "Command.h"
#include "Controller.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ChargerCommand>
//
//
//------------------------------------------------------------------------

class ChargerCommand : public Command
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
	
	void Execute ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Undo (Modele& fmodele);
    // Mode d'emploi :
    //
    // Contrat :
    //
	
	//-------------------------------------------- Constructeurs - destructeur
	ChargerCommand(std::string fname, Controller* c);
	// Mode d'emploi :
     //
     // Contrat :
     //

	virtual ~ChargerCommand(void);

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	std::string nomFichier;
	Controller* control;
	stack<Command *> saveUndo;
	stack<Command *> saveRedo;

};
//--------------------------- Autres définitions dépendantes de <AjouterCercleCommand>

#endif // AjouterCercleCommand_H_