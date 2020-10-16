/*
 * bubbleSort.c
 *
 *  Created on: 19 Oct 2017
 *      Author: pa4g17
 */

#define True 1
#define False 0

#include <stdio.h>

#include "../headers/bubbleSort.h"

void copyArray(const int size, const int* inputArray, int* outputArray)
{
	for(int i = 0; i < size; i++)
	{
		outputArray[i] = inputArray[i];
		printf("output[%d]: %d \t input[%d]: %d\n", i, outputArray[i], i, inputArray[i]);
	}
	fflush(stdout);
}

void elementSwap(int* outputArray, int elm1,int elm2)
{
	int holder = 0;
	holder = outputArray[elm1];
	outputArray[elm1] = outputArray[elm2];
	outputArray[elm2] = holder;
	/*printf("Holder: %d elm1: %d elm2: %d\n", holder, outputArray[elm1], outputArray[elm2]);*/
	return;
}


void sort_bubble(const int size, const int* inputArray, int* outputArray)
{
	printf("Sort Started\n");
	int swapped = True;
	int i;
	copyArray(size, inputArray, outputArray);

	while(swapped == True)
	{
		swapped = False;
		for(i = 1; i <= size; i++)
		{
			if(outputArray[i - 1] > outputArray[i])
			{
				/*printf("Swapping two numbers\n");*/
				elementSwap(outputArray, i, i - 1);
				swapped = True;

			}
		}
	}

	printf("Array Sorted!\n");
	return;
}

void sort_bubbleOneArray(const int size, int* outputArray)
{

	int swapped = False;
	int i;

	while(swapped)
	{
		swapped = False;
		for(i = 1; i <= size; i++)
		{
			if(outputArray[i-1] > outputArray[i])
			{
				/*printf("Swapping two numbers\n");*/
				elementSwap(outputArray, i, i-1);
				swapped = True;

			}
		}
	}

	printf("Array Sorted!\n");
	return;
}



