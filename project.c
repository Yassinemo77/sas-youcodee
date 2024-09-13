#include "functions.h"

struct etudiants etudiant[100];
int idCounter = 0;
int numEtediant = 0;

void menu(){
    printf("************************************************\n");
    printf("\t 1- Ajouter un etudiant. \n");
    printf("\t 2- modifier un etudiant. \n");
    printf("\t 3- supprimer un etudiant. \n");
    printf("\t 4- afficher  les informations completes des etudiants. \n");
    printf("\t 5- Calculer la moyenne generale. \n");
    printf("\t 6- afficher les statistiques. \n");
    printf("\t 7- Rechercher un etudiant par son nom. \n");
    printf("\t 8- Afficher la liste des etudiants inscrits dans un departement specifique. \n");
    printf("\t 9- Tri alphabetique des etudiants en fonction de leur nom (de A à Z ou de Z à A). \n");
    printf("\t 10- Tri des etudiants par moyenne generale, du plus eleve au plus faible ou inversement.  \n");
    printf("\t 11- Tri des etudiants selon leur statut de reussite .  \n");

}

void ajouter(){
    printf("entrer votre nom : ");
    scanf(" %[^\n]s",&etudiant[numEtediant].nom);

    printf("nentrer votre prenom : ");
    scanf(" %[^\n]s",&etudiant[numEtediant].prenom);

    printf("entrer la date de naissance (D/M/Y): ");
    scanf(" %[^\n]s",&etudiant[numEtediant].dateDeNaissance);

    printf("entrer la departement : ");
    scanf(" %[^\n]s",&etudiant[numEtediant].departement);

    printf("entrer la note generale : ");
    scanf("%f",&etudiant[numEtediant].noteGenerale);

    etudiant[numEtediant].id = idCounter++;

    numEtediant++;
}

int rechercherParId(){
    int idsup;
    printf("entrer ID de element supprimer : ");
    scanf("%d",&idsup);

    for(int i = 0 ; i < numEtediant ; i++ ){
        if(etudiant[i].id == idsup ){
                return i;
            }
    }
                return -1;
}

void supprimer(){
int index = rechercherParId();

int isDelete = 0;

        if ( index == -1 ){
                printf("ID introuvable");
            return;
        }
        for(int j = index ; j < numEtediant ; j++ ){
            etudiant[j] = etudiant[j + 1];
        }
        numEtediant--;


}

void modifier(){
    int idupdate;
    printf("entrer ID : "); scanf("%d",&idupdate);

int m = 0;

for(int j = 0 ; j < numEtediant ; j++){
    if(etudiant[j].id == idupdate){
        printf("entrer votre nom : ");
        scanf(" %[^\n]s",&etudiant[j].nom);

        printf("nentrer votre prenom : ");
        scanf(" %[^\n]s",&etudiant[j].prenom);

        printf("entrer la date de naissance (D/M/Y): ");
        scanf(" %[^\n]s",&etudiant[j].dateDeNaissance);

        printf("entrer la nouvelle departement : ");
        scanf(" %[^\n]s",&etudiant[j].departement);

        printf("entrer la note generale : ");
        scanf("%f",&etudiant[j].noteGenerale);
            m++;
    }
}if(m == 0){
    printf("eleve not found");
    }
}

void affichage(){

    for(int j = 0 ; j < numEtediant ; j++ ){
            printf("************ ELEVE N : %d ************\n", j+ 1);

            printf("le nom : %s \n", etudiant[j].nom);

            printf("entrer votre prenom : %s \n",etudiant[j].prenom);

            printf("entrer la date de naissance : %s \n", etudiant[j].dateDeNaissance);

            printf("entrer la departement : %s \n",etudiant[j].departement);

            printf("entrer la note generale : %.2f \n", etudiant[j].noteGenerale);

            printf("id: %d \n", etudiant[j].id);
    }
}
void moyenneGenerale(){
    char T[20][50];
    int counter = 0 ;
    int alreadyEntred = 0;

 // liste departement
  for (int i = 0; i < numEtediant; i++){
    alreadyEntred = 0;
      for(int j = 0 ; j < numEtediant ; j++ ){
            if(strcmp(etudiant[i].departement , T[j]) == 0){
                alreadyEntred = 1;
                break;
            }
        }
        if(!alreadyEntred){
                strcpy(T[counter] , etudiant[i].departement);
                counter++;
        }
  }
  // moyene generale
    float sommeChaqueDepartemet = 0;
  for(int i = 0 ; i < counter ; i++){
        float somme = 0;
        float lenghEleve = 0;

        printf("-----------------------------  \n");
        printf("moyenne generale de la departement : %s \n", T[i]);


        for(int j = 0 ; j < numEtediant ; j++ ){
            if(strcmp( T[i], etudiant[j].departement ) == 0){ // kal9aw nfss departement
                somme += etudiant[j].noteGenerale;
                lenghEleve++;
            }
        }
    printf("la somme generale : %.2f \n", somme);
    printf("la meyenne generale : %.2f \n", somme / lenghEleve);

    // somme moyennt genrale de chaque departemet
    sommeChaqueDepartemet += somme / lenghEleve;
  }

    printf("la meyenne generale la universite  : %.2f \n", sommeChaqueDepartemet / counter);
}
 // start afficher les statistic :

 void nbrTotal(){
     printf("le nombre total d'etudiants inscrits : %d \n", numEtediant);

 }

 void nbrChaqueDep(){

    char T[20][50];
    int index = 0;
    int isFound = 0;

    for(int i = 0 ; i < numEtediant ; i ++ ){
        isFound = 0;
        for(int j = 0 ; j < numEtediant ; j++){
            if(strcmp(etudiant[i].departement, T[j] ) == 0 ){
                isFound = 1;
                break;
            }
        }
        if(!isFound){
            strcpy(T[index], etudiant[i].departement);
            index++;
        }
    }

    for(int i = 0 ; i < index ; i++){
            int somme = 0;

        printf("------------------------------------- \n");

        printf("le nombre totale de departement %s : \n", T[i]);
        for(int j = 0 ; j < numEtediant ; j++){
                if(strcmp(T[i], etudiant[j].departement ) == 0 ){
                   somme++;
                }
        }

        printf("le nombre totale est : %d \n", somme);
    }
}

 void seuil(){
     int sup ;
     printf("Entrez le seuil de la moyenne generale : ");
     scanf("%d",&sup);

     int noteSup = 0;

    for(int i = 0 ; i < numEtediant ; i++){
            printf("eleve N: %d supperieur au 14 : \n",noteSup + 1);
        if( etudiant[i].noteGenerale >= sup ){
            printf("------------------------------------------------- \n");

            printf("nome : %s \n",etudiant[i].nom);
            printf("prenom : %s \n",etudiant[i].prenom);
            printf("la notes  : %.2f \n",etudiant[i].noteGenerale);
            noteSup++;
        }
    }

    if(noteSup == 0){
     printf("aucun eleve n'est superieure au seuil. \n");
    }
 }

 void troisBestNotes(){
    int max1_idx , max2_idx, max3_idx;
    max1_idx = max2_idx = max3_idx = 0;

   for(int i = 0 ; i < numEtediant ; i++){
       if(etudiant[max1_idx].noteGenerale < etudiant[i].noteGenerale ){
        max3_idx = max2_idx;
        max2_idx = max1_idx;
        max1_idx = i;
       }else if (etudiant[max1_idx].noteGenerale > etudiant[max2_idx].noteGenerale
                 && etudiant[max2_idx].noteGenerale < etudiant[i].noteGenerale ){
                   max3_idx = max2_idx;
                   max2_idx = i;

       }else if (etudiant[max1_idx].noteGenerale > etudiant[max2_idx].noteGenerale
             && etudiant[max2_idx].noteGenerale > etudiant[max3_idx].noteGenerale
             && etudiant[max3_idx].noteGenerale < etudiant[i].noteGenerale ){
             max3_idx = i;
       }
 }
 printf("La meilleure note 1  : %s , la note %.2f : \n",etudiant[max1_idx].nom ,etudiant[max1_idx].noteGenerale);
 printf("La meilleure note 2  : %s , la note %.2f : \n",etudiant[max2_idx].nom ,etudiant[max2_idx].noteGenerale);
 printf("La meilleure note 3  : %s , la note %.2f : \n",etudiant[max3_idx].nom ,etudiant[max3_idx].noteGenerale);

 }

 void nbrReussi(){
    char T[20][50];
    int isFound;
    int index;
    index = 0;

    for(int i = 0 ; i < numEtediant ; i++ ){
            isFound = 0;
        for(int j = 0 ; j < numEtediant ; j++){
            if( strcmp(etudiant[i].departement, T[j]) == 0 ){
                isFound++;
                break;
            }
        }
        if(!isFound){
            strcpy(T[index] ,etudiant[i].departement );
            index++;
        }
    }

    int sommeNbrRe;
    for(int i = 0 ; i < index ; i++){
        sommeNbrRe = 0;
        printf("------------------------------------ \n");

        for(int j = 0 ; j < numEtediant ; j++){
            if( strcmp(T[i] , etudiant[j].departement) == 0 && etudiant[j].noteGenerale >= 10 ){
                     sommeNbrRe++;
                }
        }
            printf("le nombre d'etudiants ayant reussi dans la departement %s de : %d \n",etudiant[i].departement , sommeNbrRe);
    }
 }
 // end of statisctic
 void rechercherParLeNom(){
    char name[100];
    printf("entrer le nom de l'etudiant: ");
    scanf("%s",&name);

int m = 0;

for(int j = 0 ; j < numEtediant ; j++){
    int res = strcmp(etudiant[j].nom, name);

    if(res == 0){
            printf("----------------------------------------- \n");

            printf("le nom : %s \n", etudiant[j].nom);

            printf("entrer votre prenom : %s \n",etudiant[j].prenom);

            printf("entrer la date de naissance : %s \n", etudiant[j].dateDeNaissance);

            printf("entrer la departement : %s \n",etudiant[j].departement);

            printf("entrer la note generale : %.2f \n", etudiant[j].noteGenerale);

            printf("id: %d \n", etudiant[j].id);
             m++;
    }
}
    if(m == 0){
        printf("Eleve non trouve \n");
    }
}

 void listeAmieChaqueDepartement(){
   char T[20][50];
    int index = 0;
    int isFound = 0;

    for(int i = 0 ; i < numEtediant ; i ++ ){
        isFound = 0;
        for(int j = 0 ; j < numEtediant ; j++){
            if(strcmp(etudiant[i].departement, T[j] ) == 0 ){
                isFound = 1;
                break;
            }
        }
        if(!isFound){
            strcpy(T[index], etudiant[i].departement);
            index++;
        }
    }

    for(int i = 0 ; i < index ; i++){
        isFound = 0;
        printf("------------------------------ \n");
        printf("liste de departement : %s \n", T[i]);
        printf("------------------------------ \n");

        printf("eleve N : %d \n", i+1 );

        for(int j = 0 ; j < numEtediant ; j++){
            if(strcmp(T[i], etudiant[j].departement) == 0){
                printf("le nom : %s \n", etudiant[j].nom);
                printf("le prenom  : %s \n", etudiant[j].prenom);
                printf("la date de naissance : %s \n", etudiant[j].dateDeNaissance);
                printf("la note generale : %.2f \n", etudiant[j].noteGenerale);
                printf("------------------------------ \n");
            }
        }
    }
 }

 void triAlphabitique() {
    struct etudiants tmp;
    for(int i = 0; i < numEtediant - 1; i++) {
        for(int x = 0; x < numEtediant - i - 1; x++) {
            if(strcmp(etudiant[x].nom, etudiant[x + 1].nom) > 0) {
                tmp = etudiant[x];
                etudiant[x] = etudiant[x + 1];
                etudiant[x + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < numEtediant; i++) {
        printf("**************************\n");
        printf("Nom: %s\n", etudiant[i].nom);
        printf("Prenom: %s\n", etudiant[i].prenom);
        printf("Departement: %s\n", etudiant[i].departement);
        printf("Note generale: %.2f\n", etudiant[i].noteGenerale);
        printf("Date de naissance: %d/%d/%d\n", etudiant[i].dateDeNaissance, etudiant[i].dateDeNaissance, etudiant[i].dateDeNaissance);
        printf("| ID: >%d<|\n", etudiant[i].id);
    }
 }

 void triMoyenne(){
     struct etudiants tmp;
     for(int i = 0 ; i < numEtediant - 1 ; i++ ){
        for(int j = 0 ; j < numEtediant - i - 1 ; j++){
            if(etudiant[i].noteGenerale < etudiant[i + 1].noteGenerale  ){
                tmp = etudiant[i];
                etudiant[i] = etudiant[i + 1];
                etudiant[i + 1] = tmp;
            }
        }
     }
     for (int i = 0; i < numEtediant; i++) {
            printf("**************************\n");
            printf("Nom: %s\n", etudiant[i].nom);
            printf("Prenom: %s\n", etudiant[i].prenom);
            printf("Departement: %s\n", etudiant[i].departement);
            printf("Note generale: %.2f\n", etudiant[i].noteGenerale);
            printf("Date de naissance: %d/%d/%d\n", etudiant[i].dateDeNaissance, etudiant[i].dateDeNaissance, etudiant[i].dateDeNaissance);
            printf("| ID: %d \n", etudiant[i].id);
        }
 }

 void triReussi(){
    struct etudiants temp;
    for(int i = 0 ; i < numEtediant - 1 ; i++){

        for(int j = 0 ; j < numEtediant - i - 1; j++){
            if(etudiant[j].noteGenerale < etudiant[j + 1].noteGenerale ){
             temp =   etudiant[j];
             etudiant[j] = etudiant[j + 1];
             etudiant[j + 1] = temp;
            }
        }
    }
printf("************ LES ELEVES RESUSSI **************\n");
    for (int i = 0; i < numEtediant; i++) {
        if(etudiant[i].noteGenerale >= 10 ){
        printf("Nom: %s\n", etudiant[i].nom);
        printf("Prenom: %s\n", etudiant[i].prenom);
        printf("Departement: %s\n", etudiant[i].departement);
        printf("Note generale: %.2f\n", etudiant[i].noteGenerale);
        printf("Date de naissance: %d/%d/%d\n", etudiant[i].dateDeNaissance, etudiant[i].dateDeNaissance, etudiant[i].dateDeNaissance);
        printf("| ID: %d |\n", etudiant[i].id);
        printf("**************************\n");

        }
    }
}
