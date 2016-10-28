#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include "file.h"

File file_vide(){
    File F;
    F.debut=NULL;
    F.fin=NULL;
    F.taille=0;
    return F;
}
 bool est_vide(File F){
    if(F.taille==0)return true;
    return false;
 }
 File enfiler (File F,int i){
    Noeud *n;
    n= (Noeud*) malloc(sizeof(Noeud));
    n->val=i;
    if(est_vide(F)){
        F.debut=n;
    }
    else F.fin->suiv=n;
    n->prec=F.fin;
    n->suiv=NULL;
    F.fin=n;
    F.taille++;
    return F;
 }
void affichage(File F){
    printf("NULL<->");
    while(F.taille>0){
        printf("%d<->",F.debut->val);
        F.debut=F.debut->suiv;
        F.taille--; C
    }
    printf("NULL\n");
}
File defiler(File F){
    if(est_vide(F))return F;
    if(F.taille==1){
        free(F.debut);
        return file_vide();
    }
    F.debut=F.debut->suiv;
    free(F.debut->prec);
    F.debut->prec=NULL;
    F.taille--;
    return F;
}
int tete(File F){
    if(!est_vide(F)) return F.debut->val;
    return -1;
}

#endif // FONCTIONS_H_INCLUDED
