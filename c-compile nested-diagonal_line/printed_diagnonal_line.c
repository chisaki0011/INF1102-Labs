#include <stdio.h>

int main() {
    int size = 256; // Size of the square matrix
    // x and y dimensions of the square matrix are both equal to size
    // Nested loops to print the diagonal line pattern

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}
