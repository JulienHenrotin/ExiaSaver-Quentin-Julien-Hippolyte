void initialisationAvion(int** avion_haut,int** avion_bas,int** avion_gauche,int** avion_droit)
{
	avion_haut[0][2] = 1; // ecriture manuelle de la forme de l'avion
	avion_haut[1][1] = 1;
	avion_haut[1][2] = 1;
	avion_haut[1][3] = 1;
	avion_haut[2][2] = 1;
	avion_haut[3][1] = 1;
	avion_haut[3][2] = 1;
	avion_haut[3][3] = 1;
	avion_haut[4][0] = 1;
	avion_haut[4][2] = 1;
	avion_haut[4][4] = 1;
	avion_haut[5][0] = 1;
	avion_haut[5][2] = 1;
	avion_haut[5][4] = 1;

	avion_bas[0][0] = 1;
	avion_bas[0][2] = 1;
	avion_bas[0][4] = 1;
	avion_bas[1][0] = 1;
	avion_bas[1][2] = 1;
	avion_bas[1][4] = 1;
	avion_bas[2][1] = 1;
	avion_bas[2][2] = 1;
	avion_bas[2][3] = 1;
	avion_bas[3][2] = 1;
	avion_bas[4][1] = 1;
	avion_bas[4][2] = 1;
	avion_bas[4][3] = 1;
	avion_bas[5][2] = 1;

	avion_gauche[0][4] = 1;
	avion_gauche[0][5] = 1;
	avion_gauche[1][1] = 1;
	avion_gauche[1][3] = 1;
	avion_gauche[2][0] = 1;
	avion_gauche[2][1] = 1;
	avion_gauche[2][2] = 1;
	avion_gauche[2][3] = 1;
	avion_gauche[2][4] = 1;
	avion_gauche[2][5] = 1;
	avion_gauche[3][1] = 1;
	avion_gauche[3][3] = 1;
	avion_gauche[4][4] = 1;
	avion_gauche[4][5] = 1;

	avion_droit[0][0] = 1;
	avion_droit[0][1] = 1;
	avion_droit[1][2] = 1;
	avion_droit[1][4] = 1;
	avion_droit[2][0] = 1;
	avion_droit[2][1] = 1;
	avion_droit[2][2] = 1;
	avion_droit[2][3] = 1;
	avion_droit[2][4] = 1;
	avion_droit[2][5] = 1;
	avion_droit[3][2] = 1;
	avion_droit[3][4] = 1;
	avion_droit[4][0] = 1;
	avion_droit[4][1] = 1;



}