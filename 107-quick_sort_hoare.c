#include "sort.h"
/**
*swap_ints - two position of two ints in an array
*@array: array
*@int1: array element
*@int2: array element
*/
void swap_ints(int *array, ssize_t int1, ssize_t int2)
{
	int tmp;

	tmp = array[int1];
	array[int1] = array[int2];
	array[int2] = tmp;
}
/**
 *hoare_partition - hoare partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@end: last array element
 *@size: length of array
 *Return: return the position of the end element sorted
 */
int hoare_partition(int *array, int first, int end, int size)
{
	int i = first - 1, j = end + 1;
	int pivot = array[end];

	while (1)
	{

		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (i);
		swap_ints(array, i, j);
		print_array(array, size);
	}
}
/**
 *quick_sort2 - quicksort algorithm implementation
 *@array: array
 *@first: first array element
 *@end: last array element
 *@size: array length
 */
void quick_sort2(int *array, ssize_t first, ssize_t end, int size)
{
	ssize_t position = 0;

	if (first < end)
	{
		position = hoare_partition(array, first, end, size);
		quick_sort2(array, first, position - 1, size);
		quick_sort2(array, position, end, size);
	}
}
/**
 *quick_sort_hoare - checks if array can be sorted
 *@array: array
 *@size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort2(array, 0, size - 1, size);
}
