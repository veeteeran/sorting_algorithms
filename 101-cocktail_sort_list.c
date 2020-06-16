#include "sort.h"
int check_sorted(listint_t **list);
/**
 * cocktail_sort_list - sorts a list using cocktail sort
 * @list: list to sort
 *
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int i, j, end, sorted, beg = 1, swaps = -1;
	listint_t *mover, *element;

	sorted = check_sorted(list);
	if (sorted > 0)
		return;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	end = listint_len(*list);
	element = *list;
	mover = element->next;
	while (swaps != 0)
	{
		swaps = 0;
		i = beg;
		while (i < end)
		{
			if (element->n > mover->n)
			{
				swap_node(element, mover);
				swaps++;
				print_list(*list);
				if (i < end - 1)
					mover = element->next;
			}
			else
			{
				element = mover;
				mover = mover->next;
			}
			i++;
		}
		end--;
		element = mover;
		mover = mover->prev;
		j = end;
		while (j > beg)
		{
			if (element->n < mover->n)
			{
				rev_swap_node(element, mover, list);
				swaps++;
				print_list(*list);
				if (j > beg + 1)
					mover = element->prev;
			}
			else
			{
				element = mover;
				mover = mover->prev;
			}
			j--;
		}
		beg++;
		element = mover;
		mover = mover->next;
	}
}

/**
 * listint_len - counts number of elements in list
 * @h: pointer to head of list
 *
 * Return: number of elements in list
 */
int listint_len(const listint_t *h)
{
	const listint_t *current;
	int num_nodes = 0;

	current = h;
	while (current)
	{
		num_nodes++;
		current = current->next;
	}

	return (num_nodes);
}

/**
 * swap_node - swap nodes in list properly
 * @element: the element to compare
 * @mover: pointer moving through list
 */
void swap_node(listint_t *element, listint_t *mover)
{
	mover->prev = element->prev;
	element->next = mover->next;
	if (mover->next != NULL)
		mover->next->prev = element;
	mover->next = element;
	element->prev->next = mover;
	element->prev = mover;
}

/**
 * rev_swap_node - swap nodes in list properly
 * @element: the element to compare
 * @mover: pointer moving through list
 * @list: linked list
 */
void rev_swap_node(listint_t *element, listint_t *mover, listint_t **list)
{
	element->prev = mover->prev;
	mover->next = element->next;
	if (mover->prev != NULL)
		mover->prev->next = element;
	mover->prev = element;
	element->next->prev = mover;
	element->next = mover;
	if (element->prev == NULL)
		*list = element;
}

/**
 * check_sorted - checks for a sorted list
 * @list: list to check
 *
 * Return: 1 if sorted 0 otherwise
 */
int check_sorted(listint_t **list)
{
	listint_t *mover;

	mover = *list;
	while (mover->next != NULL)
	{
		if (mover->n <= mover->next->n)
			mover = mover->next;
		else
			return (0);
	}
	return (1);
}
