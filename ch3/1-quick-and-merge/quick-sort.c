#include "quick-sort.h"
#include "sort-utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick_sort_doubles(size_t low, size_t high, double A[]) {
    if ((signed)(high-low) <= 0) return;
    swap_doubles((high+low)/2, high, A);
    size_t L = low-1;
    size_t R = high;
    while (1) {
        while (A[++L] <= A[high] && L < high);
        while (A[--R] > A[high] && L < R && R >= low);
        if (L >= R) break; 
        swap_doubles(L, R, A);
    }
    swap_doubles(L, high, A);
    quick_sort_doubles(low, L-1, A);
    quick_sort_doubles(L+1, high, A);
}

void quick_sort_strings(size_t low, size_t high, size_t buflen, char A[][buflen]) {
    if ((((signed)high-(signed)low)) <= 0) return;
    swap_strings((high+low)/2, high, buflen, A);
    size_t L = low-1;
    size_t R = high;
    while (1) {
        while (strcmp(A[++L], A[high]) <= 0 && L < high);
        while (strcmp(A[--R], A[high]) > 0 && L < R && R >= low);
        if (L >= R) break; 
        swap_strings(L, R, buflen, A);
    }
    swap_strings(L, high, buflen, A);
    quick_sort_strings(low, L-1, buflen, A);
    quick_sort_strings(L+1, high, buflen, A);
}

