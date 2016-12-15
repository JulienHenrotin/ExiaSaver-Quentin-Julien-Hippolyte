char testLettre(char lettre, int entree)
{

	printf("commande ? : " );
	scanf("%c",&lettre);

	if (lettre == 'h')
    	{
    		entree = 0;
    	}

    else if (lettre == 'b')
        {
            entree = 1;
        }

    else if (lettre == 'g')
        {
            entree = 2;
        }
    else if (lettre == 'd')
        {
            entree = 3;
        }

    else if (lettre == 'e')
    {
            entree = 4;
    }

    


    return entree;



}