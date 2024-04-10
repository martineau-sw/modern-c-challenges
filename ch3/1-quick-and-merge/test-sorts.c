#include "merge-sort.h"
#include "quick-sort.h"
#include "sort-utils.h"
#include "test-sorts.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * This implementation utilizes content covered up to chapter 7
 * in Jens Gustedt's Modern C, where this exercise originates 
 * earlier in chapter 3. The revision includes more appropriate 
 * usage of arrays and string functions, exercising a more 
 * thorough understanding of their usage in C.
 *
 * An effort has also been made to refactor according to idiomatic
 * considerations seen throughout the code samples in the book
 * thus far. 
 *
 * While segmentation faults have been resolved, this implementation
 * is now only failing at test_quick_sort_strings aborting with a 
 * 'trace trap' error. It's cause is currently unknown and light 
 * reading has pointed in the direction of macOS platform dependent
 * issue, however there has been a brief period in which it functioned 
 * without fault preceding assertion additions which were later 
 * removed in an effort to get a handle on the issue. 
 *
 * It was here I learned the value of version control and hopefully
 * to make a habit of utilizing vcs for more atomic changes. :')
 */
int main(void) {
    test_merge_sort_doubles(50);
    test_merge_sort_strings(50, 32);
    test_quick_sort_doubles(50);
    test_quick_sort_strings(50, 32); // TODO: segfaulting
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


