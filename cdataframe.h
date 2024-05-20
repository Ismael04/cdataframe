#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"  // Inclure la définition de Column

// Structure CDataframe
typedef struct {
    Colonne **colonnes;    // Tableau de pointeurs vers des Colonnes
    int nombre_colonnes;  // Nombre de colonnes
    int capacite;         // Capacité du dataframe (pour le redimensionnement dynamique)
} CDataframe;

// Prototypes des fonctions pour CDataframe
CDataframe* creer_cdataframe(void);
void remplir_cdataframe_avec_saisie(CDataframe *df);
void remplissage_dur_cdataframe(CDataframe *df);
void afficher_cdataframe(const CDataframe *df);
void ajouter_colonne(CDataframe *df, Colonne *col);
void supprimer_colonne_du_dataframe(CDataframe *df, const char *titre);
void liberer_cdataframe(CDataframe *df);

#endif //CDATAFRAME_H
