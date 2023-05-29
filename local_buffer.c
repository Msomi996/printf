#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: the format used by the string to print arguments
 * @x: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *x)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int q, curr_x;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_x = *x + 1; format[curr_x] != '\0'; curr_x++)
	{
		for (q = 0; FLAGS_CH[q] != '\0'; q++)
			if (format[curr_x] == FLAGS_CH[q])
			{
				flags |= FLAGS_ARR[q];
				break;
			}

		if (FLAGS_CH[q] == 0)
			break;
	}

	*x = curr_x - 1;

	return (flags);
}
