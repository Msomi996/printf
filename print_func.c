#include "main.h"
#include <stdio.h>
/**
 * print_c - prints character
 * @argts: input char
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: 1.
 */
int print_c(va_list argts, char *buff, unsigned int buffer_idx)
{
	char c;

	c = va_arg(argts, int);
	concat_buffer(buff, c, buffer_idx);

	return (1);
}


/**
 * print_i - prints an integer
 * @argts: input string
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: total characters printed.
 */
int print_i(va_list argts, char *buff, unsigned int buffer_idx)
{
	int i_input;
	unsigned int input_int, curr, idx, mult, check;

	i_input = va_arg(argts, int);
	check = 0;
	if (i_input < 0)
	{
		input_int = i_input * -1;
		buffer_idx = concat_buffer(buff, '-', buffer_idx);
		check = 1;
	}
	else
	{
		input_int = i_input;
	}

	curr = input_int;
	mult = 1;

	while (curr > 9)
	{
		mult *= 10;
		curr /= 10;
	}

	for (idx = 0; mult > 0; mult /= 10, idx++)
	{
		buffer_idx = concat_buffer(buff, ((input_int / mult) % 10) + '0', buffer_idx);
	}
	return (idx + check);
}


/**
 * print_s - prints string
 * @argts: input string
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: 1.
 */
int print_s(va_list argts, char *buff, unsigned int buffer_idx)
{
	char *str;
	unsigned int idx;
	char nill[] = "(null)";

	str = va_arg(argts, char *);
	if (str == NULL)
	{
		for (idx = 0; nill[idx]; idx++)
			buffer_idx = concat_buffer(buff, nill[idx], buffer_idx);
		return (6);
	}
	for (idx = 0; str[idx]; idx++)
		buffer_idx = concat_buffer(buff, str[idx], buffer_idx);
	return (idx);
}

/**
 * print_u - prints an unsigned int
 * @argts: number to print
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: total characters printed.
 */
int print_u(va_list argts, char *buff, unsigned int buffer_idx)
{
	unsigned int input_int, curr, idx, mult;

	input_int = va_arg(argts, unsigned int);
	curr = input_int;
	mult = 1;
	while (curr > 9)
	{
		mult *= 10;
		curr /= 10;
	}
	for (idx = 0; mult > 0; mult /= 10, idx++)
	{
		buffer_idx = concat_buffer(buff, ((input_int / mult) % 10) + '0', buffer_idx);
	}
	return (idx);
}

/**
 * print_plus_i - prints int with plus in front
 * @argts: input string
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: total characters printed
 */
int print_plus_i(va_list argts, char *buff, unsigned int buffer_idx)
{
	int i_input;
	unsigned int input_int, curr, idx, mult;

	i_input = va_arg(argts, int);
	if (i_input < 0)
	{
		input_int = i_input * -1;
		buffer_idx = concat_buffer(buff, '-', buffer_idx);
	}
	else
	{
		input_int = i_input;
		buffer_idx = concat_buffer(buff, '+', buffer_idx);
	}
	curr = input_int;
	mult = 1;
	while (curr > 9)
	{
		mult *= 10;
		curr /= 10;
	}
	for (idx = 0; mult > 0; mult /= 10, idx++)
	{
		buffer_idx = concat_buffer(buff, ((input_int / mult) % 10) + '0', buffer_idx);
	}
	return (idx + 1);
}

