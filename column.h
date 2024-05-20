#ifndef COLUMN_H
#define COLUMN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour une colonne
typedef struct {
    char *titre;         // Titre de la colonne
    int *donnees;        // Pointeur vers un tableau d'entiers
    int capacite;
    unsigned int taille; // Taille logique de la colonne
    unsigned int taille_max; // Taille physique du tableau
} Colonne;

// Déclarations de fonctions
Colonne *creer_colonne(const char *titre);
void inserer_valeur(Colonne *colonne, int valeur);
void imprimer_colonne(const Colonne *colonne);
void supprimer_colonne(Colonne **colonne);

// Fonctionnalités supplémentaires
int compter_valeur(const Colonne *colonne, int valeur); // Compte les occurrences d'une valeur
int valeur_a_index(const Colonne *colonne, unsigned int index); // Retourne la valeur à un indice donné
int trouver_max(const Colonne *colonne); // Trouve la valeur maximale dans la colonne
int compter_inferieur_a(const Colonne *colonne, int x); // Compte les valeurs inférieures à x
int compter_egal_a_x(const Colonne *colonne, int x); // Compte les valeurs égales à x

#endif
