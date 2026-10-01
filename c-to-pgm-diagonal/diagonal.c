#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 256; // Size of the image (size x size)
    const char *filename = "diagonal.pgm";

    // Open file in binary write mode
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // 1. Write the PGM Header (Changed max value to 255)
    fprintf(file, "P5\n%d %d\n255\n", size, size);

    // 2. Write the binary pixel data to the file
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                fputc(0, file); // black pixel for the diagonal line
            } else {
                fputc(255, file);   // white pixel for the background
            }
        }
    }

    fclose(file);
    printf("Successfully created '%s'!\n", filename);
    return 0;
}
