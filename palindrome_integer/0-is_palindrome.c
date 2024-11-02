#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned integer is a palindrome
 * @n: the number to be checked
 * 
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long reversed = 0, original = n, remainder;

    /* Reverse the number */
    while (n != 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    /* Check if the original number matches the reversed number */
    return (original == reversed);
}