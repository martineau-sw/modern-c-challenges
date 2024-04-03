#include <stdio.h>
#include <math.h>


double f(double x) {
    return sin(x);
}

double derivative(double (*f)(double), double x) {
    double h = 1E-8;
    return (f(x+h) - f(x))/h;   
}

int main(void) {
    double x = M_PI;
    printf("f(x) = sin(x)\tf(%f) = %f\n", x, f(x)); 
    printf("f'(x) = cos(x)\tf'(%f) = %f\n", x, derivative(f, x));
}
