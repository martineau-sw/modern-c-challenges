#include "./sort-utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_strings(char label[], size_t len, size_t buflen, char A[][]) {
    printf("\nsize:%zu\n", len);
    for (size_t i = 0; i < len; ++i) {
        printf("%s[%zu] = %s\n",
                label,
                i,
                A[i]);
    }
} void print_doubles(char label[], size_t len, double A[len]) {
    printf("\nsize:%zu\n", len);
    for (size_t i = 0; i < len; ++i) {
        printf("%s[%zu] = %f\n",
                label,
                i,
                A[i]);
    }
}

void generate_doubles(size_t len, double A[len]) {
    for (size_t i = 0; i< len; i++) {
        A[i] = rand() % len;
    }
}

void generate_strings(size_t len, size_t buflen, char A[len][buflen]) {
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    for (size_t i = 0; i < len; ++i) {
        char str[buflen];
        for(size_t j = 0; j < buflen - 1; ++j) {
            str[j] = alpha[rand() % 25];
        }
        str[buflen - 1] = 0;
        strcpy(A[i], str);
    }
}

signed check_sorted_doubles(size_t len, double A[len]) {
    for (size_t i = 1; i < len; i++) {
        if (A[i] < A[i-1]) {
            puts("doubles result: FAILED\n");
            return -1;
       }
    }

    puts("doubles result: PASSED\n");
    return 0;
}

signed check_sorted_strings(size_t len, size_t buflen, char A[len][buflen]) {
    for (size_t i = 1; i < len; i++) {
        if (strcmp(A[i], A[i-1]) == -1) {
            puts("strings result: FAILED\n");
            return -1;
        }
    }

    puts("strings result: PASSED\n");
    return 0;
}

void swap_doubles(size_t i, size_t j, size_t len, double A[len]) {
    double temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void swap_strings(size_t i, size_t j, size_t len, size_t buflen, char A[len][buflen]) {
    char str[buflen];
    strcpy(str, A[i]);
    strcpy(A[i], A[j]);
    strcpy(A[j], str);
}
