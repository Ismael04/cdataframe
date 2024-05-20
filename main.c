#include "column.h"
#include "cdataframe.h"

int main() {
    // Test des opérations individuelles sur les colonnes
    printf("Test des operations individuelles sur les colonnes :\n");
    Colonne *ma_col = creer_colonne("Ma colonne");
    inserer_valeur(ma_col, 10);
    inserer_valeur(ma_col, 20);
    inserer_valeur(ma_col, 10);
    inserer_valeur(ma_col, 30);
    imprimer_colonne(ma_col);

    // Affichage de diverses statistiques et comptages
    printf("Occurrences de 10 : %d\n", compter_valeur(ma_col, 10));
    printf("Valeur a l'index 1 : %d\n", valeur_a_index(ma_col, 1));
    printf("Valeur maximale : %d\n", trouver_max(ma_col));
    printf("Nombre de valeurs inferieur a 15 : %d\n", compter_inferieur_a(ma_col, 15));
    printf("Nombre de valeurs egale a 10 : %d\n", compter_egal_a_x(ma_col, 10));

    // Nettoyage de la mémoire pour la Colonne
    supprimer_colonne(&ma_col);

    // Test des opérations sur le dataframe
    printf("\n Test des operations sur le dataframe :\n");
    CDataframe *df = creer_cdataframe();

    printf("Remplissage du dataframe avec des saisies utilisateur :\n");
    remplir_cdataframe_avec_saisie(df);
    afficher_cdataframe(df);

    liberer_cdataframe(df);
    df = creer_cdataframe();

    printf("\nRemplissage du dataframe avec des donnees predefinies :\n");
    remplissage_dur_cdataframe(df);
    afficher_cdataframe(df);

    liberer_cdataframe(df);
    return 0;
}
