#ifndef SUBSTRING_H
#define SUBSTRING_H

/**
 * struct word_count - Struct for tracking how many times each word appears
 * @word: Pointer to a word string
 * @count: Number of times this word appears in the list
 */
typedef struct word_count
{
	char *word;
	int count;
} word_count_t;

int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */
