# Radix Sort

This directory contains an implementation of the **Radix Sort** algorithm, a non-comparative sorting algorithm that works by distributing elements into buckets according to their individual digits. It processes the digits from the least significant to the most significant.

## Algorithm Overview

Radix Sort works as follows:
1. Find the maximum number in the array to determine the number of digits.
2. Iterate through each digit position (starting from the least significant digit).
3. Use a stable sorting algorithm (e.g., counting sort) to sort the numbers based on the current digit.
4. Repeat until all digit positions are processed.

## Advantages
- **Time Complexity**: O(nk), where `n` is the number of elements and `k` is the number of digits in the largest number.
- Efficient for sorting large datasets with small ranges of digits.

## Disadvantages
- Requires additional memory for buckets.
- Not suitable for negative numbers without modification.

## Files in This Directory
- `radix_sort.c`: Contains the implementation of the Radix Sort algorithm.
- `main.c`: Example usage and testing of the Radix Sort function.
- `README.md`: Documentation for the project.

## How to Compile
To compile the code, use the following command:
```bash
gcc -Wall -Wextra -Werror -pedantic radix_sort.c main.c -o radix_sort
```

## How to Run
Run the compiled program with:
```bash
./radix_sort
```

## References
- [Radix Sort - GeeksforGeeks](https://www.geeksforgeeks.org/radix-sort/)
- [Wikipedia: Radix Sort](https://en.wikipedia.org/wiki/Radix_sort)