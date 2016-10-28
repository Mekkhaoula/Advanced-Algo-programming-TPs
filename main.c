#include <stdio.h>
#include <stdlib.h>
#include "file.h"


int main() {

	objet o,o1,o3,o2,o4;
	sac s;
//	t.taille=0;
		objet *t=(objet *)malloc((5)*sizeof(objet));
	o.val=1;
	o.cle=1;
	o.poids=1;

	o1.val=6;
	o1.cle=2;
	o1.poids=2;

	o2.val=18;
	o2.cle=3;
	o2.poids=5;

	o3.val=22;
	o3.cle=4;
	o3.poids=6;

	o3.val=28;
	o3.cle=5;
	o3.poids=7;

	int i;

	ajouter(t,o,2);
	ajouter(t,o1,0);
	ajouter(t,o2,1);
	ajouter(t,o3,3);
	//ajouter(t,o4,4);

for(i=0;i<4;i++)
	    printf("\nt[%d]=%d %d %d ",i,t[i].cle,t[i].val,t[i].poids);


tri_fusion(t,0,3);
printf("\n apres le tri\n");
for(i=0;i<4;i++)
	    printf("\nt[%d]=%d %d %d ",i,t[i].cle,t[i].val,t[i].poids);

printf("\n*************");
s.poids_max=11;
//printf("\n%d ",s.poids_max);

s.taille=0;
s=add(s,t,4);

//printf("\n%d ",s.taille);
printf("\nle contenu de sac");
for(i=0;i<s.taille;i++)
    printf("\ns[%d]=%d %d %d ",i,s.tab[i].cle,s.tab[i].val,s.tab[i].poids);

	return 0;
}
