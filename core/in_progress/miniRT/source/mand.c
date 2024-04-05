#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000
#define FILENAME "mandelbrot.bmp"

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Color;

Color colormap(int iter) {
    Color color;
    if (iter == MAX_ITER) {
        color.r = 0;
        color.g = 0;
        color.b = 0;
    } else {
        double t = (double)iter / MAX_ITER;
        color.r = (uint8_t)(9 * (1 - t) * t * t * t * 255);
        color.g = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
        color.b = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    }
    return color;
}

void write_bitmap(Color pixels[HEIGHT][WIDTH]) {
    FILE *f = fopen(FILENAME, "wb");
    if (!f) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    uint8_t header[54] = {
        0x42, 0x4D, 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0,
        WIDTH & 0xFF, (WIDTH >> 8) & 0xFF, (WIDTH >> 16) & 0xFF, (WIDTH >> 24) & 0xFF,
        HEIGHT & 0xFF, (HEIGHT >> 8) & 0xFF, (HEIGHT >> 16) & 0xFF, (HEIGHT >> 24) & 0xFF,
        1, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    fwrite(header, sizeof(uint8_t), 54, f);

    for (int y = HEIGHT - 1; y >= 0; y--) {
        for (int x = 0; x < WIDTH; x++) {
            fwrite(&pixels[y][x], sizeof(uint8_t), 3, f);
        }
        int padding = (4 - (WIDTH * 3) % 4) % 4;
        uint8_t pad = 0;
        fwrite(&pad, sizeof(uint8_t), padding, f);
    }

    fclose(f);
}

int mandelbrot(double x, double y) {
    double cx = x;
    double cy = y;
    double zx = 0;
    double zy = 0;
    int iter = 0;

    while (zx * zx + zy * zy < 4 && iter < MAX_ITER) {
        double tmp = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy + cy;
        zx = tmp;
        iter++;
    }

    return iter;
}

int main() {
    Color pixels[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            int iter = mandelbrot(real, imag);
            pixels[y][x] = colormap(iter);
        }
    }

    write_bitmap(pixels);
    printf("Mandelbrot set generated successfully and saved as \"%s\"\n", FILENAME);

    return 0;
}
