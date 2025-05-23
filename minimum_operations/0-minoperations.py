#!/usr/bin/python3
"""
Module to calculate the minimum operations required
to reach exactly n 'H' characters in a file using
Copy All and Paste operations.
"""


def minOperations(n):
    if n <= 1:
        return 0
    operations = 0
    divisor = 2
    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1
    return operations
