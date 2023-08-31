#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr1 = (int *)malloc(4 * sizeof(int)); // Allocate memory for 4 integers

    if (arr1 == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Return an error code
    }

    printf("Starting address of arr1: %d\n", (void *)arr1);
    printf("Ending address of arr1: %d\n", (void *)(arr1 + 3));

    int *arr2 = (int *)(arr1 + 4); // Start second array from the end address of arr1

    printf("Starting address of arr2: %d\n", (void *)arr2);

    arr1 = (int *)realloc(arr1, 6 * sizeof(int)); // Reallocate memory for 6 integers

    if (arr1 == NULL) {
        printf("Memory reallocation failed.\n");
        return 1; // Return an error code
    }

    printf("Starting address of new arr1: %d\n", (void *)arr1);
    printf("Ending address of new arr1: %d\n", (void *)(arr1 + 5));

    return 0;
}


/*
we have allocated 12 bytes of memory for arr1 
we have created another arary with length 2 and allocated memory contigiously from end address of arr1
now when we use calloc to increase memory size of arr1 it can not allocate memory to previos location because it is already occupied by arr2
hence realloc copies old elements of arr1 and allocate new memory of 20 bytes

*/

