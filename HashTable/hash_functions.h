#ifndef HASH_FUNCTIONS_H_INCLUDED
#define HASH_FUNCTIONS_H_INCLUDED
#include "hash_ouvert_headers.h"

int hashage(Table_Hash *t,char* cle){
    int c=0;
    for(;*cle;cle++){
        c+=*cle;
    }
    printf("sssssssss");
    return c%t->taille;
}

Table_Hash* create_th(int taille){
    int i=0;
    Table_Hash *t=(Table_Hash*)malloc(sizeof(Table_Hash));
    t->taille=taille;
    t->tab_elm=(ele*)malloc(sizeof(Element)*taille );
    for(i;i<t->taille;i++){
        t->tab_elm[i]=NULL;
    }
    return t;
}
void inserer(Table_Hash* t,char*  cle,char* val){
    int i=0,h;
    ele nv_ele=(ele)malloc(sizeof(Element));
    nv_ele->cle=cle;
    nv_ele->val=val;
    h=hashage(t,cle);
    while(t->tab_elm[h]!=NULL && i<t->taille ){
        h=(h+1)%t->taille;
        i++;
    }
    if(i==t->taille){
        printf("Le tabelai est plein!\n");
        return;
    }
    t->tab_elm[h]=nv_ele;
}
void supprimer(Table_Hash* t,char* cle){
    int h=0,i=0;
    h=hashage(t,cle);
   while(t->tab_elm[h] && i<t->taille ){
        if(strcmp(t->tab_elm[h]->cle,cle)==0){
            t->tab_elm[h]=NULL;
            return;
        }
        h=(h+1)%t->taille;

        i++;
    }
    printf("on ne peux pas supprimer un elemnet non existant!\n");

}
bool recheche(Table_Hash* t,char* cle,char* val){
    int h=hashage(t,cle),i=0;

    while(t->tab_elm[h] && i<t->taille ){printf("illllll");
        if(strcmp(t->tab_elm[h]->cle,cle)==0 && strcmp(t->tab_elm[h]->val,val)==0){
            return true;
        }
        h=(h+1)%t->taille;

        i++;
    }
    return false;

}
void affich(Table_Hash *t){
    int i,k=0;
    printf("***********************\n");
    for(i=0;i<t->taille;i++){
        if(t->tab_elm[i]){
                k=1;
            printf("%s\n",t->tab_elm[i]->cle);
        }
    }
    if(k==0) printf("hadshi khawiiii \n");
    printf("***********************\n");
}



#endif // HASH_FUNCTIONS_H_INCLUDED
