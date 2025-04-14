#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Biblio/LC/biblioLC.h"
#include "Biblio/H/biblioH.h"
#include "entree_sortie/LC/entreeSortieLC.h"
#include "entree_sortie/H/entreeSortieH.h"



int main(){
    FILE* pf =fopen("tempscalculq3","w");
    clock_t debut;
    clock_t fin;
    double diffLC;
    double diffH;
    for(int i=1000;i<=50000;i+=50){
        Biblio* bl=charger_n_entrees("GdeBiblio.txt",i);
        BiblioH* bh = charger_n_entreesH("GdeBiblio.txt",i);
        debut=clock();
        recherche_ouvrages_identiques(bl);
        fin=clock();
        diffLC=(double)((fin-debut)/(double)CLOCKS_PER_SEC);
        debut=clock();
        recherche_ouvrages_identiquesH(bh);
        fin=clock();
        diffH=(double)((fin-debut)/(double)CLOCKS_PER_SEC);
        fprintf(pf,"%d\t%f\t%f\n",i,diffLC,diffH);
        printf("%d\n",i);// Juste pour que je vois l'avancement 
    }
    fclose(pf);
}
