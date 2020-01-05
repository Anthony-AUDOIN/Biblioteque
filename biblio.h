#ifndef BIBLIO_H
#define BIBLIO_H

#include <iostream>
#include <string>
using namespace std;

const int maxlivres = 100;
const int maxnotes = 10;

struct t_date {
	int jj;
	int mm;
	int aa;
};

struct t_auteur {
	int id;
	string nom;
	string prenom;
	string nationalite;
	t_date datedenaissance;
	t_date datedemort;
};

struct t_livre {
	string titre;
	t_auteur id;
	string style;
	int pages;
	string editeurlivre;
	t_date datedeparution;
	string etat;
	int tabnote[maxnotes];
	int note;
};


struct t_biblio {
	int nbauteur;
	int nbelem;
	t_livre listelivres[maxlivres];
	t_auteur listeauteurs[maxlivres];
};

void menu(int minchoix, int maxchoix, string menu, int& choix);
void affichelivre(t_livre monlivre);
void affichelivres(t_biblio mabib);
//void affichelivresauteur(t_biblio mabib, t_livre monlivre);
void ajoutelivre(t_biblio& mabib);
void ajouteauteur(t_biblio& mabib);
int recherchelivre(t_biblio mabib, string titre);
void supprlivre(t_biblio& mabib);
void recherche(t_biblio mabib);
void emprunterlivre(t_biblio& mabib);
void rendrelivre(t_biblio& mabib);
void afficheauteur(t_auteur monauteur);
void afficheauteurs(t_biblio mabib);
void notelivre(t_biblio& mabib, int& nbnote);
void locate(int x, int y);
//void suggestion(t_biblio, int i);
//void sauvegarde(t_biblio& mabib);

#endif
