#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: pointer to the head of the list
 *
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (*list == NULL || (*list)->next == NULL)
	{
		return;
	}

	while (*list != NULL)
	{
		current = *list;
		*list = (*list)->next;

		while (current != NULL && ((*list) == NULL || current->n < (*list)->n))
		{
			current->next = (*list);
			(*list)->prev = current;
			(*list) = current;

			print_list(*list);
		}

		list = &((*list)->next);
	}
}
