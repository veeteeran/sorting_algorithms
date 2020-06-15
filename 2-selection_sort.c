#include "sort.h"

/**
 * selection_sort - selection sort algo for array
 * @array: array to sort
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
  size_t a, b, c;
  
  if (size < 2)
    return;
  for (a = 0; a < size; a++)
    {
      c = a;
      for (b = a; b < size; b++)
	{
	  if (array[b] < array[c])
	    {
	      c = b;
	    }
	}
      if (a != c)
	{
	  swap(&array[a], &array[c]);
	  print_array(array, size);
	}
    }
}
