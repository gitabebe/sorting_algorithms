#include "sort.h"

/**
 * shell_sort - sorts the array using the shell sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
*/
void shell_sort(int *array, size_t size)
{
	size_t i, j, k, num = 1;
	int temp;

	if (!array || !size)
		return;

	while (num < size)
		num = num * 3 + 1;
	num = (num - 1) / 3;

	for (k = num; k; k = (k - 1) / 3)
	{
		for (i = k; i < size; i++)
		{
			temp = array[i];
			for (j = i; j > k - 1 && array[j - k] > temp; j -= k)
				array[j] = array[j - k];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
