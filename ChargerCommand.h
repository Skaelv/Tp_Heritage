/*************************************************************************
                           ChargerCommand  -  description
                             -------------------
    d�but                : 20 d�c. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <ChargerCommand> (fichier ChargerCommand.h) ------
#if ! defined ( CHARGER_COMMAND_H_ )
#define CHARGER_COMMAND_H_

//--------------------------------------------------- Interfaces utilis�es
#include "Modele.h"
#include "Command.h"
#include "Controller.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <ChargerCommand>
//
//
//------------------------------------------------------------------------



class ChargerCommand : public Command
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- M�thodes publiques

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
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
	std::string nomFichier;
	Controller* control;
	stack<Command *> saveUndo;
	stack<Command *> saveRedo;

};
//--------------------------- Autres d�finitions d�pendantes de <AjouterCercleCommand>

#endif // AjouterCercleCommand_H_
