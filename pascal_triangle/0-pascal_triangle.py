#!/usr/bin/python3
"""
Returns a list of lists of integers
representing the Pascal’s triangle of n.
"""


def pascal_triangle(n):
    """
    Returns a list of lists of integers
    representing the Pascal’s triangle of n.
    """
    if n <= 0:
        return []

    triangle = [[1]]  # Start with the first row

    for i in range(1, n):
        prev_row = triangle[-1]
        new_row = [1]  # First element of the row
        for j in range(1, i):
            new_row.append(prev_row[j - 1] + prev_row[j])
        new_row.append(1)  # Last element of the row
        triangle.append(new_row)

    return triangle
