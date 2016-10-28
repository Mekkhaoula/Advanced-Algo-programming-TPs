#include "Pile_livre.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

	pilel emptyl(void){
		return NULL;
	}

	int is_emptyl(pilel pc){
		if( pc==NULL) return 1;
		return 0;
	}

	pilel pushl(Livre li,pilel pc){
		pilel p=(pilel)malloc(sizeof(Cellulel));
		p->l=li;
		p->prev=pc;
		pc=p;
		return pc;
	}

	pilel pulll(pilel pc){
		if(is_empty(pc)) {
			printf("Pile est vide !\n");
			//exit(-1);
			return pc;
		}
		return pc->prev;

	}

	Livre getsoml(pilel pc){
		if(pc==NULL){
		 printf("Pile est vide !\n");
		 exit(-1);
		}

		return pc->l;

	}

	void printlivl(Livre l){
	    //printf("Les donnees sont         :\n");
		printf("\tL'ID                     : %s \n",l.ID);
		printf("\tLe titre                 : %s \n",l.titre);
		printf("\tL'auteur                 : %s \n",l.auteur);
		printf("\tLe Numero de pages total : %d \n",l.npag);
		printf("\tLa Date de publication   : %d/%d/%d \n",l.dpublic.day,l.dpublic.month,l.dpublic.year);
	}

	Livre maxpagel(pilel ll){
		pilel l=ll;
		Livre lr;
		lr=getsoml(ll);
		int max=lr.npag;
		ll=pulll(ll);
		//printf("%d",is_emptyl(ll));
		while(is_emptyl(ll)!=1){

			if(max<ll->l.npag){
				lr=ll->l;
				max=lr.npag;
				}
				ll=pulll(ll);

		}
		return lr;
	}

	Date cred(int j,int m,int y){
		Date d;
		d.day=j;
		d.month=m;
		d.year=y;
		return d;
		}

	Livre crel(char* id,char* tr,char* at,int np,Date d){
		Livre l;
		l.ID=id;
		l.auteur=at;
		l.titre=tr;
		l.npag=np;
		l.dpublic=d;
		return l;
	}
