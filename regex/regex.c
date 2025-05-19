#include "regex.h"

/**
 * regex_match - checks if a string matches a given regex pattern
 * @str: the string to check
 * @pattern: the regex pattern
 *
 * Return: 1 if matches, 0 otherwise
 */
int regex_match(const char *str, const char *pattern)
{
	int first_match;

	if (*pattern == '\0')
		return (*str == '\0');

	first_match = (*str && (*str == *pattern || *pattern == '.'));

	if (*(pattern + 1) == '*')
	{
		return (
			regex_match(str, pattern + 2) ||
			(first_match && regex_match(str + 1, pattern))
		);
	}

	return (first_match && regex_match(str + 1, pattern + 1));
}
