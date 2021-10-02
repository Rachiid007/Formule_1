#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_CARS 20

int faireDesTours(int i);
int generateNumber(int min, int max);


typedef struct {

        int *temps_S1;
        int *temps_S2;
        int *temps_S3;

        int tempsTotal;
} voiture;

voiture tabStuctVoiture[NUMBER_OF_CARS];


int main(void)
{
    srand( time(NULL) );

    for (int i = 0; i < NUMBER_OF_CARS; i++)
    {
        faireDesTours(i);
        printf("Voiture n°%d --> Temps Total : %d\n", i, tabStuctVoiture[i].tempsTotal);

    }


    return 0;
}

int faireDesTours(int i) {

    int cmpAlloc = 0;
    int numero = 0;


    if( (cmpAlloc == 0) && (tabStuctVoiture[i].tempsTotal <= 5400) )
    {
        /*   ****       S1     ****     */
        numero = generateNumber(25, 40);
        tabStuctVoiture[i].temps_S1 = calloc(1, sizeof(int));
        if (tabStuctVoiture[i].temps_S1 == NULL) {
            perror("Problem calloc() !");
            exit(EXIT_FAILURE);
        }
        tabStuctVoiture[i].temps_S1[0] = numero;
        tabStuctVoiture[i].tempsTotal += numero;
        /* *************************************** */


        /*   ****       S2     ****     */
        numero = generateNumber(25, 40);
        tabStuctVoiture[i].temps_S2 = calloc(1, sizeof(int));
        if (tabStuctVoiture[i].temps_S2 == NULL) {
            perror("Problem calloc() !");
            exit(EXIT_FAILURE);
        }
        tabStuctVoiture[i].temps_S2[0] = numero;
        tabStuctVoiture[i].tempsTotal += numero;
        /* *************************************** */


        /*   ****       S3     ****     */
        numero = generateNumber(25, 40);
        tabStuctVoiture[i].temps_S3 = calloc(1, sizeof(int));
        if (tabStuctVoiture[i].temps_S3 == NULL) {
            perror("Problem calloc() !");
            exit(EXIT_FAILURE);
        }
        tabStuctVoiture[i].temps_S3[0] = numero;
        tabStuctVoiture[i].tempsTotal += numero;
        /* *************************************** */


        cmpAlloc++;
    }

    if ((cmpAlloc > 0) && (tabStuctVoiture[i].tempsTotal <= 5400)) {

        while ((cmpAlloc > 0) && (tabStuctVoiture[i].tempsTotal <= 5400))
        {
            if (tabStuctVoiture[i].tempsTotal >= 5400)
            {
                break;
            }
            /*   ****       S1     ****     */
            numero = generateNumber(25, 40);
            tabStuctVoiture[i].temps_S1 = realloc(tabStuctVoiture[i].temps_S1, (cmpAlloc + 1) * sizeof(int));
            if (tabStuctVoiture[i].temps_S1 == NULL) {
                perror("Problem realloc() !");
                exit(EXIT_FAILURE);
            }
            
            tabStuctVoiture[i].temps_S1[cmpAlloc] = numero;
            tabStuctVoiture[i].tempsTotal += numero;
            /* *************************************** */


            if (tabStuctVoiture[i].tempsTotal >= 5400)
            {
                break;
            }
            /*   ****       S2     ****     */
            numero = generateNumber(25, 40);
            tabStuctVoiture[i].temps_S2 = realloc(tabStuctVoiture[i].temps_S2, (cmpAlloc + 1) * sizeof(int));
            if (tabStuctVoiture[i].temps_S2 == NULL) {
                perror("Problem realloc() !");
                exit(EXIT_FAILURE);
            }
            
            tabStuctVoiture[i].temps_S2[cmpAlloc] = numero;
            tabStuctVoiture[i].tempsTotal += numero;
            /* *************************************** */


            if (tabStuctVoiture[i].tempsTotal >= 5400)
            {
                break;
            }
            /*   ****       S3     ****     */
            numero = generateNumber(25, 40);
            tabStuctVoiture[i].temps_S3 = realloc(tabStuctVoiture[i].temps_S3, (cmpAlloc + 1) * sizeof(int));
            if (tabStuctVoiture[i].temps_S3 == NULL) {
                perror("Problem realloc() !");
                exit(EXIT_FAILURE);
            }
            
            tabStuctVoiture[i].temps_S3[cmpAlloc] = numero;
            tabStuctVoiture[i].tempsTotal += numero;
            /* *************************************** */


            cmpAlloc++;
        }

    }



    free(tabStuctVoiture[i].temps_S1);
    free(tabStuctVoiture[i].temps_S2);
    free(tabStuctVoiture[i].temps_S3);


    return 0;
}

int generateNumber(int min, int max){

    return (rand() % (max - min+1)) + min;
}
