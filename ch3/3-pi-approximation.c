#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
/*
 * Solution is based on John Zelle's python implementation of Leibniz's Pi
 * approximation. 
 *
 * I'll be honest, I have no idea how or why this works.
*/
void leibniz_seq(size_t length, size_t digits[length]) {

    long double q = 1;
    long double r = 0;
    long double t = 1;
    long double k = 1;
    long double n = 3;
    long double l = 3;
    
    for(size_t i = 0; i < length;) {

        long double _q = q;
        long double _r = r;
        long double _t = t;
        long double _k = k;
        long double _n = n;
        long double _l = l;

        if ((4*_q+_r-_t) < _n*_t) {
            digits[i] = n;
            i += 1;
            q = 10*_q;
            r = 10*(_r-_n*_t);
            t = _t;
            k = _k;
            n = floorl((10*(3*_q+_r))/_t-10*_n);
            l = _l;
        } else {
            q = _q*_k;
            r = _l*(2*_q+_r);
            t = _t*_l;
            k = _k+1;
            n = floor((_q*(7*_k+2)+_r*_l)/(_t*_l));
            l = _l+2;
        }
    }
}

void print_digits(size_t length, size_t digits[length]) {

    for(size_t i = 0; i < length; i++) {
        if(i == 1) printf(".%zu", digits[i]); 
        else printf("%zu", digits[i]);
    }

}

int main(int argc, char const* argv[]) {

    if(argc != 2) {
        printf("./pi <integer:[1, 45]>");
        return EXIT_FAILURE;
    }

    char* str;
    unsigned long conv = strtoul(argv[1], &str, 10);
    size_t precision = conv;

    if(precision < 1 || precision > 46) {
        printf("./pi <integer:[1, 45]>");
        return EXIT_FAILURE; 
    }

    if(*str != '\0') {
        printf("./pi <integer:[1, 45]>");
        return EXIT_FAILURE;
    }

    size_t digits[precision];
    leibniz_seq(precision, digits);
    print_digits(precision, digits);
    
    return 0;
}
