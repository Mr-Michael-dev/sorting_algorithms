#include "sort.h"

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
	listint_t *sorted;
	listint_t *unsorted;
	listint_t *current;
	listint_t *next;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
    {
        return;
    }

    sorted = NULL;
    unsorted = *list;

    while (unsorted != NULL)
    {
        next = unsorted->next;

        if (sorted == NULL || sorted->n >= unsorted->n)
        {
            unsorted->next = sorted;
            unsorted->prev = NULL;

            if (sorted != NULL)
	    {
                sorted->prev = unsorted;
	    }

            sorted = unsorted;
        }
        else
        {
            current = sorted;

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
        }

        *list = sorted;
        print_list(*list);

        unsorted = next;
    }
}
