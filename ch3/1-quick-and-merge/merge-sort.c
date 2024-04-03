#include "merge-sort.h"
#include <string.h>

void merge_sort_doubles(size_t start, size_t end, double array[end-start]) { 
    if(start == end) return;

    size_t mid = (start + end) / 2;
    merge_sort_doubles(start, mid, array);
    merge_sort_doubles(mid+1, end, array);
    
    size_t left_length = (mid-start)+1;
    size_t right_length = (end-mid);

    double left[left_length];
    double right[right_length];

    for (size_t i = 0; i < left_length; i++) left[i] = array[start+i];
    for (size_t i = 0; i < right_length; i++) right[i] = array[mid+1+i];
    
    size_t left_index = 0;
    size_t right_index = 0;
    size_t i = start;

    while (left_index < left_length && right_index < right_length) {
        if (left[left_index] <= right[right_index]) {
            array[i++] = left[left_index++];
        } else {
            array[i++] = right[right_index++];
        }
    }

    while (left_index < left_length) array[i++] = left[left_index++];
    while (right_index < right_length) array[i++] = right[right_index++];
}

void merge_sort_strings(size_t start, size_t end, size_t str_length, char array[end-start][str_length]) {
    if (start == end) return;

    size_t mid = (start+end)/2;

    merge_sort_strings(start, mid, str_length, array);
    merge_sort_strings(mid+1, end, str_length, array);
    
    size_t left_length = (mid-start)+1;
    size_t right_length = (end-mid);

    char left[left_length][str_length];
    char right[right_length][str_length];
    
    for (size_t i = 0; i < left_length; i++) strcpy(left[i], array[start+i]);
    for (size_t i = 0; i < right_length; i++) strcpy(right[i], array[mid+1+i]);

    size_t left_index = 0;
    size_t right_index = 0;
    size_t i = start;

    while (left_index < left_length && right_index < right_length) {
        if (strcmp(left[left_index], right[right_index]) < 1) {
            strcpy(array[i++], left[left_index++]);
        } else {
            strcpy(array[i++], right[right_index++]);
        }
    }

    while (left_index < left_length) strcpy(array[i++], left[left_index++]);
    while (right_index < right_length) strcpy(array[i++], right[right_index++]);
}


