/*
 ============================================================================
 Name        : 3Bubble.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#include "./headers/bubbleSort.h"
#include "./headers/array_util.h"

#define ARRAY_SIZE 50

int main(void)
{
	int tidyArray[ARRAY_SIZE];
	int messyArray[ARRAY_SIZE];

	fillArrayRandom(messyArray, ARRAY_SIZE);

	printf("Array Before Sorting: \n");

	showArray(messyArray, ARRAY_SIZE);

	sort_bubble(ARRAY_SIZE, messyArray, tidyArray);

	printf("Array After Sorting: \n");

	showArray(tidyArray, ARRAY_SIZE);

	return 0;
}
