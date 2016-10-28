#include <stdio.h>
#include <stdlib.h>
#include "graph1.h"

int main()
{

    graphm g;
    g=graphm_vide(2);
    sommet s1=0,s2=1,s3=2;
    //g=ajout_arete(s1,s1,g);
    g=ajout_arete(s1,s2,g);
    g=ajout_arete(s2,s3,g);
    g=ajout_arete(s1,s3,g);
    print_graphm(g);
    //g=ajout_sommet(3,g);
    //g=ajout_sommet(4,g);
    //g=ajout_sommet(5,g);
    //g=ajout_sommet(6,g);
    //printf("ffffffff%d\n",g.n);
    //g=ajout_arete(5,6,g);
    //g=ajout_arete(3,4,g);
    //print_graphm(g);
    //g=ajout_arete(3,s2,g);
    print_graphm(g);
    //printf("%d",degre(1,g));
    //adjacents(1,g);
    //g=supp_sommet(s1,g);
    //print_graphm(g);
    //g=supp_arete(s2,3,g);
    //print_graphm(g);
    //profondeur2(g);
    //print_coulors(g);
    //print_graphm(g);
    g=connexe(g);
    print_coulors(g);
    //printf(" %d \n",articulation(g));

    //printf(" %d \n",articulation(g));
    articulation(g);
    //print_graphm(g);
    //print_coulors(g);



    return 0;

}

