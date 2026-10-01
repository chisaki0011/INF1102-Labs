#include <stdio.h>

int main() {
    int height = 9; // Must be an odd number for a perfect center
    int width = 9;
    
    int center_row = height / 2; // 9/2 = 4 
    int center_col = width / 2;

    // Nested loops to print the cross pattern
    // Outer loop for rows starting from 0 to height with increment of 1
    for (int i = 0; i < height; i++) { 
        // Inner loop for columns starting from 0 to width with increment of 1
        for (int j = 0; j < width; j++) {
            // Print 1 if it's the middle row or middle column
            // Otherwise, print 0
            // using dual equal to check values of i and j with center_row and center_col respectively 
            if (i == center_row || j == center_col) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n"); // Move to the next line after each row
    }

    return 0;
}
