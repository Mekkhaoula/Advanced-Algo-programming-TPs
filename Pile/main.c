#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Pile_entier.h"
#include "Pile_livre.h"
#include "Pile_GenHom.h"
#include "Pile_GenHet.h"
#include "Pile_entier.c"
#include "Pile_livre.c"
#include "Pile_GenHom.c"
#include "Pile_GenHet.c"

/*0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
******************************************************************************************************************************
*****************************************************menu_principal***********************************************************/
void menuu(PileGe pg,Pile* p){
    int i;
    do{
        printf("\t**********************************************************************\n");
        printf("\t************************* TP1 ****************************************\n");
        printf("\t**********************************************************************\n");
        printf("\t*********** 1. Choissisez une pile generique homogene   **************\n");
        printf("\t*********** 2. Choissisez une pile generique heterogene **************\n");
        printf("\t*********** 0. Quitter le programme                     **************\n");
        printf("\t**********************************************************************\n");

        i=0;
        printf("\tChoix =");
        scanf("%d",&i);
        switch (i){
            case 1:{
                system("cls");
                menuu1(pg,p,-1);
                break;
            }
            case 2:{
                system("cls");
                menuu2(pg,p);
                break;
            }
            case 0 :
            {
                printf("\n\n");
                printf("\t************Execution termine!************\n");
                printf("\t******************************************\n\n");
                return 0;
                break;
            }

            default :{
                system("cls");
                printf("\tVotre choix est invalide !!\n");
                menuu(pg,p);
            }
        }
	}while( i!=0);
}

/*11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
*******************************************************************************************************************************
***************************************************** menu_homogene ***********************************************************/
void menuu1(PileGe pg,Pile* p,int choix){
    if(choix!=1 && choix!=2){
    printf("\t**********************************************************************\n");
	printf("\t*************************** Pile Generique Homogene ******************\n");
	printf("\t**********************************************************************\n");
	printf("\t*********************** 1. Pile de Ints ******************************\n");
	printf("\t*********************** 2. Pile de Livres ****************************\n");
	printf("\t*********************** 0. Retour au menu precedent ******************\n");
    printf("\tChoix =");
	scanf("%d",&choix);
	if(choix==1)
        pg=pile_videG(INTS);
    else if(choix==2){
        pg=pile_videG(LIVRE);

    }else{
        system("cls");
        menuu(pg,p);
    }
        }
	char* t;
	if(choix==1){

        t="Int";}
    else{

        t="Livre";
    }

/******************************************************************************************************************************/

    printf("\t**********************************************************************\n");
	printf("\t********************** Pile de %s                  ****************\n",t);
	printf("\t**********************************************************************\n");
	printf("\t*********************** 1. Tester si la pile est vide     ************\n");
	printf("\t*********************** 2. Empiler un %s               ************\n",t);
	printf("\t*********************** 3. Depiler                         ***********\n");
	printf("\t*********************** 4. Visualiser le sommet de la pile ***********\n");
	printf("\t*********************** 5. Retour                              *******\n");

	int i=0;
	printf("\tChoix=");
	scanf("%d",&i);

	switch (i){
		case 1:{
		    system("cls");
			if(is_emptyG(pg))
                printf("\tLa pile est vide\n");
            else{
                printf("\tLa pile n'est pas vide\n");
            }
            menuu1(pg,p,choix);
			break;
		}
		case 2:{
		    system("cls");
		    int in;
			if(choix==1){
                printf("\tEnter l'entier a empiler :\n \tn=");
                scanf("%d",&in);
                pg=pushG(pg,&in);
            }
            else{
                char ID[20];
                printf("\tL'ID : ");
                scanf("%s",ID);
                char Titre[20];
                printf("\tLe titre : ");
                scanf("%s",Titre);
                char Auteur[20];
                printf("\tL'auteur : ");
                scanf("%s",Auteur);
                int np;
                printf("\tLe numero de pages dans ce livre : ");
                scanf("%d",&np);
                int j,m,y;
                printf("\tLa Date de publication en format jj/mm/yy : ");
                char a,b;
                scanf("%d %c %d %c %d",&j,&a,&m,&b,&y);
                Date dd=cred(j,m,y);
                Livre liv=crel(ID,Titre,Auteur,np,dd);
                pg=pushG(pg,&liv);
            }
            menuu1(pg,p,choix);
			break;
		}
     	case 3:{
		    system("cls");
		    pg=pullG(pg);
			menuu1(pg,p,choix);
			break;
		}
		case 4:{
		    system("cls");
		    printf("\tLe sommet de la pile est :\n");
		    headG(pg);
		    printf("\n");
			menuu1(pg,p,choix);
			break;
		}
		case 5:{
		    system("cls");
			menuu(pg,p);
			break;
		}

		default :{
		    system("cls");
			printf("\tVotre choix est invalide !!\n");
			menuu1(pg,p,choix);
		}
	}
}


/*******************************************************************************************************************************
***************************************************** menu_heterogene ***********************************************************/
void menuu2(PileGe pg,Pile* p){

    printf("\t***********************************************************************\n");
	printf("\t*************************** Pile Generique Heterogene *****************\n");
	printf("\t***********************************************************************\n");
	printf("\t*********************** 1. Tester si la pile est vide       ***********\n");
	printf("\t*********************** 2. Empiler un Element               ***********\n");
	printf("\t*********************** 3. Depiler                          ***********\n");
	printf("\t*********************** 4. Visualiser le sommet de la pile  ***********\n");
	printf("\t*********************** 5. Retour au menu precedent         ***********\n");

	int i=0;
	printf("\tn=");
	scanf("%d",&i);
	switch (i){
		case 1:{
		    system("cls");
			if(est_vide(p))
                printf("\tLa pile est vide\n");
            else{
                printf("\tLa pile n'est pas vide\n");
            }
            menuu2(pg,p);
			break;
		}
		case 2:{
		    system("cls");
    int choix;
	printf("\t1. Empiler un Int\n");
	printf("\t2. Empiler un Livre\n");
	scanf("%d",&choix);



			if(choix==1){
                    int in;
                printf("\tEnter le int a empiler:\n n=");
                scanf("%d",&in);
                empiler(p,in,entier);

                }
            else{
                char ID[20];
			printf("\tL'ID : ");
			scanf("%s",ID);
			char Titre[20];
			printf("\tLe titre : ");
			scanf("%s",Titre);
			char Auteur[20];
			printf("\tL'auteur : ");
			scanf("%s",Auteur);
			int np;
			printf("\tLe numero de pages dan ce livre : ");
			scanf("%d",&np);
			int j,m,y;
			printf("\tLa Date de publication en format jj/mm/yy : ");
			char a,b;
			scanf("%d %c %d %c %d",&j,&a,&m,&b,&y);
			Date dd=cred(j,m,y);
			Livre liv=crel(ID,Titre,Auteur,np,dd);
			 empiler(p,nv_livre(ID,Auteur,Titre,np,j,m,y),livre);
            }
            menuu2(pg,p);
			break;
		}
     	case 3:{
		    system("cls");
		    depiler(p);
			menuu2(pg,p);
			break;
		}
		case 4:{
		    system("cls");
		    printf("le sommet de la pile est :");
		     Element *E;
             E=p->tete;
             if(E!=NULL){
            Afficher_element(E->donnee);

        }
		    printf("\n");
			menuu2(pg,p);
			break;
		}
		case 5:{
		    system("cls");
			menuu(pg,p);
			break;
		}

		default :{
		    system("cls");
			printf("Votre choix est invalide !!\n");
			menuu2(pg,p);
		}
	}

}


int main(){

	Pilech pi=empty();
	pilel pl=emptyl();
	PileGe pg;
	Pile *L=pile_vide();
	menuu(pg,L);
	return 0;
}
