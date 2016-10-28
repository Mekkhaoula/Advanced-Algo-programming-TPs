#include "Pile_entier.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

	Pilech empty(void){
		return NULL;
	}

	bool is_empty(Pilech pc){
		if( pc==NULL) return true;
		return false;
	}

	Pilech push(Number n,Pilech pc){
		Pilech p=(Pilech)malloc(sizeof(Cellule));
		p->num=n;
		p->prev=pc;
		pc=p;
		return pc;
	}

	Pilech pull(Pilech pc){
		if(is_empty(pc)) {
			printf("Pile est vide !\n");
			//exit(-1);
			return pc;
		}
		return pc->prev;

	}

	int getsom(Pilech pc){
		if(pc==NULL){
		 printf("Pile est vide !\n");
		 exit(-1);
		}
		return pc->num;
	}
