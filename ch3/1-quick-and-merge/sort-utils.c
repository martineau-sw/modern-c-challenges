#include "./sort-utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_strings(char label[], size_t length, size_t str_length, char a[length][str_length]) {
    printf("\nsize:%zu\n", length);
    for (size_t i = 0; i < length; ++i) {
        printf("%s[%zu] = %s\n",
                label,
                i,
                a[i]);
    }
}
void print_doubles(char label[], size_t length, double a[length]) {
    printf("\nsize:%zu\n", length);
    for (size_t i = 0; i < length; ++i) {
        printf("%s[%zu] = %f\n",
                label,
                i,
                a[i]);
    }
}

void generate_doubles(size_t length, double a[length]) {
    for (size_t i = 0; i< length; i++) {
        a[i] = rand() % length;
    }
}

void generate_strings(size_t length, size_t str_length, char a[length][str_length]) {
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    for (size_t i = 0; i < length; i++) {
        char str[str_length];
        for(size_t j = 0; j < str_length; j++) {
            str[j] = alpha[(rand() + i + j) % strlen(str)];
        }
        str[str_length-1] = '\0';
        strcpy(a[i], str);
    }
}

int check_sorted_doubles(size_t length, double a[length]) {
    for (size_t i = 1; i < length; i++) {
        if (a[i] < a[i-1]) {
            printf("doubles result: FAILED\n");
            return -1;
       }
    }

    printf("doubles result: PASSED\n");
    return 0;
}

int check_sorted_strings(size_t length, size_t str_length, char a[length][str_length]) {
    for (size_t i = 1; i < length; i++) {
        if (strcmp(a[i], a[i-1]) == -1) {
            printf("strings result: FAILED\n");
            return -1;
        }
    }

    printf("strings result: PASSED\n");
    return 0;
}

void swap_doubles(int i, int j, size_t length, double a[length]) {
    double temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void swap_strings(int i, int j, size_t length, size_t str_length, char a[length][str_length]) {
    printf("string swap");
    char temp[2][str_length];
    strcpy(temp[0], a[i]);
    strcpy(temp[1], a[j]);
    strcpy(a[i], temp[1]);
    strcpy(a[j], temp[0]);
}
