#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the doubly linked list.
 * @node_1: First node to be swapped.
 * @node_2: Second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *node_1, listint_t *node_2)
{
	if (node_1->prev)
	{
		node_1->prev->next = node_2;
	}
	else
	{
		*list = node_2;
	}

	if (node_2->next)
	{
		node_2->next->prev = node_1;
	}

	node_1->next = node_2->next;
	node_2->prev = node_1->prev;
	node_1->prev = node_2;
	node_2->next = node_1;

	print_list(*list);

}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		while (temp->prev && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp->prev, temp);
		}
		current = current->next;
	}
}
