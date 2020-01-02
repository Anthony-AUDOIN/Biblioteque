#ifndef BIBLIO_H
#define BIBLIO_H

#include <iostream>
#include <string>
using namespace std;

const int maxlivres = 100;


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
<<<<<<< HEAD
	string nationalite;
=======
	t_date datedemort;
>>>>>>> c73b6e66b450e006a5a86043cfbdcb9203db8dc1
};

struct t_livre {
	string titre;
	t_auteur id;
	string style;
	int pages;
	string editeurlivre;
	t_date datedeparution;
	string editeurlivre;
	string etat;
	int note[maxlivres];
	int moynotes;
};

<<<<<<< HEAD
=======

>>>>>>> c73b6e66b450e006a5a86043cfbdcb9203db8dc1
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
int calculmoyennenotes(int nbnote, t_livre monlivre);
void affichelivre(t_livre monlivre, int nbnote);
void affichelivres(t_biblio mabib);
//void affichelivresauteur(t_biblio mabib, t_livre monlivre);
void ajoutelivre(t_biblio& mabib, string titre, int nbnote);
int recherchelivre(t_biblio mabib, string titre);
void supprlivre(t_biblio& mabib);
void recherche(t_biblio mabib);
<<<<<<< HEAD
void sauvegarde(t_biblio & mabib);
//void vousaimerezaussi(t_biblio, int i);
#endif 
=======
void emprunterlivre(t_biblio& mabib);
void rendrelivre(t_biblio& mabib);
void afficheauteur(t_auteur monauteur);
void afficheauteurs(t_biblio mabib);
void notelivre(t_biblio& mabib, int nbnote);
//void suggestion(t_biblio, int i);
//void sauvegarde(t_biblio& mabib);

#endif
>>>>>>> c73b6e66b450e006a5a86043cfbdcb9203db8dc1
