#ifndef BIBLIO_H
#define BIBLIO_H

#include <iostream>
#include <string>
using namespace std;

const int maxlivres = 10;

struct t_date {
	int jj;
	int mm;
	int aa;
};

struct t_auteur {
	int id;
	string nom;
	string prenom;
	t_date datedenaissance;
	string nationalite;
};

struct t_livre {
	string titre;
	t_auteur auteur;
	string style;
	int pages;
	t_date datedeparution;
	string editeurlivre;
	string etat;
};

struct t_biblio {
	int nbauteur;
	int nbelem;
	t_livre listelivres[maxlivres];
	t_auteur listeauteurs[maxlivres];
};

//type auteur = nom, annee, naiss, nationalite
//initialiser et desintialiser la biblio
// procedure affiche auteur

//////////////////////////////////////////////////////////////////


void menu(int minchoix, int maxchoix, string menu, int& choix);
void affichelivre(t_livre monlivre, t_auteur monauteur);
void affichelivres(t_biblio mabib);
//void affichelivresauteur(t_biblio mabib, t_livre monlivre);
void ajoutelivre(t_biblio& mabib, t_auteur& monauteur);
int recherchelivre(t_biblio mabib);
void supprlivre(t_biblio& mabib);
void recherche(t_biblio mabib);
void sauvegarde(t_biblio & mabib);
//void vousaimerezaussi(t_biblio, int i);
#endif 