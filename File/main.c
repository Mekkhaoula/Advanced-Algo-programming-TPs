#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "fonctions.h"


int main()
{
    File F;
    F=file_vide();
    F=enfiler(F,1);
    F=enfiler(F,2);
    F=enfiler(F,3);
    affichage(F);
    F=defiler(F);
    affichage(F);
    printf("%d",tete(F));
}
