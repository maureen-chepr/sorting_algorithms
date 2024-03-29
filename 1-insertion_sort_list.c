#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order
 * @list: integers to sort
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

		if (list == NULL || *list == NULL || (*list)->next == NULL)
			return;
	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		prev = current->prev;
		while (prev != NULL && prev->n > temp->n)
		{
			/* Swap nodes */
			if (temp->next != NULL)
				temp->next->prev = prev;
			prev->next = temp->next;
			temp->next = prev;
			temp->prev = prev->prev;
			prev->prev = temp;

			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;
			print_list(*list);
			prev = temp->prev;
		}
		current = current->next;
	}
}
