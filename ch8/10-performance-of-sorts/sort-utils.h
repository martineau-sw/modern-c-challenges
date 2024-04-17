#ifndef SORT_UTILS_HEADER
#define SORT_UTILS_HEADER
#include <stddef.h>
#include <stdbool.h>
void print_doubles(char* label, size_t len, double*);
void print_strings(char* label, size_t len, char**);
bool  check_sorted_doubles(size_t len, double*);
bool  check_sorted_strings(size_t len, char**);
double* generate_doubles(size_t n);
char** generate_strings(size_t n, size_t strlen);
void swap_doubles(size_t i, size_t j, double*);
void swap_strings(size_t i, size_t j, char**);
#endif
