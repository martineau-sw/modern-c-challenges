#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N_LEN 16

bool is_prime(size_t n) {
    if (n == 2) return true;
    for (size_t i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

void decompose(size_t n) {
    printf("%zu: ", n);
    for (size_t factor = 2; factor <= n; ++factor) {

        /* Check if factor is prime, ignore if not */
        if (!is_prime(factor)) continue;

        /* Check if prime is a factor of current n */
        if (n % factor == 0) {
            printf("%zu ", factor);

            /* Perform division */
            n = (n/factor);

            /* Reset factors, this value will be incremented to 2 by next */
            factor = 1;
        }
    }
    puts("");
}

/* Execute operation on an array of values */
void decompose_values(size_t len, size_t N[]) {
    for (size_t i = 0; i < len; i++) {
        decompose(N[i]);
    }
}

int main(void) {
    size_t N[N_LEN] = { 0 };
    
    /* Generate values up to 1000 */
    for (size_t i = 0; i < N_LEN; ++i) {
        N[i] = rand() % 1000;
    }

    decompose_values(N_LEN, N);
}
