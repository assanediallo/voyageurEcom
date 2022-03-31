#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 11

void print_tab(double **MAT2D);
int factorielle(int v);

void Calcul_Combinaison(int i,int **TabF, int *TabC,int *fp);
void Generer_Tab_Combinaison(int *tab, int **TabF,int *fp);
void permute(int *tab,int i,int j);

double **GenererMat(); //Generation Aleatoire

void TrajetCout(int **TABCombi, double **TABDistance, int *Somme);
int minimumBF(int *TabSomme);

void MethodeBrutForce(double **Mat);
