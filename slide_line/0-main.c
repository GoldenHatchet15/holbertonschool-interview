#include <stdio.h>
#include "slide_line.h"

int main() {
    int line[] = {2, 2, 0, 4, 4};
    size_t size = sizeof(line) / sizeof(line[0]);
    int direction = SLIDE_LEFT; // Assuming SLIDE_LEFT is defined in slide_line.h

    // Test sliding left
    if (slide_line(line, size, direction)) {
        printf("Slide to the left: ");
        for (size_t i = 0; i < size; i++) {
            printf("%d ", line[i]);
        }
        printf("\n");
    } else {
        printf("Failed to slide and merge the line to the left.\n");
    }

    // Resetting the array for right slide test
    int line2[] = {2, 2, 0, 4, 4};
    direction = SLIDE_RIGHT; // Assuming SLIDE_RIGHT is defined

    // Test sliding right
    if (slide_line(line2, size, direction)) {
        printf("Slide to the right: ");
        for (size_t i = 0; i < size; i++) {
            printf("%d ", line2[i]);
        }
        printf("\n");
    } else {
        printf("Failed to slide and merge the line to the right.\n");
    }

    return 0;
}
