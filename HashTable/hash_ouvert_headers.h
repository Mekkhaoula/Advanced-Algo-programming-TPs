#ifndef HASH_OUVERT_HEADERS_H_INCLUDED
#define HASH_OUVERT_HEADERS_H_INCLUDED
#define true 1
#define false 0
typedef int bool;

typedef struct element{
    char* cle;
    char* val;
}Element;
typedef Element *ele;
typedef struct table{
    ele* tab_elm;
    int taille;
}Table_Hash;

int hashage(Table_Hash *t,char* cle);
Table_Hash* create_th(int taille);
void inserer(Table_Hash* t,char*  cle,char* val);
bool recherche(Table_Hash* t,char*  cle,char* val);
void supprimer(Table_Hash* t,char* cle);


#endif // HASH_OUVERT_HEADERS_H_INCLUDED
