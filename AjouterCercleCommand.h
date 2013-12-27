/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <Cercle> (fichier Cercle.h) ------
#if ! defined ( AJOUTERCERCLECOMMANDE_H_ )
#define AJOUTERCERCLECOMMANDE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Modele.h"
#include "Command.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cercle>
//
//
//------------------------------------------------------------------------

class AjouterCercleCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	 AjouterCercleCommand (string fname,string fcommande, int fx, int fy,int fr,Modele& fmodele);
     // Mode d'emploi :
     //
     // Contrat :
     //


	void Execute ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Undo ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AjouterCercleCommand ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string name,commande;
int x,y,r;
Modele modele;
};

//--------------------------- Autres définitions dépendantes de <AjouterCercleCommand>

#endif // AjouterCercleCommand_H_
