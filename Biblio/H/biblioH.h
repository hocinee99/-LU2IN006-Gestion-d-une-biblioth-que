#ifndef BIBLIO_H_H
#define BIBLIO_H_H
typedef struct livreh {
    int clef ;
    int num;
    char* auteur;
    char* titre;
    struct livreh * suivant ;
} LivreH ;
typedef struct table {
    int nE ; /*nombre d’elements contenus dans la table de hachage */
    int m ; /*taille de la table de hachage */
    LivreH ** T ; /*table de hachage avec resolution des collisions par chainage */
} BiblioH ;
int fonctionClef(char* auteur);
LivreH* creer_livreH(int num,char* titre,char* auteur);
void liberer_livreH(LivreH* l);
BiblioH* creer_biblioH(int m);
void liberer_biblioH(BiblioH* b);
int fonctionHachage(int cle, int m);
void inserer(BiblioH* b,int num,char* titre,char* auteur);
void afficher_livreH(LivreH* l);
void afficher_bibliothequeH(BiblioH* b);
LivreH* rechercher_ouvrage_numH(BiblioH* b, int num);
LivreH* rechercher_ouvrage_titreH(BiblioH* b,char* titre);
BiblioH* rechercher_livres_auteurH(BiblioH* b, char* auteur);
int supprimer_ouvrageH(BiblioH* b,int num,char*titre,char*auteur);
void fusion_bibH(BiblioH** b1,BiblioH* b2);
BiblioH* recherche_ouvrages_identiquesH(BiblioH* b);
#endif
