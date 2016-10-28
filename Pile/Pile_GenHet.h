#ifndef PILE_GENHET_H_INCLUDED
#define PILE_GENHET_H_INCLUDED

#define true 1
#define false 0
typedef int bool;

typedef struct livre{
    char ID[20];
    char Auteur[30];
    char Titre[50];
    int NPage;
    int DateP[3];
}Livree;

typedef struct genre{
    int entier;
    char *mot;
    Livree *liv;

}Genre;

typedef struct element{
    void * donnee;
    struct element *suivant;
}Element;
 typedef struct pile{
    Element *tete;
    int taille;
 }Pile;

 Pile*    pile_vide();
 bool     est_vide(Pile *p);
 void*    sommet(Pile *p);
 void     empiler(Pile *p,void *i,Genre* (*fct)(void *));
 Pile*    depiler(Pile *p);
 Livree*  nouveau_livre(char *ID,char *Auteur,char *Titre,int NPage,int jour,int mois,int annee);
 Livree*  max_pages_livre(Pile *p);
 void     afficher(Pile *p);
 Genre*   entier(int e);
 Genre*   mot(char *c);
 Genre*   livre(Livree *l);

#endif // PILE_GENHET_H_INCLUDED
