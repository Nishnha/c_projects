/*
 * Nishant Sinha
 * System Level - MW 1:30
 * Ji Li
 * Homework 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int* makeRandIntArray ();

int cmp          (const void* p, const void* q);
int stdlib_qsort (int* array);
int mySortTimer  (int* array);

void mySort       (int* array);
void printTime    (float t);
void printSize    (int arraySize);
void printSchema  ();
void printNewline ();

#define INITIAL_ARRAY_SIZE 2;
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

    int *array = malloc(arraySize * sizeof(int));
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
    return ( *(int*) p - *(int*)q );
}

/*
 * Performs qsort function from stdlib given an input array
 * @returns the time the function took to sort the array in seconds
 */
int stdlib_qsort(int* array)
{
    clock_t t1, t2;
    t1 = clock();
    qsort((int *) array, sizeof(array)/sizeof(int), sizeof(int), cmp);
    t2 = clock();

    return (t2-t1) / ((float) CLOCKS_PER_SEC);
}

/*
 * Performs selection sort given an input array
 * @returns nothing
 * The input array is sorted in place
 */
void mySort(int* array)
{
    bool sorted = false;

    int temp;

    while (!sorted) {
        for (int i = 0; i < sizeof(array) / sizeof(int) - 1; i++)
        {
            sorted = true;

            if (array[i] > array[i + 1])
            {
                sorted = false;
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

/*
 * Calls mySort on the input array
 * @returns the time the function took to sort the array in seconds
 */
int mySortTimer(int* array)
{
    clock_t t1, t2;
    t1 = clock();
    mySort(array);
    t2 = clock();

    return (t2-t1) / ((float) CLOCKS_PER_SEC);
}

/*
 * Prints the difference between two times in seconds
 */
void printTime(float t)
{
    printf("%fs\t", t);
}

/*
 * Prints the size of the array
 */
void printSize(int arraySize)
{
    printf("%d\t\t", arraySize);
}

/*
 * Prints the formatted starting output schema
 */
void printSchema()
{
    printf("Size\t\tqsort\t\tmerge sort\n");
}

/*
 * Prints a newline
 */
void printNewline()
{
    printf("\n");
}

void printArray(int *array)
{
    printNewline();
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d, ", array[i]);
    }
    printNewline();
}

int main()
{
    printSchema();

    /*
     * Runs the two sorting functions with random integer arrays of size
     * 10000, 20000, 40000, 80000
     */
    for (int i = 0; i < 4; i++) {
        array1 = makeRandIntArray();
        printArray(array1);
        printTime(stdlib_qsort(array1));
        printArray(array1);

        array2 = makeRandIntArray();
        printArray(array2);

        printTime(mySortTimer(array2));
        printArray(array2);

        printSize(arraySize);

        arraySize = arraySize * 2;
        free(array1);
        free(array2);

        array1  = makeRandIntArray();
        array2 = makeRandIntArray();

    }

    return (0);
}




