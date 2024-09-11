#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 100

int main()
{
  int Id;
  char nom[50];
  char prenom[50];
  char date_naissance[15];
  char departement[30];
  float note_generale;
  int choix, numero;
  int count = 0;
  while (1)
  {
    printf("\n--- Menu principal ---\n");
    printf("1. Ajouter un étudiant\n");
    printf("2. Afficher un étudiant\n");
    printf("3. Calculer la moyenne générale\n");
    printf("4. Afficher tous les étudiants\n");
    printf("5. Quitter\n");
    printf("Choisissez une option : ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
      if (count < MAX_ETUDIANTS)
      {
        printf("Entrer le numéro unique de l'étudiant : ");
        scanf("%d", &Id);
        printf("Entrer le nom de l'étudiant : ");
        scanf("%s", nom);
        printf("Entrer le prénom de l'étudiant : ");
        scanf("%s", prenom);
        printf("Entrer la date de naissance (jj/mm/aaaa) : ");
        scanf("%s", date_naissance);
        printf("Entrer le département : ");
        scanf("%s", departement);
        printf("Entrer la note générale : ");
        scanf("%f", note_generale);

        count++;
        printf("Étudiant ajouté avec succès!\n");
      }
      else
      {
        printf("Limite d'étudiants atteinte!\n");
      }
      break;
    case 2:
      printf("Entrer le numéro unique de l'étudiant : ");
      scanf("%d", &numero);
      afficher_etudiant(numero);
      break;
    case 3:
      calculer_moyenne_generale();
      break;
    case 4:
      afficher_tous_etudiants();
      break;
    case 5:
      exit(0);
    default:
      printf("Option invalide!\n");
    }
  }
}
