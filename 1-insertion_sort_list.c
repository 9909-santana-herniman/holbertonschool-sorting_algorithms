#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the doubly linked list.
 * @node_1: First node to be swapped.
 * @node_2: Second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *node_1, listint_t *node_2)
{
	/* Get pointers to the nodes around node_1 and node_2 */
	listint_t *prev = node_1->prev;
	listint_t *next = node_2->next;

/* Update pointers: node_1_prev <-> node_2 <-> node_1 <-> node_2_next */
	if (prev != NULL)
	{
		prev->next = node_2;
	}
	else
	{
		*list = node_2; /* Update head if node_1 was the head */
	}

	node_2->prev = prev;
	node_2->next = node_1;
	node_1->prev = node_2;
	node_1->next = next;

	if (next != NULL)
	{
		next->prev = node_1;
	}
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
	}

	while (temp->prev != NULL && temp->prev->n > temp->n)
	{
		swap_nodes(list, temp->prev, temp);
		print_list(*list);
	}
}
