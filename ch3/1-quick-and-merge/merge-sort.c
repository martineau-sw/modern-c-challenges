#include "merge-sort.h"
#include <string.h>

void merge_sort_doubles(size_t start, size_t end, double A[]) { 
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

void merge_sort_strings(size_t start, size_t end, size_t buflen, char A[][buflen]) {
    if (start == end) return;

    size_t mid = (start+end)/2;

    merge_sort_strings(start, mid, buflen, A);
    merge_sort_strings(mid+1, end, buflen, A);
    
    size_t Llen = (mid-start)+1;
    size_t Rlen = (end-mid);

    char L[Llen][buflen];
    char R[Rlen][buflen];
    
    for (size_t i = 0; i < Llen; i++) strcpy(L[i], A[start+i]);
    for (size_t i = 0; i < Rlen; i++) strcpy(R[i], A[mid+1+i]);

    size_t Li = 0;
    size_t Ri = 0;
    size_t i = start;

    while (Li < Llen && Ri < Rlen) {
        if (strcmp(L[Li], R[Ri]) < 1) {
            strcpy(A[i++], L[Li++]);
        } else {
            strcpy(A[i++], R[Ri++]);
        }
    }

    while (Li < Llen) strcpy(A[i++], L[Li++]);
    while (Ri < Rlen) strcpy(A[i++], R[Ri++]);
}


