#include "holberton.h"
#include <stdlib.h>

/**
 * _isdigit - checks if a string is composed of digits
 * @s: string to check
 *
 * Return: 1 if digits only, 0 otherwise
 */
int _isdigit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string to measure
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * print_result - prints the result and frees memory
 * @res: pointer to result array
 * @len: length of result array
 */
void print_result(int *res, int len)
{
	int i, started = 0;

	for (i = 0; i < len; i++)
	{
		if (res[i])
			started = 1;
		if (started)
			_putchar(res[i] + '0');
	}

	if (!started)
		_putchar('0');

	_putchar('\n');
	free(res);
}

/**
 * main - Entry point: multiplies two large positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, i, j, mul, sum, *res;

	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	num1 = argv[1];
	num2 = argv[2];
	len1 = _strlen(num1);
	len2 = _strlen(num2);

	res = malloc(sizeof(int) * (len1 + len2));
	if (!res)
		return (1);
	for (i = 0; i < len1 + len2; i++)
		res[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = mul + res[i + j + 1];
			res[i + j + 1] = sum % 10;
			res[i + j] += sum / 10;
		}
	}

	print_result(res, len1 + len2);
	return (0);
}
