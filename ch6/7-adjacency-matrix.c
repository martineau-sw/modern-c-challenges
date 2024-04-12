#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define Q_SIZE 64

typedef bool matrix4x4_b[4][4];
typedef struct queue queue;
struct queue {
    size_t first;
    size_t length;
    size_t A[Q_SIZE];
};

void print_queue(queue Q) {
    printf(
        "queue\n"
        "frame:  %zu-%zu (%zu)\n"
        "[",
        Q.first,
        Q.first + Q.length,
        Q.length
    );
    
    for (size_t i = 0; i < Q.length; i++) {
        printf("%zu", Q.A[(Q.first+i)%Q_SIZE]);
        if (i != Q.length-1) printf("\t");
        if (i > 0 && i % 8 == 0) printf("\n");
    }

    printf("]\n");
}

bool is_empty(queue Q) {
    if (Q.length == 0) return true;
    return false;
}

void enqueue(size_t key, queue* Q) {
    assert(Q->length < Q_SIZE);
    Q->A[(Q->first+Q->length++)%Q_SIZE] = key;
}

size_t dequeue(queue* Q) {
    if (is_empty(*Q)) return SIZE_MAX;
    size_t value = Q->A[Q->first]; 
    Q->A[Q->first] = SIZE_MAX;
    Q->first = (Q->first + 1) % Q_SIZE;
    Q->length--;
    return value;
}

void print_matrix(char label[], size_t len, matrix4x4_b M) {
    printf("%s\n", label);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            printf("%u", M[i][j]);
            if (j < len - 1) printf(", ");
        }
        if(i < len) printf("\n");
    }
    
}

size_t breadth_first_search(size_t start, size_t key, size_t len, matrix4x4_b M) {
    queue Q = {
        .A = { SIZE_MAX, },
        .first = 0,
        .length = 0,
    };
    
    bool explored[len];
    
    explored[start] = true;
    enqueue(start, &Q); 
    print_queue(Q);

    while (!is_empty(Q)) {
        size_t value = dequeue(&Q);
        printf("dequeued: %zu\n", value);
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
        {0, 1, 0, 0,},
        {0, 0, 0, 1,},
        {0, 0, 1, 0,},
        {1, 0, 1, 0,},
    };


    print_matrix("adjacency matrix", 4, A);
    printf("%zu", breadth_first_search(0, 3, 4, A));
}
