#include <stdio.h> // pour la fonction FILE*
#include <stdlib.h> 
#include <time.h> // Pour l'aleatoire
#include "main.h" // structure position
#include "aleatoire.h"
#include "initialiser_tableau.h" // pour une mise à zero propre
#include "afficher_tableau.h" // pour afficher le tableau
#include "mouvement.h" // gere la position de l'avion
#include "testLettre.h" // interface entre l'utilisateur et le programme
#include "placementAvion.h" // pour placer l'avion dans la grille
#include "initialisationAvion.h" // pour placer le code ASCII dans les avions


int main(int argc, char const *argv[])
{

// Declaration des variables

	int MAX_position = 3;
	int MIN_position = 0;

	int MAX_position_x = 80;
	int MAX_position_y = 24;
	int MIN_position_xy = 0;

	


	char lettre = 0;
	int entree = 0;

	int mystere = 0;
	int x_mystere = 0;
	int y_mystere = 0;

	int **avionH;
	int **avionB;
	int **avionG;
	int **avionD; //tableaux à deux dimensions
	int **grille;

	position placement;



//allocation de l'avion tableaux 

	avionH = malloc(6 *sizeof(*avionH)); //avion haut

	for(int i=0; i< 6; i++)
	{

		avionH[i] = malloc(6 * sizeof(**avionH));
	}
//                   ************************
	avionB = malloc(6 *sizeof(*avionB)); // avion bas

	for(int i=0; i< 6; i++)
	{

		avionB[i] = malloc(6 * sizeof(**avionB));
	}
//                   ************************
	avionG = malloc(6 *sizeof(*avionG)); //avion gauche

	for(int i=0; i< 6; i++)
	{

		avionG[i] = malloc(6 * sizeof(**avionG));
	}
//                   ************************
	avionD = malloc(6 *sizeof(*avionD)); //avion droit

	for(int i=0; i< 6; i++)
	{

		avionD[i] = malloc(6 * sizeof(**avionD));
	}

//                   ************************allocation de la grille****************************

	grille = malloc(28 *sizeof(*grille));

	for(int i=0; i< 28; i++)
	{

		grille[i] = malloc(80 * sizeof(**grille));
	}

//                   ************************


	mystere = aleatoire(mystere,MIN_position,MAX_position);
	x_mystere = aleatoire(x_mystere,MIN_position_xy,MAX_position_x);
	y_mystere = aleatoire(y_mystere,MIN_position_xy,MAX_position_y);
	


	entree = mystere;
	placement.x = x_mystere;
	placement.y = y_mystere;


    InitialiserTableau(grille, 24, 80); // mise à zero des tableaux
 
    InitialiserTableau(avionH,6,6);
    InitialiserTableau(avionB,6,6);
    InitialiserTableau(avionG,6,6);
    InitialiserTableau(avionD,6,6);

    initialisationAvion(avionH,avionB,avionG,avionD);

    if (entree == 0)
    {
    	placementAvion(grille,avionH,&placement,entree);
    }

    if (entree == 1)
    {
    	placementAvion(grille,avionB,&placement,entree);
    }

    if (entree == 2)
    {
    	placementAvion(grille,avionG,&placement,entree);
    }
    if (entree == 3)
    {
    	placementAvion(grille,avionD,&placement,entree);
    }


    afficherTableau(grille,24,80);




  //                ************************Boucle principale******************

    do

    {

    	entree= testLettre(lettre, entree);

    	system("clear");

    	InitialiserTableau(grille,24,80); //nettoyage de la grille precedente


    	if (entree == 4)
    	{
    		return 0;
    	}


    	mouvementAvion(&placement,entree); // changement des positions de l'avion
    
//                   ************************PLACEMENT DE L'AVION DANS LA GRILLE*********************************

switch (entree)
{

    case 0:

    	placementAvion(grille,avionH,&placement,entree);
    
    break;

    case 1:
    
    	placementAvion(grille,avionB,&placement,entree);
    
    break;

    case 2:
    
    	placementAvion(grille,avionG,&placement,entree);

    break;
    
    case 3:
    
    	placementAvion(grille,avionD,&placement,entree);
    
    break;

}
	


    	
    	afficherTableau(grille,24,80);
    	


    }while(lettre != 'e');




	return 0;
}
