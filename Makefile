CC = gcc
CFLAGS = -g -Wall

all: mon_prog question1exo3 question3exo3

mon_prog: main.o biblioLC.o entreeSortieLC.o biblioH.o entreeSortieH.o
	$(CC) $(CFLAGS) -o mon_prog main.o biblioLC.o entreeSortieLC.o biblioH.o entreeSortieH.o

tempscalculE3Q3.o: tempsCalculE3Q3.c Biblio/LC/biblioLC.h entree_sortie/LC/entreeSortieLC.h Biblio/H/biblioH.h entree_sortie/H/entreeSortieH.h
	$(CC) $(CFLAGS) -c tempsCalculE3Q3.c

tempsCalculE3Q1.o: tempsCalculE3Q1.c Biblio/LC/biblioLC.h entree_sortie/LC/entreeSortieLC.h Biblio/H/biblioH.h entree_sortie/H/entreeSortieH.h
	$(CC) $(CFLAGS) -c tempsCalculE3Q1.c

question1exo3: tempsCalculE3Q1.o biblioLC.o entreeSortieLC.o biblioH.o entreeSortieH.o
	$(CC) $(CFLAGS) -o question1exo3 tempsCalculE3Q1.o biblioLC.o entreeSortieLC.o biblioH.o entreeSortieH.o

question3exo3: tempsCalculE3Q3.o biblioLC.o entreeSortieLC.o biblioH.o entreeSortieH.o
	$(CC) $(CFLAGS) -o question3exo3 tempsCalculE3Q3.o biblioLC.o entreeSortieLC.o biblioH.o entreeSortieH.o

biblioLC.o: Biblio/LC/biblioLC.c Biblio/LC/biblioLC.h
	$(CC) $(CFLAGS) -c Biblio/LC/biblioLC.c

entreeSortieLC.o: entree_sortie/LC/entreeSortieLC.c entree_sortie/LC/entreeSortieLC.h
	$(CC) $(CFLAGS) -c entree_sortie/LC/entreeSortieLC.c

biblioH.o: Biblio/H/biblioH.c Biblio/H/biblioH.h
	$(CC) $(CFLAGS) -c Biblio/H/biblioH.c

entreeSortieH.o: entree_sortie/H/entreeSortieH.c entree_sortie/H/entreeSortieH.h
	$(CC) $(CFLAGS) -c entree_sortie/H/entreeSortieH.c


main.o: main.c Biblio/LC/biblioLC.h entree_sortie/LC/entreeSortieLC.h Biblio/H/biblioH.h entree_sortie/H/entreeSortieH.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o mon_prog question1exo3 question3exo3
