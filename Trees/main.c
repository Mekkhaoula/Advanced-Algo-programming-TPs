#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "tree_functions.h"
int main()
{
    Arbre_BR A=arbre_vide();
	FILE *file;
	char line[1024],word[1024],*p,*eow;
	file=fopen("C:/Users/Admin/Desktop/momo.txt","r");
	while(fgets(line,sizeof line,file)){
		p=line;
		while(eow=strchr(p,' ')){
			*eow=0;
			inserer(new_valeur(p),&A);
		}
		fclose(file);
	}

    return 0;
}
