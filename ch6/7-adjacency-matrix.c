#include <stdio.h>
#include <stdlib.h>

typedef double matrix4x4[4][4];

void print_matrix(char label[], size_t rows, size_t cols, double M[][cols]) {
    printf("%s\n", label);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f", M[i][j]);
            if (j < cols - 1) printf(", ");
        }
        if(i < rows) printf("\n");
    }
    
}

int main(void) {
    matrix4x4 A = {
        {0, 1, 1, 1,},
        {1, 0, 1, 1,},
        {1, 1, 0, 1,},
        {1, 1, 1, 0,},
    };

    print_matrix("adjacency matrix", 4, 4, A);
}
