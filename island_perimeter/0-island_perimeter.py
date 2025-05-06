#!/usr/bin/python3
"""
This module contains a function that calculates the
perimeter of an island in a grid.
"""


def island_perimeter(grid):
    """
    Calculates the perimeter of the island in the grid.

    Args:
        grid (list of list of int): 2D list representing the island map

    Returns:
        int: The perimeter of the island
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
    return perimeter
