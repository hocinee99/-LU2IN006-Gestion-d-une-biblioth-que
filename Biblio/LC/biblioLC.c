#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"

Livre* creer_livre(int num,char* titre,char* auteur){
    Livre* a= malloc(sizeof(Livre));
    a->num=num;
    a->titre=strdup(titre);
    a->auteur=strdup(auteur);
    a->suiv=NULL;
    return a;
}

void liberer_livre(Livre* l){
    free(l->titre);
    free(l->auteur);
    free(l);
}

Biblio* creer_biblio(){
    Biblio* bbl = (Biblio*)malloc(sizeof(Biblio));
    bbl->L = NULL;
    return bbl;
}

void liberer_biblio(Biblio* b){
    Livre* tmp;
    while (b->L)
    {
        tmp=b->L;
        b->L=b->L->suiv;
        liberer_livre(tmp);
    }
    free(b);
}

void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur){
    Livre* ll = creer_livre(num,titre,auteur);
    ll->suiv= b->L;
    b->L = ll;
}

void afficher_livre(Livre* l){
        printf("%d %s %s\n",l->num,l->titre,l->auteur);
}

void afficher_bibliotheque(Biblio* b){
    Livre* l = b->L;
    while(l){
    afficher_livre(l);
    l=l->suiv;
    }
}
Livre* rechercher_ouvrage_num(Biblio* b, int num){
    Livre* livres = b->L;
    while(livres){
        if(livres->num == num){return livres;}
        livres=livres->suiv;
    }
    return NULL;
}

Livre* rechercher_ouvrage_titre(Biblio* b, char* title){
    Livre* livres = b->L;
    while(livres){
        if(strcmp(livres->titre,title )== 0){return livres;}
        livres=livres->suiv;
    }
    return NULL;
}

Biblio* rechercher_livres_auteur(Biblio* b, char* auteur){
    Biblio* nb = creer_biblio();
    Livre* livres = b->L;
    while(livres){
        if(strcmp(livres->auteur,auteur) == 0){inserer_en_tete(nb,livres->num,livres->titre,livres->auteur);}
        livres=livres->suiv;
    }
    return nb;
}

int supprimer_ouvrage(Biblio* b,int num,char*titre,char*auteur){
    Livre* prev=NULL;
    Livre* cur = b->L;
    while(cur){
        if(cur->num == num && strcmp(cur->titre,titre)==0 && strcmp(cur->auteur,auteur)==0){
            if (prev == NULL) {
                b->L = cur->suiv;
                liberer_livre(cur);
                return 0;
        }
        else{
            prev->suiv=cur->suiv;
            liberer_livre(cur);
            return 0;
        }
    }
        prev = cur;
        cur = cur->suiv;
}
return 1;
}

void fusion_bib(Biblio** b1,Biblio* b2){
    if (*b1 == NULL){
        *b1 = creer_biblio();
    }
    Biblio* tmp = b2;
    while(tmp->L){
        inserer_en_tete(*b1, tmp->L->num, tmp->L->titre, tmp->L->auteur);
        tmp->L = tmp->L->suiv;
    }
    liberer_biblio(b2);
}
Biblio* recherche_ouvrages_identiques(Biblio* b){
    if (b == NULL || b->L == NULL) return NULL;
    Biblio* b2=creer_biblio();
    Livre* cur1 = b->L;
    while (cur1) {
        Livre* cur2 = cur1->suiv;
        while (cur2) {
            if (strcmp(cur1->titre, cur2->titre) == 0 && strcmp(cur1->auteur, cur2->auteur) == 0) {
                inserer_en_tete(b2,cur1->num,cur1->titre,cur1->auteur);
                inserer_en_tete(b2,cur2->num,cur2->titre,cur2->auteur);
            }
            cur2 = cur2->suiv;
        }
        cur1 = cur1->suiv;
    }
    return b2;
}
