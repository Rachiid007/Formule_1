#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOMBRE 7

int generateNumber(void);


typedef struct {
        int numero;

        int *temps_S1;
        int *temps_S2;
        int *temps_S3;

        int tempsTotal;
} voiture;

voiture tabStuctVoiture[NOMBRE];



int main(void) {

    srand (time(NULL));

    int compteur = 0; // pour savoir si malloc() ou realloc()

    for (int a = 0; a < NOMBRE; a++)
    {
        tabStuctVoiture[a].tempsTotal = 0;
        
        while(tabStuctVoiture[a].tempsTotal <= 5400) {

            if (compteur == 0)
            {
                for (int k = 0; k < NOMBRE; k++)
                {
                    tabStuctVoiture[k].temps_S1 = calloc(1, sizeof(int));
                    if (tabStuctVoiture[k].temps_S1 == NULL) {
                        perror("Problem calloc() !");
                        exit(EXIT_FAILURE);
                    }
                    tabStuctVoiture[k].temps_S1[0] = generateNumber();
                    tabStuctVoiture[a].tempsTotal += tabStuctVoiture[k].temps_S1[0];


                    tabStuctVoiture[k].temps_S2 = calloc(1, sizeof(int));
                    if (tabStuctVoiture[k].temps_S2 == NULL) {
                        perror("Problem calloc() !");
                        exit(EXIT_FAILURE);
                    }
                    tabStuctVoiture[k].temps_S2[0] = generateNumber();
                    tabStuctVoiture[a].tempsTotal += tabStuctVoiture[k].temps_S2[0];



                    tabStuctVoiture[k].temps_S3 = calloc(1, sizeof(int));
                    if (tabStuctVoiture[k].temps_S3 == NULL) {
                        perror("Problem calloc() !");
                        exit(EXIT_FAILURE);
                    }
                    tabStuctVoiture[k].temps_S3[0] = generateNumber();
                    tabStuctVoiture[a].tempsTotal += tabStuctVoiture[k].temps_S3[0];

                }
                compteur++;
            }

            else
            {
                for (int k = 0; k < NOMBRE; k++)
                {
                    tabStuctVoiture[k].temps_S1 = realloc(tabStuctVoiture[k].temps_S1, (compteur + 1) * sizeof(int));
                    if (tabStuctVoiture[k].temps_S1 == NULL) {
                        perror("Problem realloc() !");
                        exit(EXIT_FAILURE);
                    }
                    tabStuctVoiture[k].temps_S1[compteur] = generateNumber();
                    tabStuctVoiture[a].tempsTotal += tabStuctVoiture[k].temps_S1[compteur];


                    tabStuctVoiture[k].temps_S2 = realloc(tabStuctVoiture[k].temps_S2, (compteur + 1) * sizeof(int));
                    if (tabStuctVoiture[k].temps_S2 == NULL) {
                        perror("Problem realloc() !");
                        exit(EXIT_FAILURE);
                    }
                    tabStuctVoiture[k].temps_S2[compteur] = generateNumber();
                    tabStuctVoiture[a].tempsTotal += tabStuctVoiture[k].temps_S2[compteur];


                    tabStuctVoiture[k].temps_S3 = realloc(tabStuctVoiture[k].temps_S3, (compteur + 1) * sizeof(int));
                    if (tabStuctVoiture[k].temps_S3 == NULL) {
                        perror("Problem realloc() !");
                        exit(EXIT_FAILURE);
                    }

                    tabStuctVoiture[k].temps_S3[compteur] = generateNumber();
                    tabStuctVoiture[a].tempsTotal += tabStuctVoiture[k].temps_S3[compteur];
                }
                compteur++;
            }
        }
    }



    for(int i=0; i < NOMBRE; i++)
    {
        printf("%d\n", tabStuctVoiture[i].tempsTotal);

        for(int j = 0; j < compteur; j++)
        {
            printf("%4d",tabStuctVoiture[i].temps_S1[j]);
            printf("%4d",tabStuctVoiture[i].temps_S2[j]);
            printf("%4d",tabStuctVoiture[i].temps_S3[j]);

        }
        printf("\n\n\n");

        free(tabStuctVoiture[i].temps_S1);
        free(tabStuctVoiture[i].temps_S2);
        free(tabStuctVoiture[i].temps_S3);
    }

    
    return 0;
}


int generateNumber(void){
  return (rand() % 14 + 26);
}


/*

    for(int i=0; i < NOMBRE; i++)
    {
        for(size_t j = 0; j < compteur; j++)
        {
        printf("%4d",tabStuctVoiture[i].temps[j]);
        }
        printf("\n");
    }
*/