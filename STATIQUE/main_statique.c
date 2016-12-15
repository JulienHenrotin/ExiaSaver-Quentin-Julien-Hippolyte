#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ncurses.h>
#include <dirent.h> 
#include <sys/types.h>

#define img1 "PBM_STATIQUE/chateau.pbm"
#define img2 "PBM_STATIQUE/carre.pbm"
#define img3 "PBM_STATIQUE/croix.pbm"
#define img4 "PBM_STATIQUE/img1.pbm"
#define img5 "PBM_STATIQUE/rond-grille.pbm"




void convertPBM (int largeur,int hauteur,int randnbIMG)
{

 
  char **tab;
  char caractereActuel = 'a';
  char caractereImage = 'W';          //Initialisation des variables
  int blanc = 219;
  int noir = 255;
  initscr();                              //Initialisation Windows
  int posline = LINES/2 - hauteur/2;       //Position curseur
  int poscol = COLS/2 - largeur/2;
  move(posline,poscol); 
  FILE *fichier = NULL;
  
  switch (randnbIMG)
        {
          case 1:
            fichier = fopen(img1, "r+");        
          break;
          case 2:
            fichier = fopen(img2, "r+");
          break;
          case 3:
            fichier = fopen(img3, "r+");
          break;
          case 4:
            fichier = fopen(img4, "r+");
          break;
          case 5:
            fichier = fopen(img5, "r+");
          break;
        }

  tab = malloc((hauteur) * sizeof(char*));             // allocation mémoire tableau
  for (int i = 0 ; i < largeur ; i++)
    {
      tab[i] = malloc((largeur) * sizeof(char));
    }
    for (int i = 0; i < hauteur; ++i)
    {
        for (int j = 0; j < largeur; ++j)
        {
            tab[i][j]=0;
        }
    }

 
   for (int a = 0; a < 2; ++a)
    {
                           
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
        } while (caractereActuel != '\n'); // On continue tant que fgetc n'a pas retourné \n (saut de ligne)

    }

    for (int i = 0; i < hauteur; ++i)                     // écriture tableau
    {
        for (int j = 0; j < largeur; ++j)
        {
            
            caractereImage = fgetc (fichier);     //Traittement des valeurs 

            switch (caractereImage){              //Assignation cacartère ASCII pour les valeurs du fichier PBM

                case '0':
                    tab[i][j]= noir;
                    break;

                case '1':
                    tab[i][j]= blanc;
                    break;

                case ' ':                       //Non prise en compte des " " dans l'affichage
                    j--;
                    break;

                default:
                    tab[i][j]=' ';
                    break;
            }

   

        }
    }
    
  fclose(fichier);

    for (int i = 0;i < hauteur; ++i)                     // Boucle pour sauter les lignes
    {
      for (int j = 0;j < largeur; ++j)                 // Boucle pour sauter les colonnes
        {
          
          printw("%c", tab[i][j-1]);            //Affichage tableau dans screan windows
          move(posline,poscol);
          poscol ++;
          
        }
    posline ++;
    poscol = COLS/2 - largeur/2;

    move(0,0);               //Position final curseur
    }
  refresh();
  getch();
  endwin();        //fermeture windows
}

int main()
  {
    char caractereActuel;
    char largeur[3];               //Initialisation des variables
    char hauteur[4];
    int largeurInt;
    int hauteurInt;
   //  int i = 0;
    // int nombre_aleatoire = 0;
    srand(time(NULL));
    FILE *fichier = NULL;
    // int nbIMGstat;
    // nbIMGstat = nombreImagesStatique();  // Choix aléatoire entre les images
    int randnbIMG = rand()%5+1;


    
      //Ouverture image = au nombre aléatoire
      switch (randnbIMG)
      {
        case 1:
          fichier = fopen(img1, "r+");        
        break;
        case 2:
          fichier = fopen(img2, "r+");
        break;
        case 3:
          fichier = fopen(img3, "r+");
        break;
        case 4:
          fichier = fopen(img4, "r+");
        break;
        case 5:
          fichier = fopen(img5, "r+");
        break;
      }
    
  
  
    if (fichier != NULL)
     {
      // Boucle de leecture des caractères un à un
         do
           {
             caractereActuel = fgetc(fichier); // On lit le caractère
          }
       while (caractereActuel != '\n'); // On continue tant que fgetc n'a pas retourné \n (saut de ligne)
        fgets (largeur,3,fichier);
        fgets (hauteur,4,fichier);
        largeurInt = atoi (largeur)+1;             //Récupération de la hauteur et de la largeur du fichier PBM
        hauteurInt = atoi (hauteur)+1;
        printf("%d&%d\n",largeurInt,hauteurInt );
        fclose(fichier); 
        
  }
  convertPBM(largeurInt,hauteurInt,randnbIMG);
 return (randnbIMG);
}

