#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_nodeint - adds a node at the beginning of a listint_t list
 * @head: pointer to pointer to head node
 * @n: integer to store in the node
 * Return: address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * free_listint_safe - frees a listint_t list safely (even with loops)
 * @h: pointer to pointer to head node
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *runner;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		runner = *h;
		*h = (*h)->next;
		free(runner);
		count++;
	}
	*h = NULL;

	return (count);
}

/**
 * print_listint_safe - prints a listint_t list safely (even with loops)
 * @head: pointer to head node
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t count = 0;
	int loop_found = 0;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			loop_found = 1;
			break;
		}
	}

	slow = head;
	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		if (loop_found && head == fast)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			break;
		}
		head = head->next;
	}

	return (count);
}