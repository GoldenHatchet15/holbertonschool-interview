#ifndef SUBSTRING_H
#define SUBSTRING_H

/**
 * struct word_count - word frequency structure
 * @word: the word string
 * @count: the number of times it appears
 */
struct word_count
{
	char *word;
	int count;
};

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int match(char *s, struct word_count *wc, int wc_size,
		  int word_len, int nb_words);
#endif /* SUBSTRING_H */
