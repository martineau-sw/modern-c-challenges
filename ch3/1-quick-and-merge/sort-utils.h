#ifndef SORT_UTILS_HEADER
#define SORT_UTILS_HEADER
#include <stddef.h>
void print_doubles(char label[], size_t len, double A[len]);
void print_strings(char label[], size_t len, size_t buflen, char A[len][buflen]);
int  check_sorted_doubles(size_t len, double A[len]);
int  check_sorted_strings(size_t len, size_t buflen, char A[len][buflen]);
void generate_doubles(size_t len, double A[len]);
void generate_strings(size_t len, size_t buflen, char A[len][buflen]);
void swap_doubles(size_t i, size_t j, size_t len, double A[len]);
void swap_strings(size_t i, size_t j, size_t len, size_t buflen, char A[len][buflen]);
#endif
