#!/usr/bin/python3
"""
Prime Game Module
"""


def isWinner(x, nums):
    """
    Determines the winner of the Prime Game.

    Args:
        x (int): Number of rounds.
        nums (list): List of n values for each round.

    Returns:
        str: Name of the player who won the most rounds (Maria or Ben).
             None if the winner cannot be determined.
    """
    if not nums or x < 1:
        return None

    max_num = max(nums)

    # Generate a list of primes up to max_num using Sieve of Eratosthenes
    primes = [True for _ in range(max_num + 1)]
    primes[0] = primes[1] = False

    for i in range(2, int(max_num**0.5) + 1):
        if primes[i]:
            for j in range(i*i, max_num + 1, i):
                primes[j] = False

    # For each round, determine the winner
    maria_wins = 0
    ben_wins = 0

    for n in nums:
        # Count prime numbers in the range [1, n]
        prime_count = sum(1 for i in range(2, n + 1) if primes[i])

        # Determine the winner based on the count of prime numbers
        # If the count is odd, Maria wins (since she goes first)
        # If the count is even, Ben wins
        if prime_count % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
