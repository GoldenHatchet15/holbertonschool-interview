#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size, i, j, check_i, check_j;
	char symbol;

	if (level < 0)
		return;

	size = pow(3, level); /* Calculate the size of the grid */

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			symbol = '#';
			check_i = i;
			check_j = j;

			/* Determine whether the current cell should be empty */
			while (check_i > 0 || check_j > 0)
			{
				if (check_i % 3 == 1 && check_j % 3 == 1)
				{
					symbol = ' ';
					break;
				}
				check_i /= 3;
				check_j /= 3;
			}

			printf("%c", symbol);
		}
		printf("\n");
	}
}
