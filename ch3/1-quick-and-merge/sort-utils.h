#ifndef SORT_UTILS_HEADER
#define SORT_UTILS_HEADER
#include <stddef.h>
void print_doubles(char label[], size_t length, double a[length]);
void print_strings(char label[], size_t length, size_t str_length, char a[length][str_length]);
int check_sorted_doubles(size_t length, double a[length]);
int check_sorted_strings(size_t length, size_t str_length, char a[length][str_length]);
void generate_doubles(size_t length, double a[length]);
void generate_strings(size_t length, size_t str_length, char a[length][str_length]);
void swap_doubles(int i, int j, size_t length, double a[length]);
void swap_strings(int i, int j, size_t length, size_t str_length, char a[length][str_length]);
#endif
