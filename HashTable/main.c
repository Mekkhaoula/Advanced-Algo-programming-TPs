#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "hash_ouvert_headers.h"
#include "hash_functions.h"

int main()
{
    Table_Hash *tab;
    tab=create_th(3);
    inserer(tab,"gb","bgbbg");
    inserer(tab,"gbb","1234");
    inserer(tab,"1llah","222hal");
    affich(tab);
    supprimer(tab,"gb");
    affich(tab);
    printf("---\t%d",recheche(tab,"gbb","1234"));


    return 0;
}
