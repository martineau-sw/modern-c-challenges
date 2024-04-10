#ifndef QUICK_SORT_HEADER
#define QUICK_SORT_HEADER
#include <stddef.h>
void quick_sort_doubles(size_t low, size_t high, double A[]);
void quick_sort_strings(size_t low, size_t high, size_t buflen, char A[][buflen]);
#endif
