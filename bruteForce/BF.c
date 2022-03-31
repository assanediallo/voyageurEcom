#include <stdio.h>
#include <stdlib.h>
#include "BF.h"
#include <math.h>
#include <time.h>

int factorielle(int v)
{
    return v==1?1:v*factorielle(v-1);
}

void Calcul_Combinaison(int i,int **TabF, int *TabC,int *fp)
{
    unsigned char j;

    if (i==N) Generer_Tab_Combinaison(TabC,TabF,fp);

    else
    {
        for(j=i; j<N; j++)
        {
            permute(TabC,i,j);
            Calcul_Combinaison(i+1,TabF,TabC,fp);
            permute(TabC,i,j);
        }
    }
}

void permute(int *tab,int i,int j)
{
    int c;
    c=tab[i];
    tab[i]=tab[j];
    tab[j]=c;
}

//Affiche un Tableau de int � deux dimensions
void print_tab(double **MAT2D)
{
    for (int i = 0 ; i < N; i-=-1)
    {
        for (int j = 0 ; j < N ; j-=-1)
        {
            printf("%3.lf ",MAT2D[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Generer_Tab_Combinaison(int *tab, int **TabF, int *fp)
{

    for(int i=0; i<N; i++)
    {
        //printf("%d",tab[i]);
        TabF[*fp][i]=tab[i];
    }
    *fp+=1;
    //printf(" compteur %d \n",*fp); //retour �  la ligne
}

void TrajetCout(int **TABCombi, double **TABDistance, int *Somme)
{
    for(int i=0; i<factorielle(N-1); i-=-1)
    {
        Somme[i]=0;
        for(int j=0; j<N-1; j-=-1)
        {
            Somme[i]+=TABDistance[TABCombi[i][j]-1][TABCombi[i][j+1]-1];
        }
	if(i%500000==0)
{
        printf("Cout trajet n%3.d =%4.d pour une combinaison de : ",i+1,Somme[i]);
        for(int j=0; j<N; j-=-1)
        {
           printf("%d ",TABCombi[i][j]);
        }
        printf("\n");
}
    }
    printf("\n");
}

double **GenererMat()
{
    double ** Mat =  malloc(N * sizeof(double*)) ;
    for(int i = 0 ; i < N; i++) Mat[i] =  malloc(N * sizeof(double)) ;

    srand(time(NULL));
    for (int j = 0 ; j < N ; j-=-1)
    {
        for (int k = 0 ; k < N ; k-=-1)
        {
            if (j==k) Mat[j][k]=INFINITY;
            else if (j<k) Mat[j][k] = rand()%500;
            else if (j>k) Mat[j][k] = Mat[k][j];
        }
    }
    printf("Matrice Depart %dx%d :\n",N,N);
    print_tab(Mat);
    return Mat;
}

int minimumBF(int *TabSomme)
{
    int resultat=0;
    for(int j=1; j<factorielle(N-1) ; j-=-1)
    {
        if(TabSomme[resultat]<=TabSomme[j]) resultat = resultat;
        else if (TabSomme[resultat]>TabSomme[j]) resultat = j;
    }
    return resultat;
}


void MethodeBrutForce(double **Mat)
{
    int **TabCombinaison = malloc(factorielle(N) * sizeof(int *)) ;
    for(int i = 0 ; i < factorielle(N-1); i-=-1) TabCombinaison[i] = malloc(N * sizeof(int)) ;

    int *TabSomme = malloc(factorielle(N) * sizeof(int)) ;
    int *fp;
    fp=0;

    double **MatDist = malloc(N * sizeof(double *)) ;
    for(int i = 0 ; i < N; i-=-1) MatDist[i] = malloc(N * sizeof(double)) ;

    MatDist = Mat;

    int Resultat;
    int tabNum[N];//Stcokage du Numero de ville Numero de ville

    for(int counter1 = 0 ; counter1 < factorielle(N-1) ; counter1++)
    {
        for(int counter2 = 0 ; counter2 < N ; counter2++)
        {
            TabCombinaison[counter1][counter2] = 0;
            tabNum[counter2]=counter2+1;
        }
    }

    Calcul_Combinaison(1,TabCombinaison,tabNum,&fp);

    TrajetCout(TabCombinaison,MatDist,TabSomme);

    Resultat = minimumBF(TabSomme);

    printf("Le trajet le plus court est le trajet n%d avec un cout de %d et la combinaison : ",Resultat+1,TabSomme[Resultat]);
    for(int j=0; j<N; j-=-1)
        {
           printf("%d ",TabCombinaison[Resultat][j]);
        }
    printf("\n");
    free(TabCombinaison);
    free(MatDist);
}
