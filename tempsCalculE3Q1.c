#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Biblio/H/biblioH.h"
#include "Biblio/LC/biblioLC.h"
#include "entree_sortie/LC/entreeSortieLC.h"
#include "entree_sortie/H/entreeSortieH.h"



int main(){
    Biblio* bl = charger_n_entrees("GdeBiblio.txt",50000);
    BiblioH* bh = charger_n_entreesH("GdeBiblio.txt",50000);
    clock_t debut;
    clock_t fin;
    double diff;
    printf("\n RECHERCHE NUM\n");
    debut=clock();
    for(int i=0;i<1000;i++){
    rechercher_ouvrage_num(bl,9999);
    rechercher_ouvrage_num(bl,39);
    rechercher_ouvrage_num(bl,8500);
    rechercher_ouvrage_num(bl,4264);
    rechercher_ouvrage_num(bl,9999);
    }
    fin=clock();
    diff=(double)((fin-debut)/(double)CLOCKS_PER_SEC);
    printf("Le temps de recherche avec numéro (cas livre présent) pour une liste chainée est %0.10fs\n",diff);
    debut=clock();
    for(int i=0;i<1000;i++){
    rechercher_ouvrage_numH(bh,9999);
    rechercher_ouvrage_numH(bh,39);
    rechercher_ouvrage_numH(bh,8500);
    rechercher_ouvrage_numH(bh,4264);
    rechercher_ouvrage_numH(bh,9999);
}
    fin=clock();
    diff=(double)((fin-debut)/(double)CLOCKS_PER_SEC);
    printf("Le temps de recherche avec numéro (cas livre présent)pour une table de hachage est %0.10fs\n",diff);
    debut=clock();
    for(int i=0;i<1000;i++){
    rechercher_ouvrage_num(bl,123456);
    rechercher_ouvrage_num(bl,416846);
    rechercher_ouvrage_num(bl,141144);
    rechercher_ouvrage_num(bl,131233);
    rechercher_ouvrage_num(bl,315324);
    }
    fin=clock();
    diff=(double)((fin-debut)/(double)CLOCKS_PER_SEC);
    printf("Le temps de recherche avec numéro (cas livre absent) pour une liste chainée est %0.10fs\n",diff);
    debut=clock();
    for(int i=0;i<1000;i++){
    rechercher_ouvrage_numH(bh,123456);
    rechercher_ouvrage_numH(bh,416846);
    rechercher_ouvrage_numH(bh,141144);
    rechercher_ouvrage_numH(bh,131233);
    rechercher_ouvrage_numH(bh,315324);
    }
    fin=clock();
    diff=(double)((fin-debut)/(double)CLOCKS_PER_SEC);
    printf("Le temps de recherche avec numéro (cas livre présent)pour une table de hachage est %0.10fs\n",diff);    
    
    // Recherche titre
    printf("\n RECHERCHE TITRE\n");
    
    debut=clock();
    for(int i=0;i<1000;i++){
    rechercher_ouvrage_titre(bl,"RJFPSPYEEZPZS");
    rechercher_ouvrage_titre(bl,"EKLL");
    rechercher_ouvrage_titre(bl,"LANACLHWIAV");
    rechercher_ouvrage_titre(bl,"BUCIZWKOS");
    rechercher_ouvrage_titre(bl,"GPNN");
    }
    fin=clock();
    diff=(double)((fin-debut)/(double)CLOCKS_PER_SEC);
    printf("Le temps de recherche avec titre (cas livre présent) pour une liste chainée est %0.10fs\n",diff);
    debut=clock();
    for(int i=0;i<1000;i++){
        rechercher_ouvrage_titreH(bh,"RJFPSPYEEZPZS");
        rechercher_ouvrage_titreH(bh,"EKLL");
        rechercher_ouvrage_titreH(bh,"LANACLHWIAV");
        rechercher_ouvrage_titreH(bh,"BUCIZWKOS");
        rechercher_ouvrage_titreH(bh,"GPNN");
}
    fin=clock();
    diff=(double)((fin-debut)/(double)CLOCKS_PER_SEC);
    printf("Le temps de recherche avec titre (cas livre présent)pour une table de hachage est %0.10fs\n",diff);
    debut=clock();
    for(int i=0;i<1000;i++){
        rechercher_ouvrage_titre(bl,"test");
        rechercher_ouvrage_titre(bl,"rgthuyregyukljezgfyujerzsgyuferszyugfuezysigfy");
        rechercher_ouvrage_titre(bl,"trgnj:kldrefgbjuitrjhg");
        rechercher_ouvrage_titre(bl,"tbmjklurtbjklumtrf");
        rechercher_ouvrage_titre(bl,"aredzzesfez");
    }
    fin=clock();
    diff=(double)((fin-debut)/(double)CLOCKS_PER_SEC);
    printf("Le temps de recherche avec titre (cas livre absent) pour une liste chainée est %0.10fs\n",diff);
    debut=clock();
    for(int i=0;i<1000;i++){
    rechercher_ouvrage_titreH(bh,"test");
    rechercher_ouvrage_titreH(bh,"rgthuyregyukljezgfyujerzsgyuferszyugfuezysigfy");
    rechercher_ouvrage_titreH(bh,"trgnj:kldrefgbjuitrjhg");
    rechercher_ouvrage_titreH(bh,"tbmjklurtbjklumtrf");
    rechercher_ouvrage_titreH(bh,"aredzzesfez");
    }
    fin=clock();
    diff=(double)((fin-debut)/(double)CLOCKS_PER_SEC);
    printf("Le temps de recherche avec titre (cas livre absent)pour une table de hachage est %0.10fs\n",diff);

    // Recherche auteur
    printf("\n RECHERCHE AUTEUR\n");
    
    debut=clock();
    for(int i=0;i<1000;i++){
    rechercher_livres_auteur(bl,"yhidd");
    rechercher_livres_auteur(bl,"ccwcqa");
    rechercher_livres_auteur(bl,"lmbvus");
    rechercher_livres_auteur(bl,"eplzhxhkdcwy");
    rechercher_livres_auteur(bl,"oitqyd");
    }
    fin=clock();
    diff=(double)((fin-debut)/(double)CLOCKS_PER_SEC);
    printf("Le temps de recherche avec auteur (cas livre présent) pour une liste chainée est %0.10fs\n",diff);
    debut=clock();
    for(int i=0;i<1000;i++){
        rechercher_livres_auteurH(bh,"yhidd");
        rechercher_livres_auteurH(bh,"ccwcqa");
        rechercher_livres_auteurH(bh,"lmbvus");
        rechercher_livres_auteurH(bh,"eplzhxhkdcwy");
        rechercher_livres_auteurH(bh,"oitqyd");
}
    fin=clock();
    diff=(double)((fin-debut)/(double)CLOCKS_PER_SEC);
    printf("Le temps de recherche avec auteur (cas livre présent)pour une table de hachage est %0.10fs\n",diff);
    debut=clock();
    for(int i=0;i<10000;i++){
        rechercher_livres_auteur(bl,"test");
        rechercher_livres_auteur(bl,"rgthuyregyukljezgfyujerzsgyuferszyugfuezysigfy");
        rechercher_livres_auteur(bl,"trgnj:kldrefgbjuitrjhg");
        rechercher_livres_auteur(bl,"tbmjklurtbjklumtrf");
        rechercher_livres_auteur(bl,"aredzzesfez");
    }
    fin=clock();
    diff=(double)((fin-debut)/(double)CLOCKS_PER_SEC);
    printf("Le temps de recherche avec auteur (cas livre absent) pour une liste chainée est %0.10fs\n",diff);
    debut=clock();
    for(int i=0;i<10000;i++){
    rechercher_livres_auteurH(bh,"test");
    rechercher_livres_auteurH(bh,"rgthuyregyukljezgfyujerzsgyuferszyugfuezysigfy");
    rechercher_livres_auteurH(bh,"trgnj:kldrefgbjuitrjhg");
    rechercher_livres_auteurH(bh,"tbmjklurtbjklumtrf");
    rechercher_livres_auteurH(bh,"aredzzesfez");
    }
    fin=clock();
    diff=(double)((fin-debut)/(double)CLOCKS_PER_SEC);
    printf("Le temps de recherche avec auteur (cas livre absent)pour une table de hachage est %0.10fs\n",diff);
}
