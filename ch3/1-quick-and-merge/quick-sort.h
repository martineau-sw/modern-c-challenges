#ifndef QUICK_SORT_HEADER
#define QUICK_SORT_HEADER
#include <stddef.h>
void quick_sort_doubles(int low, int high, double a[high-low]);
void quick_sort_strings(int low, int high, size_t str_length, char[high-low][str_length]);
#endif
