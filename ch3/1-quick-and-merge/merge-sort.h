#ifndef MERGE_SORT_HEADER
#define MERGE_SORT_HEADER
#include <stddef.h>

void merge_sort_doubles(size_t start, size_t end, double a[end-start]);
void merge_sort_strings(size_t start, size_t end, size_t str_length, char a[end-start][255]);
#endif
