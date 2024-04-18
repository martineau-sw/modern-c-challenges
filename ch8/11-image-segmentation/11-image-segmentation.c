#include <stdio.h>
#include <stdbool.h>
#define STB_IMAGE_IMPLEMENTATION
#include "sb_image.h"


bool load_image() {
    signed x;
    signed y;
    signed n;
    unsigned char *data = stbi_load("rose.jpg", &x, &y, &n, 0);
    
    if (data == NULL) return false;
    printf("x: %u, y: %u, n: %u\n", x, y, n);

    stbi_image_free(data);
    return true;
}

int main(void) {
    puts("loading image");
    load_image();
    puts("done");
}
