


#define N_MAX 20

typedef struct cellule {
	int sommet;
	struct cellule* suivant;
} Cellule;

typedef Cellule* Liste;

typedef struct {
	Liste a[N_MAX];
	int n;
} GrapheL;

typedef int atteint[N_MAX];


GrapheL graphe_vide();
GrapheL parcoursProf(GrapheL graphe,int i);
GrapheL inserer(GrapheL graphe,int destination,int elementAjouter);
GrapheL supprimer(GrapheL graphe, int sommet);
Liste connexe(GrapheL graphe);





