#include "merge-sort.h"
#include <stdlib.h>
#include <string.h>

void merge_sort_doubles(size_t start, size_t end, double* A) { 
    if(start == end) return;

    size_t mid = (start + end) / 2;
    merge_sort_doubles(start, mid, A);
    merge_sort_doubles(mid+1, end, A);
    
    size_t Llen = (mid-start)+1;
    size_t Rlen = (end-mid);

    double L[Llen];
    double R[Rlen];

    for (size_t i = 0; i < Llen; i++) L[i] = A[start+i];
    for (size_t i = 0; i < Rlen; i++) R[i] = A[mid+1+i];
    
    size_t Li = 0;
    size_t Ri = 0;
    size_t i = start;

    while (Li < Llen && Ri < Rlen) {
        if (L[Li] <= R[Ri]) {
            A[i++] = L[Li++];
        } else {
            A[i++] = R[Ri++];
        }
    }

    while (Li < Llen) A[i++] = L[Li++];
    while (Ri < Rlen) A[i++] = R[Ri++];
}

void merge_sort_strings(size_t start, size_t end, char** strings) {
    if (start == end) return;

    size_t mid = (start+end)/2;

    merge_sort_strings(start, mid, strings);
    merge_sort_strings(mid+1, end, strings);
    
    size_t Llen = (mid-start)+1;
    size_t Rlen = (end-mid);
    
    size_t strlen = 0;
    for(; strings[0][strlen] != 0; ++strlen);

    char** L = (char**)malloc(Llen * sizeof(char*));
    char** R = (char**)malloc(Rlen * sizeof(char*));
    
    for (size_t i = 0; i < Llen; i++) {
        L[i] = (char*)malloc(strlen * sizeof(char));
        strcpy(L[i], strings[start+i]);
    }

    for (size_t i = 0; i < Rlen; i++) {
        R[i] = (char*)malloc(strlen * sizeof(char));
        strcpy(R[i], strings[mid+1+i]);
    }

    size_t Li = 0;
    size_t Ri = 0;
    size_t i = start;

    while (Li < Llen && Ri < Rlen) {
        if (strcmp(L[Li], R[Ri]) < 1) strcpy(strings[i++], L[Li++]);
        else strcpy(strings[i++], R[Ri++]);
    }

    while (Li < Llen) strcpy(strings[i++], L[Li++]);
    while (Ri < Rlen) strcpy(strings[i++], R[Ri++]);
    
    for(size_t i = 0; i < Rlen; ++i) free(R[i]);
    for(size_t i = 0; i < Llen; ++i) free(L[i]);

    free(R);
    free(L);
}


