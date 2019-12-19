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
	cout << "|titre : " << monlivre.titre << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|auteur : " << monauteur.nom << " "<< monauteur.prenom << " (" << monauteur.datedenaissance.jj <<"/" << monauteur.datedenaissance.mm << "/" << monauteur.datedenaissance.aa << ")" << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|style : " << monlivre.style << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|date de parrution : " << monlivre.datedeparution.jj << "/" << monlivre.datedeparution.mm << "/" << monlivre.datedeparution.aa << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|nombre de pages : " << monlivre.pages << "|" << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|note : " << monlivre.note << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|etat : " << monlivre.etat << endl;
	cout << "+------------------------------------------------------------+" << endl;
}

/*void vousaimerezaussi(t_biblio mabib, t_livre monlivre) {
	int y;
	//string stylelivre;
	// = mabib.listelivres[i].style;
	for (y = 0; y < mabib.nbelem; y++) {
		if (monlivre.style == mabib.listelivres[y].style) {
			affichelivre(mabib.listelivres[y], mabib.listeauteurs[y]);
			cout << "ca marche";
		}
	}
}*/

void affichelivres(t_biblio mabib) {

	if (mabib.nbelem != 0) {
		for (int i = 0; i < mabib.nbelem; i++) {
			cout << "############################"<<endl;
			cout << "############################" << endl;
			affichelivre(mabib.listelivres[i], mabib.listeauteurs[i]);
			cout << "############################" << endl;
			cout << "############################" << endl;

		}
	} else {
		cout << "Il n'y a aucun livre dans la biblioteque" << endl;
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

void ajoutelivre(t_biblio& mabib) {
	if (maxlivres == mabib.nbelem) {
		cout << "Impossible d'ajouter ce livre, la bibliotheque est pleine.";
	}
	else
	{
		mabib.listelivres[mabib.nbelem].etat = "disponible";
		mabib.listelivres[mabib.nbelem].note = 0;
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
	int pos = 0;
	string titre;
	cout << "Entrer le titre du livre que vous rechercher : ";
	cin.ignore();
	getline(cin, titre);
	bool trouve;
	trouve = false;
	while (trouve == false && mabib.nbelem > pos) {
		if (mabib.listelivres[pos].titre == titre)
		{
			trouve = true;
			affichelivre(mabib.listelivres[pos], mabib.listeauteurs[pos]);

		}
			pos++;
	}
	return pos;
}

int rechercheauteur(t_biblio mabib) {
		int pos = 0;
		string auteur;
		cout << "Entrer le titre du livre que vous rechercher : ";
		cin >> auteur;
		bool trouve;
		trouve = false;
		while (trouve == false && mabib.nbauteur > pos) {
			if (mabib.listeauteurs[pos].nom == auteur)
			{
				trouve = true;
				affichelivre(mabib.listelivres[pos], mabib.listeauteurs[pos]);

			}
			pos++;
		}
		return pos;
}
	
void recherche(t_biblio mabib) {
		if (mabib.nbelem == 0){
			cout << "Il n'y a aucun livre dans la biblioteque";
				}	
		else {
			int choix;
			menu(0, 3, "1 : Recherche par titre du livre\n2 : Rechercher par nom de l'auteur\n3 : Quitter", choix);
			switch (choix) {
			case 1: recherchelivre(mabib);
				break;
			case 2: rechercheauteur(mabib);
				break;
			case 3: break;
				system("cls");
			}
		}
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

	string livre, rep;
	cout << "Entrer le nom du livre que vous voulez emprunter : ";
	cin >> livre;
	for (int i = 0; i < mabib.nbelem; i++) {
		if (livre == mabib.listelivres[i].titre) {
			affichelivre(mabib.listelivres[i], mabib.listeauteurs[i]);
			cout << "voulez vous emprunter " << mabib.listelivres[i].titre << " ? (o/n) : ";
			cin >> rep;
			if (rep == "o" && mabib.listelivres[i].etat=="disponible") {
				mabib.listelivres[i].etat = "emprunte";
				cout << "Vous avez emprunte le livre : " << mabib.listelivres[i].titre;
			}
			else {
				if (rep == "o" && mabib.listelivres[i].etat != "disponible") {
					cout << "Ce livre n'est pas disponible.";
				}
			}
		}
		else {
			cout << "Ce livre n'existe pas dans la bibliotheque.";
		}
	}
	system("pause");
}

void rendrelivre(t_biblio& mabib) {
	string livre;
	cout << "Entrer le nom du livre que vous voulez rendre : ";
	cin >> livre;
	for (int i = 0; i < mabib.nbelem; i++) {
		if (livre == mabib.listelivres[i].titre) {
			if (mabib.listelivres[i].etat == "emprunte") {
				mabib.listelivres[i].etat = "disponible";
				cout << "Vous avez rendu le livre : " << mabib.listelivres[i].titre;
			}
			else {
				if (mabib.listelivres[i].etat != "emprunte") {
					cout << "Vous n'avez pas emprunte ce livre.";
				}
			}
		}
		else {
			cout << "Ce livre n'existe pas dans la bibliotheque.";
		}
	}
	system("pause");
}

void notelivre(t_biblio& mabib) {
	
	string livre;
	cout << "Entrer le titre du livre que vous souhaitez noter : ";
	cin >> livre;
	for (int i = 0; i < mabib.nbelem; i++) {
		if (livre == mabib.listelivres[i].titre) {
			cout << "Avez-vous appreci\202 " << mabib.listelivres[i].titre << ", faites le nous savoir en lui attribuant un note sur 5 : ";
			cin >> mabib.listelivres[i].note;
			cout << endl << "Merci pour votre avis !";
		}
		else {
			cout << "Ce livre n'existe pas dans la bibliotheque";
		}
	}
}




/*void ajoutelivre(t_biblio& mabib) {
	//string auteur;
	if (maxlivres == mabib.nbelem) {
		cout << "Impossible d'ajouter ce livre, la bibliotheque est pleine.";
	}
	else
	{
		mabib.listelivres[mabib.nbelem].etat = "disponible";
		cout << "Entrer le titre du livre : ";
		cin.ignore();
		getline(cin, mabib.listelivres[mabib.nbelem].titre);
		//l'id de l'auteur
		cout << "Entrer le style du livre (horreur, romantique, comédie, scientifique, biographique) : ";
		cin >> mabib.listelivres[mabib.nbelem].style;
		cout << "Entrer la jour de parution : ";
		cin >> mabib.listelivres[mabib.nbelem].datedeparution.jj;
		cout << "Entrer la mois de parution : ";
		cin >> mabib.listelivres[mabib.nbelem].datedeparution.mm;
		cout << "Entrer l annee de parution : ";
		cin >> mabib.listelivres[mabib.nbelem].datedeparution.aa;
		cout << "Entrer le nombre de pages : ";
		cin >> mabib.listelivres[mabib.nbelem].pages;

		int nbiteration = mabib.nbauteur; //on doit passer par une autre variable pour que le nombre d'itération reste fixe tout en pouvant incrementer le nombre d'auteur
		int w = mabib.nbelem;
		cout << endl << "Entrer le nom de l'auteur : ";
		cin >> mabib.listeauteurs[mabib.nbauteur].nom;
		for (int i = 0; i <= nbiteration;i++) {
			if (mabib.listeauteurs[i].nom == mabib.listeauteurs[mabib.nbauteur].nom) {
				mabib.listeauteurs[mabib.nbauteur].nom = mabib.listeauteurs[i].nom;
				mabib.listeauteurs[mabib.nbauteur].prenom = mabib.listeauteurs[i].prenom;
				mabib.listeauteurs[mabib.nbauteur].datedenaissance.jj = mabib.listeauteurs[i].datedenaissance.jj;
				mabib.listeauteurs[mabib.nbauteur].datedenaissance.mm = mabib.listeauteurs[i].datedenaissance.mm;
				mabib.listeauteurs[mabib.nbauteur].datedenaissance.aa = mabib.listeauteurs[i].datedenaissance.aa;

				mabib.nbelem = mabib.nbelem + 1;
			}
		}
		if (w == mabib.nbelem) {
			cout << "Entrer le prenom de l'auteur : ";
			cin >> mabib.listeauteurs[mabib.nbauteur].prenom;
			cout << "Entrer le jour de naissance de l'auteur : ";
			cin >> mabib.listeauteurs[mabib.nbauteur].datedenaissance.jj;
			cout << "Entrer le mois de naissance de l'auteur : ";
			cin >> mabib.listeauteurs[mabib.nbauteur].datedenaissance.mm;
			cout << "Entrer l'annee de naissance de l'auteur : ";
			cin >> mabib.listeauteurs[mabib.nbauteur].datedenaissance.aa;

			mabib.nbauteur = mabib.nbauteur + 1;
			mabib.nbelem = mabib.nbelem + 1;
		}
	}
}*/