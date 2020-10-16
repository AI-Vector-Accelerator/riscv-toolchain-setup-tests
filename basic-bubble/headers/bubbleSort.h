/*
 * bubbleSort.h
 *
 *  Created on: 19 Oct 2017
 *      Author: pa4g17
 */

#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_


void copyArray(const int size, const int* inputArray, int* outputArray);
void sort_bubble(const int size, const int* inputArray, int* outputArray);
void elementSwap(int* outputArray, int elm1, int elm2);
void sort_bubbleOneArray(const int size, int* outputArray);



#endif /* BUBBLESORT_H_ */
