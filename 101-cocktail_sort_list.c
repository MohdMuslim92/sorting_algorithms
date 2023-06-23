#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 *			ascending order using the Cocktail Shaker Sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the doubly linked list.
 *
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current = *list;

	if (list == NULL || *list == NULL)
		return;
	while (swapped)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap(list, current, current->next);
				print_list(*list);
				swapped = 1;
			} else
			{
				current = current->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;

		while (current->prev != NULL)
		{
			if (current->prev->n > current->n)
			{
				swap(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			} else
			{
				current = current->prev;
			}
		}
	}
}

/**
 * swap - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to a pointer to the head of the doubly linked list.
 * @node1: Pointer to the first node to be swapped.
 * @node2: Pointer to the second node to be swapped.
 *
 */

void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1 == NULL || node2 == NULL)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	if (node1->next != NULL)
		node1->next->prev = node1;
	node2->next = node1;
}

