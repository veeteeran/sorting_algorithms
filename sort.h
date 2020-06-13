#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

/* DATA STRUCTURES */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
  const int n;
  struct listint_s *prev;
  struct listint_s *next;
} listint_t;

/* PROTOTYPES */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void swap(int *a, int *b);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
int partition(int *array, size_t size, int low, int high);
void my_sort(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);




#endif /* SORT_H */
