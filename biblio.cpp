#include "biblio.h"
#include <iostream>
#include <string>
using namespace std;


void menu(int minchoix, int maxchoix, string menu, int& choix) {
		cout << menu<< endl;
		cout << "Choix : ";
		cin >> choix;
}


void affichelivre(t_livre monlivre, t_auteur monauteur)
{
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|titre : " << monlivre.titre << "                            |" << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|auteur : " << monauteur.nom << " "<< monauteur.prenom << " (" << monauteur.datedenaissance.jj <<"/" << monauteur.datedenaissance.mm << "/" << monauteur.datedenaissance.aa << ")" << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|style : " << monlivre.style << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|date de parrution : " << monlivre.datedeparution.jj << "/" << monlivre.datedeparution.mm << "/" << monlivre.datedeparution.aa << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|nombre de pages : " << monlivre.pages << "|" << endl;
	cout << "+------------------------------------------------------------+" << endl;
}
void vousaimerezaussi(t_biblio mabib, t_livre monlivre) {
	int y;
	//string stylelivre;
	// = mabib.listelivres[i].style;
	for (y = 0; y < mabib.nbelem; y++) {
		if (monlivre.style == mabib.listelivres[y].style) {
			affichelivre(mabib.listelivres[y], mabib.listeauteurs[y]);
			cout << "ca marche";
		}
	}
}

void affichelivres(t_biblio mabib) {
	if (mabib.nbelem != 0)
	{
		for (int i = 0; i < mabib.nbelem; i++) {
			affichelivre(mabib.listelivres[i], mabib.listeauteurs[i]);
		}
	}
	else
	{
		cout << "Il y a aucun livre dans la biblioteque";
	}
	
}

/*void affichelivresauteur(t_biblio mabib, t_livre monlivre) {
	int i;
	string auteur;
	for (i = 0; i < mabib.nbauteur;i++) {
		if (mabib.listeauteurs[i].nom == auteur) {
			affichelivre(mabib.listelivres[i], mabib.listeauteurs[i]);
		}
	}
}*/

void ajoutelivre(t_biblio& mabib, t_auteur& monauteur) {
	if (maxlivres == mabib.nbelem) {
		cout << "Impossible d'ajouter ce livre, la bibliotheque est pleine.";
	}
	else
	{
		cout << "Entrer le titre du livre : " ;
		cin.ignore();
		getline(cin, mabib.listelivres[mabib.nbelem].titre);
		//l'id de l'auteur
		cout << "Entrer le style du livre (horreur, romantique, comédie, scientifique, biographique) : ";
		cin >> mabib.listelivres[mabib.nbelem].style;
		cout << endl << "Entrer le nom de l'auteur : " ;
		cin >> mabib.listeauteurs[mabib.nbauteur].nom;
		cout  << "Entrer le prenom de l'auteur : " ;
		cin >> mabib.listeauteurs[mabib.nbauteur].prenom;
		cout << "Entrer le jour de naissance de l'auteur : ";
		cin >> mabib.listeauteurs[mabib.nbauteur].datedenaissance.jj;
		cout << "Entrer le mois de naissance de l'auteur : ";
		cin >> mabib.listeauteurs[mabib.nbauteur].datedenaissance.mm;
		cout << "Entrer l'annee de naissance de l'auteur : ";
		cin >> mabib.listeauteurs[mabib.nbauteur].datedenaissance.aa;
		cout << endl <<"Entrer la jour de parution : " ;
		cin >> mabib.listelivres[mabib.nbelem].datedeparution.jj;
		cout << "Entrer la mois de parution : ";
		cin >> mabib.listelivres[mabib.nbelem].datedeparution.mm;
		cout << "Entrer l annee de parution : ";
		cin >> mabib.listelivres[mabib.nbelem].datedeparution.aa;
		cout << "Entrer le nombre de pages : ";
		cin >> mabib.listelivres[mabib.nbelem].pages;
		mabib.nbelem = mabib.nbelem + 1;
		mabib.nbauteur = mabib.nbauteur + 1;
	}
}

int recherchelivre(t_biblio mabib) {
	if (mabib.nbelem != 0)
	{
		int pos = 0;
		string titrerecher;
		cout << "Entrer le titre du livre que vous rechercher : ";
		cin.ignore();
		getline(cin, titrerecher);
		bool trouve;
		trouve = false;
		while (trouve == false && mabib.nbelem > pos) {
			if (mabib.listelivres[pos].titre == titrerecher)
			{
				trouve = true;
				affichelivre(mabib.listelivres[pos], mabib.listeauteurs[pos]);

			}
			pos++;
		}
		return pos;
	}
	else
	{
		cout << "Il y a aucun livre dans la biblioteque " << endl;
	}
}

int rechercheauteur(t_biblio mabib) {
	if (mabib.nbelem != 0)
	{
		int pos = 0;
		string auteurrecherch;
		cout << "Entrer le titre du livre que vous rechercher : ";
		cin.ignore();
		getline(cin, auteurrecherch);
		bool trouve;
		trouve = false;
		while (trouve == false && mabib.nbauteur > pos) {
			if (mabib.listeauteurs[pos].nom == auteurrecherch)
			{
				trouve = true;
				affichelivre(mabib.listelivres[pos], mabib.listeauteurs[pos]);

			}
			pos++;
		}
		return pos;
	} 
	else
	{
		cout << "Il y a aucun livre dans la biblioteque " << endl;
	}
}
	
void recherche(t_biblio mabib) {
	int choix;
	menu(0, 3, "1 : Recherche par titre du livre\n2 : Rechercher par nom de l'auteur\n3 : Quitter", choix);
	switch (choix) {
	case 1: recherchelivre(mabib);
		break;
	case 2: rechercheauteur(mabib);
		break;
	case 3: break;
	}
	//vousaimerezaussi(mabib, mabib.listelivres[i]);
}

void sauvegarde(t_biblio& mabib)
{

}

void supprlivre(t_biblio& mabib) {
	char rep;
	string titre;
	int position = 0;
	//int recherchelivre(t_biblio mabib, string titrerecher);
	//void affichelivres(int nbelem, t_livre listelivres[maxlivres]);
	cin >> titre;
	//position = recherchelivre(mabib, titre); //A ECRIRE DANS LE MAIN APRES L'APPEL DE LA PROCEDURE (-d'apres ma correction du td avec ce bon vieux DD)
	affichelivre(mabib.listelivres[position], mabib.listeauteurs[position]);
	cout << "Supprimer (y/n) : " << endl;
	cin >> rep;
	if (rep == 'y') {
		mabib.listelivres[position] = mabib.listelivres[mabib.nbelem - 1];
		mabib.nbelem = mabib.nbelem - 1;
	}
}

void emprunterlivre(t_biblio& mabib) {

	cout << "voulez vous emprunter ce livre ?";
	//cin >> .etat;
}

