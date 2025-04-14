#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "biblioH.h"
int fonctionClef(char* auteur){
    int cle = 0;
    while (*auteur) {
        cle += (int)(*auteur);
        auteur++;
    }
    return cle;
}

LivreH* creer_livreH(int num,char* titre,char* auteur){
    LivreH* nl = (LivreH*)malloc(sizeof(LivreH));
    nl->clef=fonctionClef(auteur);
    nl->auteur=strdup(auteur);
    nl->num=num;
    nl->titre=strdup(titre);
    nl->suivant=NULL;
    return nl;
}
void liberer_livreH(LivreH* l){
    free(l->auteur);
    free(l->titre);
    free(l);
} 

BiblioH* creer_biblioH(int m){
    BiblioH* nb = (BiblioH*)malloc(sizeof(BiblioH));
    nb->nE=0;
    nb->m=m;
    nb->T=(LivreH**)malloc(m*sizeof(LivreH*));
    for(int i=0;i<m;i++){
        nb->T[i]=NULL;
    }
    return nb;
}

void liberer_biblioH(BiblioH* b){
    LivreH** tmp1 = b->T;
    LivreH* tmp2;
    for(int i=0;i<b->m;b++){
        LivreH* livre=tmp1[i];
        if(livre != NULL){
        while(livre){
            tmp2 =livre->suivant;
            liberer_livreH(livre);
            livre=tmp2;
        }}
        free(tmp1);
        free(b);}
    }
int fonctionHachage(int cle, int m){
    const double A = (sqrt(5)-1)/2;
    int hash = (int)(m*(cle*A- (int)(cle*A)));
    return hash;
}
void inserer(BiblioH* b,int num,char* titre,char* auteur){
    int cle=fonctionClef(auteur);
    int indice = fonctionHachage(cle,b->m);
    LivreH* livre = creer_livreH(num,titre,auteur);
    livre->suivant=b->T[indice];
    b->T[indice]=livre;
    b->nE++;
}

void afficher_livreH(LivreH* l){
    printf("%d %s %s\n",l->num,l->titre,l->auteur);
}

void afficher_bibliothequeH(BiblioH* b){
if(b){
LivreH** l = b->T;
LivreH* livre;
for(int i=0;i<b->m;i++){
    livre = l[i];
    while(livre){
        afficher_livreH(livre);
        livre=livre->suivant;
    }
}
}}
LivreH* rechercher_ouvrage_numH(BiblioH* b, int num){
LivreH** tmp = b->T;
for(int i=0;i<b->m;i++){
    LivreH* livre = tmp[i];
    while(livre){
        if(livre->num == num){return livre;}
        livre=livre->suivant;
    }
}
return NULL;
}

LivreH* rechercher_ouvrage_titreH(BiblioH* b,char* titre){
    LivreH** tmp = b->T;
    for(int i=0;i<b->m;i++){
        LivreH* livre = tmp[i];
        while(livre){
            if(strcmp(livre->titre,titre)==0){return livre;}
            livre=livre->suivant;
        }
    }
    return NULL;
    }

BiblioH* rechercher_livres_auteurH(BiblioH* b, char* auteur){
int cle = fonctionClef(auteur);
int hash =fonctionHachage(cle,b->m);
BiblioH* nb = creer_biblioH(1);
LivreH* livres = b->T[hash];
while(livres){
    if(strcmp(livres->auteur,auteur) == 0){inserer(nb,livres->num,livres->titre,livres->auteur);}
    livres=livres->suivant;
}
return nb;
}

int supprimer_ouvrageH(BiblioH* b,int num,char*titre,char*auteur){
int cle= fonctionClef(auteur);
int hash = fonctionHachage(cle,b->m);
LivreH* prev=NULL;
LivreH* cur = b->T[hash];
while(cur){
    if(cur->num == num && strcmp(cur->titre,titre)==0 && strcmp(cur->auteur,auteur)==0){
        if (prev == NULL) {
            b->T[hash] = cur->suivant;
            liberer_livreH(cur);
            return 0;
    }
    else{
        prev->suivant=cur->suivant;
        liberer_livreH(cur);
        return 0;
    }
}
    prev = cur;
    cur = cur->suivant;
}
return 1;
}
void fusion_bibH(BiblioH** b1,BiblioH* b2){
if (*b1 == NULL){
    *b1 = creer_biblioH(b2->m);
}
LivreH** tmp=b2->T;
for(int i=0;i<b2->m;i++){
    LivreH* livre = tmp[i];
    while (livre)
    {
        inserer(*b1,livre->num,livre->titre,livre->auteur);
        livre=livre->suivant;
    }
}
}
BiblioH* recherche_ouvrages_identiquesH(BiblioH* b){
    BiblioH* b2=creer_biblioH(1);
    LivreH* cur1;
    for(int i=0;i<b->m;i++){
        cur1 = b->T[i];
        while(cur1){
            LivreH* cur2 = cur1->suivant;
            while(cur2){
                if (strcmp(cur1->titre, cur2->titre) == 0 && strcmp(cur1->auteur, cur2->auteur) == 0) {
                    inserer(b2,cur1->num,cur1->titre,cur1->auteur);
                    inserer(b2,cur2->num,cur2->titre,cur2->auteur);
            }
            cur2=cur2->suivant;
        }
        cur1=cur1->suivant;
    }}
    return b2;
}
