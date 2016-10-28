#include <stdio.h>
#include <stdlib.h>
#include "graph1.h"

    //initialisation de graph_Matrice

    graphm graphm_vide(int n){
        int i,j;
        graphm gr;
        gr.n=n;
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                gr.g[i][j] = 0;
                gr.couleur[i][j] = -1;
            }
        }
        return gr;
    }

    //affichage de matrice

    void print_graphm(graphm gr){
        int i,j,k,l;
        printf("\nLa Matrice est :\n");
        printf("-------------------------------------------------------------\n");
        for(i=0;i<=gr.n;i++){
            for(j=0;j<=gr.n;j++){
                printf("\t %d \t",gr.g[i][j]);
            }
            printf("\n");
        }
        printf("-------------------------------------------------------------\n\n");

    }

    //affichage des couleurs d'une matrice

    void print_coulors(graphm gr){
        int k,l;
        printf("\nSes couleurs :\n");
        printf("-------------------------------------------------------------\n");
        for(k=0;k<=gr.n;k++){
            for(l=0;l<=gr.n;l++){
                printf("\t %d \t",gr.couleur[k][l]);
            }
            printf("\n");
        }
        printf("-------------------------------------------------------------\n\n");

    }

    //ajouter un nv sommet ( en ordre )

    graphm ajout_sommet(sommet s,graphm gr){
        if(s<=gr.n){
            printf("ce sommet existe deja");
            exit(-1);
        }
        else{
            int k,l;
            int nn=gr.n;// je met ici la taille de la matrice avant ajout du nv sommet
            int aj=s-nn;//je calcule la difference
            gr.n+=aj;//je modifie la taille
            //boucle pour last colomn only pour chaque ligne existante
            for(k=0;k<=nn;k++){
                for(l=nn+1;l<=gr.n;l++){
                    gr.g[k][l]=0;
                    gr.couleur[k][l]=-1;
                }
            }
            //boucle pour les nouvelles lignes et columns li b9aaw htaal la fin
            for(k=nn+1;k<=gr.n;k++){
                for(l=0;l<=gr.n;l++){
                    gr.g[k][l]=0;
                    gr.couleur[k][l]=-1;
                }
            }
        }
        return gr;
    }

    //ajouter un nv arc ssi les deux sommets existe deja , ou arc est non existant

    graphm ajout_arete(sommet s,sommet ss,graphm gr){
        if( gr.g[s][ss]!=0 || gr.g[s][ss]!=0){
            printf("cette arete existe deja ! \n");
        }
        else if(s>gr.n || ss>gr.n){
            printf("l'un de ces sommets n'existe pas");
        }
        else{
            gr.g[s][ss]=1;
            gr.g[ss][s]=1;
        }
        return gr;
    }

    bool est_sommet(sommet s, graphm g){
            return s<=g.n?true:false;
    }

    bool est_arete(sommet s,sommet ss, graphm gr){
        if(gr.g[s][ss]!=0 && gr.g[s][ss]!=0)
            return true;
        return false;
    }

    int degre(sommet s,graphm g){
        int i,j,x=0;
        i=s;
        for(j=0;j<=g.n;j++){
            if(g.g[i][j]==1)
                x++;
        }
        printf("Le degre du sommet %d est :\t",s);
        return x;
    }

    void adjacents(sommet s,graphm g){
      int i,j,x=0;
      printf("\nle sommet %d a comme sommets adjacents :\t",s);
        i=s;
        for(j=0;j<=g.n;j++){
            if(g.g[i][j]==1)
            printf(" %d\t",j);
        }
    }

    graphm supp_sommet(sommet s,graphm g){
        //if sommet supprimé , ses aretes adjacents sont suprimés
        int i,j;
        int par=s;
        for(i=0;i<g.n;i++){
            for(j=0;j<g.n;j++){
                g.g[s][j]=0;g.couleur[s][j]=-1;
                g.g[i][s]=0;g.couleur[i][s]=-1;
            }
        }
        return g;
    }

    graphm supp_arete(sommet s,sommet ss,graphm g){
        g.g[s][ss]=0;g.couleur[s][ss]=-1;
        g.g[ss][s]=0;g.couleur[ss][s]=-1;
        return g;
    }
    /*void connexe(graphm gr){
        int i,j,k,l,col=0;
        for(i=0;i<gr.n;i++){
            for(j=0;j<gr.n;j++){
                if(gr.g[i][j]!=0){
                    if(gr.couleur[i][j]=-1){
                        for(k=i;k<j;k++){
                            for(l=0;l<j;l++){
                                if(gr.couleur[k][l]!=-1){
                                    gr.couleur[i][j]=gr.couleur[k][l];
                                    //gr.couleur[j][i]=gr.couleur[k][l];
                                }else{
                                    gr.couleur[i][j]=col;
                                    gr.couleur[j][i]=col;
                                }
                            }
                        }
                    }else if(gr.couleur[i][j]!=-1){
                        if(gr.couleur[i][j]!=gr.couleur[j][i])
                        gr.couleur[j][i]=gr.couleur[i][j];
                    }
                }
            }
        printf("ana hna100000000000000\n");
            col++;
        }
        //return gr;
    }*/

    void profondeur(graphm g,int* t,int nb){
        int i,j;
        for(i=nb;i<g.n;i++){
         if(t[i]==0){
            //printf("\n%d :",i);
            t[i]=1;}
            for(j=0;j<g.n+1;j++){
                //printf("j%d",j);
                printf("ij%d\n",g.g[i][j]);
                if(g.g[i][j]==1){

                    if(t[j+1]==0){
                        printf("%d->",j);
                            t[j]=1;
                            profondeur(g,t,j);
                    }
                }
            }

        }

    }

    void profondeur2(graphm g){
        int k;
        int tab[g.n];
        for(k=0;k<g.n;k++){
            tab[k]=0;
        }

            profondeur(g,tab,0);
    }

    graphm colorie_ligne(graphm g,int couleur,int ligne){
        int i,j,k,l;
        for(i=0;i<g.n;i++){
            if(g.g[ligne][i]==1)
                g.couleur[ligne][i]=couleur;
        }
        return g;
    }

    graphm colorie_column(graphm g,int couleur,int column){
        int i;
        for(i=0;i<g.n;i++){
            if(g.g[i][column]==1)
                g.couleur[i][column]=couleur;
        }
        return g;
    }

    graphm connexe(graphm g){
        int i,k,j,coul=0,l;
        for(i=0;i<=g.n;i++){
            for(j=0;j<=g.n;j++){
                if(g.g[i][j]==1){
                    if(g.couleur[i][j]==-1){
                        g=colorie_ligne(g,coul,i);
                        g=colorie_column(g,coul,j);
                        /*g=colorie_ligne(g,coul,j);
                        g=colorie_column(g,coul,i);*/
                        coul++;
                    }
                    else{
                        g=colorie_ligne(g,g.couleur[i][j],i);
                        g=colorie_column(g,g.couleur[i][j],j);
                        /*g=colorie_ligne(g,g.couleur[i][j],j);
                        g=colorie_column(g,g.couleur[i][j],i);*/

                    }
                }

            }
        }
        for(k=0;k<=g.n;k++){
            int bol=0;
            for(j=0;j<=g.n;j++){
                if(g.couleur[k][j]!=-1 || g.couleur[j][k]!=-1)
                    bol=1;
            }
            if(bol==0){
                g.couleur[k][k]=-3;
                //coul++;
            }
        }
        return g;
    }

int colornb(graphm g){
    int i,j,s=0,c=77;
    for(i=0;i<=g.n;i++){
        for(j=0;j<=g.n;j++){
            if(g.couleur[i][j]!=-1 /*&& g.couleur[i][j]!=-3*/){
                if(c!=g.couleur[i][j]){
                    c=g.couleur[i][j];
                    s++;
                }
            }
        }
    }
    return s;
}

int articulation(graphm g){
    int i,s;
    graphm gg;
    if(colornb(g)>1){
        printf("ce graphe est non connexe !\n");
        return -1;
    }
    for(i=0;i<=g.n;i++){
        gg=g;
        gg=supp_sommet(i,gg);
        //print_coulors(gg);
        gg=connexe(gg);
        print_coulors(gg);
        s=colornb(gg);
        printf("*sommet qui est considere comme une articulation est :\n*//*/*/*/*/*/*/%d*/***/*/*/*/*/*/",s);
        if(s>1){
             printf("*sommet qui est considere comme une articulation est :\n*//*/*/*/*/*/*/%d*/***/*/*/*/*/*/",s);
            return i;
            //break;
        }
            //return i;
    }
    return -1;
    //exit("Pas de sommet d'artciulation ! \n");
}

void pont(graphm g){
    int j,i,s;
    graphm gg;
    for(i=0;i<=g.n;i++){
        for(j=0;j<=g.n;j++){
            gg=g;
            //if(g.couleur)
            gg=supp_arete(i,j,gg);
            gg=connexe(gg);
            s=colornb(gg);
            if(s>1){
                    printf("L'arete %d %d est un pont",i,j);
            }
        }
    }
    //return -0.9999999;

}




