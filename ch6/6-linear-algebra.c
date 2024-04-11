/*
 * CHALLENGE 6 Linear algebra
 *
 * Some of the most important problems for which arrays are used stem from linear algebra.
 *
 * Can you write functions that do vector-to-vector or matrix-to-vector products at this point?
 *
 * What about Gauß elimination or iterative algorithms for matrix inversion?
 *
 * Jens Gustedt, Modern C, pg 85
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef double vector2[2];
typedef double vector3[3];
typedef double vector4[4];

typedef vector2 matrix22[2];
typedef vector3 matrix33[3];
typedef vector4 matrix44[4];

void print_vector(char label[], size_t len, double V[]) {
    printf("%s(", label);    
    for (int i = 0; i < len; i++) {
        printf("%f", V[i]);
        if(i < len - 1) printf(", ");
    }
    printf(")\n");
}

void print_matrix(char label[], size_t rows, size_t cols, double M[][cols]) {
    printf("%s\n", label);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f", M[i][j]);
            if (j < cols - 1) printf(", ");
        }
        if(i < rows) printf("\n");
    }
    
}

// available in three dimensions since only one valid
// solution for any two vectors, where none may not in
// single dimension or infinitely many in 4 or more
void cross(vector3 V0, vector3 V1, vector3 V) {
    V[0] = V0[1]*V1[2] - V0[2]*V1[1];
    V[1] = V0[2]*V1[0] - V0[0]*V1[2];
    V[2] = V0[0]*V1[1] - V0[1]*V1[0];
}

double dot(size_t vlen, double V0[], double V1[]) {
    double sum = 0; 
    for (int i = 0; i < vlen; i++) {
        sum += V0[i]*V1[i];
    }

    return sum;
}

void matrix_vector_product(size_t rows, size_t cols, double M[rows][cols], size_t vrows, double V0[vrows], double V[rows]) {
    assert(cols == vrows);
    size_t row = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            V[i] += M[i][j] * V0[j];
        }
    }

}

int main(void) {
    matrix33 M = {
        [0][0] = 1, [0][1] = 1, [0][2] = 1,
        [1][0] = 1, [1][1] = 1, [1][2] = 1,
        [2][0] = 1, [2][1] = 1, [2][2] = 1,
    };
    
    vector3 V = {
        [0] = 1,
        [1] = 1,
        [2] = 1,
    };

    vector3 V0 = {
        [0] = 2,
        [1] = 2,
        [2] = 2,
    };
    print_vector("vector", 3, V);
    print_matrix("matrix", 3, 3, M);

    vector3 result = { 0 };

    matrix_vector_product(3, 3, M, 3, V, result);
    print_vector("matrix-vector", 3, result);

    cross(V, V0, result);
    print_vector("cross", 3, result);
    printf("dot result: %f\n", dot(3, V0, V));
    return EXIT_SUCCESS;
}
