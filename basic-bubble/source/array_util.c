#include <stdio.h>
#include <time.h>

#include "../headers/array_util.h"

void fillArrayRandom(int* array, const int size)
{
    int i;

    printf("Filling an array..");
    srand(34533453);
    for(i=0; i<size; i++)
    {
        array[i] = rand() % 1000;
    }

    printf("\ndone.\n");

    return;
}

/*
    This function does not modify the array content,
    so we declare the first argument as "const",
    even though it is still a pointer..
*/

void showArray(const int * array, const int size)
{
    int j;

    printf("\n");
    printf("Showing an array:\n");

    for(j=0; j<size; j++)
    {
        printf("element %d: %d\n", j, array[j]);
        /*
        because we declared the first argument
        as const the following would cause a compiler error: try!
        array[j] = 0;
        */
    }

    return;
}
