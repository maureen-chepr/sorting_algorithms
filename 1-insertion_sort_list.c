#include "sort.h"
/**
 * swap - swap 2 element in an list
 * @head: head of list
 * @x: node
 * @y: node
 */
void swap(listint_t *x, listint_t *y, listint_t **head)
{
	listint_t *aux1 = NULL, *aux2 = NULL;

	if (x == NULL || y == NULL)
		return;
	aux1 = x->prev;
	aux2 = y->next;
	
	if (aux1)
		aux1->next = y;
	if (aux2)
		aux2->prev = x;
	x->next = aux2;
	x->prev = y;
	y->next = x;
	y->prev = aux1;
	if (aux1 == NULL)
		*head = y;
}
/**
 * insertion_sort_list  - insertion_sort_list
 * @list: doubly liked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;
	int value;

	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
	{
		return;
	}
	head = *list;
	while (head)
	{
		prev = head->prev;
				value = head->n;

		while (prev && prev->n > value)
		{
			swap(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}
		head = head->next;
	}
}

