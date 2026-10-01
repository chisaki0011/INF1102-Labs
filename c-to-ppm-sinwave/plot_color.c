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
    // P3 means ASCII color format, followed by width, height, and max color depth
    printf("P3\n");
    printf("%d %d\n", X_DIM, Y_DIM);
    printf("255\n");

    // 2. Loop through every pixel to calculate colors dynamically
    for (int py = 0; py < Y_DIM; py++) {
        for (int px = 0; px < X_DIM; px++) {
            
            // Map the current pixel position to the mathematical function value
            // We use the professor's exact mathematical scaling formula
            int target_yy = (int)((Y_DIM / 2.0) * (1.0 - MYFN(px * X_SCALE)));

            // Check if the current pixel row (py) matches our plotted function curve
            // We give it a thickness threshold of 2 pixels so the line remains solid
            if (abs(py - target_yy) <= 2) {
                // Bright Neon Green curve for clean contrast against the background
                printf("0 255 128  ");
            } 
            // Optional bonus: Draw a subtle gray horizontal axis grid line through the center
            else if (py == Y_DIM / 2) {
                printf("100 100 100  ");
            }
            else {
                // Generate a beautiful procedural gradient background
                // Red ramps up as we move right, Blue stays deep, Green subtle
                int r = px;               // Smooth horizontal transition
                int g = (py * 30) / 255;  // Subtle green tint based on vertical height
                int b = 255 - py;         // Dark blue shifts to bright blue vertically
                
                printf("%d %d %d  ", r, g, b);
            }
        }
        // Newline at the end of each row makes the raw text readable if opened in an editor
        printf("\n");
    }

    // Print a quick confirmation status to stderr so it doesn't pollute the image data
    fprintf(stderr, "Color function plot generated successfully via stdout redirection!\n");

    return 0;
}

// 1. Compile the code using the explicit math library linking flag
// gcc plot_color.c -o plot_color -lm

// 2. Run the executable and redirect the data stream to generate your image
// ./plot_color > function_plot.ppm
