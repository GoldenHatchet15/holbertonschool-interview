#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * reverse_list - Reverses a singly linked list.
 * @head: Pointer to the head of the list.
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL;
	listint_t *next;

	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return (prev);
}

/**
 * compare_lists - Compares two halves of a linked list.
 * @first_half: Pointer to the first half of the list.
 * @second_half: Pointer to the second half of the list.
 * Return: 1 if both halves are identical, 0 otherwise.
 */
int compare_lists(listint_t *first_half, listint_t *second_half)
{
	while (second_half && first_half)
	{
		if (first_half->n != second_half->n)
			return (0);
		first_half = first_half->next;
		second_half = second_half->next;
	}
	return (1);
}

/**
 * restore_list - Restores the original order of the list by reversing it back.
 * @prev_slow: Pointer to the node before the reversed part.
 * @mid_node: Pointer to the middle node (in case of an odd number of nodes).
 * @second_half: Pointer to the reversed second half.
 */
void restore_list(listint_t *prev_slow,
listint_t *mid_node, listint_t *second_half)
{
	second_half = reverse_list(second_half);
	if (mid_node)
	{
		prev_slow->next = mid_node;
		mid_node->next = second_half;
	}
	else
		prev_slow->next = second_half;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the linked list.
 * Return: 1 if the list is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head;
	listint_t *second_half, *prev_slow = *head;
	listint_t *mid_node = NULL;
	int result = 1;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	/* Find the middle of the list */
	while (fast && fast->next)
	{
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}

	/* If the list has an odd number of nodes */
	if (fast)
	{
		mid_node = slow;
		slow = slow->next;
	}

	/* Reverse the second half of the list */
	second_half = reverse_list(slow);
	prev_slow->next = NULL; /* Terminate the first half */

	/* Compare the two halves */
	result = compare_lists(*head, second_half);

	/* Restore the list */
	restore_list(prev_slow, mid_node, second_half);

	return (result);
}
