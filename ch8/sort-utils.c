#include "./sort-utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void print_strings(char label[], size_t len, char** A) {
    printf("\nsize:%zu\n", len);
    for (size_t i = 0; i < len; ++i) {
        printf("%s[%zu] = %s\n",
                label,
                i,
                A[i]);
    }
} 

void print_doubles(char label[], size_t len, double* A) {
    printf("\nsize:%zu\n", len);
    for (size_t i = 0; i < len; ++i) {
        printf("%s[%zu] = %f\n",
                label,
                i,
                A[i]);
    }
}

double* generate_doubles(size_t n) {
    double* doubles = (double*)calloc(n, sizeof(double));

    for (size_t i = 0; i < n; i++) {
        doubles[i] = rand() % n;
    }

    return doubles;

}

char** generate_strings(size_t n, size_t strlen) {
    char** strings = (char**)malloc(strlen * sizeof(char*));
    char* alpha = "abcdefghijklmnopqrstuvwxyz";
    for (size_t i = 0; i < n; ++i) {
        strings[i] = (char*)malloc(strlen * sizeof(char));
        strings[i][strlen-1] = '\0';
        for(size_t j = 0; j < strlen-1; ++j) {
            strings[i][j] = alpha[rand() % 26];
        }
    }

    return strings;
}

bool check_sorted_doubles(size_t len, double* doubles) {
    for (size_t i = 1; i < len; i++) {
        if (doubles[i] < doubles[i-1]) {
            puts("doubles result: FAILED");
            free(doubles);
            return false;
       }
    }

    puts("doubles result: PASSED");
    free(doubles);
    return true;
}

bool check_sorted_strings(size_t len, char** strings) {
    for (size_t i = 1; i < len; i++) {
        if (strcmp(strings[i], strings[i-1]) == -1) {
            puts("strings result: FAILED");
            free(strings);
            return false; 
        }
    }

    puts("strings result: PASSED");
    free(strings);
    return true;
}

void swap_doubles(size_t i, size_t j, double* doubles) {
    double temp = doubles[i];
    doubles[i] = doubles[j];
    doubles[j] = temp;
}

void swap_strings(size_t i, size_t j, char** strings) {
    size_t strlen_i = 0;
    for (; strings[i][strlen_i] != '\0'; ++strlen_i); 
    char* temp = (char*)malloc(strlen_i * sizeof(char)); 

    memcpy(temp, strings[i], strlen_i);
    memcpy(strings[i], strings[j], strlen_i);
    memcpy(strings[j], temp, strlen_i);
    free(temp);
}
