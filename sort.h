#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void count_sort(int *array, size_t size, int exp);
int get_max(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void printcheck(int *array, int r1, int r2);
void countSort(int *array, size_t size, int exp, int *buff);
void _swap(int *array, ssize_t item1, ssize_t item2);
int hoare_partition(int *array, int f_el, int l_el, int size);
void q_h_sort(int *array, ssize_t f_el, ssize_t l_el, int size);
void quick_sort_hoare(int *array, size_t size);
#endif
