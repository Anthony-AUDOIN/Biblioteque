#include "biblio.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

void menu(int minchoix, int maxchoix, string menu, int& choix) {
	cout << menu << endl;
	cout << "Choix : ";
	cin >> choix;
}

void affichelivre(t_livre monlivre)
{
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << " TITRE : " << monlivre.titre << " | STYLE : " << monlivre.style << " | DATE DE PARUTION : " << monlivre.datedeparution.jj << "/" << monlivre.datedeparution.mm << "/" << monlivre.datedeparution.aa << endl << " NOMBRE DE PAGES: " << monlivre.pages << " | NOTE : " << monlivre.note << " | ETAT : " << monlivre.etat << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl << endl;
}

void afficheauteur(t_auteur monauteur) {
	if(monauteur.mort == true) {
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|auteur : " << monauteur.nom << " " << monauteur.prenom << " (" << monauteur.datedenaissance.jj << "/" << monauteur.datedenaissance.mm << "/" << monauteur.datedenaissance.aa << "-" << monauteur.datedemort.jj << "/" << monauteur.datedemort.mm << "/" << monauteur.datedemort.aa << ")  " << monauteur.nationalite << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl << endl;

	}
	else {
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|auteur : " << monauteur.nom << " " << monauteur.prenom << " (" << monauteur.datedenaissance.jj << "/" << monauteur.datedenaissance.mm << "/" << monauteur.datedenaissance.aa << ")  " << monauteur.nationalite << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl << endl;
	}
}

void affichelivres(t_biblio mabib) {
	cout << endl;
	cout << "#######################################################################################################################" << endl;
	cout << "#############################################   TOUS NOS LIVRES   #####################################################" << endl;
	cout << "#######################################################################################################################" << endl << endl << endl;
	if (mabib.nbelem != 0) {
		for (int i = 0; i < mabib.nbelem; i++) {
			affichelivre(mabib.listelivres[i]);
		}
	}
	else {
		cout << "Il n'y a aucun livre dans la biblioteque" << endl;
	}
}

bool VerifDate(int jour, int mois, int annee)
{	
	bool valide;
	int cas;
	cas = 0;
	if (mois == 2) cas = 3;
	if (mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 || mois == 12)cas = 2;
	if (mois == 4 || mois == 6 || mois == 9 || mois == 11) cas = 1;

	switch (cas)
	{
	case 1: if (jour < 1 || jour >30)
	{
		valide = false;
	}
		  break;
	case 2:if ((mois == 12) && (jour == 31)) {
		jour = 1;
		mois = 1;
		annee = annee + 1;
	}
		  else {
		valide = true;
	}

		  break;
	case 3: if (annee % 4 == 0 && (annee % 100 != 0 || annee % 400 == 0) && jour <= 29)
	{
		valide = true;
	}
		  else
	{
		if (jour > 28)
		{
			valide = false;
		}
		else
		{
			valide = true;
		}
	}
		  break;
	default: valide = false;
		break;
	}
	return valide;
}

void ajouteauteur(t_biblio& mabib) {
	string nom, rep;
	string doexist = "non";
	bool correct;

	cout << endl;
	cout << "#######################################################################################################################" << endl;
	cout << "#############################################   AJOUT D'AUTEUR  #######################################################" << endl;
	cout << "#######################################################################################################################" << endl << endl << endl;

	if (maxlivres == mabib.nbauteur) {
		cout << "Impossible d'ajouter cet auteur, la bibliotheque est pleine.";
	}
	else
	{
		cout << "Entrer le nom de l'auteur : ";
		cin >> nom;
		for (int i = 0; i < mabib.nbauteur; i++) {
			if (mabib.listelivres[i].titre == nom) {
				doexist = "oui";
				cout << "Cet auteur existe deja dans la bibliotheque" << endl;
			}
		}
		if (doexist == "non") {
			mabib.listeauteurs[mabib.nbauteur].nom = nom;
			cout << "Entrer le prenom de l'auteur : ";
			cin >> mabib.listeauteurs[mabib.nbauteur].prenom;
			do {
				cout << "Entrer le jour, le mois, et l'annee de naissance de l'auteur : ";
				cin >> mabib.listeauteurs[mabib.nbauteur].datedenaissance.jj >> mabib.listeauteurs[mabib.nbauteur].datedenaissance.mm >> mabib.listeauteurs[mabib.nbauteur].datedenaissance.aa;
				correct = VerifDate(mabib.listeauteurs[mabib.nbauteur].datedenaissance.jj, mabib.listeauteurs[mabib.nbauteur].datedenaissance.mm, mabib.listeauteurs[mabib.nbauteur].datedenaissance.aa);
				if (correct == false) {
					cout << "Veuillez entrer une date correcte" << endl;
				}
			} while (correct == false);
			cout << "Votre auteur est-il/elle toujours en vie ? (o/n) : ";
			cin >> rep;
			if (rep == "n") {
				cout << "Entrer la date de mort de l'auteur : ";
				cin >> mabib.listeauteurs[mabib.nbauteur].datedemort.jj >> mabib.listeauteurs[mabib.nbauteur].datedemort.mm >> mabib.listeauteurs[mabib.nbauteur].datedemort.aa;
				mabib.listeauteurs[mabib.nbauteur].mort = true;
			}
			else {
				mabib.listeauteurs[mabib.nbauteur].mort = false;
			}
			cout << "Entrer la nationalite de l'auteur : ";
			cin >> mabib.listeauteurs[mabib.nbauteur].nationalite;
		}

	}
	mabib.nbauteur = mabib.nbauteur + 1;
}

void affichelivresauteur(t_biblio mabib) {
	string nom;
	cout << "Entrer le nom de l'auteur que vous recherchez : ";
	cin >> nom;
	for (int i = 0; i < mabib.nbauteur; i++) {
		if (mabib.listeauteurs[i].nom == nom) {
			for (int y = 0; y < mabib.nbelem; y++) {
				if (mabib.listeauteurs[i].nom == mabib.listeauteurs[y].nom)
				{
					affichelivre(mabib.listelivres[y]);
				}
			}
		}
	}
}

int rechercheauteur(t_biblio mabib, string nom) {
	int pos = 0;
	bool trouve = false;
	while (trouve == false && mabib.nbauteur > pos) {
		if (mabib.listeauteurs[pos].nom == nom)
		{
			trouve = true;
		}
		else
		{
			pos++;
		}
	}
	if (trouve == true) {
		return pos;
	}
	else
	{
		return -1;
	}
}

void ajoutelivre(t_biblio& mabib) {
	string doexist = "non";
	string titre;
	bool correct;

	cout << endl;
	cout << "#######################################################################################################################" << endl;
	cout << "#############################################   AJOUT DE LIVRE   ######################################################" << endl;
	cout << "#######################################################################################################################" << endl << endl << endl;

	if (maxlivres == mabib.nbelem) {
		cout << "Impossible d'ajouter ce livre, la bibliotheque est pleine.";
	}
	else
	{
		cout << "Entrer le titre du livre : ";
		//cin.ignore();
		//getline(cin, titre);
		cin >> titre;
		for (int i = 0; i < mabib.nbelem; i++) {
			if (mabib.listelivres[i].titre == titre) {
				doexist = "oui";
				cout << "Ce livre existe deja dans la bibliotheque" << endl;
			}
		}
		if (doexist == "non") {
			mabib.listelivres[mabib.nbelem].titre = titre;
			//l'id de l'auteur
			cout << "Entrer le style litt\202raire du livre (aventure, romantique, scientifique, biographique, etc ...) : ";
			cin >> mabib.listelivres[mabib.nbelem].style;
			do {
				cout << "Entrer le jour, le mois, et l'annee de parution : ";
				cin >> mabib.listelivres[mabib.nbelem].datedeparution.jj >> mabib.listelivres[mabib.nbelem].datedeparution.mm >> mabib.listelivres[mabib.nbelem].datedeparution.aa;
				correct = VerifDate(mabib.listelivres[mabib.nbelem].datedeparution.jj, mabib.listelivres[mabib.nbelem].datedeparution.mm, mabib.listelivres[mabib.nbelem].datedeparution.aa);
				if (correct == false) {
					cout << "Veuillez entrer une date correcte" << endl;
				}
			} while (correct == false);
			cout << "Entrer le nombre de pages : ";
			cin >> mabib.listelivres[mabib.nbelem].pages;
			mabib.listelivres[mabib.nbelem].etat = "disponible";
			mabib.listelivres[mabib.nbelem].note = 0;

			string nom;
			cout << endl << "Entrer le nom de l'auteur : ";
			cin >> nom;
			int resrech = rechercheauteur(mabib, nom);
			if (resrech == -1) {
				cout << "Cet auteur n'est pas encore enregistr\202 dans la bibliotheque, veuillez entrer ses informations." << endl;
				ajouteauteur(mabib);
				//resrech = mabib.nbauteur - 1;
			}
			else
			{
				cout << "auteur trouve." << endl;
				mabib.listeauteurs[mabib.nbauteur].nom = mabib.listeauteurs[resrech].nom;
				mabib.listeauteurs[mabib.nbauteur].prenom = mabib.listeauteurs[resrech].prenom;
				mabib.listeauteurs[mabib.nbauteur].datedenaissance.jj = mabib.listeauteurs[resrech].datedenaissance.jj;
				mabib.listeauteurs[mabib.nbauteur].datedenaissance.mm = mabib.listeauteurs[resrech].datedenaissance.mm;
				mabib.listeauteurs[mabib.nbauteur].datedenaissance.aa = mabib.listeauteurs[resrech].datedenaissance.aa;
			}
			mabib.nbelem = mabib.nbelem + 1;
		}
	}
}

void afficheauteurs(t_biblio mabib) {
	cout << endl;
	cout << "#######################################################################################################################" << endl;
	cout << "#############################################   TOUS NOS AUTEURS   ####################################################" << endl;
	cout << "#######################################################################################################################" << endl << endl << endl;

	if (mabib.nbauteur != 0) {
		for (int i = 0; i < mabib.nbauteur; i++) {
			afficheauteur(mabib.listeauteurs[i]);
		}
	}
	else {
		cout << "Il n'y a aucun auteur dans la biblioteque" << endl;
	}
}

int recherchelivre(t_biblio mabib, string titre) {
	int pos = 0;
	bool trouve = false;
	while (trouve == false && mabib.nbelem > pos) {
		if (mabib.listelivres[pos].titre == titre)
		{
			trouve = true;
		}
		else
		{
			pos++;
		}
	}
	if (trouve == false) {
		cout << "Aucun resultat" << endl;
	}
	return pos;
}

void recherchestyle(t_biblio mabib, string style) {
	bool trouve = false;
	for (int i = 0; i < mabib.nbelem; i++) {
		if (mabib.listelivres[i].style == style) {
			affichelivre(mabib.listelivres[i]);
		}
	}
	if (trouve == false) {
		cout << "Aucun resultat" << endl;
	}
}

void suggestion(t_biblio mabib, string titre) {
	int i, y;
	for (i = 0; i < mabib.nbelem; i++) {
		if (mabib.listelivres[i].titre == titre) {
			for (y = 0; y < mabib.nbelem; y++) {
				if (mabib.listelivres[i].style == mabib.listelivres[y].style && i != y) {
					cout << endl << "Ces livres pourraient vous interesser : " << endl;
					affichelivre(mabib.listelivres[y]);
				}
			}
		}
	}
}

void recherche(t_biblio mabib) {
	string titre, nom, style;

	cout << endl;
	cout << "#######################################################################################################################" << endl;
	cout << "################################################   RECHERCHE   ########################################################" << endl;
	cout << "#######################################################################################################################" << endl << endl << endl;

	if (mabib.nbelem == 0) {
		cout << "Il n'y a aucun livre dans la biblioteque" << endl;
	}
	else {
		int choix;
		menu(0, 4, "1 : Recherche par titre du livre\n2 : Rechercher par nom de l'auteur\n3 : Recherche par genre\n4 : Quitter", choix);
		switch (choix) {
		case 1:
			cout << "Entrer le titre du livre du livre que vous recherchez : ";
			cin.ignore();
			getline(cin, titre);
			affichelivre(mabib.listelivres[recherchelivre(mabib, titre)]);
			suggestion(mabib, titre);
			break;
		case 2:
			affichelivresauteur(mabib);
			break;
		case 3:
			cout << "Entrer le style litt\202raire que vous recherchez : ";
			cin >> style;
			recherchestyle(mabib, style);
			break;
		case 4: break;
			system("cls");
		}
	}
}

void supprlivre(t_biblio& mabib) {
	char rep;
	string titre;
	int position = 0;

	cout << endl;
	cout << "#######################################################################################################################" << endl;
	cout << "###############################################   SUPPRESSION   #######################################################" << endl;
	cout << "#######################################################################################################################" << endl << endl << endl;

	if (mabib.nbelem == 0) {
		cout << "la bibliotheque est vide." << endl;
	}
	else {
		cout << "Entrer le titre du livre que vous souhaitez supprimer : ";
		cin >> titre;
		for (int i = 0; i < mabib.nbelem; i++) {
			if (titre == mabib.listelivres[i].titre) {
				affichelivre(mabib.listelivres[i]);
			}

			cout << "Supprimer ? (o/n) : ";
			cin >> rep;
			if (rep == 'o') {
				mabib.listelivres[i] = mabib.listelivres[mabib.nbelem - 1];
				mabib.nbelem = mabib.nbelem - 1;
				cout << "Ce livre a bien \202t\202 suprim\202" << endl;
			}
		}
	}
}

void emprunterlivre(t_biblio& mabib) {

	string livre, rep;
	string doexist = "non";

	cout << endl;
	cout << "#######################################################################################################################" << endl;
	cout << "#################################################   EMPRUNT   #########################################################" << endl;
	cout << "#######################################################################################################################" << endl << endl << endl;

	cout << "Entrer le nom du livre que vous voulez emprunter : ";
	cin >> livre;
	for (int i = 0; i < mabib.nbelem; i++) {
		if (livre == mabib.listelivres[i].titre) {
			doexist = 'oui';
			affichelivre(mabib.listelivres[i]);
			cout << "voulez vous emprunter " << mabib.listelivres[i].titre << " ? (o/n) : ";
			cin >> rep;
			if (rep == "o" && mabib.listelivres[i].etat == "disponible") {
				mabib.listelivres[i].etat = "emprunt\202";
				cout << "Vous avez emprunt\202 le livre : " << mabib.listelivres[i].titre << endl;
			}
			else {
				if (rep == "o" && mabib.listelivres[i].etat != "disponible") {
					cout << "Ce livre n'est pas disponible.";
				}
			}
		}
	}
	if (doexist == "non") {
		cout << "Ce livre n'existe pas dans la bibliotheque.";
	}
}

void rendrelivre(t_biblio& mabib) {
	string livre;
	string doexist = "non";

	cout << endl;
	cout << "#######################################################################################################################" << endl;
	cout << "#################################################   RETOUR   ##########################################################" << endl;
	cout << "#######################################################################################################################" << endl << endl << endl;

	cout << "Entrer le nom du livre que vous voulez rendre : ";
	cin >> livre;
	for (int i = 0; i < mabib.nbelem; i++) {
		if (livre == mabib.listelivres[i].titre) {
			doexist = "oui";
			if (mabib.listelivres[i].etat == "emprunt\202") {
				mabib.listelivres[i].etat = "disponible";
				cout << "Vous avez rendu le livre : " << mabib.listelivres[i].titre << endl;
			}
			else {
				if (mabib.listelivres[i].etat != "emprunte") {
					cout << "Vous n'avez pas emprunt\202 ce livre.";
				}
			}
		}
	}
	if (doexist == "non") {
		cout << "Ce livre n'existe pas dans la bibliotheque.";
	}
}

void notelivre(t_biblio& mabib, int& nbnote) {
	string doexist = "non";
	string livre;
	int somme = 0;


	cout << endl;
	cout << "#######################################################################################################################" << endl;
	cout << "################################################   NOTATION   #########################################################" << endl;
	cout << "#######################################################################################################################" << endl << endl << endl;

	cout << "Entrer le titre du livre que vous souhaitez noter : ";
	cin >> livre;
	for (int i = 0; i < mabib.nbelem; i++) {
		if (livre == mabib.listelivres[i].titre) {
			doexist = "oui";
			cout << "Avez-vous appreci\202 " << mabib.listelivres[i].titre << " ? Faites le nous savoir en lui attribuant un note entre 1 et 5 : ";
			cin >> mabib.listelivres[i].tabnote[nbnote];
			nbnote++;
			cout << endl << "Merci pour votre avis !" << endl;

			for (int y = 0; y < nbnote; y++) {
				somme = somme + mabib.listelivres[i].tabnote[y];
			}
			mabib.listelivres[i].note = float(somme) / float(nbnote);

		}
	}
	if (doexist == "non") {
		cout << "Ce livre n'existe pas dans la bibliotheque.";
	}
}

/*void classementlivre(t_biblio mabib) {
	int notemax;

	for (int i = 0; i < mabib.nbelem; i++) {
		notemax=mabib.listelivres[i]
		if (mabib.listelivres[i + 1].note > mabib.listelivres[i].note) {
			notemax = mabib.listelivres[i + 1].note;
		}
		for (int y = 0;y < mabib.nbelem;y++) {
			if (mabib.listelivres[y].note == notemax) {
				affichelivre(mabib.listelivres[y]);
			}
		}
	}

}*/



void locate(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;

	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}