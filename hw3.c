/*
 * Nishant Sinha
 * System Level - MW 1:30
 * Ji Li
 * Homework 3
 *
 * UNCOMMENT THE LINES IN MAIN TO VIEW THE ARRAYS
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hw3-print_functions.h"

int* makeRandIntArray ();
int  cmp           (const void* p, const void* q);
void mySort        (int* array, size_t size);
float stdlib_qsort (int* array, size_t size);
float mySortTimer  (int* array, size_t size);

#define INITIAL_ARRAY_SIZE 10000;
int  arraySize = INITIAL_ARRAY_SIZE;
int *array1    = NULL;
int *array2    = NULL;

/*
 * Creates an integer array filled with random integers
 * @returns the address of the array
 */
int* makeRandIntArray()
{
    const int LARGEST_INT_SIZE = 10000;

    int *array = (int *)malloc(arraySize * sizeof(int));
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = rand() % LARGEST_INT_SIZE;                                   // % limits the size of ints
    }

    return (int *) array;
}

/*
 * Compare function used for qsort from stdlib
 */
int cmp (const void* p, const void* q)
{
    return ( *(int*)p - *(int*)q );
}

/*
 * Performs qsort function from stdlib given an input array
 * @returns the time the function took to sort the array in seconds
 */
float stdlib_qsort(int* array, size_t size)
{
    clock_t t1, t2;
    t1 = clock();
    qsort((int *) array, size, sizeof(int), cmp);
    t2 = clock();

    return (float) (t2-t1) / ((float) CLOCKS_PER_SEC);
}

/*
 * Performs selection sort given an input array
 * @returns nothing
 * The input array is sorted in place
 */
void mySort(int* array, size_t size)
{
    int sorted = 0;

    int temp;

    do {
        sorted = 1;

        for (int i = 0; i < size - 1; i++)
        {

            if (array[i] > array[i + 1])
            {
                sorted = 0;
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    } while (sorted != 1);
}

/*
 * Calls mySort on the input array
 * @returns the time the function took to sort the array in seconds
 */
float mySortTimer(int* array, size_t size)
{
    clock_t t1, t2;
    t1 = clock();
    mySort(array, size);
    t2 = clock();

    return (float) (t2-t1) / ((float) CLOCKS_PER_SEC);
}


int main()
{
    printSchema();

    /*
     * Runs the two sorting functions with random integer arrays of size
     * 10000, 20000, 40000, 80000
     */
    for (int i = 0; i < 4; i++) {
        printSize(arraySize);

        array1 = makeRandIntArray();
        // printArray(array1, arraySize);
        printTime(stdlib_qsort(array1, arraySize));
        // printArray(array1, arraySize);

        array2 = makeRandIntArray();
        // printArray(array2, arraySize);
        printTime(mySortTimer(array2, arraySize));
        // printArray(array2, arraySize);

        printNewline();
        arraySize = arraySize * 2;
        free(array1);
        free(array2);

        array1 = makeRandIntArray();
        array2 = makeRandIntArray();

    }

    return (0);
}
