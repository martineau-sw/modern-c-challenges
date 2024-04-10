#ifndef SORT_UTILS_HEADER
#define SORT_UTILS_HEADER
#include <stddef.h>
void prsize_t_doubles(char label[], size_t len, double a[]);
void prsize_t_strings(char label[], size_t len, size_t buflen, char a[][buflen]);
signed check_sorted_doubles(size_t len, double a[]);
signed check_sorted_strings(size_t len, size_t buflen, char a[][buflen]);
void generate_doubles(size_t len, double a[]);
void generate_strings(size_t len, size_t buflen, char a[][buflen]);
void swap_doubles(size_t i, size_t j, double a[]);
void swap_strings(size_t i, size_t j,size_t buflen, char a[][buflen]);
#endif
