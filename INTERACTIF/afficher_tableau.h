void afficherTableau(int** grille,int y,int x)
{
	int i = 0;
	int j = 0;
	char blanc = 219; // 219 est le code ascii du carré blanc
	for ( i = 0; i < y; i++)
	{
		for ( j = 0; j < x; j++)
		{
			if (grille[i][j] == 1)
			{
				printf("%c",blanc);
			}

			else
			{

				printf(" ");

			}

		}

	}


}