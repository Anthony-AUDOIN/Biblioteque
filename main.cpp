#include "biblio.h"
#include <iostream>
#include <string>

using namespace std;

<<<<<<< HEAD
int main() { 
	//system("color 70");
=======
int main() {

	system("color F0");

	int nbnote = 0;
	string titre;
>>>>>>> c73b6e66b450e006a5a86043cfbdcb9203db8dc1
	t_auteur monauteur;
	t_biblio mabib;
	mabib.nbelem = 0;
	mabib.nbauteur = 0;
	int choix;
	do {
<<<<<<< HEAD
		menu(1, 5, "			BIBLIOTHEQUE\n#################################################################\n			  ACCUEIL\n1 : Afficher l'ensemble des livres de la bibilotheque\n2 : Ajouter un livre\n3 : Supprimer un livre\n4 : Recherche\n5 : Quitter", choix);
=======
		menu(1, 9, "|------------------------------------------------------------------|\n			BIBLIOTHEQUE			\n#################################################################\n			  ACCUEIL					\n1 : Afficher l'ensemble des livres de la bibilotheque\n2 : Ajouter un livre\n3 : Afficher l'ensemble des auteurs de la biblioteque\n4 : Supprimer un livre\n5 : Recherche\n6 : Emprunter un livre\n7 : Rendre un livre\n8 : Noter un livre\n9 : Quitter", choix);
>>>>>>> c73b6e66b450e006a5a86043cfbdcb9203db8dc1
		switch (choix) {
		case 1: affichelivres(mabib);
			system("pause");
			break;
		case 2: ajoutelivre(mabib, titre, nbnote);
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
		case 8: notelivre(mabib, nbnote);
			nbnote++;
			system("pause");
			break;
		case 9:
			break;
		}
		system("cls");
	} while (choix != 9);
	return 0;

}