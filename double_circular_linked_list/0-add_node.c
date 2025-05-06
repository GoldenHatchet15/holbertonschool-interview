#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 * @list: Double pointer to the list head
 * @str: String to be duplicated into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *last;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (!list || !*list)
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		last = (*list)->prev;

		new_node->next = *list;
		new_node->prev = last;
		last->next = new_node;
		(*list)->prev = new_node;
	}

	return (new_node);
}

/**
 * add_node_begin - Adds a new node to the beginning of a double circular list
 * @list: Double pointer to the list head
 * @str: String to be duplicated into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = add_node_end(list, str);

	if (new_node)
		*list = new_node;

	return (new_node);
}
