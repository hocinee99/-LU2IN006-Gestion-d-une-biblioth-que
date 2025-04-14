#ifndef BIBLIO_LC_H
#define BIBLIO_LC_H
typedef struct livre {
    int num ;
    char * titre ;
    char * auteur ;
    struct livre * suiv ;
} Livre ;
typedef struct { /* Tete fictive */
    Livre * L ; /* Premier element */
} Biblio ;

Livre* creer_livre(int num,char* titre,char* auteur);
void liberer_livre(Livre* l);
Biblio* creer_biblio();
void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur);
void liberer_biblio(Biblio* b);
void afficher_livre(Livre* l);
void afficher_bibliotheque(Biblio* b);
Livre* rechercher_ouvrage_num(Biblio* b, int num);
Livre* rechercher_ouvrage_titre(Biblio* b, char* title);
Biblio* rechercher_livres_auteur(Biblio* b, char* auteur);
int supprimer_ouvrage(Biblio* b,int num,char*titre,char*auteur);
void fusion_bib(Biblio** b1,Biblio* b2);
Biblio* recherche_ouvrages_identiques(Biblio* b);
#endif
