#include "sort.h"

/**
 * quick_sort - sorts an array of integers using Quick sort
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	my_sort(array, size, 0, (int)(size - 1));	
}

/**
 * partition - implementation of Lomuto partition scheme
 * @array: array to partition
 * @low: start of sub-array
 * @high: end of sub-array
 *
 * Return: index of pivot
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
        int i = low - 1;
        int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if(i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
/*			swap(&array[i], &array[j]);
*/		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * my_sort - the actual sort
 * @array: array to sort
 * @low: start of sub-array
 * @high: end of sub-array
 */
void my_sort(int *array, size_t size, int low, int high)
{
	/*Return of partition*/
	int pivot;

	if (low < high)
	{
		pivot = partition(array, size, low, high);
		my_sort(array, size, low, pivot - 1);
		my_sort(array, size, pivot + 1, high);
	}
}
