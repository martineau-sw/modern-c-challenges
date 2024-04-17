# Challenge 9: Factorization

### Specification

- For a given value of type `size_t` output a list of the prime factors in the
  form `N0: F0 F1 F2 ...` 
- Extend this program to operate on a list of values

### Reflection

This challenge is asking for a sieve, an algorithm that decomposes an integer to
its integer prime factors. I'm going to take the simple approach for this one,
Trial Division, since the maximum value to decompose is `SIZE_MAX` where factors
to test goes up to `SIZE_MAX`. 

I wrote a `decompose` function for trial division and a function `is_prime` to
determine if a given factor is suitable to try. The program breaks down at large
values, like `SIZE_MAX`. I have yet to test if the program simply hangs after a
limit or if it takes an inordinate amount of time.

# Sources

- Jens Gustedt, Modern C
