#include "Pile_GenHom.h"
#include "Pile_livre.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
	PileGe pile_videG(Type t) {
		PileGe pg;
		pg.pile=NULL;
		pg.type=t;
	    return pg;
	}
	bool is_emptyG(PileGe pc){
		if( pc.pile==NULL)
			return true;
		return false;
	}
	PileGe pushG(PileGe pg,elm e) {
		 PileG p= (PileG)malloc(sizeof(CelluleG));
	     p->elmt=e;
	     p->prev=pg.pile;
	     pg.pile=p;
	     return pg;
	    }

	PileGe pullG(PileGe pg){
		if(pg.pile==NULL)
		    exit(-1);
		pg.pile=pg.pile->prev;
		return pg;
	}
	void afficheInt(elm p){
		printf("%d",*(int*)p);
	}
	void afficheDouble(elm p){
		printf("%f",*(double*)p);
	}
	void afficheFloat(elm p){
		printf("%f",*(float*)p);
	}
	void afficheLivre(elm p){
		Livre l=*(Livre*)p;
		printlivl(l);
	}
	void headG(PileGe pg){
		void (*affichePtr)(elm);//=&afficheInt;
		switch(pg.type){
			case INTS :{
				affichePtr=&afficheInt;
				break;
			}
		    case FLOATS :{
				affichePtr=&afficheFloat;
			    break;
			}
			case DOUBLE :{
				affichePtr=&afficheDouble;
			    break;
			}
			case LIVRE :{
				affichePtr=&afficheLivre;
			    break;
			}
		}
		(*affichePtr)(pg.pile->elmt);
	}
	void affichElm(PileGe p,void (*aff)(elm) ){
		while(!is_emptyG(p)){
			(*aff)(p.pile->elmt);
			p=pullG(p);
			printf("\n");
		}
	}




