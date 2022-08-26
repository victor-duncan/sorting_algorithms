#include "sort.h"
#define UP 0
#define DOWN 1

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The length of the array.
 * @initial: The initialing index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @direction: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t initial, size_t seq,
		char direction)
{
	size_t i, range = seq / 2;

	if (seq > 1)
	{
		for (i = initial; i < initial + range; i++)
		{
			if ((direction == UP && array[i] > array[i + range]) ||
			    (direction == DOWN && array[i] < array[i + range]))
				swap_ints(array + i, array + i + range);
		}
		bitonic_merge(array, size, initial, range, direction);
		bitonic_merge(array, size, initial + range, range, direction);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The length of the array.
 * @initial: The initialing index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @direction: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t initial, size_t seq,
		char direction)
{
	size_t child_seq = seq / 2;
	char *str = (direction == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + initial, seq);

		bitonic_seq(array, size, initial, child_seq, UP);
		bitonic_seq(array, size, initial + child_seq, child_seq, DOWN);
		bitonic_merge(array, size, initial, seq, direction);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + initial, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The length of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
