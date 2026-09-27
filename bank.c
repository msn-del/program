#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct compte
{
    int num;
    char nom[50];
    float solde;
    struct compte *suivant;
} compte;

compte *head = NULL;

void ajouter()
{
    compte *nouveau = (compte *) malloc(sizeof(compte));
    if (nouveau == NULL)
    {
        printf("\nErreur d'allocation memoire.\n");
        return;
    }

    printf("\nEntrer le numero du compte : ");
    scanf("%d", &nouveau->num);

    printf("Entrer le nom du titulaire : ");
    scanf(" %49[^\n]", nouveau->nom);

    printf("Entrer le solde initial : ");
    scanf("%f", &nouveau->solde);

    nouveau->suivant = head;
    head = nouveau;

    printf("\nLe compte a ete ajoute avec succes.\n");
}

compte *rechercher()
{
    int rech;
    compte *temp = head;

    printf("\nSaisir le numero de compte a rechercher : ");
    scanf("%d", &rech);

    while (temp != NULL)
    {
        if (temp->num == rech)
        {
            printf("\nCompte trouve :\n");
            printf("Numero : %d\n", temp->num);
            printf("Nom    : %s\n", temp->nom);
            printf("Solde  : %.2f\n", temp->solde);
            return temp;
        }
        temp = temp->suivant;
    }

    printf("\nCe compte n'existe pas.\n");
    return NULL;
}

void supprimer(compte *x)
{
    int rech;
    compte *temp1 = head;
    compte *temp2 = NULL;

    printf("\nsaisir le numero de compte que vous voulez supprimer : ");
    scanf("%d", &rech);

    while (temp1 != NULL)
    {
        if (temp1->num == rech)
        {
            if (temp2 == NULL)
            {
                head = temp1->suivant;
            }
            else
            {
                temp2->suivant = temp1->suivant;
            }
            free(temp1);
            printf("\n le compte a ete supprime.\n");
            return;
        }
        temp2 = temp1;
        temp1 = temp1->suivant;
    }
    printf("\nce compte n'existe pas.\n");
}

void afficher()
{
    compte *temp = head;

    if (temp == NULL)
    {
        printf("\nAucun compte enregistre.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "Numero", "Nom", "Solde");
    printf("--------------------------------------------\n");
    while (temp != NULL)
    {
        printf("%-10d %-20s %-10.2f\n", temp->num, temp->nom, temp->solde);
        temp = temp->suivant;
    }
}

void tran(compte *x)
{
    int rech;
    char type;
    float montant;
    compte *temp = head;

    printf("\nSaisir le numero de compte : ");
    scanf("%d", &rech);

    while (temp != NULL && temp->num != rech)
    {
        temp = temp->suivant;
    }

    if (temp == NULL)
    {
        printf("\nCe compte n'existe pas.\n");
        return;
    }

    printf("Depot (d) ou retrait (r) ? ");
    scanf(" %c", &type);

    printf("Montant : ");
    scanf("%f", &montant);

    if (type == 'd' || type == 'D')
    {
        temp->solde += montant;
        printf("\nDepot effectue. Nouveau solde : %.2f\n", temp->solde);
    }
    else if (type == 'r' || type == 'R')
    {
        if (montant > temp->solde)
        {
            printf("\nSolde insuffisant.\n");
        }
        else
        {
            temp->solde -= montant;
            printf("\nRetrait effectue. Nouveau solde : %.2f\n", temp->solde);
        }
    }
    else
    {
        printf("\nOperation invalide.\n");
    }
}

void libererTout()
{
    compte *temp = head;
    while (temp != NULL)
    {
        compte *suivant = temp->suivant;
        free(temp);
        temp = suivant;
    }
    head = NULL;
}

int main(void)
{
    int choix;

    do
    {
        printf("\n===== GESTION DE COMPTES BANCAIRES =====\n");
        printf("1. Ajouter un compte\n");
        printf("2. Supprimer un compte\n");
        printf("3. Rechercher un compte (voir le solde)\n");
        printf("4. Afficher tous les comptes\n");
        printf("5. Effectuer une transaction (depot/retrait)\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                ajouter();
                break;
            case 2:
                supprimer(head);
                break;
            case 3:
                rechercher();
                break;
            case 4:
                afficher();
                break;
            case 5:
                tran(head);
                break;
            case 0:
                printf("\nAu revoir !\n");
                break;
            default:
                printf("\nChoix invalide.\n");
        }

    } while (choix != 0);

    libererTout();
    return 0;
}
