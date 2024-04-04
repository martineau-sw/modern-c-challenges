#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * The specifications on this challenge are worded rather,
 * in my opinion, ambiguously. The Union-Find probelm is
 * well documented and writing the functions themselves
 * was not as daunting as anticipated, however the utility
 * of the specified functions are questionable, FindCompress
 * in particular which states: 
 *
 * "Can you implement a FindCompress function that changes 
 * all parent entries to the root that has been found?"
 * (Modern C Gustedt p. 47)
 *
 * After working with the problem for quite a long time,
 * I decided on an operation which pushes elements to 
 * root by rank which can be thought of as a super-operation
 * to FindReplace which assigns a chosen parent value to
 * each element on the path to root. Neither of which preserve
 * the structure of the trees in my reading of the specification
 * so I took some liberties when devising functions and perhaps
 * strayed from the spirit of the exercise.
 *
 * Some search queries I recommend when tackling this challenge
 * are Union-Find and Disjoint Sets, as well as being familiar
 * with graphs and trees, specifically. 
 *
 * The defined array is written as a preorder tree traversal
 * which made it far easier to work with including creating
 * diagrams. 
 *
 * All in all, this challenge was an interesting engagement
 * on a data structure I haven't explored in as much depth
 * as some others. A nice refreshment it is to be able to 
 * gaze at the math at distance in much the same way we 
 * admire strokes of color that trees paint some of our 
 * backdrops.
 */
void print_array(size_t length, size_t parent[length]) {
    printf("[");
    for(size_t i = 0; i < length; i++) {
        if (parent[i] == SIZE_MAX) printf( (i == length - 1) ? "%zu:ROOT]\n" : "%zu:ROOT, ", i );
        else printf( (i == length - 1) ? "%zu:%zu]\n" : "%zu:%zu, ", i, parent[i]);
    }
}

void check_input(char label[32], size_t value, size_t length) { 
    if (value < SIZE_MAX && value > length) {
        printf("%s: invalid parameters passed", label);
        exit(-1);
    }
}

void initialize(size_t length, size_t parent[length]) {
    for(size_t i = 0; i < length; parent[i++] = SIZE_MAX); 
}

size_t get_root_index(size_t i, size_t length, size_t parent[length]) {
    check_input("get_root_index", i, length);
    if (parent[i] == SIZE_MAX) return i;
    return get_root_index(parent[i], length, parent);
}

size_t find(size_t value, size_t length, size_t parent[length]) {
    check_input("find", value, length);
    size_t index = SIZE_MAX;
    while (++index < length && parent[index] != value);
    if (index == length) return SIZE_MAX;
    return index;
}

size_t find_at_ground_level(size_t value, size_t length, size_t parent[length]) {
    check_input("find_at_ground_level", value, length);
    size_t value_index = find(value, length, parent);
    if (find(value_index, length, parent) == SIZE_MAX) return value_index;
    return SIZE_MAX;    
}

void find_replace(size_t value, size_t new, size_t length, size_t parent[length]) {
    check_input("find_replace: value", value, length);
    check_input("find_replace: new", new, length);
    size_t value_index = find(value, length, parent);
    if (new == get_root_index(value_index, length, parent)) return; 
    while(parent[value_index] != SIZE_MAX) {
        value = value_index;
        value_index = parent[value_index];
        parent[value] = new;
    }
    parent[value_index] = new;
}

void find_compress(size_t value, size_t length, size_t parent[length]) {
    check_input("find_compress: value", value, length);
    check_input("find_replace: new", value, length);
    size_t value_root = get_root_index(value, length, parent);
    size_t next_rank = parent[value];
    for (;;) {
        size_t value_index = find(value, length, parent);
        if (value_index == SIZE_MAX) {
            if (next_rank == value_root) break;
            value = next_rank;
            next_rank = parent[value];
        }
        parent[value_index] = value_root;
    }
}

void union(size_t a, size_t b, size_t length, size_t parent[length]) {
    check_input("union: a", a, length);
    check_input("union: b", b, length);

    size_t a_root = get_root_index(a, length, parent);
    size_t b_root = get_root_index(b, length, parent);

    parent[b_root] = a_root;
}

int main(void) {
    size_t array[10] = {
        [0] = SIZE_MAX,
        [1] = 0,
        [2] = 1,
        [3] = 1,
        [4] = 0,
        [5] = 4,
        [6] = SIZE_MAX,
        [7] = 6,
        [8] = 7,
        [9] = SIZE_MAX,
    };
    print_array(10, array);
    printf("find(1) expect: 2 actual: %zu\n", find(1, 10, array));
    printf("find(SIZE_MAX) expect: 0 actual: %zu\n", find(SIZE_MAX, 10, array));
    printf("find_at_ground_level(1) expect: 2 actual: %zu\n", find_at_ground_level(1, 10, array));
    printf("find_at_ground_level(0) expect: SIZE_MAX actual: %zu\n", find_at_ground_level(0, 10, array));
    printf("get_root_index(2) expect: 0 actual: %zu\n", get_root_index(0, 10, array));
    //printf("find_replace(1, 3) expect: [0:3, 1:3, 2:3, 3:1, 4:0, 5:4, 6:ROOT, 7:6, 8:7, 9:ROOT] actual: ");
    printf("find_compress(1, 3) expect: [0:3, 1:3, 2:3, 3:1, 4:0, 5:4, 6:ROOT, 7:6, 8:7, 9:ROOT] actual: ");
    find_replace(1, 3, 10, array);
    print_array(10, array);
}
