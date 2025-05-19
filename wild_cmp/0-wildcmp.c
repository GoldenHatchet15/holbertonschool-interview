#include "holberton.h"

/**
 * wildcmp - Compares two strings, supporting wildcard '*' in s2
 * @s1: First string (normal string)
 * @s2: Second string (can contain wildcard '*')
 * Return: 1 if strings are considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1); /* End of both strings */

	if (*s2 == '*')
	{
		/* Try to match '*' with 0 or more chars in s1 */
		if (*(s2 + 1) == '\0')
			return (1); /* '*' at end matches all remaining */
		if (wildcmp(s1, s2 + 1))
			return (1); /* Skip '*' */
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1); /* Match one char and retry */
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1)); /* Match chars and continue */

	return (0); /* No match */
}
