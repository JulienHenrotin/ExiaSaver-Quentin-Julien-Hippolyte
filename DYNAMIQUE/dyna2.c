#include <stdlib.h>		//Bibliothèque fondamentales
#include <stdio.h>		//Contenant printf, scanf, ...
#include <ncurses.h>		//Bibliothèque pour quitter le processus sur commande de touches
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define TAILLE_MAX 1000					//Taille maximum du fichier
#define LARGEUR_CONSOLE 80

int Afheure()
{
	time_t secondes;
	struct tm instant;
	time(&secondes);
	instant=*localtime(&secondes);

	int TimeS1 = (instant.tm_sec)/10;
	int TimeS2 = (instant.tm_sec)-(TimeS1*10);
	int TimeM1 = (instant.tm_min)/10;
	int TimeM2 = (instant.tm_min)-(TimeM1*10);
	int TimeH1 = (instant.tm_hour)/10;
	int TimeH2 = (instant.tm_hour)-(TimeH1*10);
	
	
	int Tab[8];

	Tab[0]=TimeH1;
	Tab[1]=TimeH2;
	Tab[2]=20;
	Tab[3]=TimeM1;
	Tab[4]=TimeM2;
	Tab[5]=20;
	Tab[6]=TimeS1;
	Tab[7]=TimeS2;

	int a = 0;
	int TailleFich = 1;

	int y=12, x=9;

	FILE* fichier = NULL;  //initialisation du pointeur
	char chaine[TAILLE_MAX];        
	int chaine2[2];
        int i=0, j=0; //Déclaration variables
        int r,e;	

	for (a=0;a<8;a++)
	{
		switch (Tab[a])
		{
			case 0:
				fichier = fopen("PBM_dynamique/chiffre0.pbm", "r");
				break;
			case 1:
				fichier = fopen("PBM_dynamique/chiffre1.pbm", "r");
				break;
			case 2:
				fichier = fopen("PBM_dynamique/chiffre2.pbm", "r");
				break;
			case 3:
				fichier = fopen("PBM_dynamique/chiffre3.pbm", "r");
				break;
			case 4:
				fichier = fopen("PBM_dynamique/chiffre4.pbm", "r");
				break;
			case 5:
				fichier = fopen("PBM_dynamique/chiffre5.pbm", "r");
				break;
			case 6:
				fichier = fopen("PBM_dynamique/chiffre6.pbm", "r");
				break;
			case 7:
				fichier = fopen("PBM_dynamique/chiffre7.pbm", "r");
				break;
			case 8:
				fichier = fopen("PBM_dynamique/chiffre8.pbm", "r");
				break;
			case 9:
				fichier = fopen("PBM_dynamique/chiffre9.pbm", "r");
				break;
			case 20:
				fichier = fopen("PBM_dynamique/deuxpoint.pbm", "r");
				break;
		}
		

       
		 if (fichier != NULL) 	//lire le fichier
        	    {
        	        fseek(fichier, 3, SEEK_SET);                   
        	        fscanf(fichier, "%d %d", &chaine2[0], &chaine2[1]);
        	        r = chaine2[0];
        	        e = chaine2[1];
        	        r = (r*2)-1;
        		
			fseek(fichier, 1, SEEK_CUR);
        	      	for(i=0; i<e; i++)                   			//Boucle qui va parcourir les lignes
        	            {
				gotoxy(x,y);        	                
				fgets(chaine, TAILLE_MAX, fichier);		//récupération de la ligne
        	                for(j=0; j<r; j++)               		//boucle qui parcours la ligne
        	                    {
					gotoxy(x,y);        	                    	
					if (chaine[j] == '0')
        	                            chaine[j] = ' ';        		//Affiche les caractères correspondants en ' '
        	       			else if (chaine[j] == '1')
        	                            	chaine[j] = 223;      
        	                    }
				x=x+1;
				printf("%s", chaine);				//Afficher l'image ligne par ligne
        	            }
				fclose(fichier);   				//On ferme le fichier ouvert
				fichier = NULL;	
        	    }
		x=x-5;
		y=y+7;
	}
			
}

int main()
{

	int refresh = 10;				//Temps en seconde avant actualisation
	int ctrlc = 0;
	int g;
	int a = 20,b = 13,c = 20,d = 30;		//Encrage de l'horloge et de la phrase
	system("clear");				//Nettoiement de la console
	while (ctrlc != 1)
	{
		int y = 60;
		gotoxy(c,d);
		Afheure();
		gotoxy(a,b);
		printf("Cet ecran sera actualise dans quelques seconde");
		printf ("\n\n\n");

		for (g=0; g<refresh; g++)
		{
			sleep(1);
			gotoxy(a,y);
			printf(".\n");
			y++;
		}
		y=y-refresh;
		gotoxy(a,y);
		printf("                            ");
	}
	return 0;
}