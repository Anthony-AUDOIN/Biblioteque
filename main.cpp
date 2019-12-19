#include "biblio.h"
#include <iostream>
#include <string>
using namespace std;

int main() { 
	//system("color 70");
	t_auteur monauteur;
	t_biblio mabib;
	mabib.nbelem = 0;
	mabib.nbauteur = 0;
	int choix;
	do {
		menu(1, 5, "			BIBLIOTHEQUE\n#################################################################\n			  ACCUEIL\n1 : Afficher l'ensemble des livres de la bibilotheque\n2 : Ajouter un livre\n3 : Supprimer un livre\n4 : Recherche\n5 : Quitter", choix);
		switch (choix) {
		case 1: affichelivres(mabib);
			cout << endl;
			system("pause");

			break;
		case 2: ajoutelivre(mabib, monauteur);
			system("pause");
			break;
		case 3:supprlivre(mabib);
			system("pause");
			break;
		case 4: recherche(mabib);
			system("pause");
			break;
		case 5:;
			break;
		}
		system("cls");
	}
	while (choix != 5);

	
}