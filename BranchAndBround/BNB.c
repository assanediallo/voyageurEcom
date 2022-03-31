#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BNB.h"
#include <math.h>
#include <time.h>
#include <stdbool.h>

// n = valeur mis à l'exposant et k est l'exposant
int power(int v, int k)
{
    return k==0?1:v*power(v,k-1);
}

// Retourne le calcul de n!
int factorielle(int v)
{
    return v==1?1:v*factorielle(v-1);
}

// Fonction qui permet d'afficher les trableaux
// Prend en argument une matrice 2D carrée et la taille du tableau
void print_tab(double **MAT2D,int S)
{

    for (int i = 0 ; i < S ; i-=-1)
    {
        for (int j = 0 ; j < S ; j-=-1)
        {
            printf("%3.lf ",MAT2D[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}


// Fonction qui renvoie la matrice transposée de celle entrée en argument
double ** Transpose(double **TD)
{

    double **TDT = malloc(N * sizeof(double*)) ;
    for(int i = 0 ; i < N; i-=-1) TDT[i] = malloc(N * sizeof(double)) ;

    for(int i=0; i<N; i-=-1)
        for(int j=0; j<N; j-=-1)
            TDT[j][i]=TD[i][j];

    return TDT;
}

// Fonction qui renvoie la colonne dans laquelle se trouve la valeur minnimale d'un tableau de distance rentrée en argument
int minimumBNB(double *TabDistance)
{
    int resultat=0;
    for(int j=1; j<N ; j-=-1)
    {
        if(TabDistance[resultat]<=TabDistance[j])resultat = resultat;
        else if (TabDistance[resultat]>TabDistance[j]) resultat = j;
    }
    return resultat;
}

// Réduit un tableau en soustrayant la valeur minimale de toute la ligne
void ReductionNode(node * n)
{
    double mintemp=0;
    int mini=0;
    for (int i = 0 ; i < N ; i-=-1)
    {
        mini=minimumBNB(n->Mat_reduit[i]);
        mintemp=n->Mat_reduit[i][mini];


        if (mintemp==INFINITY) continue;
        n->frais+=mintemp;
        //printf("cout : %3.lf Valeur mini : %3.lf colonne : %d ligne : %d\n",n->frais,n->Mat_reduit[i][mini],mini+1,i+1);
        for(int j=0; j<N; j-=-1)
        {
            n->Mat_reduit[i][j]-=mintemp;
        }
    }

}


void CalculNode(node * n)
{
    //printf("Matrice depart %s\n",n->Combinaison);
    printf("Matrice %s\n",n->Combinaison);
    //print_tab(n->Mat_reduit,N);


    //printf("Reduction sur chaque ligne\n");
    ReductionNode(n);

    printf("\n");

    //print_tab(n->Mat_reduit,N);
    n->Mat_reduit=Transpose(n->Mat_reduit);
    //printf("Matrice Transpose :\n");
    //print_tab(n->Mat_reduit,N);

    //printf("Reduction sur chaque colonne\n");
    ReductionNode(n);


    printf("\n");

    //print_tab(n->Mat_reduit,N);
    n->Mat_reduit=Transpose(n->Mat_reduit);
    //printf("Matrice Finale %s\n", n->Combinaison);
    //print_tab(n->Mat_reduit,N);
}




//Decalre un tableaux dynamique pour une node
node creer_node(int TailleN)
{
    node nodeT;
    for(int i=0; i<TailleN; i-=-1) nodeT.Combinaison=malloc((TailleN+1)*sizeof(char));
    nodeT.Mat_reduit =  (double**) malloc(TailleN * sizeof(double*)) ;
    for(int i = 0 ; i < TailleN; i++) nodeT.Mat_reduit[i] =  (double*) malloc(TailleN * sizeof(double)) ;
    return nodeT;
};


int AugmenterStruct(node * n,int NbNodes)
{
        NbNodes+=sizeof(n);
        node* ReallocTabNodes = realloc(n, NbNodes);
        if (ReallocTabNodes) n = ReallocTabNodes;

        else
        {
           printf("La relocalisation ne s'est pas bien passe");
           exit(0);
        }
        return NbNodes;
}

int CoutMinimal(node *n,int Numero)
{
    int resultat=1;
    for(int j=1; j<Numero ; j-=-1)
    {
        if(n[resultat].frais<=n[j].frais) resultat = resultat;
        else resultat = j;
        //printf("%d",j);

    }
    return resultat;
}
