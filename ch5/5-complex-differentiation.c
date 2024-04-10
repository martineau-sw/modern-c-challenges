#include <stdio.h>
#include <math.h>
#include <complex.h>

double complex f(double x) {
    return sin(x);
}

double complex derivative(double (*f)(double), double x) {
    double h = 1E-8;
    return (f(x+h) - f(x))/h;   
}

int main(void) {
    double x = M_PI;
    printf("f(x) = sin(x)\tf(%f + %fi) = %f + %fi\n", creal(x), cimag(x), creal(f(x)), cimag(f(x))); 
    printf("f'(x) = cos(x)\tf'(%f + %fi) = %f + %fi\n", creal(x), cimag(x), creal(f(x)), cimag(f(x)));  
}
