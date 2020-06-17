#include "sort.h"
int is_sorted(int *array, size_t size);
int find_max(int *array, size_t size);
/**
 * counting_sort - sorts array using counting sort
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int i, j, max = 0;
	int *count_array, *new_array;

	if (array == NULL || size < 2 || is_sorted(array, size))
		return;

	max = find_max(array, size);

	count_array = malloc(sizeof(int) * (max + 1));
	if (count_array == NULL)
		return;

	for (i = 0; i < max; i++)
		count_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;

	for (i = 1; i <= max; i++)
		count_array[i] = count_array[i] + count_array[i - 1];

	print_array(count_array, (size_t)max + 1);

	new_array = malloc(sizeof(int) * size);
	if (new_array == NULL)
		return;

	for (j = size - 1; j >= 0; j--)
	{
		new_array[count_array[array[j]] - 1] = array[j];
		count_array[j]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = new_array[i];

	free(count_array);
	free(new_array);
}

/**
 * is_sorted - check for sorted array
 * @array: array to sort
 * @size: size of array
 *
 * Return: 1 is sorted, 0 otherwise
 */
int is_sorted(int *array, size_t size)
{
	int i;

	for (i = 0; i < (int)size - 1; i++)
	{
		if (array[i] > array[i + 1])
			return (0);
	}
	return (1);
}

/**
 * find_max - find max int in array
 * @array: array to sort
 * @size: size of array
 *
 * Return: max int in array
 */
int find_max(int *array, size_t size)
{
	int i, max = array[0];

	for (i = 0; i < (int)size - 1; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
