void placementAvion(int** grille,int** avion,position *point,int entree)
{

int x = (*point).x; // *point represente le placement de l'avion dans la grille
int y = (*point).y;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if(avion[i][j] == 1)
			{
			grille[y + i][x + j] = 1;
			}

			else
			{
				grille[y + i][x + j] = 0;

			}


		}
	}


	for (int i = 0; i < 23; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (grille[i][1] == 1)
			{

				grille[i][1] = 0;
				grille[i][78] = 1;
				
			}

			if (grille[i][79] == 1)
			{
				grille[i][79] = 0;
				grille[i][2] = 1;
			}

			if (grille[23][j] == 1)
			{
				grille[23][j] = 0;
				grille[2][j] = 1;
			}

			if (grille[1][j] == 1)
			{
				grille[1][j] = 0;
				grille[22][j] = 1;
			}
		}
	}


}