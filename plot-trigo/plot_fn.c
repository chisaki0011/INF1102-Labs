#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Internal Definitions / Configurations
#define X_DIM 256
#define Y_DIM 256

// Choose your function here: sin, cos, tan, etc.
#define MYFN sin 

// Mathematical domain boundaries
#define X_MIN (-M_PI * 2.0)
#define X_MAX (M_PI * 2.0)
#define Y_MIN (-1.5)
#define Y_MAX (1.5)

// Visual styles (Grayscale 0-255)
#define COLOR_BG      0    // Black background
#define COLOR_AXIS    80   // Muted gray for axis grid
#define COLOR_CURVE   255  // Bright white for the function curve

int main() {
    const char *filename = "function_plot.pgm";
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write standard P5 PGM Header
    fprintf(file, "P5\n%d %d\n255\n", X_DIM, Y_DIM);

    // Calculate scaling factors to map pixels to math domain
    double x_scale = (X_MAX - X_MIN) / X_DIM;
    double y_scale = (Y_MAX - Y_MIN) / Y_DIM;

    // Loop through every pixel on the screen
    for (int py = 0; py < Y_DIM; py++) {
        for (int px = 0; px < X_DIM; px++) {
            
            // Step 1: Map pixel coordinate to mathematical coordinate
            double x_math = X_MIN + (px * x_scale);
            // Invert Y because pixel rows go down, but math graphs go up
            double y_math = Y_MAX - (py * y_scale);

            // Step 2: Compute the actual function value at this X
            double target_y = MYFN(x_math);

            // Default pixel color is background
            unsigned char pixel_color = COLOR_BG;

            // Step 3: Draw the X and Y axes if we cross 0
            // We use a small threshold (half pixel width) to catch the axis line
            if (fabs(x_math) < (x_scale / 2.0) || fabs(y_math) < (y_scale / 2.0)) {
                pixel_color = COLOR_AXIS;
            }

            // Step 4: Plot the function curve
            // Instead of an exact match (y_math == target_y), we check if the pixel
            // is close enough to the curve. This prevents the line from breaking.
            double thickness = y_scale * 1.5; 
            if (fabs(y_math - target_y) < thickness) {
                pixel_color = COLOR_CURVE;
            }

            // Write raw pixel byte to file
            fputc(pixel_color, file);
        }
    }

    fclose(file);
    printf("Successfully plotted function to '%s'!\n", filename);
    return 0;
}
