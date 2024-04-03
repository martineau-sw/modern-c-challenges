#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
/*
 * solution is based on John Zelle's python 
 * implementation found at the link below
 *
 * avoided using continued declartions found in
 * the python implementation in accordance to 
 * this section of Gustedt's Modern C p. 24
 *
 * additionally, continued assignments take on 
 * the following sequential form because it appears 
 * variable references used in a continued 
 * assignment use the value before the continued 
 * assignment began instead of its most recent 
 * assignment within the same line 
 *
 * (https://www.gavalas.dev/blog/spigot-algorithms-for-pi-in-python/)
 *
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
    for(size_t i = 0; i < length; i++) 
        i == 1 ? printf(".%zu", digits[i]) : printf("%zu", digits[i]);
}
/*
 * pointers and this main signature
 * have not been covered yet, and 
 * has been implemented using external
 * resources without taking account 
 * safety and context due to ignorance
 *
 * will revise once able
 *
 */
int main(int argc, char const* argv[]) {

    if(argc < 2 || argc > 2) {
        printf("specify n digits");
        return 1;
    }

    char* str;
    unsigned long conv = strtoul(argv[1], &str, 10);
    size_t length = conv;

    if(length < 1 || length > 46) {
        printf("length exceeds precision");
        return 1; 
    }

    if(*str != '\0') {
        printf("invalid argument");
        return -1;
    }

    size_t digits[length];
    leibniz_seq(length, digits);
    print_digits(length, digits);
    
    return 0;
}
