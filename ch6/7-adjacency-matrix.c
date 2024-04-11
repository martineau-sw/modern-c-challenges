#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

typedef bool matrix4x4_b[4][4];
typedef struct queue queue;
struct queue {
    size_t A[UCHAR_MAX];
    size_t first;
    size_t last;
};

void enqueue(short key, queue* Q) {
    assert(Q->last < UCHAR_MAX);
    Q->A[Q->last++] = key;
}

size_t dequeue(queue* Q) {
    assert(Q->first <= Q->last);
    size_t value = Q->A[Q->first]; 
    Q->A[Q->first++] = SIZE_MAX;
    return value;
}

void compress(queue* Q) {
    size_t count = Q->last - Q->first;

    for(size_t i = 0; i < count; i++) {
        Q->A[i] = Q->A[Q->first+i];
        Q->A[Q->first+i] = SIZE_MAX;
    }

    Q->first = 0;
    Q->last = count;
}

signed is_empty(queue Q) {
    if (Q.A[Q.first] == SIZE_MAX) return 1;
    return 0;
}

void print_matrix(char label[], size_t len, matrix4x4_b M) {
    printf("%s\n", label);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            printf("%b", M[i][j]);
            if (j < len - 1) printf(", ");
        }
        if(i < len) printf("\n");
    }
    
}

size_t breadth_first_search(size_t start, size_t key, size_t len, matrix4x4_b M) {
    queue Q;
    size_t A[UCHAR_MAX] = { SIZE_MAX };
    memcpy(Q.A, A, UCHAR_MAX);
    bool explored[len];
    
    explored[start] = true;
    enqueue(start, &Q); 

    while (!is_empty(Q)) {
        size_t value = dequeue(&Q);
        if (value == key) return value;
        for (size_t i = 0; i < len; i++) {
            if (M[value][i] == 1 && !explored[i]) {
                explored[i] = true;
                enqueue(i, &Q);
            }
        }
    }

    return SIZE_MAX;
}

int main(void) {
    matrix4x4_b A = {
        {0, 1, 1, 1,},
        {1, 0, 1, 1,},
        {1, 1, 0, 1,},
        {1, 1, 1, 0,},
    };

    print_matrix("adjacency matrix", 4, A);
}
