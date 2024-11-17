#include "slide_line.h"

int slide_line(int *line, size_t size, int direction) {
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT) {
        return 0; // Invalid direction
    }

    if (size == 0 || line == NULL) {
        return 0; // Invalid input
    }

    // Example logic to slide left, just moves all non-zero elements to the left
    if (direction == SLIDE_LEFT) {
        size_t j = 0; // Index for non-zero elements, now using size_t
        for (size_t i = 0; i < size; i++) {
            if (line[i] != 0) {
                line[j++] = line[i];
            }
        }
        while (j < size) {
            line[j++] = 0; // Fill the rest with zeros
        }
    } else {
        // Slide right: similar to left but in reverse
        size_t j = size - 1; // Start from the end, using size_t
        for (size_t i = size - 1; i != (size_t)-1; i--) { // Safe loop for size_t
            if (line[i] != 0) {
                line[j--] = line[i];
            }
        }
        while (j != (size_t)-1) {
            line[j--] = 0; // Fill the rest with zeros
        }
    }

    return 1; // Indicate success
}
