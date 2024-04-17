#include "merge-sort.h"
#include "quick-sort.h"
#include "sort-utils.h"
#include "test-sorts.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    test_merge_sort_doubles(50);
    test_merge_sort_strings(50, 32);
    test_quick_sort_doubles(50);
    test_quick_sort_strings(50, 32); 
}

int test_merge_sort_doubles(size_t len) {
    double A[len];
    printf("conducting merge sort test on %zu doubles: ", len);
    generate_doubles(len, A);
    merge_sort_doubles(0, len-1, A);
    
    return check_sorted_doubles(len, A); 
}

int test_merge_sort_strings(size_t len, size_t buflen) { 
    char A[len][buflen];
    printf("conducting merge sort test on %zu strings: ", len);
    generate_strings(len, buflen, A);
    merge_sort_strings(0, len-1, buflen, A);

    return check_sorted_strings(len, buflen, A);
}

int test_quick_sort_doubles(size_t len) {
    double A[len];
    printf("conducting quick sort test on %zu doubles: ", len);
    generate_doubles(len, A);
    quick_sort_doubles(0, len-1, A);

    return check_sorted_doubles(len, A);
}

int test_quick_sort_strings(size_t len, size_t buflen) {
    char A[len][buflen];
    printf("conducting quick sort test on %zu strings: ", len);
    generate_strings(len, buflen, A);
    quick_sort_strings(0, len-1, buflen, A);

    return check_sorted_strings(len, buflen, A);
}


