/*
Boukhemza Hocine 21327665
Kaouane Walid
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioH.h"

BiblioH* charger_n_entreesH(char* nomfic, int n) {
    FILE *f = fopen(nomfic, "r");
    if (!f) {
        printf("Erreur d'ouverture du fichier");
        return NULL;
    }
    BiblioH* biblio = creer_biblioH(n);
    if (!biblio) {
        fclose(f);
        return NULL;
    }

    int num;
    char titre[256], auteur[256];

    for (int i = 0; i < n; i++) {
        if (fscanf(f, "%d %255s %255s\n", &num, titre, auteur) != 3) break;
        inserer(biblio, num, titre, auteur);
    }

    fclose(f);
    return biblio;
}

void enregistrer_biblioH(BiblioH *b, char* nomfic){
    FILE *f = fopen(nomfic, "w");
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier\n");
    }
    LivreH** tmp = b->T;
        for(int i=0;i<b->m;i++){
            if(tmp[i]){
                LivreH* livre = tmp[i];
                while(livre){
                    fprintf(f,"%d %s %s\n",livre->num,livre->titre,livre->auteur);
                    livre=livre->suivant;
                }
            }
        
        }
    fclose(f);
}