#include "merge-sort.h"
#include "quick-sort.h"
#include "sort-utils.h"
#include "test-sorts.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N 256 
#define STRLEN 8 

int main(void) {
     
    struct timespec time[5];

    timespec_get(&time[0], TIME_UTC);

    test_merge_sort_doubles(N);
    timespec_get(&time[1], TIME_UTC);
    printf("%.4fs\n", (time[1].tv_nsec - time[0].tv_nsec)/1E+9);
    
    test_merge_sort_strings(N, STRLEN);
    timespec_get(&time[2], TIME_UTC);
    printf("%.4fs\n", (time[2].tv_nsec - time[1].tv_nsec)/1E+9);
    
    test_quick_sort_doubles(N);
    timespec_get(&time[3], TIME_UTC);
    printf("%.4fs\n", (time[3].tv_nsec - time[2].tv_nsec)/1E+9);
    
    test_quick_sort_strings(N, STRLEN); 
    timespec_get(&time[4], TIME_UTC);
    printf("%.4fs\n", (time[4].tv_nsec - time[3].tv_nsec)/1E+9);

}

int test_merge_sort_doubles(size_t len) {
    printf("conducting merge sort test on %zu doubles: ", len);
    double* doubles = generate_doubles(len);
    merge_sort_doubles(0, len-1, doubles);
    
    return check_sorted_doubles(len, doubles); 
}

int test_merge_sort_strings(size_t len, size_t strlen) { 
    printf("conducting merge sort test on %zu strings: ", len);
    char** strings = generate_strings(len, strlen);
    merge_sort_strings(0, len-1, strings);

    return check_sorted_strings(len, strings);
}

int test_quick_sort_doubles(size_t len) {
    printf("conducting quick sort test on %zu doubles: ", len);
    double* doubles = generate_doubles(len);
    quick_sort_doubles(0, len-1, doubles);

    return check_sorted_doubles(len, doubles);
}

int test_quick_sort_strings(size_t len, size_t strlen) {
    printf("conducting quick sort test on %zu strings: ", len);
    char** strings = generate_strings(len, strlen);
    quick_sort_strings(0, len-1, strings);

    return check_sorted_strings(len, strings);
}


