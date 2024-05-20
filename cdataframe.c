#include "column.h"
#include "cdataframe.h"

// Fonction pour créer une colonne (4.1.1)
Colonne *creer_colonne(const char *titre) {
    Colonne *col = malloc(sizeof(Colonne));
    if (col == NULL) return NULL;

    col->titre = strdup(titre);
    col->taille = 0;
    col->taille_max = 10; // Commence avec une capacité initiale de 10
    col->donnees = malloc(col->taille_max * sizeof(int));
    if (col->donnees == NULL) {
        free(col->titre);
        free(col);
        return NULL;
    }
    return col;
}

// Fonction pour insérer une valeur dans une colonne (4.1.2)
void inserer_valeur(Colonne *colonne, int valeur) {
    if (colonne->taille == colonne->taille_max) {
        int *nouvelles_donnees = realloc(colonne->donnees, (colonne->taille_max + 10) * sizeof(int));
        if (nouvelles_donnees == NULL) return;
        colonne->donnees = nouvelles_donnees;
        colonne->taille_max += 10;
    }
    colonne->donnees[colonne->taille++] = valeur;
}

// Fonction pour imprimer le contenu d'une colonne (4.1.4)
void imprimer_colonne(const Colonne *colonne) {
    printf("Colonne: %s\n", colonne->titre);
    for (unsigned int i = 0; i < colonne->taille; i++) {
        printf("[%u] %d\n", i, colonne->donnees[i]);
    }
}

// Fonction pour libérer une colonne de la mémoire (4.1.3)
void supprimer_colonne(Colonne **colonne) {
    if (colonne == NULL || *colonne == NULL) return;
    free((*colonne)->donnees);
    free((*colonne)->titre);
    free(*colonne);
    *colonne = NULL;
}

// Fonction pour compter les occurrences d'une valeur spécifique (4.1.5)
int compter_valeur(const Colonne *colonne, int valeur) {
    int compte = 0;
    for (unsigned int i = 0; i < colonne->taille; i++) {
        if (colonne->donnees[i] == valeur) {
            compte++;
        }
    }
    return compte;
}

// Fonction pour vérifier la valeur à un indice spécifique (4.1.5)
int valeur_a_index(const Colonne *colonne, unsigned int index) {
    if (index < colonne->taille) {
        return colonne->donnees[index];
    } else {
        printf("Index hors limites.\n");
        return -1; // Valeur indicative d'erreur
    }
}

// Fonction pour trouver la valeur maximale dans la colonne (4.1.5)
int trouver_max(const Colonne *colonne) {
    if (colonne->taille == 0) return -1; // Valeur indicative d'erreur si la colonne est vide

    int max = colonne->donnees[0];
    for (unsigned int i = 1; i < colonne->taille; i++) {
        if (colonne->donnees[i] > max) {
            max = colonne->donnees[i];
        }
    }
    return max;
}

// Fonction pour compter les valeurs inférieures à une valeur spécifiée 'x' (4.1.5)
int compter_inferieur_a(const Colonne *colonne, int x) {
    int compte = 0;
    for (unsigned int i = 0; i < colonne->taille; i++) {
        if (colonne->donnees[i] < x) {
            compte++;
        }
    }
    return compte;
}

// Fonction pour compter le nombre de valeurs égales à 'x' (4.1.5)
int compter_egal_a_x(const Colonne *colonne, int x) {
    int compte = 0;
    for (unsigned int i = 0; i < colonne->taille; i++) {
        if (colonne->donnees[i] == x) {
            compte++;
        }
    }
    return compte;
}

// Implémentations des fonctions de Colonne
// Fonction pour créer une nouvelle colonne
Colonne* creer_colonne_cdataframe(const char *titre) {
    Colonne *col = malloc(sizeof(Colonne));
    if (col) {
        col->titre = strdup(titre);
        col->donnees = NULL;
        col->taille = 0;
        col->capacite = 0;
    }
    return col;
}

void inserer_valeur_cdataframe(Colonne *col, int valeur) {
    if (col->taille >= col->capacite) {
        int nouvelle_capacite = col->capacite == 0 ? 4 : col->capacite * 2;
        int *nouvelles_donnees = realloc(col->donnees, nouvelle_capacite * sizeof(int));
        if (!nouvelles_donnees) return;
        col->donnees = nouvelles_donnees;
        col->capacite = nouvelle_capacite;
    }
    col->donnees[col->taille++] = valeur;
}

void imprimer_colonne_cdataframe(const Colonne *col) {
    printf("%s: ", col->titre);
    for (int i = 0; i < col->taille; i++) {
        printf("%d ", col->donnees[i]);
    }
    printf("\n");
}

// Implémentations des fonctions de CDataframe
CDataframe* creer_cdataframe() {
    CDataframe *df = malloc(sizeof(CDataframe));
    if (!df) return NULL;
    df->colonnes = NULL;
    df->nombre_colonnes = 0;
    df->capacite = 0;
    return df;
}

void remplir_cdataframe_avec_saisie(CDataframe *df) {
    if (!df) return;

    int nombreColonnes = 0;
    printf("Entrez le nombre de colonnes a ajouter : ");
    scanf("%d", &nombreColonnes);

    for (int i = 0; i < nombreColonnes; i++) {
        char titre[100];
        printf("Entrez le titre de la colonne %d : ", i + 1);
        scanf("%s", titre);

        Colonne *nouvelleColonne = creer_colonne(titre);
        if (!nouvelleColonne) continue; // Continue en cas d'échec d'allocation de la nouvelle colonne

        int nombreValeurs;
        printf("Entrez le nombre de valeurs pour la colonne '%s' : ", titre);
        scanf("%d", &nombreValeurs);

        for (int j = 0; j < nombreValeurs; j++) {
            int valeur;
            printf("Entrez la valeur %d pour la colonne '%s' : ", j + 1, titre);
            scanf("%d", &valeur);
            inserer_valeur(nouvelleColonne, valeur);
        }

        ajouter_colonne(df, nouvelleColonne);
    }
}

void remplissage_dur_cdataframe(CDataframe *df) {
    if (!df) return;

    // Exemple de données prédéfinies
    Colonne *col1 = creer_colonne("Ma Colonne");
    int valeurs1[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < sizeof(valeurs1) / sizeof(valeurs1[0]); i++) {
        inserer_valeur(col1, valeurs1[i]);
    }
    ajouter_colonne(df, col1);

    Colonne *col2 = creer_colonne("Votre Colonne");
    int valeurs2[] = {5, 15, 25, 35, 45};
    for (int i = 0; i < sizeof(valeurs2) / sizeof(valeurs2[0]); i++) {
        inserer_valeur(col2, valeurs2[i]);
    }
    ajouter_colonne(df, col2);
}

void afficher_cdataframe(const CDataframe *df) {
    for (int i = 0; i < df->nombre_colonnes; i++) {
        imprimer_colonne(df->colonnes[i]);
    }
}

void ajouter_colonne(CDataframe *df, Colonne *col) {
    if (df->nombre_colonnes >= df->capacite) {
        int nouvelle_capacite = df->capacite == 0 ? 4 : df->capacite * 2;
        Colonne **nouvelles_colonnes = realloc(df->colonnes, nouvelle_capacite * sizeof(Colonne *));
        if (!nouvelles_colonnes) return;
        df->colonnes = nouvelles_colonnes;
        df->capacite = nouvelle_capacite;
    }
    df->colonnes[df->nombre_colonnes++] = col;
}

// Fonction pour supprimer une colonne du dataframe par titre
void supprimer_colonne_du_dataframe(CDataframe *df, const char *titre) {
    if (!df || !titre) return;
    for (int i = 0; i < df->nombre_colonnes; i++) {
        if (strcmp(df->colonnes[i]->titre, titre) == 0) {
            // Colonne trouvée, suppression et retrait du tableau
            supprimer_colonne(&(df->colonnes[i]));  // Supposant que supprimer_colonne prend Column**
            // Décalage des colonnes restantes vers la gauche
            for (int j = i; j < df->nombre_colonnes - 1; j++) {
                df->colonnes[j] = df->colonnes[j + 1];
            }
            df->nombre_colonnes--;
            break;
        }
    }
}

// Fonction pour libérer l'ensemble du dataframe
void liberer_cdataframe(CDataframe *df) {
    if (!df) return;
    // Libérer toutes les colonnes
    for (int i = 0; i < df->nombre_colonnes; i++) {
        supprimer_colonne(&(df->colonnes[i]));  // Assurer que cela correspond à la signature attendue
    }
    free(df->colonnes);
    free(df);
}
