#include "biblio.h"
#include <iostream>
#include <string>
using namespace std;


int nbnote;
void menu(int minchoix, int maxchoix, string menu, int& choix) {
	cout << menu << endl;
	cout << "Choix : ";
	cin >> choix;
}

int calculmoyennenotes(int nbnote, t_livre monlivre) {
	int somme = 0;
	float moyenne;
	for (int i = 0; i < nbnote;i++) {
		somme = somme + monlivre.note[i];
	}
	moyenne = float(somme) / float(nbnote);
	return moyenne;
}

void afficheauteur(t_auteur monauteur) {
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|auteur : " << monauteur.nom << " " << monauteur.prenom << " (" << monauteur.datedenaissance.jj << "/" << monauteur.datedenaissance.mm << "/" << monauteur.datedenaissance.aa << ")" << endl;
	cout << "+------------------------------------------------------------+" << endl;
}

void affichelivre(t_livre monlivre, int nbnote)
{
	int note;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|titre : " << monlivre.titre << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|style : " << monlivre.style << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|date de parrution : " << monlivre.datedeparution.jj << "/" << monlivre.datedeparution.mm << "/" << monlivre.datedeparution.aa << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|nombre de pages : " << monlivre.pages << endl;
	cout << "+------------------------------------------------------------+" << endl;
	note = calculmoyennenotes(nbnote, monlivre);
	cout << "|note : " << note << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|etat : " << monlivre.etat << endl;
	cout << "+------------------------------------------------------------+" << endl;
}

void affichelivres(t_biblio mabib) {

	if (mabib.nbelem != 0) {
		for (int i = 0; i < mabib.nbelem; i++) {
			cout << "############################" << endl;
			affichelivre(mabib.listelivres[i],nbnote);
			cout << "############################" << endl;
		}
	}
	else {
		cout << "Il n'y a aucun livre dans la biblioteque" << endl;
	}
}

void ajouteauteur(t_biblio& mabib, string nom) {

	if (maxlivres == mabib.nbauteur) {
		cout << "Impossible d'ajouter cet auteur, la bibliotheque est pleine.";
	}
	else
	{
		mabib.listeauteurs[mabib.nbauteur].nom=nom;
		cout << "Entrer le prenom de l'auteur : ";
		cin >> mabib.listeauteurs[mabib.nbauteur].prenom;
		cout << "Entrer le jour de naissance de l'auteur : ";
		cin >> mabib.listeauteurs[mabib.nbauteur].datedenaissance.jj;
		cout << "Entrer le mois de naissance de l'auteur : ";
		cin >> mabib.listeauteurs[mabib.nbauteur].datedenaissance.mm;
		cout << "Entrer l'annee de naissance de l'auteur : ";
		cin >> mabib.listeauteurs[mabib.nbauteur].datedenaissance.aa;
	}
	mabib.nbauteur = mabib.nbauteur + 1;
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

int rechercheauteur(t_biblio mabib, string nom) {
	int pos = 0;
	bool trouve=false;
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

void ajoutelivre(t_biblio& mabib, string titre, int nbnote) {
	string doexist = "non";
	if (maxlivres == mabib.nbelem) {
		cout << "Impossible d'ajouter ce livre, la bibliotheque est pleine.";
	}
	else
	{
		cout << "Entrer le titre du livre : ";
		cin.ignore();
		getline(cin, titre);
		for (int i = 0; i < mabib.nbelem; i++) {
			if (mabib.listelivres[i].titre == titre) {
				doexist = "oui";
				cout << "Ce livre existe deja dans la bibliotheque"<< endl;
			}
		}
		if (doexist=="non"){
			mabib.listelivres[mabib.nbelem].titre = titre;
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
			mabib.listelivres[mabib.nbelem].etat = "disponible";
			mabib.listelivres[mabib.nbelem].note[nbnote] = 0;

			string nom;
			cout << endl << "Entrer le nom de l'auteur : ";
			cin >> nom;
			int resrech = rechercheauteur(mabib, nom);
			if (resrech == -1) {
				ajouteauteur(mabib, nom);
				resrech = mabib.nbauteur - 1;
			}
			else
			{
				cout << "auteur trouve."<<endl;
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
	if (mabib.nbelem != 0) {
		for (int i = 0; i < mabib.nbauteur; i++) {
			cout << "############################" << endl;
			afficheauteur(mabib.listeauteurs[i]);
			cout << "############################" << endl;
		}
	}
	else {
		cout << "Il n'y a aucun auteur dans la biblioteque" << endl;
	}
}


int recherchelivre(t_biblio mabib, string titre) {
	int pos = 0;
	bool trouve=false;
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

void suggestion(t_biblio mabib, string titre) {
	int i, y;
	cout << endl << "Ces livres pourraient vous interesser : " << endl;
	for (i = 0; i < mabib.nbelem; i++) {
		if (mabib.listelivres[i].titre==titre) {
			for (y = 0; y < mabib.nbelem; y++) {
				if (mabib.listelivres[i].style == mabib.listelivres[y].style && i!=y) {
					affichelivre(mabib.listelivres[y], nbnote);
				}
			}
		}
	}
}

void recherche(t_biblio mabib) {
	string titre;
	string nom;
	if (mabib.nbelem == 0) {
		cout << "Il n'y a aucun livre dans la biblioteque";
	}
	else {
		int choix;
		menu(0, 3, "1 : Recherche par titre du livre\n2 : Rechercher par nom de l'auteur\n3 : Quitter", choix);
		switch (choix) {
		case 1: 
			cout << "Entrer le titre du livre du livre que vous recherchez : ";
			cin.ignore();
			getline(cin, titre);
			affichelivre(mabib.listelivres[recherchelivre(mabib, titre)], nbnote);
			suggestion(mabib, titre);
			break;
		case 2:
			cout << "Entrer le nom de l'auteur que vous recherchez : ";
			cin >> nom;
			for (int i = 0; i < mabib.nbauteur ;i++) {
				if (mabib.listeauteurs[i].nom == nom) {
					for (int y = 0; y < mabib.nbelem; y++) {
						if (mabib.listeauteurs[i].id == mabib.listeauteurs[y].id)
							affichelivre(mabib.listelivres[y], nbnote);
					}
				}
			}
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
	if (mabib.nbelem == 0) {
		cout << "la bibliotheque est vide." << endl;
	}
	else {
		cout << "Entrer le titre du livre que vous souhaitez supprimer : ";
		cin >> titre;
		affichelivre(mabib.listelivres[position],nbnote);
		cout << "Supprimer ? (o/n) : ";
		cin >> rep;
		if (rep == 'o') {
			mabib.listelivres[position] = mabib.listelivres[mabib.nbelem - 1];
			mabib.nbelem = mabib.nbelem - 1;
			cout << "Ce livre a bien été suprimé" << endl;
		}
	}
}

void emprunterlivre(t_biblio& mabib) {

	string livre, rep;
	string doexist = "non";
	cout << "Entrer le nom du livre que vous voulez emprunter : ";
	cin >> livre;
	for (int i = 0; i < mabib.nbelem; i++) {
		if (livre == mabib.listelivres[i].titre) {
			doexist = 'oui';
			affichelivre(mabib.listelivres[i],nbnote);
			cout << "voulez vous emprunter " << mabib.listelivres[i].titre << " ? (o/n) : ";
			cin >> rep;
			if (rep == "o" && mabib.listelivres[i].etat == "disponible") {
				mabib.listelivres[i].etat = "emprunte";
				cout << "Vous avez emprunte le livre : " << mabib.listelivres[i].titre << endl;
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
	system("pause");
}

void rendrelivre(t_biblio& mabib) {
	string livre;
	string doexist = "non";
	cout << "Entrer le nom du livre que vous voulez rendre : ";
	cin >> livre;
	for (int i = 0; i < mabib.nbelem; i++) {
		if (livre == mabib.listelivres[i].titre) {
			doexist = "oui";
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
	}
	if (doexist == "non") {
		cout << "Ce livre n'existe pas dans la bibliotheque.";
	}
	system("pause");
}

void notelivre(t_biblio& mabib, int nbnote) {
	string doexist = "non";
	string livre;
	cout << "Entrer le titre du livre que vous souhaitez noter : ";
	cin >> livre;
	for (int i = 0; i < mabib.nbelem; i++) {
		if (livre == mabib.listelivres[i].titre) {
			doexist = "oui";
			cout << "Avez-vous appreci\202 " << mabib.listelivres[i].titre << " ? Faites le nous savoir en lui attribuant un note entre 1 et 5 : ";
			cin >> mabib.listelivres[i].note[nbnote];
			cout << endl << "Merci pour votre avis !" << endl;
		}
	}
	if (doexist == "non") {
		cout << "Ce livre n'existe pas dans la bibliotheque.";
	}
}

void classementlivre(t_biblio mabib) {
	//a faire des que la moyenne des notes est ok

}