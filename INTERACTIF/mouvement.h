
void mouvementAvion(position *point , int entree)
{
	if (entree == 0)
	{

		(*point).y = (*point).y  - 1;

		if ((*point).y < 5)
		{

			(*point).y = 19;


		}


	}

	if (entree == 1)
	{
		(*point).y = (*point).y  + 1;	

		if ((*point).y > 19)
		{

			(*point).y = 5;

		}

	}

	if (entree == 2)
	{
		(*point).x = (*point).x -1;

		if ((*point).x <= 2)
		{
			(*point).x = 78;
		}
	}

	if (entree == 3)
	{
		(*point).x = (*point).x + 1;

		if ((*point).x >=78)
		{
			(*point).x = 2;
		}
	}


}