# 2D Menger Sponge

## Description
This project involves writing a function that draws a 2D Menger Sponge. The Menger Sponge is a fractal curve, and in this task, we will focus on its 2D representation.

## Prototype
```c
void menger(int level);
```

- `level`: The level of the Menger Sponge to draw. If `level` is lower than 0, the function does nothing.

## Requirements
- You are allowed to use the math library.
- Your program will be compiled using the `-lm` flag.

## Format
- A Menger Sponge is a 3x3 square of level N-1 sponges, except for the center one, which is left empty.
- A level 0 sponge is represented by the `#` character.

### Examples
- A level 0 sponge is a simple 1x1 square:
    ```
    #
    ```
- A level 1 sponge is a 3x3 square of level 0 sponges, except for the center one, which is left empty:
    ```
    ###
    # #
    ###
    ```
- A level 2 sponge is a 3x3 square of level 1 sponges, except for the center one, which is left empty:
    ```
    ####### 
    # # # #
    #######
    ### ###
    # # # #
    ### ###
    #######
    ```

### TIP
The size of a level N Menger sponge is calculated as follows: `3^N`.

## Example Usage
```c
#include <stdio.h>
#include <stdlib.h>
#include "menger.h"

/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
        int level;

        if (ac < 2)
        {
                fprintf(stderr, "Usage: %s level\n", av[0]);
                return (EXIT_FAILURE);
        }

        level = atoi(av[1]);
        menger(level);

        return (EXIT_SUCCESS);
}
```

## Compilation
```sh
gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
```