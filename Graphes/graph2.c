#include<stdio.h>
#include<conio.h>
#include "graph2.h"

Liste liste_vide(){
     return NULL;
}
int existeDansListe(int sommet,Liste l){
   while(l){
    if(l->sommet==sommet)
      return 1;
    l=l->suivant;

   }
    return 0;
}
Liste ajouterListe(int sommet,Liste l){
                   int a=0;
    if(sommet==-1)
        a=1;
    if(existeDansListe(sommet,l)==0 || a==1){
   Liste liste=(Liste)malloc(sizeof(Cellule));
   liste->suivant=NULL;
   liste->sommet=sommet;
   Liste temp=l;
   if(l==NULL)
     return liste;
   while(temp->suivant)
     temp=temp->suivant;
   temp->suivant=liste;
    }
   return l;

}

void afficheListe(Liste l){
    int i=0;
     printf("%d:",i);
    while(l){

        if(l->sommet!=-1)
           printf("%d->",l->sommet);
        else{printf("\n",i);i++;
        printf("%d:",i);
        }
        l=l->suivant;


    }
    printf("\n");

}


GrapheL graphe_vide(){
	GrapheL graphe;
	graphe.n=0;
    int i;
    for (i = 0; i < N_MAX; i++){
		graphe.a[i]=NULL;
	}
    return graphe;
}

GrapheL inserer(GrapheL graphe,int destination,int elementAjouter){
	Liste liste=(Liste)malloc(sizeof(Cellule));
	liste->suivant=NULL;
	liste->sommet=elementAjouter;
	liste->suivant=graphe.a[destination];
	graphe.a[destination]=liste;
	graphe.n++;
	return graphe;
}

GrapheL supprimer(GrapheL graphe, int sommet){
    graphe.a[sommet]=NULL;
    int j;
	for(j=0;j<N_MAX;j++){
		Liste ptr=graphe.a[j];
		Liste prec=graphe.a[j];
		int position=0;
		while(ptr){
			if(ptr->sommet==sommet){

			if(position==0)
				graphe.a[j]=graphe.a[j]->suivant;

			else{
				while(prec->suivant!=ptr)
					prec=prec->suivant;
				prec->suivant=ptr->suivant;
			}
			}
			position++;
			ptr=ptr->suivant;
		}
	}
	return graphe;
}


void Prof(GrapheL graphe,int i,int *vis){
        Liste l=graphe.a[i];
        while(l){
                //printf("e");
            if(vis[l->sommet]==-1){
                 printf("%d->",l->sommet);
            vis[l->sommet]=0;
            Prof(graphe,l->sommet,vis);}
            l=l->suivant;}

    }



int ListProf2(GrapheL graphe,int i,int* vis,Liste temp){
         Liste l=graphe.a[i];
        while(l){
            if(vis[l->sommet]==-1){
                 temp=ajouterListe(l->sommet,temp);
            vis[l->sommet]=0;
            temp=ListProf2(graphe,l->sommet,vis,temp);}
            l=l->suivant;}
        return temp;
    }




void parcoursProf(GrapheL graphe,int i) {

    int j,k;
    int vis[N_MAX];
    for(j=0;j<N_MAX;j++)
        vis[j]=-1;

    for(j=i;j<N_MAX;j++){
      if(graphe.a[j] && vis[j]==-1){
      printf("%d->",j);

          vis[j]=0;}
        Prof(graphe,j,vis);
        //printf("\n");}
       // for(k=0;k<N_MAX;k++)
       // printf("%d",vis[k]);
       // printf("\n");



    }}
Liste parcoursListeProf(GrapheL graphe,int i) {

    int j,k;
    int vis[N_MAX];
    for(j=0;j<N_MAX;j++)
        vis[j]=-1;
 Liste temp=liste_vide();
    return ListProf2(graphe,i,vis,temp);}


Liste connexe(GrapheL graphe){
   int i,j;
   Liste l=liste_vide();
   for(i=0;i<N_MAX;i++){


        Liste temp=parcoursListeProf( graphe,i);
        for(j=i;j<N_MAX;j++){

            if(existeDansListe(j,temp)){
               Liste temp2=parcoursListeProf(graphe,j);
               if(existeDansListe(i,temp2)){

                 l=ajouterListe(i,l);
                 l=ajouterListe(j,l);
               }

   }
        }

l=ajouterListe(-1,l);
}
afficheListe(l);
return l;

}





