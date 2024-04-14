#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define Q_SIZE 64

typedef bool matrix4x4_b[4][4];
typedef size_t matrix4x4_s[4][4];
typedef struct queue queue;

enum {
    A = 0,
    B = 1,
    C = 2,
    D = 3,
};

struct queue {
    size_t first;
    size_t length;
    size_t A[Q_SIZE];
};

char to_label(size_t index) {
    switch (index) {
        case 0:
            return 'A';
        case 1:
            return 'B';
        case 2:
            return 'C';
        case 3:
            return 'D';
        default:
            return '-';
    }
}

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

void print_matrix(char label[], size_t len, matrix4x4_s M) {
    printf("%s\n", label);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (M[i][j] == SIZE_MAX) printf("-");
            else printf("%zu", M[i][j]);
            if (j < len - 1) printf(", ");
        }
        if(i < len) printf("\n");
    }
    puts(""); 
}

size_t breadth_first_search(size_t v, size_t key, size_t len, matrix4x4_b M) {
    queue Q = {
        .A = { SIZE_MAX, },
        .first = 0,
        .length = 0,
    };
    
    bool explored[len];
    
    explored[v] = true;
    enqueue(v, &Q); 
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

size_t get_min_index(size_t v, size_t len, matrix4x4_s M) {
    size_t min_index = 0;
    for (size_t i = 0; i < len; i++) 
        min_index = M[v][i] < M[v][min_index] ? i : min_index; 
    return min_index;
}

size_t dijkstras(size_t i, size_t j, size_t len, matrix4x4_s M) {
    queue Q = {
        .A = { SIZE_MAX, },
        .first = 0,
        .length = 0,
    };
    
    size_t explored[len];
    for (size_t k = 0; k < len;) explored[k++] = SIZE_MAX;
    explored[i] = 0;

    size_t distance = 0;

    enqueue(i, &Q); 

    printf("dijkstra's algorithm path: ");
    while (!is_empty(Q)) {
        size_t val = dequeue(&Q);
        //printf("dequeued: %c\n", to_label(val));
        for (size_t k = 0; k < len; k++) {
            if(explored[k] != SIZE_MAX || M[val][k] == SIZE_MAX) continue;
            
            enqueue(k, &Q);
            //print_queue(Q);
        }

        if (explored[val] == 0) continue;
        size_t min = 0;
    
        for (size_t k = 0; k < len; k++) {
            if (M[val][k] < M[val][min]) {
                if (explored[k] != SIZE_MAX) {
                    min = k;
                }
            }
        }

        explored[val] = M[val][min] + explored[min];
        distance += explored[min];
        printf("%c:%zu->%c:%zu ", 
                to_label(min), 
                explored[min], 
                to_label(val), 
                explored[val]);
        if (val == j) return distance;
    }

    return SIZE_MAX;
}

void print_adjacent_verteces(size_t vertex, size_t len, matrix4x4_b M) {
    printf("adjacent verteces of %c: ", to_label(vertex));
    for (size_t i = 0; i < len; i++) {
        if (M[vertex][i]) printf("%c ", to_label(i));
    }
    puts("");
}

int main(void) {

    // Complete bidirectional
    matrix4x4_s G0 = {
        {-1, 2, 3, 2,},
        {2, -1, 4, 7,},
        {3, 4, -1, 5,},
        {2, 5, 5, -1,},
    };
    
    // Unidirectional A adjacent to all other nodes
    matrix4x4_s G1 = {
        {-1, 2, 4, 3,},
        {-1, -1, -1, -1,},
        {-1, -1, -1, -1,},
        {-1, -1, -1, -1,},
    };
    
    // Only self cycles
    matrix4x4_s G2 = {
        {1, -1, -1, -1,},
        {-1, 1, -1, -1,},
        {-1, -1, 1, -1,},
        {-1, -1, -1, 1,},
    };

    matrix4x4_s G3 = {
        { -1,  1, -1, -1 },
        {  1, -1,  1, -1 },
        { -1,  1, -1,  1 },
        { -1, -1,  1, -1 },

    };
    print_matrix("G0: bidirection, complete, no self cycles", 4, G0);
    print_matrix("G1: unidirection, tree, A root, no self cycles", 4, G1);
    print_matrix("G2: self-cycles", 4, G2);

    printf("%zu", dijkstras(A, D, 4, G3));
}
