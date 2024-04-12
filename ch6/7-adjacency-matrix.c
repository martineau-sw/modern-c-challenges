#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define Q_SIZE 64

typedef bool matrix4x4_b[4][4];
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

void print_matrix(char label[], size_t len, matrix4x4_b M) {
    printf("%s\n", label);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            printf("%u", M[i][j]);
            if (j < len - 1) printf(", ");
        }
        if(i < len) printf("\n");
    }
    puts(""); 
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
    // print_queue(Q);

    while (!is_empty(Q)) {
        size_t value = dequeue(&Q);
        // printf("dequeued: %zu\n", value);
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

void print_adjacent_verteces(size_t vertex, size_t len, matrix4x4_b M) {
    printf("adjacent verteces of %c: ", to_label(vertex));
    for (size_t i = 0; i < len; i++) {
        if (M[vertex][i]) printf("%c ", to_label(i));
    }
    puts("");
}

bool has_spanning_tree(size_t start, size_t len, matrix4x4_b M) {
    size_t sum = 0;
    for (size_t j = 1; j < len; j++) {
        size_t col_sum = 0;
        for (size_t i = 0; i < len-1; i++) col_sum += M[i][j];
        if (col_sum > 1) return false;
        sum = col_sum;
    }

    if (sum > 1) return true;
    return false;
}

int main(void) {

    // Complete bidirectional
    matrix4x4_b G0 = {
        {0, 1, 1, 1,},
        {1, 0, 1, 1,},
        {1, 1, 0, 1,},
        {1, 1, 1, 0,},
    };
    
    // Unidirectional A adjacent to all other nodes
    matrix4x4_b G1 = {
        {0, 1, 1, 1,},
        {0, 0, 0, 0,},
        {0, 0, 0, 0,},
        {0, 0, 0, 0,},
    };
    
    // Only self cycles
    matrix4x4_b G2 = {
        {1, 0, 0, 0,},
        {0, 1, 0, 0,},
        {0, 0, 1, 0,},
        {0, 0, 0, 1,},
    };
    print_matrix("G0: bidirection, complete, no self cycles", 4, G0);

    print_adjacent_verteces(A, 4, G0);
    print_adjacent_verteces(B, 4, G0);
    print_adjacent_verteces(C, 4, G0);
    print_adjacent_verteces(D, 4, G0);
    puts("");    

    print_matrix("G1: unidirection, tree, A root, no self cycles", 4, G1);

    print_adjacent_verteces(A, 4, G1);
    print_adjacent_verteces(B, 4, G1);
    print_adjacent_verteces(C, 4, G1);
    print_adjacent_verteces(D, 4, G1);
    puts("");    

    print_matrix("G2: self-cycles", 4, G2);

    print_adjacent_verteces(A, 4, G2);
    print_adjacent_verteces(B, 4, G2);
    print_adjacent_verteces(C, 4, G2);
    print_adjacent_verteces(D, 4, G2);
    puts("");    

    puts("bfs(root, search, graph)");
    printf("bfs(A, D, G0): %c\n", to_label(breadth_first_search(A, D, 4, G0)));
    printf("bfs(D, A, G0): %c\n", to_label(breadth_first_search(D, A, 4, G0)));
    printf("bfs(A, A, G0): %c\n", to_label(breadth_first_search(A, A, 4, G0)));
    printf("bfs(A, D, G1): %c\n", to_label(breadth_first_search(A, D, 4, G1)));
    printf("bfs(D, A, G1): %c\n", to_label(breadth_first_search(D, A, 4, G1)));
    printf("bfs(A, A, G1): %c\n", to_label(breadth_first_search(A, A, 4, G1)));
    printf("bfs(A, D, G2): %c\n", to_label(breadth_first_search(A, D, 4, G2)));
    printf("bfs(D, A, G2): %c\n", to_label(breadth_first_search(D, A, 4, G2)));
    printf("bfs(A, A, G2): %c\n", to_label(breadth_first_search(A, A, 4, G2)));

}
