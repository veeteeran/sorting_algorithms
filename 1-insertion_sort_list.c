#include "sort.h"
void reset_ptr(listint_t *element, listint_t *mover);
/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: list to sort
 *
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted_end;
	listint_t *element;
	listint_t *mover;

	if ((*list)->next == NULL || *list == NULL)
		return;

	sorted_end = *list;
	mover = sorted_end;
	element = sorted_end->next;
	while (sorted_end->next != NULL)
	{
		if (element->n >= sorted_end->n)
		{
			sorted_end = element;
			element = element->next;
			mover = sorted_end;
			continue;
		}
		while (element->n < mover->n && mover->prev != NULL && element->prev != NULL)
		{
			mover = mover->prev;
			element->prev->next = element->next;
			if (element->next != NULL)
				element->next->prev = element->prev;
			element->prev = mover;
			element->next = mover->next;
			mover->next->prev = element;
			mover->next = element;
			print_list(*list);
		}
		if (mover->prev == NULL && element->n < mover->n)
		{
			reset_ptr(element, mover);
			*list = element;
			print_list(*list);
		}
		mover = sorted_end;
		if (sorted_end->next != NULL)
			element = sorted_end->next;
	}
}

/**
 * reset_ptr - point nodes in list properly
 * @element: the element to compare
 * @mover: pointer moving through list
 */
void reset_ptr(listint_t *element, listint_t *mover)
{
	mover->prev = element;
	element->prev->next = element->next;
	if (element->next != NULL)
		element->next->prev = element->prev;
	element->prev = NULL;
	element->next = mover;
}
