#include "main.h"

/**
 * get_size - Counts the size to cast the argument
 * @format: the format used by string to print the arguments
 * @x: List of arguments to be returned.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *x)
{
	int curr_x = *x + 1;
	int size = 0;

	if (format[curr_x] == 'l')
		size = S_LONG;
	else if (format[curr_x] == 't')
		size = S_SHORT;

	if (size == 0)
		*x = curr_x - 1;
	else
		*x = curr_x;

	return (size);
}
