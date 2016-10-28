#ifndef GRAPH1_H_INCLUDED
#define GRAPH1_H_INCLUDED
#define N_MAX 10
#define true 1
#define false 0
typedef int  bool;
typedef int sommet;

typedef struct graphm{
    int g[N_MAX][N_MAX];
    int n;
    int couleur[N_MAX][N_MAX];
}graphm;

    graphm graphm_vide(int n);
    graphm ajout_sommet(sommet s,graphm g);
    graphm ajout_arete(sommet s,sommet ss,graphm gr);
    bool est_sommet(sommet s, graphm g);
    bool est_arete(sommet s,sommet ss, graphm g);
    int degre(sommet s,graphm g);// ici since c un graphe non orienté le degre sera le nb d arete. ( la entrante la sortante )
    void adjacents(sommet s,graphm g);
    graphm supp_sommet(sommet s,graphm g);
    graphm supp_arete(sommet s,sommet ss,graphm g);
    //int nb_sommets(graphm g);
    //int nb_aretes(graphm g);
    graphm connexe(graphm g);
    void profondeur(graphm g,int* t,int nb);
    graphm colorie_ligne(graphm g,int couleur,int ligne);
    graphm colorie_column(graphm g,int couleur,int column);
    int articulation(graphm g);
    void pont(graphm g);


    int colornb(graphm g);
    int articulation(graphm g);


#endif // GRAPH1_H_INCLUDED
