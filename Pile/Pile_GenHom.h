#ifndef PILE_GENHOM_H_INCLUDED
#define PILE_GENHOM_H_INCLUDED

#define true 1
#define false 0
typedef int bool;
typedef void *elm;

typedef enum  { INTS, FLOATS, DOUBLE,LIVRE } Type;

typedef struct celluleG {
	elm elmt;
	struct celluleG *prev;
}CelluleG;

typedef CelluleG *PileG;

typedef struct PileGe{
	PileG pile;
	Type type;
}PileGe;

	PileGe pile_videG (Type t);
	PileGe pushG (PileGe p, elm e);
	PileGe pullG (PileGe p);
	void headG (PileGe p);
	bool is_emptyG (PileGe p);

	void afficheInt(elm p);
	void afficheFloat(elm p);
	void afficheDouble(elm p);
	void afficheLivre(elm p);



#endif // PILE_GENHOM_H_INCLUDED
