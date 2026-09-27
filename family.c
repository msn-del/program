#include <stdio.h>
#include <stdlib.h>

typedef struct date {
    int jour, mois, an;
} date;

typedef struct personne {
    char nom[100], prenom[100];
    date datedn;
} personne;

typedef struct famille {
    personne P[20];
    int n;
} famille;

// Saisir les membres d'une famille
void saisirfamille(famille *f)
{
    printf("\nSaisir le nombre des membres: ");
    scanf("%d", &f->n);

    for (int i = 0; i < f->n; i++) {
        printf("\n--- Membre numéro %d ---", i + 1);

        printf("\nNom: ");
        scanf("%s", f->P[i].nom);

        printf("Prénom: ");
        scanf("%s", f->P[i].prenom);

        printf("Jour de naissance: ");
        scanf("%d", &f->P[i].datedn.jour);

        printf("Mois de naissance: ");
        scanf("%d", &f->P[i].datedn.mois);

        printf("Année de naissance: ");
        scanf("%d", &f->P[i].datedn.an);
    }
}

// Trier les membres de la famille selon la date de naissance (du plus vieux au plus jeune)
void classerfamille(int n, famille *f)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            date d1 = f->P[i].datedn;
            date d2 = f->P[j].datedn;

            if (d1.an > d2.an ||
                (d1.an == d2.an && d1.mois > d2.mois) ||
                (d1.an == d2.an && d1.mois == d2.mois && d1.jour > d2.jour)) {
                // Échanger les personnes
                personne tmp = f->P[i];
                f->P[i] = f->P[j];
                f->P[j] = tmp;
            }
        }
    }
}

// Afficher une seule personne
void afficherpersonne(personne f)
{
    printf("%s %s né le %02d/%02d/%04d\n", f.nom, f.prenom, f.datedn.jour, f.datedn.mois, f.datedn.an);
}

// Afficher toute la famille
void afficherfamille(int n, famille f)
{
    printf("\n--- Liste des membres classés ---\n");
    for (int i = 0; i < n; i++) {
        afficherpersonne(f.P[i]);
    }
}

// Programme principal
int main()
{
    famille X;

    saisirfamille(&X);
    classerfamille(X.n, &X);
    afficherfamille(X.n, X);

    return 0;
}
