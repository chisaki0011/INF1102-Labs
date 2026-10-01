#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Internal Definitions / Image Dimensions
#define X_DIM 256
#define Y_DIM 256

// Choose your function to plot: sin, cos, tan etc.
#define MYFN cos

// Mathematical scale transformations
#define X_SCALE (3.14159265 * 2.0 / X_DIM)
#define Y_SCALE (2.0 / Y_DIM)

int main() {
    // 1. Output the standard P3 PPM Header to stdout
    printf("P3\n");
    printf("%d %d\n", X_DIM, Y_DIM);
    printf("255\n");

    // 2. Loop through every single pixel row and column
    for (int py = 0; py < Y_DIM; py++) {
        for (int px = 0; px < X_DIM; px++) {
            
            // Calculate where the curve target row is for this column
            int target_yy = (int)((Y_DIM / 2.0) * (1.0 - MYFN(px * X_SCALE)));

            // If the current row 'py' is underneath or inside the curve limit
            if (py >= target_yy) {
                // Generate a vibrant rainbow gradient only inside the curve area
                int r = px;               // Shifts red color left-to-right
                int g = py;               // Shifts green color top-to-bottom
                int b = 255 - px;         // Shifts blue color right-to-left
                
                printf("%d %d %d  ", r, g, b);
            } 
            else {
                // Background outside the curve: Solid Pure White
                printf("255 255 255  ");
            }
        }
        printf("\n");
    }

    // Print status updates to stderr so it doesn't break the image file data
    fprintf(stderr, "Filled function curve plot generated successfully!\n");

    return 0;
}

// Compile and Generate Instructions:
// gcc fill_curve.c -o fill_curve -lm
// ./fill_curve > filled_plot.ppm
