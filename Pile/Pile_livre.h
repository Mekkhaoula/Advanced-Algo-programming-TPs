#ifndef PILE_LIVRE_H_INCLUDED
#define PILE_LIVRE_H_INCLUDED
#define true 1
#define false 0
typedef int bool;

typedef struct Date{
	int day;
	int month;
	int year;
}Date;

typedef struct Livre{
	char* ID;
	char* titre;
	char* auteur;
	int npag;
	Date dpublic;
}Livre;

typedef struct Cellulel{
	Livre l;
	struct Cellulel *prev;
}Cellulel				;
typedef Cellulel *pilel;

	pilel  emptyl(void);
	bool   is_emptyl(pilel pc);
	pilel  pushl(Livre n,pilel pc);
	pilel  pulll(pilel pc);
	Livre  getsoml(pilel pc);

	void printlivl(Livre l);
	Livre  maxpagel(pilel ll);
	Livre  crel(char* id,char* tr,char* at,int np,Date d);
	Date   cred(int j,int m,int y);

#endif // PILE_LIVRE_H_INCLUDED
