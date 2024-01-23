#include "sort.h"

void insertion_sort_list(listint_t **list);

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: pointer to the head of the list
 *
 * Description: This function sorts a doubly linked list using the
 * Insertion Sort algorithm. It swaps nodes to rearrange the list in
 * ascending order and prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *unsorted = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	while (unsorted != NULL)
	{
		listint_t *next = unsorted->next;

		if (sorted == NULL || sorted->n >= unsorted->n)
		{
			unsorted->next = sorted;
			unsorted->prev = NULL;

			if (sorted != NULL)
			{
				sorted->prev = unsorted;
			}

			sorted = unsorted;
			print_list(*list);
		}
		else
		{
			listint_t *current = sorted;

			while (current->next != NULL && current->next->n > unsorted->n)
			{
				current = current->next;
			}

			unsorted->next = current->next;
			unsorted->prev = current;

			if (current->next != NULL)
			{
				current->next->prev = unsorted;
			}

			current->next = unsorted;
			print_list(*list);
		}

		unsorted = next;
	}

	*list = sorted;
}
