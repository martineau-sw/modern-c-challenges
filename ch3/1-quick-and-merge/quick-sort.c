#include "quick-sort.h"
#include "sort-utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick_sort_doubles(int start, int end, double a[end-start+1]) {
    if (end - start <= 0) return;
    swap_doubles((end+start)/2, end, end-start+1, a);
    int left = start-1;
    int right = end;
    while (1) {
        while (a[++left] <= a[end] && left < end);
        while (a[--right] > a[end] && left < right && right >= start);
        if (left >= right) break; 
        swap_doubles(left, right, end-start+1, a);
    }
    swap_doubles(left, end, end-start+1, a);
    quick_sort_doubles(start, left-1, a);
    quick_sort_doubles(left+1, end, a);
}

void quick_sort_strings(int start, int end, size_t str_length, char a[end-start+1][str_length]) {
    if (end-start <= 0) return;
    swap_strings((end+start)/2, end, end-start+1, str_length, a);
    int left = start-1;
    int right = end;
    while (1) {
        while (strcmp(a[++left], a[end]) < 0 && left < end);
        while (strcmp(a[--right], a[end]) > 0 && left < right && right >= start);
        if (left >= right) break; 
        swap_strings(left, right, end-start+1, str_length, a);
    }
    swap_strings(left, end, end-start+1, str_length, a);
    quick_sort_strings(start, left-1, str_length, a);
    quick_sort_strings(left+1, end, str_length, a);
}

