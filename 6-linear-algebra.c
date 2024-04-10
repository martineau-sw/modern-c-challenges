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

// available in three dimensions since only one valid
// solution for any two vectors, where none may not in
// single dimension or infinitely many in 4 or more
void cross(vector3 V0, vector3 V1, vector3 V) {
    V[0] = V0[2]*V1[3] - V0[3]*V1[2];
    V[1] = V0[3]*V1[1] - V0[1]*V1[3];
    V[2] = V0[1]*V1[2] - V0[2]*V1[1];
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
            V[i] = M[i][j] + V[j];
        }
    }

}


int main(void) {
    vector2 vec = { 2.0, 3.0 }; 
    
    printf("vector(%f, %f)\n", vec[0], vec[1]);
    return EXIT_SUCCESS;
}
