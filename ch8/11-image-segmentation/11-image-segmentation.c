#include <stdio.h>
#include <stdbool.h>
#define STB_IMAGE_IMPLEMENTATION
#include "sb_image.h"

int get_char(unsigned char b) {
    switch (b/16) {
        case 0: return ' ';
        case 1: return '.';
        case 2: return ',';
        case 3: return ':';
        case 4: return ';';
        case 5: return '-';
        case 6: return '~';
        case 7: return '=';
        case 8: return '+';
        case 9: return '^';
        case 10: return '*';
        case 11: return '#';
        case 12: return '%';
        case 13: return '8';
        case 14: return '$';
        case 15: return '@';
        default: return 'X';
    }
}

unsigned char mean(size_t x, size_t y, signed w, signed h, unsigned char *data) {
    size_t sum = 0;
    size_t pixels = 0;
    for (signed j = -1; j < 4; ++j) {
        for (signed i = -1; i < 2; ++i) {
            if (((x + i) > w) || ((x + i) < 0)) continue;
            if (((y + j) > h) || ((y + j) < 0)) continue;
            sum += data[w*(y + j) + (x + i)];
            pixels++;
        }
    }
    return sum/pixels;
}

bool load_image() {
    signed x;
    signed y;
    signed n;
    unsigned char *data = stbi_load("rose.jpg", &x, &y, &n, 0);
    
    if (data == NULL) return false;
    printf("data[0]: %u, x: %u, y: %u, n: %u\n", data[0], x, y, n);
    stbi_image_free(data);
    return true;
}

void print_image() {
    signed x, y, n;
    unsigned char *data = stbi_load("rose.jpg", &x, &y, &n, 1);
    if (data == NULL) return;

    for (size_t j = 0; j < y; j += 4) {
        putchar('\t');
        for (size_t i = 0; i < x; i += 2) {
            putchar(get_char(mean(i, j, x, y, data)));
        }
        putchar('\n');
    }
    stbi_image_free(data);
}

int main(void) {
    puts("loading image");
    print_image();
    puts("done");
}
