#include <stdio.h>
#include <stdlib.h>
#include "libresistance.h"

float calc_resistance(int count, char conn, float *array)
	{
	float totres = 0;
	int i = 0;
	// int count anger antalet resistorer som används.
	
	// char conn kan anta värdena: P eller S

	// float *array ger adressen till den array med information
	//  kring storleken på resistorerna. Lika stor/lång som count.
	// varje plats av arrayn ges genom *array+n
	if(array == NULL)
	{
		printf("Minne ej allokerat");
		exit(0);
	}
	if(conn == 'S')
	{
//		printf("Gå till serie\n");
		goto series;
	}
	else if(conn == 'P')
	{
//		printf("Gå till parallell\n");
		goto parallell;
	}
	else
	{
		printf("Felaktigt val! \n");
		return -1;
	}
	// Ersättningsresistans vid seriekoppling:
	series:
//		printf("I serie\n");
		for(i = 0; i < count; ++i)
		{
			totres += *(array + i);
			//printf(" %f \n",&totres);
//			printf("Tillfällig res: %f \n",totres);
		}
//		printf("Att returnera: %f \n",totres);
		return totres;
	
	// Ersättningsresistans vid parallellkoppling.
	parallell:
//		printf("I parallell\n");
		for(i = 0; i < count; ++i)
		{
			// Räkna om R till 1/R i hela arrayen och addera ( 1/R1 + 1/R2 etc.)
			totres  = totres + 1/(*(array + i));
		}
		totres = 1/totres;
		return totres;
	}
