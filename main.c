#include <stdio.h>
#include <stdlib.h>
#include "libresistance.h"

int main(void)
{
	int volt, i, antal = 0;
 	char koppling;
	float *rval = NULL;

	//Ange spänningskälla
	printf("Ange spänningskälla i V: ");
	scanf(" %d", &volt);

	//Ange koppling
	printf("Ange koppling [ S | P ]: ");
	scanf(" %c", &koppling);

	//Ange antal komponenter
	printf("Antal komponenter: ");
	scanf(" %d", &antal);

	//Minnesallokering av arrayen rval
	rval = (float*) malloc(antal * sizeof(float));
	for(i = 0; i < antal; ++i)
	{
	//Ange komponentvärden
	printf("Komponent %d i ohm: ", i + 1);
	scanf(" %f", rval+i);
	}

	//Skriv ut ersättningsresistans
	printf("Ersättningsresistans: %.1f ohm\n", calc_resistance(antal,koppling,rval));
	//Frigör minnet
	free(rval);

	//Skriv ut effekt:
	printf("Effekt: \n");

	//Skriv ut ersättningsresistanser:
	printf("Ersättingsresistanser i E12-serien kopplade i serie: \n");

	return 0;
}

