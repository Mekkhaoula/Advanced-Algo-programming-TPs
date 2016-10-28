#include "Pile_GenHet.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

	Pile* pile_vide(){
        Pile *p;
        p=(Pile*)malloc(sizeof(Pile));
        p->tete=NULL;
        p->taille=0;
        return p;
	}

	bool est_vide(Pile *p){
        if(p->tete==NULL)
            return true;
        return false;
	}

	void* sommet(Pile *p){
        if(est_vide(p)==true)
            return NULL;
        else return p->tete->donnee;
	}

    void empiler(Pile *p,void *i,Genre* (*fct)(void *)){
        Element *nv_element;
        if((nv_element=(Element*)malloc(sizeof(Element)))==NULL)
            printf("Element non insere !\n");
        nv_element->donnee=fct(i);
        nv_element->suivant=p->tete;
        p->tete=nv_element;
        p->taille=p->taille+1;
    }

	Pile* depiler(Pile *p){
        Element *e;
        e=p->tete;
        p->tete=e->suivant;
        free(e->donnee);
        free(e);
        p->taille--;
        return p;
	}

	Livree* nv_livre(char *ID,char *Auteur, char *Titre, int NPage, int jour,int mois,int annee){
        Livree *NV_livre=NULL;
        if((NV_livre=(Livree*)malloc(sizeof(Livre)))==NULL)
            printf("Element non insere!\n");
        strcpy(NV_livre->ID,ID);
        strcpy(NV_livre->Auteur,Auteur);
        strcpy(NV_livre->Titre,Titre);
        NV_livre->NPage=NPage;
        NV_livre->DateP[0]=jour;
        NV_livre->DateP[1]=mois;
        NV_livre->DateP[2]=annee;
        return NV_livre;
	}

	void Afficher_livre(Livree *L){
    printf("  ----------------------------------------------------------------------------\n\n");
    printf("                  ID:    %s\n\n",L->ID);
    printf("               Titre:    %s\n\n",L->Titre);
    printf("              Auteur:    %s\n\n",L->Auteur);
    printf("     Numero de pages:    %i\n\n",L->NPage);
    printf("    Date de creation:    %i/%i/%i\n\n",L->DateP[0],L->DateP[1],L->DateP[2]);
    printf("  ----------------------------------------------------------------------------\n\n");
}
	void Afficher_int(int t){
    printf("%i\n",t);
}

    void Afficher_double(double t){
        printf("%f\n",t);
    }

    void Afficher_charactere(char *c){
        printf("%s\n",c);
    }
    void Afficher_element(Genre *G){
        if(G->entier!=NULL)
            Afficher_int(G->entier);
        if(G->mot!=NULL)
            Afficher_charactere(G->mot);
        if (G->liv!=NULL)
            Afficher_livre(G->liv);
    }

    void afficher(Pile *P){
        Element *E;
        E=P->tete;
        while(E!=NULL){
            Afficher_element(E->donnee);
            E=E->suivant;
        }
    }

    Genre * entier(int e){
        Genre *G;
        G=(Genre *)malloc(sizeof(Genre));
        G->entier=e;
        G->mot=NULL;
        G->liv=NULL;
        return G;
    }
Genre * charactere(char *c){
    Genre *G;
    G=(Genre *)malloc(sizeof(Genre));
    G->mot=c;
    G->entier=NULL;
    G->liv=NULL;
    return G;
}
Genre * livre(Livree *L){
    Genre *G;
    G=(Genre *)malloc(sizeof(Genre));
    G->liv=L;
    G->entier=NULL;
    G->mot=NULL;
    return G;
}




