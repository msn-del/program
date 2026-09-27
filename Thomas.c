#include <stdio.h>

void affichage(double X[4][4])
{
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++)
        {
            printf("%8.2lf", X[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    double A[4][4]; double U[4][4] = {0.0}; double L[4][4] = {0.0};
    printf("remplir les éléments de la matrice donnée: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("entrer A[%d][%d]= ", i+1, j+1);
            scanf("%lf", &A[i][j]);
        }
    }

    U[0][0] = A[0][0];
    L[0][0] = 1;
    for (int i = 0; i < 3; i++)
    {
        U[i+1][i+1] = (A[i+1][i+1] - (A[i+1][i]/U[i][i]) * A[i][i+1]);
        U[i][i+1] = A[i][i+1];

        L[i+1][i] = A[i+1][i] / U[i][i];
        L[i+1][i+1] = 1;
    }
    printf("la matrice U est :\n\n"); affichage(U);
    printf("la matrice L est :\n\n"); affichage(L);
    return 0;
}
