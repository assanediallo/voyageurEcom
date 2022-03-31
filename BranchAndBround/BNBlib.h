#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#define N 3


typedef struct nodes {
    double frais;
    char *Combinaison;
    double **Mat_reduit;
    int ville_actuelle;
}node;

node creer_node(int TailleN);
int AugmenterStruct(node * n,int NbNodes);


int power(int v, int k);
int factorielle(int v);

void print_tab(double **MAT2D,int S);

int minimumBNB(double *TabDistance);
int CoutMinimal(node *n,int Numero);

void CalculNode(node * n);
double ** Transpose(double **TD);
void ReductionNode(node * n);

double **GenererMat();

void MethodeBranchAndBround(double **Mat);
