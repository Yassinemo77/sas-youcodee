#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct etudiants{
    int id;
    char nom[100];
    char prenom[100];
    char dateDeNaissance[100];
    char departement[100];
    float noteGenerale;
};

void menu();
void ajouter();
int rechercherParId();

void supprimer();
void modifier();
void affichage();
void moyenneGenerale();
void nbrTotal();
void nbrChaqueDep();
void seuil();
void troisBestNotes();
void nbrReussi();
void rechercherParLeNom();
void listeAmieChaqueDepartement();
void triAlphabitique();
void triMoyenne();
void triReussi();
#endif
