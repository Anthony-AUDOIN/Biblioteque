#include "biblio.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	system("color F0");

	int nbnote = 0;
	string titre;
	t_auteur monauteur;
	t_biblio mabib;
	t_livre monlivre;
	mabib.nbelem = 0;
	mabib.nbauteur = 0;
	int choix;
	do {
		menu(1, 9, "|------------------------------------------------------------------|\n			BIBLIOTHEQUE			\n#################################################################\n			  ACCUEIL					\n1 : Afficher l'ensemble des livres de la bibilotheque\n2 : Ajouter un livre\n3 : Afficher l'ensemble des auteurs de la biblioteque\n4 : Supprimer un livre\n5 : Recherche\n6 : Emprunter un livre\n7 : Rendre un livre\n8 : Noter un livre\n9 : Quitter", choix);
		switch (choix) {
		case 1: affichelivres(mabib);
			system("pause");
			break;
		case 2: ajoutelivre(mabib, titre);
			system("pause");
			break;
		case 3: afficheauteurs(mabib);
			system("pause");
			break;
		case 4:supprlivre(mabib);
			system("pause");
			break;
		case 5: recherche(mabib);
			system("pause");
			break;
		case 6: emprunterlivre(mabib);
			system("pause");
			break;
		case 7: rendrelivre(mabib);
			system("pause");
			break;
		case 8: notelivre(mabib, nbnote, monlivre);
			system("pause");
			break;
		case 9:
			break;
		}
		system("cls");
	} while (choix != 9);
	return 0;

}