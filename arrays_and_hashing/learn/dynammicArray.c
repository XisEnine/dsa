// dynamic array in C*/
/*#include <stdio.h>*/
/*#include <stdlib.h>*/
/**/
/*// structure*/
/*typedef struct {*/
/*  int *items;      // the actual array which will hold the elements.*/
/*  size_t size;     // the actual size of the array.*/
/*  size_t capacity; // the max size of the array which will get adjusted when*/
/*                   // more space is needed.*/
/*} Numbers;*/
/**/
/*int main(void) {*/
/*  Numbers arr = {0}; // This sets everything to zero (items = NULL, size = 0,*/
/*                     // capacity = 0).*/
/*  for (int i = 0; i < 10; ++i) {*/
/*    if (arr.size == arr.capacity) {*/
/*      if (arr.capacity == 0)*/
/*        arr.capacity = 256;*/
/*      else*/
/*        arr.capacity *= 2;*/
/*      arr.items = realloc(*/
/*          arr.items,*/
/*          arr.capacity **/
/*              sizeof(*arr.items)); // realloc() gives us a bigger memory block*/
/*                                   // while keeping the existing numbers. We*/
/*                                   // multiply by sizeof(*arr.items) to allocate*/
/*                                   // the right amount of memory for the array.*/
/*    }*/
/*    arr.items[arr.size++] = i;*/
/*  }*/
/*  for (int i = 0; i < arr.size; i++) {*/
/*    printf("%d ", arr.items[i]);*/
/*  }*/
/**/
/*  return 0;*/
/*}*/

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct Numbers
 * @brief Structure to represent a dynamic array of integers
 * 
 * This structure holds the necessary information to maintain a
 * dynamically sized array of integers that grows as needed.
 */
typedef struct {
    int *items;      /**< Pointer to the actual array of integers */
    size_t size;     /**< Number of elements currently stored */
    size_t capacity; /**< Total allocated capacity */
} Numbers;

/**
 * @brief Initializes a dynamic array
 * 
 * Sets all members of the array structure to their default values.
 * Must be called before using any other functions on the array.
 * 
 * @param[out] arr Pointer to the Numbers structure to initialize
 */
void initArray(Numbers *arr) {
    arr->items = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

/**
 * @brief Resizes the array to accommodate more elements
 * 
 * Doubles the current capacity of the array, or sets it to 2 if
 * the array is currently empty.
 * 
 * @param[in,out] arr Pointer to the Numbers structure to resize
 * @return 1 on success, 0 on memory allocation failure
 */
int resizeArray(Numbers *arr) {
    size_t new_capacity = (arr->capacity == 0) ? 2 : arr->capacity * 2;
    int *new_items = realloc(arr->items, new_capacity * sizeof(*arr->items));
    
    if (!new_items) {
        return 0; /* Memory allocation failed */
    }
    
    arr->items = new_items;
    arr->capacity = new_capacity;
    return 1; /* Success */
}

/**
 * @brief Inserts an element at the end of the dynamic array
 * 
 * Adds a new integer to the end of the array, automatically
 * resizing the array if necessary.
 * 
 * @param[in,out] arr Pointer to the Numbers structure
 * @param[in] value The integer value to insert
 * @return 1 on success, 0 on memory allocation failure
 */
int insertElement(Numbers *arr, int value) {
    if (arr->size == arr->capacity) {
        if (!resizeArray(arr)) {
            printf("Memory allocation failed!\n");
            return 0;
        }
    }
    
    arr->items[arr->size++] = value;
    return 1;
}

/**
 * @brief Prints all elements in the array
 * 
 * Outputs all integers currently stored in the array to stdout,
 * separated by spaces and followed by a newline.
 * 
 * @param[in] arr Pointer to the Numbers structure to print
 */
void printArray(const Numbers *arr) {
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d ", arr->items[i]);
    }
    printf("\n");
}

/**
 * @brief Frees all memory associated with the dynamic array
 * 
 * Releases the memory allocated for the array and resets all
 * structure members to their default values.
 * 
 * @param[in,out] arr Pointer to the Numbers structure to free
 */
void freeArray(Numbers *arr) {
    free(arr->items);
    arr->items = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

/**
 * @brief Main function demonstrating the use of the dynamic array
 * 
 * Creates a dynamic array, inserts values 0-9 into it,
 * prints the array contents, and cleans up resources.
 * 
 * @return 0 on success, 1 on failure
 */
int main(void) {
    Numbers arr;
    initArray(&arr);
    
    /* Insert elements */
    for (int i = 0; i < 10; ++i) {
        if (!insertElement(&arr, i)) {
            freeArray(&arr);
            return 1;
        }
    }
    
    /* Print elements */
    printArray(&arr);
    
    /* Cleanup */
    freeArray(&arr);
    return 0;
}
