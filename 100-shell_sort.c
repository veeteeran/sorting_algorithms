#include "sort.h"

/**
 * shell_sort - sort array with shell short algo
 * @array: array to be sorted
 * @size: size of array
 */

void shell_sort(int *array, size_t size) 
{
  size_t knuth, c, c2;
  int temp;
    
  knuth = 1;
  while (knuth < size)
    knuth = (knuth * 3) + 1;
  knuth = (knuth - 1) / 3;
  while (knuth > 0)
    {
      for (c = knuth; c < size; c++) 
	{
	  temp = array[c];
	  for (c2 = c; c2 >= knuth && array[c2 - knuth] > temp; c2 -= knuth) 
	    {
	      array[c2] = array[c2 - knuth];
	    }
	  array[c2] = temp;
	}
      knuth = (knuth - 1) / 3;
      print_array(array, size);
	
    }
}
