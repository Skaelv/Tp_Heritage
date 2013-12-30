/*
 * main.cpp
 *
 *  Created on: 22 déc. 2013
 *      Author: kevin
 */




#include "Controller.h"
using namespace std;
#include <iostream>

int main ()
{
	Controller Cont;
	string commande;
	cout << " # Entrez une commande" << endl;
	getline(cin,commande);
	cout << commande << endl;
	while (commande!="EXIT")
	{
		Cont.Validation(commande);
		cout << " # Entrez une commande" << endl;
		getline(cin,commande);
	}

	return 0;
}
