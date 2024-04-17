#include "quick-sort.h"
#include "sort-utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick_sort_doubles(size_t low, size_t high, double* A) {
    if ((signed)(high-low) <= 0) return;
    swap_doubles((high+low)/2, high, A);
    size_t L = low;
    size_t R = high-1;
    for (;;) {
        while (L < high && A[L] <= A[high]) L++;
        while (L < R && R >= low && A[R] > A[high]) R--;
        if (L >= R) break; 
        swap_doubles(L, R, A);
    }
    swap_doubles(L, high, A);
    quick_sort_doubles(low, L-1, A);
    quick_sort_doubles(L+1, high, A);
}

void quick_sort_strings(size_t low, size_t high, char** strings) {
    if ((signed)(high-low) <= 0) return;
    swap_strings((high+low)/2, high, strings);
    size_t L = low;
    size_t R = high-1;
    for (;;) {
        while (L < high && strcmp(strings[L], strings[high]) <= 0) L++;
        while (L < R && R >= low && strcmp(strings[R], strings[high]) > 0) R--;
        if (L >= R) break; 
        swap_strings(L, R, strings);
    }
    swap_strings(L, high, strings);
    quick_sort_strings(low, L-1, strings);
    quick_sort_strings(L+1, high, strings);
}

