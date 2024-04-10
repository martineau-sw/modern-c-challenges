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

typedef double vector[2];

int main(void) {

    vector vec = { 2.0, 3.0 }; 
    
    printf("vector(%f, %f)\n", vec[0], vec[1]);
    return EXIT_SUCCESS;
}
