#include "sort.h"

/**
 * bubble_sort - sorting algo for array
 * @array: the array to sort
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
  size_t a, b, c = 0;
  if (size > 1)
    {
      for (a = 0; a < size; a++)
	{
	  for (b = 0; b < (size - 1); b++)
	    {
	      if (array[b] > array[b + 1])
		{
		  swap(&array[b], &array[b + 1]);
		  print_array(array, size);
		  c++;
		}
	    }
	  if (c == 0)
	    break;
	}
    }
}
