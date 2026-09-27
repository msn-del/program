#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define bleu "\033[1;36m"
#define reset "\033[0m"

typedef struct etud {
    int id;
    char nom[50];
    float moyenne;
} etud;

typedef struct liste {
    etud etu;
    struct liste *next;
} liste;

liste *head = NULL;

void ajouter_etudiant(etud e)
{
    liste *nouveau = (liste*)malloc(sizeof(liste));
    if (nouveau == NULL) {
        printf("Probleme d'allocation..\n");
        exit(1);
    }
    nouveau->etu = e;
    nouveau->next = NULL;
    if (head == NULL) {
        head = nouveau;
        return;
    }
    liste *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nouveau;
}

void afficher_liste()
{
    liste *temp = head;
    int index = 1;
    while (temp != NULL) {
        printf(bleu"[Etudiant %d] id : %d \t nom : %s \t moyenne : %.2f\n"reset,
               index, temp->etu.id, temp->etu.nom, temp->etu.moyenne);
        index++;
        temp = temp->next;
    }
    printf("\n");
}

etud rechercher(int id)
{
    etud e;
    e.id = -1;
    liste *temp = head;
    while (temp != NULL) {
        if (temp->etu.id == id) {
            return temp->etu;
        }
        temp = temp->next;
    }
    return e;
}

void afficher_plus_10()
{
    liste *temp = head;
    while (temp != NULL) {
        if (temp->etu.moyenne > 10.0) {
            printf(bleu"id : %d \t nom : %s \t moyenne : %.2f\n"reset,
                   temp->etu.id, temp->etu.nom, temp->etu.moyenne);
        }
        temp = temp->next;
    }
}

int main()
{
    int choix;
    do {
        printf("(1) ajouter un etudiant :\n");
        printf("(2) afficher la liste des etudiants :\n");
        printf("(3) chercher un etudiant :\n");
        printf("(4) afficrher les etudiant a moyenne plus que 10 :\n");
        printf("entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: {
                etud e;
                printf("ID : ");
                scanf("%d", &e.id);
                printf("NOM : ");
                scanf("%s", e.nom);
                printf("MOYENNE : ");
                scanf("%f", &e.moyenne);
                ajouter_etudiant(e);
                break;
            }
            case 2:
                afficher_liste();
                break;
            case 3: {
                int id;
                printf("entrez ID d'etudiant que vous cherchez : \n");
                scanf("%d", &id);
                etud chercher = rechercher(id);
                if (chercher.id == -1) {
                    printf("aucun element n'a ete trouve \n");
                } else {
                    printf(bleu"id : %d \t nom : %s \t moyenne : %.2f\n"reset,
                           chercher.id, chercher.nom, chercher.moyenne);
                }
                break;
            }
            case 4:
                afficher_plus_10();
                break;
            default:
                break;
        }
    } while (choix >= 1 && choix <= 4);

    return 0;
}
