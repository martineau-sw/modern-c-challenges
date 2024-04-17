#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(size_t len, size_t parent[len]) {

    putchar('[');

    for(size_t i = 0; i < len; i++) {
        if (parent[i] == SIZE_MAX) {
            printf( 
                    (i == len - 1) ? "%zu:ROOT]\n" : "%zu:ROOT, ", 
                    i);
        } else {
            printf( 
                    (i == len - 1) ? "%zu:%zu]\n" : "%zu:%zu, ", 
                    i, 
                    parent[i]);
        }
    }

}

void initialize(size_t len, size_t parent[len]) {

    for(size_t i = 0; i < len; parent[i++] = SIZE_MAX); 

}

size_t get_root_index(size_t i, size_t len, size_t parent[len]) {
    if (parent[i] == SIZE_MAX) return i;
    return get_root_index(parent[i], len, parent);
}

size_t find(size_t value, size_t len, size_t parent[len]) {

    size_t index = SIZE_MAX;

    while (++index < len && parent[index] != value);

    if (index == len) return SIZE_MAX;

    return index;

}

size_t find_at_ground_level(size_t value, size_t len, size_t parent[len]) {
    size_t value_index = find(value, len, parent);
    if (find(value_index, len, parent) == SIZE_MAX) return value_index;
    return SIZE_MAX;    
}

void find_replace(size_t value, size_t new, size_t len, size_t parent[len]) {
    size_t value_index = find(value, len, parent);
    if (new == get_root_index(value_index, len, parent)) return; 
    while(parent[value_index] != SIZE_MAX) {
        value = value_index;
        value_index = parent[value_index];
        parent[value] = new;
    }
    parent[value_index] = new;

}

void find_compress(size_t value, size_t len, size_t parent[len]) {
    size_t value_root = get_root_index(value, len, parent);
    size_t next_rank = parent[value];
    for (;;) {
        size_t value_index = find(value, len, parent);
        if (value_index == SIZE_MAX) {
            if (next_rank == value_root) break;
            value = next_rank;
            next_rank = parent[value];
        }
        parent[value_index] = value_root;
    }
}

void tree_union(size_t a, size_t b, size_t len, size_t parent[len]) {
    size_t a_root = get_root_index(a, len, parent);
    size_t b_root = get_root_index(b, len, parent);
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
    printf("find(1) expect: 2 actual: %zu\n", find(1, 10, array)); printf("find(SIZE_MAX) expect: 0 actual: %zu\n", find(SIZE_MAX, 10, array));
    printf("find_at_ground_level(1) expect: 2 actual: %zu\n", find_at_ground_level(1, 10, array));
    printf("find_at_ground_level(0) expect: SIZE_MAX actual: %zu\n", find_at_ground_level(0, 10, array));
    printf("get_root_index(2) expect: 0 actual: %zu\n", get_root_index(0, 10, array));
    printf("find_compress(1, 3) expect: [0:3, 1:3, 2:3, 3:1, 4:0, 5:4, 6:ROOT, 7:6, 8:7, 9:ROOT] actual: ");
    find_replace(1, 3, 10, array);
    print_array(10, array);
}
