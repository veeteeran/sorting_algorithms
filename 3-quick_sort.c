#include "sort.h"

/**
 * quick_sort - sorts an array of integers using Quick sort
 * @array: array to sort
 * @size: size of array
 */
/*void quick_sort(int *array, size_t size)
{
	
}
*/
/**
 * partition - implementation of Lomuto partition scheme
 * @array: array to partition
 * @size: size of array
 */
void partition(int *array, size_t size)
{
	size_t pivot = size - 1;
	size_t low = 0;
	size_t high = size - 2;
	int flag = 0;

	while (low < high)
	{
		while (array[low] < array[pivot] && low < size)
			low++;

		while (array[high] > array[pivot])
		{
			high--;
			if (high == 0)
				swap(&array[pivot], &array[high]);
				flag = 1;
			continue;
		}
		if (low < high)
			swap(&array[low], &array[high]);
		
	}
	if (flag == 0)
		swap(&array[pivot], &array[low]);
	else
		swap(&array[pivot], &array[high]);
}
