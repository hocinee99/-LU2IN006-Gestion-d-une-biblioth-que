#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Biblio/LC/biblioLC.h"

Biblio* charger_n_entrees(char* nomfic, int n) {
    FILE *f = fopen(nomfic, "r");
    if (!f) {
        printf("Erreur d'ouverture du fichier");
        return NULL;
    }
    
    Biblio* biblio = creer_biblio();
    if (!biblio) {
        fclose(f);
        return NULL;
    }

    int num;
    char titre[256], auteur[256];

    for (int i = 0; i < n; i++) {
        if (fscanf(f, "%d %255s %255s\n", &num, titre, auteur) != 3) break;
        inserer_en_tete(biblio, num, titre, auteur);
    }

    fclose(f);
    return biblio;
}

void enregistrer_biblio(Biblio *b, char* nomfic){
    FILE *f = fopen(nomfic, "w");
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier\n");
    }
    Livre* tmp = b->L;
        while(tmp){
        fprintf(f,"%d %s %s\n",tmp->num,tmp->titre,tmp->auteur);
        tmp=tmp->suiv;
        }
    fclose(f);
}
