#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#define true 1
#define false 0
typedef int bool;

	typedef struct Element{
		int n_occurence;
		char *mot;
	}Element;

	typedef struct noeud {
		Element *val;
		struct noeud *fg;
		struct noeud *fd;
	} Noeud;
	typedef Noeud *Arbre_BR;

	Arbre_BR arbre_vide();
	bool est_vide(Arbre_BR A);
	//Noeud* nouveau_noeud(Element* e);
	//Arbre_BR cons(Noeud *r,Arbre_BR G,Arbre_BR D);
	Arbre_BR creer_arbre(Element *v,Arbre_BR fg,Arbre_BR fd);
	Noeud racine(Arbre_BR A);
	Arbre_BR gauche(Arbre_BR A);
	Arbre_BR droite(Arbre_BR A);
	Element* new_valeur(char* c);
	int compare(Element *v1,Element *v2);
	void incrementer(Element *v);
//	bool recherche(Element e,Arbre_BR A);
	bool inserer(Element *x,Arbre_BR *A);
	void aff_noeud(Arbre_BR A);
	void aff_arb(Arbre_BR A);




#endif // TREE_H_INCLUDED
