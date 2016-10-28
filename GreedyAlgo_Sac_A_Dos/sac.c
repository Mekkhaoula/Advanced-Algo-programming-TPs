#include <stdio.h>
#include <stdlib.h>
#include "file.h"



void ajouter(objet *t,objet o,int i)
{
	t[i]=o;
}



 float VP(objet o)
 {
 	return (float)o.val/o.poids;
 }

 void fusion(objet *t,int d,int m,int f)
 {
 	int i1=d,i2=m+1,i3=0;
 	objet *temp=(objet *)malloc((f-d+1)*sizeof(objet));

 	while((i1<=m)&&(i2<=f))
 	{

 		if(VP(t[i1])<= VP(t[i2]))
 		{
 			temp[i3]=t[i1];
 			i1++;
		 }
		else
		{
			temp[i3]=t[i2];
 			i2++;
		}
		i3++;
	 }

	for(;i2<f;i2++,i3++)
	    temp[i3]=t[i2];

	for(;i1<m;i1++,i3++)
	    temp[i3]=t[i1];

 	for(i1=0;i1<i3;i1++)
	    t[i1+d]=temp[i1];
 }

 void tri_fusion(objet *t,int d,int f)
 {
  	int m;
 if(d<f)
 {
 	 m=(d+f)/2;
 	  tri_fusion(t,d,m);
 	  tri_fusion(t,m+1,f);
 	  fusion(t,d,m,f);

 }
  }


  sac add(sac s,objet *t,int n)
{
int poid=0;
int i,a;
for(i=n-1;i>0;i--)
{
    a=poid+t[i].poids;
	if(a<=s.poids_max)
	{
		s.tab[s.taille]=t[i];
		poid+=t[i].poids;
		s.taille++;
	}
}
return s;

}


