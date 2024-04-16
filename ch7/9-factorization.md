# Challenge 9: Factorization

### Specification

- For a given value of type `size_t` output a list of the prime factors in the
  form `N0: F0 F1 F2 ...` 
- Extend this program to operate on a list of values

### Reflection

This challenge is asking for a sieve, an algorithm that decomposes an integer to
its integer prime factors. I'm going to take the simple approach for this one,
Trial Division, since the maximum value to decompose is `SIZE_MAX` where factors
to test goes up to the square root of `SIZE_MAX`. 

My first step is to determine the divisors I'm using are prime numbers to the
square root of `SIZE_MAX` and take the modulo where if the result is equal to
`0`, then we can test a given prime. To get the max value on my system, simply
run:

```C #include <stdlib.h> #include <stdio.h>

int main(void) { printf("%zu", SIZE_MAX); } 

```

```Output 

18446744073709551615 

```

# Sources

- Jens Gustedt, Modern C
