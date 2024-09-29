#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Prints the 3x3 grid
 * @grid: The 3x3 grid to print
 *
 * Description: Prints the grid row by row, with spaces between numbers.
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Checks if the grid is stable
 * @grid: The 3x3 grid to check
 *
 * Return: 1 if stable, 0 if not
 *
 * Description: A grid is considered unstable if any cell has more
 * than 3 grains of sand.
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - Topples the sandpile grid to make it stable
 * @grid: The 3x3 grid to topple
 *
 * Description: For any cell with more than 3 grains, it topples,
 * distributing 1 grain to each of its neighbors.
 */
void topple(int grid[3][3])
{
	int i, j;
	int temp[3][3] = {0};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i > 0)
					temp[i - 1][j] += 1;
				if (i < 2)
					temp[i + 1][j] += 1;
				if (j > 0)
					temp[i][j - 1] += 1;
				if (j < 2)
					temp[i][j + 1] += 1;
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] += temp[i][j];
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: The first 3x3 grid
 * @grid2: The second 3x3 grid
 *
 * Description: Adds grid2 to grid1 and stabilizes grid1
 * if needed by repeatedly toppling the grid until it is stable.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Step 1: Add grid2 to grid1 */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/* Step 2: Stabilize grid1 */
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
