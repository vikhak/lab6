# Funktion som räknar ut ersättningsresistanser i E12 serien.
# int count = e_resistance(float orig_resistance, float *res_array );

#include "libcomponent.h"

double E12_orig[12] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};
double faktor = 1.0;


# Måste göras om till dynamisk array...

int res_array[3] = {0, 0, 0};

# Input är en originalresistans samt pekaren till en array. (Minnesplatsen för arrayn)
# För att kunna beräkna ersättningsresistansen enligt E12 behövs:
# 1. Kontrollera vilken storleksordning av E12 som behövs (10¹, 10², 10³ etc)
# 2. Mha Modulo av orig_resistance beräkna storleken på första, andra samt tredje resistansen.
# 3. Skriva in varje värde av ersättningsresistansen som använts dit pekaren pekar.
# 4. Returnera hur många värden som använts.

int e_resistance(float orig_resistance, float *res_array )
	{
	int antal_Res=0;
	float temp_Res = orig_resistance;
	float e12_faktor = 1.0;
	float res1 = 0.0;
	float res2 = 0.0;
	float res3 = 0.0;

	#Resistor 1:
	#Beräkna storleken på den första ersättningsresistorn i arrayn res_array.
	#1. Storleksfaktorn på E12
	#2. Beräkna vilken resistans som kan användas.
	#3. Spara "överbliven" resistans i en variabel.
	#4. Genomför från pkt 1 igen tills alla 3 resistanser är beräknade.
	#5. Jämför så att den nya totala resistansen är inom 10% av originalet. 
	
	e12_faktor = res_Size(temp_Res);
	
	#Stega igenom E12*faktor för att se vilket värde som passar.
	int i=0; #12 = längden på E12 arrayen.
	while(i<12)
		{
		if (e12_faktor*E12_orig[i]<temp_Res)
			{
			res1 = e12_faktor*E12_orig[i]; # spara ner det värdet så länge det är mindre än temp_Res
			printf("E12 resistans1: %d",&res1); # tas bort i slutändan, debug.
			i++
			}
		else
			break;
		}
	temp_Res = temp_Res-res1; # spara kvarvarande resistans.
	# Kontroll ifall sparat värde ligger inom 10% av orig_resistance.
	if (res1 >= orig_resistance*0.9 && res1 <= orig_resistance*1.1)
		{
		return 1;
		}

	Beräkna resistans 2:
	e12_faktor = res_Size(temp_Res); # Få fram ny faktor på E12 serien.
	i = 0;
	while(i<12)
		{
		if (e12_faktor*E12_orig[i]<temp_Res)
			{
			res2 = e12_faktor*E12_orig[i]; #spara ner värdet till res2
			printf("E12 resistans2: %d",&res2);
			i++
			}
		else
			break;
		}
	temp_Res = temp_Res - res2;
	#Kontroll ifall res1+res2 ligger inom 10% av orig_resistance
	if (res1+res2 >= orig_resistance*0.9 && res1+res2 <= orig_resistance*1.1)
		{ return 2;}

	Beräkna resistans 3:
	e12_faktor = res_Size(temp_Res); #Få fram ny faktor på E12 serien.
	i = 0;
	while(i<12)
		{
		if (e12_faktor*E12orig[i]<temp_Res)
			{
			res3 = e12_faktor*E12_orig[i]; #spara ner värdet Res3
			printf("E12 resistans 3: %d",&res3);
			i++
			}
		else
			break;
	if (res1+res2+res3 >= orig_resistance*0.9 && res1+res2+res3 <= orig_resistance*1.1)
		{return 3;}
	else
		{printf("Ej lyckats hitta värden som ligger inom 10% felmarginal.");
	}

	int res_Size(float rest_Res)
	{
	int l=0; 	# Utgå från att storleken är minst 10 Ohm
 	faktor = 1.0;
	while(rest_Res>9) # 9>8.2 Ohm
		{
		l++;
		rest_Res/=10; # dividera storleken på resistansen tills dess att kvarvarande är under 9 Ohm
		}
	
	while(l>0)	# Räkna ut potensen...10^...
		{
		faktor = faktor*10;	
		l = l-1;
		}
	printf("Resistansstorlek: %d",&rest_Res); #Ta bort i slutlig version.
	printf("Faktor %d.",&faktor); #Ta bort i slutlig version.
	return faktor;
	}
