#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxEtudiants 100
#define maxLen 50
#define dateLen 15

int numeroUnique[maxEtudiants];
char nom[maxEtudiants][maxLen];
char prenom[maxEtudiants][maxLen];
char dateNaissance[maxEtudiants][dateLen];
char departement[maxEtudiants][maxLen];
float noteGenerale[maxEtudiants];

int count = 0;
int ID = 1;

void ajouterEtudiant()
{
  if (count < maxEtudiants)
  {
    numeroUnique[count] = ID++;
    printf("Entrer le nom de l'etudiant : ");
    scanf("%s", nom[count]);
    printf("Entrer le prenom de l'etudiant : ");
    scanf("%s", prenom[count]);
    printf("Entrer la date de naissance (jj/mm/aaaa) : ");
    scanf("%s", dateNaissance[count]);
    do
    {
      printf("Entrer le departement ('SMI','SMA','SP'): ");
      scanf("%s", departement[count]);
    } while (strcmp(departement[count], "SMI") != 0 && strcmp(departement[count], "SMA") != 0 && strcmp(departement[count], "SP") != 0);
    do
    {
      printf("Entrer la note generale (entre 0 et 20) : ");
      scanf("%f", &noteGenerale[count]);
    } while (noteGenerale[count] < 0 || noteGenerale[count] > 20);
    count++;
    printf("Etudiant ajoute avec succes avec le numero unique: %d\n", numeroUnique[count - 1]);
  }
  else
  {
    printf("limite d'etudiants atteinte!\n");
  }
}

void afficherTousEtudiant()
{
  int i;
  if (count == 0)
  {
    printf("Aucun etudiant enregistre.\n");
  }
  printf("\n--- Liste des etudiants ---\n");
  for (i = 0; i < count; i++)
  {
    printf("%d.%s %s\n\t(Numero : %d, Departement : %s, Date de naissance : %s, Note generale : %.2f)\n", i + 1, nom[i], prenom[i], numeroUnique[i], departement[i], dateNaissance[i], noteGenerale[i]);
  }
}

void modifierEtudiant(int numero)
{
  int i;
  for (i = 0; i < count; i++)
  {
    if (numero == numeroUnique[i])
    {
      printf("Modifier les informations pour l'etudiant %d\n", numero);
      printf("Entrer le nouveau nom: ");
      scanf("%s", nom[i]);
      printf("Entrer le nouveau prenom: ");
      scanf("%s", prenom[i]);
      printf("Entrer le nouvelle date de naissance (jj/mm/aaaa): ");
      scanf("%s", dateNaissance[i]);
      do
      {
        printf("Entrer le nouveau departement ('SMI','SMA','SP'): ");
        scanf("%s", departement[count]);
      } while (strcmp(departement[count], "SMI") != 0 && strcmp(departement[count], "SMA") != 0 && strcmp(departement[count], "SP") != 0);
      do
      {
        printf("Entrer la nouvelle note generale (entre 0 et 20) : ");
        scanf("%f", &noteGenerale[count]);
      } while (noteGenerale[count] < 0 || noteGenerale[count] > 20);

      printf("Etudiant modifie avec succes!");
    }
  }
  printf("Etudiant non trouve!");
}

void supprimerEtudiant(int numero){
  int i, j;
  for (i = 0; i < count; i++){
    if (numeroUnique[i] == numero){
      for(j = i; j < count - 1; j++){
        numeroUnique[j] = numeroUnique[j + 1];
        strcpy(nom[j], nom[j + 1]);
        strcpy(prenom[j], prenom[j + 1]);
        strcpy(dateNaissance[j], dateNaissance[j + 1]);
        strcpy(departement[j], departement[j + 1]);
      }
      count--;
      printf("Etudiant supprime avec succe!\n");
    }
  }
}

void calculerMoyenneGenerale(){
  if (count == 0){
    printf("Aucun etudiant enregistre.\n");
  }
  float sommeNotesUniversite = 0.0;
  int nbEtudiantsUniversite = 0;
  char departements[maxEtudiants][maxLen];
  int totalDepartements = 0;
  int i,j;
  for(i = 0; i < count; i++){
    int trouve = 0;
    for (j = 0; j < totalDepartements; j++){
      if(strcmp(departements[j], departement[i]) == 0){
        trouve = 1;
        break;
      }
    }
    if(trouve == 0){
      strcpy(departements[totalDepartements], departement[i]);
      totalDepartements++;
    }
  }
  for(i = 0; i < totalDepartements; i++){
    float sommeNotesDepartement = 0.0;
    int nbEtudiantsDepartement = 0;
    for(j = 0; j < count; j++){
      if(strcmp(departement[j], departements[i]) == 0){
        sommeNotesDepartement += noteGenerale[j];
        nbEtudiantsDepartement++;
      }
    }
    if (nbEtudiantsDepartement > 0){
      printf("La moyenne generale du departement %s est : %.2f\n",departements[i], sommeNotesDepartement / nbEtudiantsDepartement);
      sommeNotesUniversite += sommeNotesDepartement;
      nbEtudiantsUniversite += nbEtudiantsDepartement;
    }
  }

  if(nbEtudiantsUniversite > 0){
    printf("La moyenne generale de l'universite est : %.2f\n",
    sommeNotesUniversite / nbEtudiantsUniversite);
  }
}



void menu()
{
  int choix, numero;
  do
  {
    printf("\n--- Menu principal ---\n");
    printf("1 . Ajouter un etudiant\n");
    printf("2 . Afficher tous les etudiants\n");
    printf("3 . Modifier un etudiant\n");
    printf("4 . supprimer un etudient\n");
    printf("5 . Calculer la moyenne generale\n");
    printf("6 . Rechercher un etudiant par nom\n");
    printf("7 . Afficher les etudiant par departement\n");
    printf("8 . Quitter\n");
    printf("Choisissez une option : ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
      system("cls");
      ajouterEtudiant();
      break;
    case 2:
      system("cls");
      afficherTousEtudiant();
      break;
    case 3:
      system("cls");
      printf("Entrer le numero unique de l'etudiant a modifier : ");
      scanf("%d", &numero);
      modifierEtudiant(numero);
      break;
    case 4:
      system("cls");
      printf("Entrer le numero unique de l'etudiant a supprimer : ");
      scanf("%d", &numero);
      supprimerEtudiant(numero);
      break;
    case 5:
      system("cls");
      calculerMoyenneGenerale();
      break;
    }
  } while (choix != 8);
}
int main()
{
  menu();
}
