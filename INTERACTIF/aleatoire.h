int aleatoire(int mystere,int min,int max)
{

	srand(time(NULL));
	mystere = (rand() % (max - min + 1)) + min;

	return mystere;


}