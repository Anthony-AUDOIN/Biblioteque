#include "biblio.h"
#include <iostream>
#include <string>

using namespace std;

int main() { 
	
	system("color F0");


	t_auteur monauteur;
	t_biblio mabib;
	mabib.nbelem = 0;
	mabib.nbauteur = 0;
	int choix;
	do {
		menu(1, 7, "|------------------------------------------------------------------|\n			BIBLIOTHEQUE			\n#################################################################\n			  ACCUEIL					\n1 : Afficher l'ensemble des livres de la bibilotheque\n2 : Ajouter un livre\n3 : Supprimer un livre\n4 : Recherche\n5 : Emprunter un livre\n6 : Rendre un livre\n7 : Quitter", choix);
		switch (choix) {
		case 1: affichelivres(mabib);
			system("pause");
			break;
		case 2: ajoutelivre(mabib);
			system("pause");
			break;
		case 3:supprlivre(mabib);
			system("pause");
			break;
		case 4: recherche(mabib);
			system("pause");
			break;
		case 5: emprunterlivre(mabib);
			break;
		case 6: rendrelivre(mabib);
			break;
		case 7:
			break;
		}
		system("cls");
	}
	while (choix != 7);
	return 0;
	
}