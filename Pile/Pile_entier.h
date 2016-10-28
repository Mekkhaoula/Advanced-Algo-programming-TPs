#ifndef PILE_ENTIER_H_INCLUDED
#define PILE_ENTIER_H_INCLUDED
#define true 1
#define false 0
typedef int bool;
typedef int Number;

typedef struct Cellule{
	Number num;
	struct Cellule *prev;
}Cellule;
typedef Cellule *Pilech;

	Pilech empty(void);
	bool   is_empty(Pilech pc);
	Pilech push(Number n,Pilech pc);
	Pilech pull(Pilech pc);
	int    getsom(Pilech pc);

#endif // PILE_ENTIER_H_INCLUDED
