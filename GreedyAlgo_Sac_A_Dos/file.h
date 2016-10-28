#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#define max_range 20

typedef struct Objet
{
	int val;
	int poids;
//	char *element;
	int cle;
}objet;


/*
typedef struct tab_objet
{
	objet tab[max_range];
	int taille;
}tab_objet;
*/

typedef struct sac
{
	objet  tab[max_range];
	int poids_max;
	int taille;
}sac;

float VP(objet o);
void ajouter(objet *t,objet o,int i);
//float* Tvp(tab_objet t );
sac add(sac s,objet *t,int n);




#endif // FILE_H_INCLUDED
