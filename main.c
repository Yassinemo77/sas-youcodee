#include "functions.h"

int main() {
      int choix;
      do{
        menu();
          printf("entrer un choix : ");
          scanf("%d",&choix);

        switch(choix){
                case 1 :
                    ajouter();
                    break;
                case 2 :
                    modifier();
                    break;
                case 3 :
                    supprimer();
                    break;
                 case 4 :
                    affichage();
                    break;
                case 5 :
                    moyenneGenerale();
                    break;

                    int statisticChoix;
                case 6 :
                    do{
                        printf("\t 1- Afficher le nombre total d'etudiants inscrits. \n");
                        printf("\t 2- Afficher le nombre d'etudiants dans chaque departement. \n");
                        printf("\t 3- Afficher les etudiants ayant une moyenne generale superieure a un certain seuil. \n");
                        printf("\t 4- Afficher les 3 etudiants ayant les meilleures notes. \n");
                        printf("\t 5- Afficher le nombre d'etudiants ayant reussi dans chaque departement \n");

                        printf("choisir un choix : \n");
                        scanf("%d",&statisticChoix);

                        switch(statisticChoix){
                        case 1 :
                            nbrTotal();
                            break;

                        case 2 :
                            nbrChaqueDep();
                            break;

                        case 3 :
                            seuil();
                            break;

                        case 4 :
                            troisBestNotes();
                            break;
                        case 5 :
                            nbrReussi();
                            break;            }
                    }while(statisticChoix < 1);
                    break;

                case 7 :
                    rechercherParLeNom();
                    break;

                case 8 :
                    listeAmieChaqueDepartement();
                    break;
                case 9 :
                    triAlphabitique();
                break;

                case 10 :
                    triMoyenne();
                break;

                 case 11 :
                    triReussi();
                break;
                }

    }while(choix < 12);

return 0;
}
