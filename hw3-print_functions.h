void printTime     (float t);
void printSize     (size_t size);
void printSchema   ();
void printNewline  ();
void printArray    (int *array, size_t size);

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
void printSize(size_t size)
{
    printf("%d\t\t", size);
}

/*
 * Prints the formatted starting output schema
 */
void printSchema()
{
    printf("Size\t\tqsort\t\tmy sort\n");
}

/*
 * Prints a newline
 */
void printNewline()
{
    printf("\n");
}

/*
* Prints the array
*/
void printArray(int *array, size_t size)
{
    printNewline();
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printNewline();
}
