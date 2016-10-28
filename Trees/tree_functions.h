#ifndef TREE_FUNCTIONS_H_INCLUDED
#define TREE_FUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

	Arbre_BR arbre_vide() {
		return NULL;
	}

	bool est_vide(Arbre_BR A) {
		return A == NULL ;
	}

	/*Noeud* nouveau_noeud(Element* e) {
		Noeud* p = (Noeud*) malloc(sizeof(Noeud));
		if (p != NULL) {
			 p->val = e;
			 p->fg = NULL;
			 p->fd = NULL;
		}
		return (p);
	}

	Arbre_BR cons(Noeud *r,Arbre_BR G,Arbre_BR D) {
		r->fg = G ;
		r->fd = D ;
		return r ;
	}*/

	Arbre_BR creer_arbre(Element *v,Arbre_BR fg,Arbre_BR fd){
    Arbre_BR ab=(Arbre_BR)malloc(sizeof(Noeud));
    ab->val=v;
    ab->fg=fg;
    ab->fd=fd;
    return ab;
}

	Noeud racine(Arbre_BR A) {
	// précondition : A est non vide !
		if (est_vide(A)) {
		 printf("Erreur : Arbre vide ! \n");
		 exit(-1);
		}
		return (*A) ;
	}

	Arbre_BR gauche(Arbre_BR A) {
	// précondition : A est non vide !
		if (est_vide(A)) {
			 printf("Erreur : Arbre vide ! \n");
			 exit(-1);
		}
		return A->fg ; /* ou bien (*A).fg; */
	}

	Arbre_BR droite(Arbre_BR A) {
	// précondition : A est non vide !
		if (est_vide(A)) {
		 printf("Erreur : Arbre vide ! \n");
		 exit(-1);
		}
		return A->fd ; /* ou bien (*A). fd; */
	}

	/*Element contenu(Noeud n) {
		return n->val ;
	}*/

	Element* new_valeur(char *c){
		Element *v;
		v=(Element*)malloc(sizeof(Element));
		v->mot=c;
		v->n_occurence=1;
		return v;
	}

	int compare(Element *v1, Element *v2){
    int i;
    char *chaine_un,*chaine_deux;
    chaine_un=v1->mot;
    chaine_deux=v2->mot;
    for(i=0; chaine_un[i] != '\0' || chaine_deux[i] != '\0'; i++){
        if (chaine_un[i] < chaine_deux[i])
           return -1;
        if (chaine_un[i] > chaine_deux[i])
           return 1;
    }
    return 0;
	}

	void incrementer(Element *v){
		v->n_occurence++;
	}

	/*bool recherche(Element x,Arbre_BR A){
		if(compare(contenu(x),contenu(A.val.mot))==0){
			recherche(x,arbre_vide())=false;
			return true;
		}
		if(contenu(x)<contenu(A.val)){
			recherche(x,A)=recherche(x,gauche(A));
		}
		if(contenu(x)>contenu(A.val)){
			recherche(x,A)=recherche(x,droite(A));
		}
		return false;
	}*/

	bool inserer(Element * x,Arbre_BR *A){
		if(est_vide(*A)==true){
			*A=creer_arbre(x,arbre_vide(),arbre_vide());
			return true;
		}
		if(compare(x,(*A)->val)==0){
			incrementer((*A)->val);
			return true;
		}
		if(compare(x,(A*)->val)==-1 && est_vide(A->fd)==true){
			A->fd=creer_arbre(x,arbre_vide(),arbre_vide());
			return true;
		}
		if(compare(x,(A*)->val)==-1 && est_vide(A->fg)==true){
			(A*)->fg=creer_arbre(x,arbre_vide(),arbre_vide());
			return true;
		}else if(compare(x,(A*)->val)==-1 ){
			return inserer(x,&((A*)->fd));
		}else{
			return inserer(x,&((A*)->fg));
		}

	}
	void aff_noeud(Arbre_BR A){
		if(est_vide(A)==true){
			printf("Arbre est vide !! \n");
		}else{
			printf("***************************\n");
			printf("*** Le mot : %s ***\n",A->val->mot);
			printf("*** Occured : %d***\n",A->val->n_occurence);
			printf("***************************\n");
		}
	}

	void aff_arb(Arbre_BR A){
		if(est_vide(A->fd)==true && est_vide(A->fg)==true)
			aff_noeud(A);
		else if(est_vide(A->fd)==true && est_vide(A->fg)==false){
			aff_arb(A->fd);
			aff_noeud(A);
		}
		else if(est_vide(A->fd)==false && est_vide(A->fg)==true){
			aff_arb(A->fg);
			aff_noeud(A);
		}
		else{
			aff_arb(A->fd);
			aff_noeud(A);
			aff_arb(A->fg);
		}
	}



#endif // TREE_FUNCTIONS_H_INCLUDED
