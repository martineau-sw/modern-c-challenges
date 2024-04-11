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
#include <math.h>
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

void swap_rows(size_t i, size_t j, size_t len, double M[len][len+1]) {
    for (size_t k = 0; k <= len; k++) {
        double temp = M[i][k];
        M[i][k] = M[j][k];
        M[j][k] = temp;
    }
}

signed forward_elimination(size_t len, double M[len][len+1]) {
    for (size_t k = 0; k < len; k++) {
        size_t max_index = k;
        double max_value = M[max_index][k];

        for (size_t i = k+1; i < len; i++) { 
            if (fabs(M[i][k]) > max_value) {
                max_value = M[i][k];
                max_index = i;
            }
        }

        if (!M[k][max_index]) return k;

        if (max_index != k) swap_rows(max_index, k, len, M);

        for (size_t i = k+1; i < len; i++) {
            double factor = M[i][k]/M[k][k];

            for (size_t j = k+1; j <= len; j++) M[i][j] -= M[k][j]*factor;

            M[i][k] = 0;
        }
    }

    return -1;

}

void back_substitution(size_t len, double M[len][len+1], double result[len]) {
    for (signed i = len-1; i >= 0; i--) {
        result[i] = M[i][len];

        for (size_t j = i+1; j < len; j++) {
            result[i] -= M[i][j]*result[j];
        }

        result[i] = result[i]/M[i][i];
    }

}

void gaussian_elimination(size_t len, double M[len][len+1], double result[len]) {
    signed singular_flag = forward_elimination(len, M); 

    if (singular_flag != -1) {
        if (M[singular_flag][len]) {
            printf("Inconsistent system");
        } else {
            printf("May have infinitely many solutions");
        }

        return;
    }

    back_substitution(len, M, result);
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
    /*
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
    */
    double M[3][4] = {
        { 3.0,  2.0, -4.0, 3.0, },
        { 2.0,  3.0,  3.0, 15.0,},
        { 5.0, -3.0,  1.0, 14.0,},
    };

    double result[3] = { 0 };

    gaussian_elimination(3, M, result);
    print_vector("solution", 3, result);
    return EXIT_SUCCESS;
}
