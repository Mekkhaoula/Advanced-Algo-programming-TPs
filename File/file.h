#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#define true 1;
#define false 0;
typedef int bool;


typedef struct noeud{
    int val;
    struct noeud *suiv;
    struct noeud *prec;
}Noeud;

typedef struct file{
    Noeud *debut;
    Noeud *fin;
    int taille;
}File;

File file_vide();
bool est_vide(File F);
File enfiler(File F,int i);
File defiler(File F);

#endif // FILE_H_INCLUDED
