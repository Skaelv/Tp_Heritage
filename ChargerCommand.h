/*************************************************************************
                           ChargerCommand  -  description
                             -------------------
    d�but                : 20 d�c. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <ChargerCommand> (fichier ChargerCommand.h) ------
#if ! defined ( CHARGERCOMMAND_H_ )
#define CHARGERCOMMAND_H_

//--------------------------------------------------- Interfaces utilis�es
#include "Modele.h"
#include "Command.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <ChargerCommand>
//
//
//------------------------------------------------------------------------
class Controller;
class ChargerCommand : public Command
{


//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- M�thodes publiques


	void Execute (Modele& fmodele);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Undo (Modele& fmodele);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool IsNewModel ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    std::string GetCommande();
    // Mode d'emploi :
    //
    // Contrat :
    //

	//-------------------------------------------- Constructeurs - destructeur
	ChargerCommand(string fname, Controller * c);
	// Mode d'emploi :
     //
     // Contrat :
     //

	virtual ~ChargerCommand(void);

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
	string nomFichier;
	Controller * control;
	Modele OldModel;
};
//--------------------------- Autres d�finitions d�pendantes de <AjouterCercleCommand>


#endif // AjouterCercleCommand_H_

