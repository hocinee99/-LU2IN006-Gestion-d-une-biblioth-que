#include <stdio.h>
#include <stdlib.h>
#include "Biblio/LC/biblioLC.h"
#include "Biblio/H/biblioH.h"
#include "entree_sortie/LC/entreeSortieLC.h"
#include "entree_sortie/H/entreeSortieH.h"

    void menu(){
        printf("\nMENU\n");
        printf("0 - Sortie du programme\n");
        printf("1 - Afficher la bibliothèque\n");
        printf("2 - Inserer un ouvrage\n");
        printf("3 - Supprimer un livre\n");
        printf("4 - Rechercher un ouvrage (num)\n");
        printf("5 - Rechercher un ouvrages (titre)\n");
        printf("6 - Rechercher des livres (auteur)\n");
        printf("7 - Trouver les exemplaires identiques\n");
        printf("8 - Enregistrer la bibliothéque\n");
    }
int main(int argc, char** argv){
    if (argc != 3){
        printf("Usage ./main <fichier> <nombre>");
        return 1;
    }
    char rep[3];
    char buffer[256];
    printf("1-Liste chainée\n2-Table de hachage\n");
    fgets(rep, sizeof(rep), stdin);
    if(atoi(rep)== 1){ // Cas 1 LC
    Biblio* b = charger_n_entrees(argv[1], atoi(argv[2]));
    do {
        menu();
        fgets(rep,sizeof(rep),stdin);
        switch(atoi(rep)) {
            case 0:
                printf("Merci et au revoir !\n");
                break;
            case 1:
                printf("Affichage de la bibliothèque :\n");
                afficher_bibliotheque(b);
                break;
            case 2: {
                int num;
                char titre[256];
                char auteur[256];
                printf("Veuillez entrer le numéro, le titre et l'auteur de l'ouvrage\n");
                fgets(buffer,sizeof(buffer),stdin);
                if (sscanf(buffer,"%d %s %s", &num, titre, auteur) == 3) {
                    inserer_en_tete(b, num, titre, auteur);
                    printf("Ajout fait.\n");
                } else {
                    printf("Erreur format.\n");
                }
                break;
            }
                
            case 3: {
                int num;
                char titre[256], auteur[256];
                printf("Veuillez entrer le numéro, le titre et l'auteur de l'ouvrage à supprimer \n");
                fgets(buffer,sizeof(buffer),stdin);
                if (sscanf(buffer,"%d %s %s", &num, titre, auteur) == 3) {
                    int a =supprimer_ouvrage(b, num, titre, auteur);
                    if(a==0){
                        printf("Suppression effectuée.\n");
                    } else {
                        printf("Livre pas trouvé\n");
                    }
                }
                break;
            }

            case 4: {
                int num;
                printf("Veuillez entrer le numéro de l'ouvrage à rechercher\n");
                fgets(buffer,sizeof(buffer),stdin);
                if(sscanf(buffer,"%d",&num)==1);
                Livre* l1 = rechercher_ouvrage_num(b, num);
                if(l1){
                afficher_livre(l1);}else{printf("Numero pas trouvé");}
                break;
            }

            case 5: {
                char titre[256];
                printf("Veuillez entrer le titre de l'ouvrage à rechercher :\n");
                fgets(buffer,sizeof(buffer),stdin);
                if (sscanf(buffer,"%s",titre)==1){
                Livre* l2 = rechercher_ouvrage_titre(b, titre);
                if(l2){
                afficher_livre(l2);}else{printf("Titre pas trouvé");}}
                break;
            }

            case 6: {
                char auteur[256];
                printf("Veuillez entrer l'auteur des livres à rechercher :\n");
                fgets(buffer,sizeof(buffer),stdin);
                if(sscanf(buffer,"%s",auteur)==1){
                Biblio* b2 = rechercher_livres_auteur(b, auteur);
                if(b2){
                afficher_bibliotheque(b2);}else{printf("Auteur pas trouvé");}
            }
                break;
            }

            case 7:
                Biblio* exemplaires = recherche_ouvrages_identiques(b);
                if(exemplaires){
                afficher_bibliotheque(exemplaires);}else{printf("Aucun ouvrage n'est present plusieurs fois");}
                break;

            case 8: {
                char fichier[256];
                printf("Veuillez entrer le nom du fichier");
                fgets(buffer,sizeof(buffer),stdin);
                if (sscanf(buffer,"%s",fichier)==1){
                    enregistrer_biblio(b,fichier);
                }
                break;
            }
            liberer_biblio(b);
        }
    } while (atoi(rep) != 0);}
    if(atoi(rep)==2){ // Cas 2 table de hachage
        BiblioH* bH = charger_n_entreesH(argv[1], atoi(argv[2]));
        do {
            menu();
            fgets(rep,sizeof(rep),stdin);
            switch(atoi(rep)) {
                case 0:
                    printf("Merci et au revoir !\n");
                    break;
                case 1:
                    printf("Affichage de la bibliothèque :\n");
                    afficher_bibliothequeH(bH);
                    break;
                case 2: {
                    int num;
                    char titre[256];
                    char auteur[256];
                    printf("Veuillez entrer le numéro, le titre et l'auteur de l'ouvrage\n");
                    fgets(buffer,sizeof(buffer),stdin);
                    if (sscanf(buffer,"%d %s %s", &num, titre, auteur) == 3) {
                        inserer(bH, num, titre, auteur);
                        printf("Ajout fait.\n");
                    } else {
                        printf("Erreur format.\n");
                    }
                    break;
                }
                    
                case 3: {
                    int num;
                    char titre[256], auteur[256];
                    printf("Veuillez entrer le numéro, le titre et l'auteur de l'ouvrage à supprimer \n");
                    fgets(buffer,sizeof(buffer),stdin);
                    if (sscanf(buffer,"%d %s %s", &num, titre, auteur) == 3) {
                        int a =supprimer_ouvrageH(bH, num, titre, auteur);
                        if(a==0){
                            printf("Suppression effectuée.\n");
                        } else {
                            printf("Livre pas trouvé\n");
                        }
                    }
                    break;
                }
    
                case 4: {
                    int num;
                    printf("Veuillez entrer le numéro de l'ouvrage à rechercher\n");
                    fgets(buffer,sizeof(buffer),stdin);
                    if(sscanf(buffer,"%d",&num)==1);
                    LivreH* l1 = rechercher_ouvrage_numH(bH, num);
                    if(l1){
                    afficher_livreH(l1);}else{printf("Numero pas trouvé");}
                    break;
                }
    
                case 5: {
                    char titre[256];
                    printf("Veuillez entrer le titre de l'ouvrage à rechercher :\n");
                    fgets(buffer,sizeof(buffer),stdin);
                    if (sscanf(buffer,"%s",titre)==1){
                    LivreH* l2 = rechercher_ouvrage_titreH(bH, titre);
                    if(l2){
                    afficher_livreH(l2);}else{printf("Titre pas trouvé");}}
                    break;
                }
    
                case 6: {
                    char auteur[256];
                    printf("Veuillez entrer l'auteur des livres à rechercher :\n");
                    fgets(buffer,sizeof(buffer),stdin);
                    if(sscanf(buffer,"%s",auteur)==1){
                    BiblioH* b2 = rechercher_livres_auteurH(bH, auteur);
                    if(b2){
                    afficher_bibliothequeH(b2);
                liberer_biblioH(b2);}else{printf("Auteur pas trouvé");}
                }
                    break;
                }
    
                case 7:
                    BiblioH* exemplaires = recherche_ouvrages_identiquesH(bH);
                    if(exemplaires->T[0]){
                    afficher_bibliothequeH(exemplaires);}else{printf("Aucun ouvrage n'est present plusieurs fois");}
                    break;
    
                case 8: {
                    char fichier[256];
                    printf("Veuillez entrer le nom du fichier");
                    fgets(buffer,sizeof(buffer),stdin);
                    if (sscanf(buffer,"%s",fichier)==1){
                        enregistrer_biblioH(bH,fichier);
                        printf("Fichier enregistré");
                    }
                    break;
                }
                liberer_biblioH(bH);
            }
    
        } while (atoi(rep) != 0);
    return 0;
}}
