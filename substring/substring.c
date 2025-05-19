#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * match - checks if the substring matches the concatenation of all words
 * @s: pointer to substring
 * @wc: array of word_count structs
 * @wc_size: number of unique words
 * @word_len: length of each word
 * @nb_words: total number of words
 *
 * Return: 1 if match, 0 otherwise
 */
static int match(char *s, word_count_t *wc, int wc_size,
		  int word_len, int nb_words)
{
	int i, j, found;
	int *seen;
	char *w;

	seen = calloc(wc_size, sizeof(int));
	if (!seen)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		w = strndup(s + i * word_len, word_len);
		found = 0;
		for (j = 0; j < wc_size; j++)
		{
			if (strncmp(w, wc[j].word, word_len) == 0)
			{
				seen[j]++;
				if (seen[j] > wc[j].count)
				{
					free(w);
					free(seen);
					return (0);
				}
				found = 1;
				break;
			}
		}
		free(w);
		if (!found)
		{
			free(seen);
			return (0);
		}
	}
	free(seen);
	return (1);
}

/**
 * build_word_count - builds word_count array
 * @words: list of words
 * @nb_words: number of words
 * @count: pointer to store number of unique words
 *
 * Return: array of word_count structs
 */
static word_count_t *build_word_count(
	const char **words,
	int nb_words,
	int *count)
{
	int i, j;
	word_count_t *wc = calloc(nb_words, sizeof(word_count_t));

	if (!wc)
		return (NULL);

	*count = 0;
	for (i = 0; i < nb_words; i++)
	{
		for (j = 0; j < *count; j++)
		{
			if (strcmp(words[i], wc[j].word) == 0)
			{
				wc[j].count++;
				break;
			}
		}
		if (j == *count)
		{
			wc[*count].word = strdup(words[i]);
			wc[*count].count = 1;
			(*count)++;
		}
	}
	return (wc);
}

/**
 * collect_indices - checks each index for valid substring
 * @s: input string
 * @wc: word_count array
 * @count: number of unique words
 * @word_len: length of each word
 * @nb_words: number of total words
 * @s_len: length of input string
 * @total_len: length of full valid substring
 * @n: pointer to store size of output
 *
 * Return: array of valid starting indices
 */
static int *collect_indices(const char *s, word_count_t *wc, int count,
					 int word_len, int nb_words, int s_len, int total_len, int *n)
{
	int i;
	int *indices = malloc(sizeof(int) * (s_len - total_len + 1));

	*n = 0;
	if (!indices)
		return (NULL);

	for (i = 0; i <= s_len - total_len; i++)
	{
		if (match((char *)s + i, wc, count, word_len, nb_words))
			indices[(*n)++] = i;
	}

	if (*n == 0)
	{
		free(indices);
		return (NULL);
	}
	return (indices);
}

/**
 * find_substring - finds starting indices of substrings made from words
 * @s: input string
 * @words: array of words
 * @nb_words: number of words
 * @n: pointer to store result size
 *
 * Return: array of starting indices, or NULL
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
	int word_len, total_len, s_len, count;
	word_count_t *wc;
	int *indices;
	int i;

	if (!s || !words || nb_words == 0)
		return (NULL);

	word_len = strlen(words[0]);
	total_len = word_len * nb_words;
	s_len = strlen(s);
	if (s_len < total_len)
		return (NULL);

	wc = build_word_count(words, nb_words, &count);
	if (!wc)
		return (NULL);

	indices = collect_indices(
s, wc, count, word_len, nb_words, s_len, total_len, n
);

	for (i = 0; i < count; i++)
		free(wc[i].word);
	free(wc);

	return (indices);
}
