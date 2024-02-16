
/*Idée : une parenthèse fermante est associée à la dernière parenthèse ouvrante rencontrée d’où LIFO = >PILE. */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "pile.h" /*objet abstrait */

char *sous_chaine(char ch[], unsigned debut, unsigned fin){
/* rend la sous_chaine comprise entre ch[debut et ch[fin] */
	unsigned i ; /* entre debut et fin */
	char *sch ;
	char *p ;
	sch = (char*) malloc (fin - debut + 2) ;
	p = sch ;
	for(i = debut; i <= fin; i++){
		*p = ch[i] ;
	    p++ ;
	}
	*p = '\0' ;
	return sch ;
}

void main( ){
	char ch[80] ; /* expression proposée */
	char *sch ; /* expression courant entre parenthèses */
	unsigned i ;

	printf("donner une expression valide \n");
    gets(ch);


    for(i=0, creePile() ;i<strlen(ch) ;i++){
		if(ch[i]== '(')
			empiler(i) ;
		else if(ch[i]== ')'){
			sch=sous_chaine(ch,dernier(),i) ;
			puts(sch) ;
			depiler() ;
		}
	} /* fin for */
} /* fin main */