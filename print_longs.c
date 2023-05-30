#include "main.h"
/**
 * print_l_x - converts long decimal to hexadecimal
 * @argts: input value
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: total characters printed
 */

int print_l_x(va_list argts, char *buff, unsigned int buffer_idx)
{
	long int i_input, idx, check, count, is_first;
	char *hexadecimal, *bnry;

	i_input = va_arg(argts, long int);
	check = 0;
	if (i_input == 0)
	{
		buffer_idx = concat_buffer(buff, '0', buffer_idx);
		return (1);
	}
	if (i_input < 0)
	{
		i_input = (i_input * -1) - 1;
		check = 1;
	}

	bnry = malloc(sizeof(char) * (64 + 1));
	bnry = print_binary(bnry, i_input, check, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = print_x_arr(bnry, hexadecimal, 0, 16);
	for (is_first = idx = count = 0; hexadecimal[idx]; idx++)
	{
		if (hexadecimal[idx] != '0' && is_first == 0)
			is_first = 1;
		if (is_first)
		{
			buffer_idx = concat_buffer(buff, hexadecimal[idx], buffer_idx);
			count++;
		}
	}
	free(bnry);
	free(hexadecimal);
	return (count);
}

/**
 * print_l_i - prints a long integer
 * @argts: input value
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: total characters printed.
 */
int print_l_i(va_list argts, char *buff, unsigned int buffer_idx)
{
	long int i_input;
	unsigned long int input_int, curr, idx, mult, check;

	i_input = va_arg(argts, long int);
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
 * print_l_o - converts long decimal to octal
 * @argts: input value
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: total characters printed.
 */
int print_l_o(va_list argts, char *buff, unsigned int buffer_idx)
{
	long int i_input, idx, check, count, is_first;
	char *octal, *bnry;

	i_input = va_arg(argts, long int);
	check = 0;
	if (i_input == 0)
	{
		buffer_idx = concat_buffer(buff, '0', buffer_idx);
		return (1);
	}
	if (i_input < 0)
	{
		i_input = (i_input * -1) - 1;
		check = 1;
	}

	bnry = malloc(sizeof(char) * (64 + 1));
	bnry = print_binary(bnry, i_input, check, 64);
	octal = malloc(sizeof(char) * (22 + 1));
	octal = print_l_oct_arr(bnry, octal);
	for (is_first = idx = count = 0; octal[idx]; idx++)
	{
		if (octal[idx] != '0' && is_first == 0)
			is_first = 1;
		if (is_first)
		{
			buffer_idx = concat_buffer(buff, octal[idx], buffer_idx);
			count++;
		}
	}
	free(bnry);
	free(octal);
	return (count);
}

/**
 * print_l_u - prints long unsigned integer
 * @argts: number to print
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: total characters printed.
 */
int print_l_u(va_list argts, char *buff, unsigned int buffer_idx)
{
	unsigned long int input_int, curr, idx, mult;

	input_int = va_arg(argts, unsigned long int);
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
 * print_l_X - converts a long decimal to hex
 * @argts: input value
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: total characters printed
 */
int print_l_X(va_list argts, char *buff, unsigned int buffer_idx)
{
	long int i_input, idx, check, count, is_first;
	char *hexadecimal, *bnry;

	i_input = va_arg(argts, long int);
	check = 0;
	if (i_input == 0)
	{
		buffer_idx = concat_buffer(buff, '0', buffer_idx);
		return (1);
	}
	if (i_input < 0)
	{
		i_input = (i_input * -1) - 1;
		check = 1;
	}

	bnry = malloc(sizeof(char) * (64 + 1));
	bnry = print_binary(bnry, i_input, check, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = print_x_arr(bnry, hexadecimal, 1, 16);
	for (is_first = idx = count = 0; hexadecimal[idx]; idx++)
	{
		if (hexadecimal[idx] != '0' && is_first == 0)
			is_first = 1;
		if (is_first)
		{
			buffer_idx = concat_buffer(buff, hexadecimal[idx], buffer_idx);
			count++;
		}
	}
	free(bnry);
	free(hexadecimal);
	return (count);
}

