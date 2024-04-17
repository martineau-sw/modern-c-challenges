#include "quick-sort.h"
#include "sort-utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick_sort_doubles(size_t low, size_t high, double* A) {
    /* Single element is sorted */
    if ((signed)(high-low) <= 0) return;
    
    /* Select center as pivot and swap with end of array */
    swap_doubles((high+low)/2, high, A);
    size_t L = low;
    size_t R = high-1;

    /* Left searches to end of partition until value is greater or equal to 
     * pivot
     *
     * Right searches to start of partition until value is less than pivot
     * or crosses left
     *
     * If both stop without crossing, swap values at respective locations
    */
    for (;;) {
        while (L < high && A[L] <= A[high]) L++;
        while (L < R && R >= low && A[R] > A[high]) R--;
        if (L >= R) break; 
        swap_doubles(L, R, A);
    }
    
    /* All elements left of pivot are less than pivot and elements right of 
     * pivot are greater than pivot
     *
     * Swap pivot value from end to left after right has crossed
     *
     * Pivot is now in the correct location
    */
    swap_doubles(L, high, A);

    /* Perform quick sort on partitions to the left and right of pivot,
     * exclusive
    */
    quick_sort_doubles(low, L-1, A);
    quick_sort_doubles(L+1, high, A);
}

void quick_sort_strings(size_t low, size_t high, char** strings) {
    /* Single element is sorted */
    if ((signed)(high-low) <= 0) return;

    /* Select center as pivot and swap with end of array */
    swap_strings((high+low)/2, high, strings);
    size_t L = low;
    size_t R = high-1;

    /* Left searches to end of partition until value is greater or equal to 
     * pivot
     *
     * Right searches to start of partition until value is less than pivot
     * or crosses left
     *
     * If both stop without crossing, swap values at respective locations
    */
    for (;;) {
        while (L < high && strcmp(strings[L], strings[high]) <= 0) L++;
        while (L < R && R >= low && strcmp(strings[R], strings[high]) > 0) R--;
        if (L >= R) break; 
        swap_strings(L, R, strings);
    }

    /* All elements left of pivot are less than pivot and elements right of 
     * pivot are greater than pivot
     *
     * Swap pivot value from end to left after right has crossed
     *
     * Pivot is now in the correct location
    */
    swap_strings(L, high, strings);
   
    /* Perform quick sort on partitions to the left and right of pivot,
     * exclusive
    */
    quick_sort_strings(low, L-1, strings);
    quick_sort_strings(L+1, high, strings);
}

