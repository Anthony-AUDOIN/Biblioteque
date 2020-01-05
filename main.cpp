#include "biblio.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	//system("color F0");
	int nbnote = 0;
	string titre, nom;
	t_auteur monauteur;
	t_biblio mabib;
	t_livre monlivre;
	mabib.nbelem = 0;
	mabib.nbauteur = 0;
	//int choix;

	//const int RIGHT = 0x4d;
	//const int LEFT = 0x4b;
	const int UP = 0x48;
	const int DOWN = 0x50;
	const int ENTER = 0xd;
	int CursorY = 4;
	int bouton;

	void locate(int x, int y);

	/*do {
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
	} while (choix != 9);*/


	do {
		cout << "\t\t\t_________________________________________________________________" << endl;
		cout << "\t\t\t|\t\t\t\tMenu\t\t\t\t|" << endl;
		cout << "\t\t\t|_______________________________________________________________|" << endl;
		cout << "\t\t\t|\t\t\t\t\t\t\t\t|" << endl;
		cout << "\t\t\t|   Rechercher\t\t\t\t\t\t\t|" << endl;
		cout << "\t\t\t|   Afficher les livres\t\t\t\t\t\t|" << endl;
		cout << "\t\t\t|   Afficher les auteurs\t\t\t\t\t|" << endl;
		cout << "\t\t\t|   Ajouter un livre\t\t\t\t\t\t|" << endl;
		cout << "\t\t\t|   Ajouter un auteur\t\t\t\t\t\t|" << endl;
		cout << "\t\t\t|   Supprimer un livre\t\t\t\t\t\t|" << endl;
		cout << "\t\t\t|   Emprunter un livre\t\t\t\t\t\t|" << endl;
		cout << "\t\t\t|   Rendre un livre\t\t\t\t\t\t|" << endl;
		cout << "\t\t\t|   Noter un livre\t\t\t\t\t\t|" << endl;
		cout << "\t\t\t|   Quitter\t\t\t\t\t\t\t|" << endl;
		cout << "\t\t\t|_______________________________________________________________|" << endl;

		do {
			locate(25, CursorY);
			cout << "->";
			bouton = _getch();
			switch (bouton) {
			case UP:
				if (CursorY > 4) {
					locate(25, CursorY);
					cout << "  ";
					CursorY--;
				}
				break;
			case DOWN:
				CursorY;
				if (CursorY < 13) {
					locate(25, CursorY);
					cout << "  ";
					CursorY++;
				}
				break;
			default:
				break;
			}
		} while (bouton != ENTER);

		switch (CursorY) {
		case 4:
			system("cls");
			recherche(mabib);
			system("pause");
			break;
		case 5:
			system("cls");
			affichelivres(mabib);
			system("pause");
			break;
		case 6:
			system("cls");
			afficheauteurs(mabib);
			system("pause");
			break;
		case 7:
			system("cls");
			ajoutelivre(mabib);
			system("pause");
			break;
		case 8:
			system("cls");
			ajouteauteur(mabib);
			system("pause");
			break;
		case 9:		
			system("cls");
			supprlivre(mabib);
			system("pause");
			break;
		case 10:
			system("cls");
			emprunterlivre(mabib);
			system("pause");
			break;
		case 11:
			system("cls");
			rendrelivre(mabib);
			system("pause");
			break;
		case 12:
			system("cls");
			notelivre(mabib, nbnote);
			system("pause");
			break;
		case 13:
			break;
		default:
			break;
		}
		system("cls");
	} while (CursorY != 13);
	


	return 0;

}