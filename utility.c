#include "sort.h"

/**
 * swap - swaps two values
 * @a: first value to swap
 * @b: second value to swap
 *
 * Return: nothing
 */
void swap(int *a, int *b)
{
int temp = *a;

*a = *b;
*b = temp;
}
