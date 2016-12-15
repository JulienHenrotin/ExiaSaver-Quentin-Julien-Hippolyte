#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <sys/wait.h>


//Bibliothèque contenant les fonctions pour le parcours de dossiers
#include <dirent.h>

// Si le système n'est pas windows, alors inclure sys/types.h
#ifndef WIN32
    #include <sys/types.h>
#endif

//On inclut les prototypes des fonctions du launcher
#include "launcher.h"

#define FALSE 0
#define TRUE 1
#define TAILLE_MAX 40

// int main(int argc, char * argv[])
// {
// 	menu();
// 	int choix_type;
// 	int choix_image;
// 	saveDate(choix_type,choix_image);
// 	//lanceurProcess (agrc, * argv[]);
// 	//statistiques();


// }

int menu(int argc,char *argv[])
{
	system("clear");
	srand(time(NULL));
	int choix_type=nb_rand()%3+1;

	// int nb_I_S;
	// nb_I_S = nombreImagesStatique();

	int choix_image=nb_rand()%5+1;

	printf("Bonjour et bienvenue dans exiaSaver !\nVeuillez appuyez sur Entrée pour continuer...");
	getchar();
	printf("\nNous allons voir ensemble quel écran de veille nous allons lancer\nVeuillez appuyez sur Entrée pour continuer...\n\n");
	getchar();
	printf("Le nombre random est de : %d\n\n", choix_type);
	if (choix_type == 1)
	{
		printf("Nous allons lancer le type statique !\n");


		//L'IMAGE QUE L'ON VA LANCER
		/*switch (nbPic)
		{
		case 1:
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
		break;
		}*/
	}
	else if (choix_type == 2)
	{
		printf("Nous allons lancer le type dynamique !\n");
	}
	else if (choix_type == 3)
	{
		printf("Nous allons lancer le type interactif !\n");
	}
	return choix_type;
}

//FONCTION NOMBRE RANDOM

int nb_rand(void)
	{
	    return (rand());
	}


//FONCTION POUR EXPORTER DANS L'HISTORIQUE

void saveDate(int type, int nombrePicture)
{
	FILE* fhistorique = NULL; //initialise le pointeur à NULL
	fhistorique = fopen("historique.txt", "r+"); //OUVRE LE FICHIER historique.c

	if (fhistorique != NULL) //Vérifie si le fichier est bien ouvert, car si fichier=NULL signifie qu'il y a une erreur
	{
		printf("\nSuccès pour l'ouverture de l'historique.\n");

		//RECUPERER L'HEURE ET LA DATE

		//Lire l'heure courante
		time_t HeureDate;
		HeureDate = time(NULL);

		//Convertir l'heure en heure locale
		struct tm tm_HeureDate = *localtime (&HeureDate);

		//Crée une chapine JJ/MM/AAAA HH:MM:SS
		char s_HeureDate[sizeof "JJ/MM/AAAA HH:MM:SS"];

		strftime (s_HeureDate, sizeof s_HeureDate, "%d/%m/%Y %H:%M:%S", &tm_HeureDate);


		fseek(fhistorique, 0, SEEK_END); //Place le curseur à la fin du fichier

		//Récupère le paramètre associé



		//ECRITURE DE TOUTES LES DONNEES (SAUF PARAMETRE) DANS L'HISTORIQUE

		fseek(fhistorique, 0, SEEK_END); //Place le curseur à la fin du fichier

		//Ecrit la date
		fseek(fhistorique, 0, SEEK_END);
		fprintf(fhistorique,"%s", s_HeureDate);
		fprintf(fhistorique,";");

		//Ecrit le type lancé
		fseek(fhistorique, 0, SEEK_END);
		fprintf(fhistorique, "%d", type);
		fseek(fhistorique, 0, SEEK_END);
		fprintf(fhistorique,";\n");


		//ECRITURE DES PARAMETRES ASSOCIES AU TERMSAVER CHOISI
		if(type == 1)
		{
			//Ecrit l'image utilisé pour le type statique
			switch (nombrePicture)
			{
				case 1:
					fseek(fhistorique, 0, SEEK_END);
					fprintf(fhistorique,"test.pbm\n");
				break;
				case 2:
					fseek(fhistorique, 0, SEEK_END);
					fprintf(fhistorique,"test.pbm\n");
				break;
				case 3:
					fseek(fhistorique, 0, SEEK_END);
					fprintf(fhistorique,"test.pbm\n");
				break;
				case 4:
					fseek(fhistorique, 0, SEEK_END);
					fprintf(fhistorique,"test.pbm\n");
                break;
                case 5:
                    fseek(fhistorique, 0, SEEK_END);
					fprintf(fhistorique,"test.pbm\n");
				break;
			}
		}
		else if (type == 2)
		{
			fseek(fhistorique, 0, SEEK_END);
			fprintf(fhistorique,"\n");
		}
		else if (type == 3)
		{
			fseek(fhistorique, 0, SEEK_END);
			fprintf(fhistorique,"\n");
		}
		fclose(fhistorique);//FERME LE FICHIER
		printf("Ecriture dans l'historique réussie\n\n");

	}
	else
	{
		printf("\nImpossible d'ouvrir le fichier historique...");
	}
}

FILE* fichierstats = NULL;                                              /*Déclare la variable fichierstats comme variable globale fichier*/
char chainehisto[40960][40];                                            //Donne a chainehisto des valeurs globales

int transformation(int n)                                               //Fonction permettant la transformation du code uni en valeur
{                                                                       //La récupération du char en int donne des code uni
    switch(n){                                                          //Ici on les transforme en entier, ce qui...
        case 49:                                                        //Leur redonne la valeur d'origine
            n=1;
            break;
        case 50:
            n=2;
            break;
        case 51:
            n=3;
            break;
    }
    return n;
}

void tri_bulle(int n)                                                   //Fonction de tri à bulle ( Se ref. wikipedia tri a bulle)
{
    int j = 0;                                                          //Déclaration d'un compteur entier
    char tmp[2][40];                                                    //Déclaration d'un tableau de char en 2D de 2x40
    int pastrie = 1;                                                    //Déclaration d'un int pastrie, si 1 alors le tri n'est pas finit                                                              //
    int a;                                                              //Déclaration d'un entier prenant le code UNI d'un char
    int b;                                                              //Déclaration d'un entier prenant le code UNI d'un char
    char temp;                                                          //Déclaration d'une variable char tempon, contient la chaine en cours de transfert dans le tri à bulle
    int typea=0;                                                        //Déclaration de variable contenant le nombre de fois qu'est utilisé l'ES pour les statiques
    int typeb=0;                                                        //Déclaration de variable contenant le nombre de fois qu'est utilisé l'ES pour les dynamiques
    int typec=0;                                                        //Déclaration de variable contenant le nombre de fois qu'est utilisé l'ES pour les intéractifs
    while(pastrie)                                                      //Boucle qui tourne tant que le tri n'est pas finis
    {
        pastrie=FALSE;                                                  //Définit de base le tri comme non finit (juste pour être sur)
        for(j=0;j<n;j++)                                                //Boucle qui tourne jusqua que toute les lignes du char chainehisto soient traitées
        {
            a=(int) chainehisto[j][20];                                 //Prend la valeur UNI du char étant à la ligne J au rand 20, emplacement exacte du numéro de mode dans le fichier histo
            b=(int) chainehisto[j+1][20];                               //Prend la valeur UNI du char étant à la ligne J+1 (la ligne suivante la varible a ) au rand 20
            a=transformation(a);                                        //Ici on appelle la fonction transformation pour transformer le code UNI en int
            b=transformation(b);

            if(a>b){                                                    //Si, grace a la transformation on comprend que a est supérieur à b, alos...
                strcpy(tmp[0],chainehisto[j+1]);                        //On effectue le tri à bulle c-a-d on prend le trop grand, on le met dans une variable temporaire
                strcpy(chainehisto[j+1],chainehisto[j]);                //Ensuite on met le plus petit à la place du plus grand et on met le plus grand a la place du plus petit.
                strcpy(chainehisto[j],tmp[0]);                          //Grace a ça on ecrase aucune donnée.
                pastrie=TRUE;                                           //On signale le tri comme terminé mais ne sera effectife que quand le boucle for sera finie
            }
            
        }
    }
    n=n+1;                                                              //On incrémente n, car le 0 étant compté precedement pour le déplacement dans les tableaux, pour avoir un affichage plus propre pour l'utilisateur
    for (j=0; j<n; j++){                                                //Ici on affiche la chainehisto trié ligne par ligne
        printf("%s",chainehisto[j]);                                    //Tant que toutes les lignes ne sont pas passées
        a=(int) chainehisto[j][20];                                     //On récupère de nouveau la valeur UNI
        a=transformation(a);                                            //On la traite
        switch(a){                                                      //Et en fonction du résultat on incrément des variables pour
                case 1:                                                 //donner à l'utilisateur les statistiques et le
                    typea++;                                            // nombre de fois que chaque ES à été lancé.
                    break;
                case 2:
                    typeb++;
                    break;
                case 3:
                    typec++;
                    break;
            }
    }
    typec=typec-1;
    printf("Vous avez lancé %d fois l'ExiaSaver statique, %d fois le dynamique et %d fois l'interactif ! \n",typea,typeb,typec);
}

void statistiques()                                                 //Fonction permettant l'affichage des statistiques
{
    char chaine[TAILLE_MAX] = "r";                                  //Variable chaine définie avec une taille par DEFINE qui contiendra la chaine en cours d'utilisation
    int modetri;                                                    //Varibale qui contient le mode de triage choisit par l'utilisateur
    int i=0;                                                          //Variable qui sert de compteur pour le nombre de ligne dans le fichier historique
    int j;                                                          //Compteur
    int n;                                                          //Compteur
    fichierstats = fopen("historique.txt", "r" );                       //Ouvre le fichier d'historique avec les droits de lecture
    if (fichierstats==NULL){ 
                printf("Erreur d'ouverture fichier");               //Affiche une erreur si le fichier n'est pas ouvrable
            }                                                        
    while (strcmp(chaine," ")!=0)                                   //Tant que la variable chaine ne contient pas un blanc....
    {
        fgets(chaine, TAILLE_MAX, fichierstats);                    //On récupère ligne par ligne le fichier historique et....
        if (strcmp(chaine," ")!=0)                                  //Si ce qu'on recupère n'est toujours pas un blanc
        {
            strcat(chainehisto[i], chaine);                         //On colle ce qu'on vient de récuperer dans une variable char tampon qui contiendra alors l'ensemble du fichier historique sous forme de varibale, le tout dans le bon format (saut de lignes inclus)
        }
        i++;                                                        //On incrément i pour ajouter chaine dans une autre ligne du tableau chainehisto ( pour garder un format lisible)
    }
    fclose(fichierstats);                                           //On ferme le fichier historique
    i=i-1;                                                          //On decrémente i une fois car la boucle while nous compte une ligne de trop
    while (modetri!=1 && modetri!=2 && modetri!=3)                  //Ici tant que l'utilisateur rentre pas un mode de tri valide on continue de demander
    {
        printf("Pour trier par date tapez 1, par type tapez 2 et par dates inversées tapez 3 :\n");
        scanf("%d",&modetri);                                       //On place dans la varible modetri le choix de l'utilisateur
    }
    printf("Voici votre historique ");
    switch(modetri){                                                //Ici en fonction du choix de l'utilisateur, on lance nos différents tri
        case 1:                                                     //Si modetri=1 ....
            printf("trié par date:\n\n");
            for (j=0;j<i;j++){                                      //Ici on affiche ligne par ligne avec le compteur j qu'on incrémente...
                printf("Utilisation N°%d:  ",j+1);                  //les différentes lignes du tableau chainehisto
                printf("%s\n",chainehisto[j]);
            }
            printf("Vous avez lancé %d fois ExiaSaver !\n",i);      //On indique à l'utilisateur combien de fois il a utilisé l'ES
            break;                                                  //Met fin au cas 1
        case 2:                                                     //Si modetri=2 ....
            printf("trié par type:\n\n");
            tri_bulle(i);                                           //On appelle la fonction tri à bulle avec l'argument i, qui est le nombre de lignes
            
            break;
        case 3:                                                     //Si modetri=3 ....
            printf("trié par dates inversées:\n\n");
             for (j=i;j>=0;j--){                                    //On inverse la boucle du mode 1
                printf("Utilisation N°%d:  ",j+1);                  //ce qui a pour effet d'afficher dans l'autre sens
                printf("%s\n",chainehisto[j]);                      //les entrées de chainehisto
            }
            printf("Vous avez lancé %d fois ExiaSaver !\n",i);      //On indique à l'utilisateur combien de fois il a lancé l'ES
            break;
    }

}

// char getch()                                                            /*Fonction getch de windows, importée sur Linux. SNIPPET TROUVE SUR INTERNET*/
// {
//     char buf=0;                                                         /*Permet de capter l'utilisation du clavier par l'utilisateur*/
//     struct termios old={0};

//     fflush(stdout);
//     if(tcgetattr(0, &old)<0)
//         perror("tcsetattr()");
//     old.c_lflag&=~ICANON;
//     old.c_lflag&=~ECHO;
//     old.c_cc[VMIN]=1;
//     old.c_cc[VTIME]=0;
//     if(tcsetattr(0, TCSANOW, &old)<0)
//         perror("tcsetattr ICANON");
//     if(read(0,&buf,1)<0)
//         perror("read()");
//     old.c_lflag|=ICANON;
//     old.c_lflag|=ECHO;
//     if(tcsetattr(0, TCSADRAIN, &old)<0)
//         perror ("tcsetattr ~ICANON");
//     printf("%c\n",buf);
//     return buf;
// }

int lanceurProcess (int argc, char * argv[])
{
    char data[16];                                              //Variable contenant le pramètre de lancement du ScreenSaver
    char *fichier;                                              //Variable contenant le nom du fichier à executer pour le ScreenSaver
    int f;														//Variable pour le Fork. Contient 0 si fils et le PID du processus si père
    int choix_type; 
    int status;                                             
                                                     //Variable contenant une valeur aléatoire en 1 et 3 pour le lancement du SS

    // system("clear");                                            //Commande vidant la console, affiche plus propre
    if (argc>1)                                                 //Condition valide si agrc (nombre de paramètres lancés avec ES) est supérieur à 1
    {
        if (strcmp(argv[1],"-stats"))                           //Condition valide si argv (valeur des pramètres lancés avec ES) vaut -stats
        {
            printf("Erreur de paramètres\n");                   
        }
        else
        {
            printf("Lancement des stats...\n");
            statistiques();                                     //Lancement de la fonction statistiques
        }
    }  
    else                                                        //Arrive ici si le ES n'est pas lancé avec des arguments
    {
        printf("Lancement du screensaver...\n");
        //srand(time(NULL));                                      //Graine permettant d'éviter la repetition lors du randomize
        //random = rand();                                        //Place dans random une valeur aléatoire sans limites à partir de la seed
        //random = (random%3);                                    //%3 réduit le résultat à une plage en 0 et 2 soit 3 valeurs
        if (choix_type==1)                                          //Si le nombre genere est 0 alors...
        {
            f=fork();                                           //Lance un processus fils 
            if (f==0)                                           //Uniquement le processus fils avec un PID de 0 peut entrer dans la boucle
            {
                //strcpy(data,"chateau.pbm");                  //On met la chaîne de caractère grenouille.pbm dans la variable data
                //saveDate(choix_type,*data);                  //On entre dans la fonction entreehistorique avec les arguments random et data
                //fichier="AFFPBM";                            //On donne à fichier la chaine de caratcère afficheur qui correspond au fichier à ouvrir
                printf("Demarrage du statique\n");
                execl(fichier,fichier,"666","666",data,NULL);       //On execute le fichier afficheur avec l'argument 666 qui position au centre de la console l'image
                exit(1);                                        //On tue le processus fils
            }
            else                                                
            {
                wait(&status);                                         //Sinon le père attend l'arrivée ou la mort du fils
            }
        }
        if (choix_type==2)
        {
            f=fork();
            if (f==0)
            {
                //strcpy(data,"10x10");                           //On rentre dans data des valeurs
                //saveDate(choix_type,*data);                  
                printf("Demarrage du dynamique\n");
                exit(1);
            }
            else
            {
                wait(&status);
            }
        }
        if (choix_type==3)
        {
            f=fork();
            if (f==0)
            {
                //strcpy(data,"20x20");
                //saveDate(choix_type,*data);
                //fichier="screensaver";
                printf("Demarrage de l'interactif\n");
                execl(fichier,fichier,"20","20","2",NULL);
                perror("Erreur: ");
                exit(1);
            }
            else
            {
                wait(&status);
            }
        }
    }
   
    return 0;
}

int main(int argc, char * argv[])
{
	menu(argc,argv);
	int choix_type;
	int choix_image;
	saveDate(choix_type,choix_image);
	lanceurProcess (argc,argv);


}