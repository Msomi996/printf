#include "main.h"
#include <stdio.h>

/**
 * print_add - prints the address input
 * @argts: input address.
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: total characters printed.
 */
int print_add(va_list argts, char *buff, unsigned int buffer_idx)
{
	void *add;
	long int i_input;
	int idx, count, is_first, check;
	char *hexadecimal, *bnry;
	char nill[] = "(nil)";

	add = (va_arg(argts, void *));
	if (add == NULL)
	{
		for (idx = 0; nill[idx]; idx++)
			buffer_idx = concat_buffer(buff, nill[idx], buffer_idx);
		return (5);
	}
	i_input = (intptr_t)add;
	check = 0;
	if (i_input < 0)
	{
		i_input = (i_input * -1) - 1;
		check = 1;
	}
	bnry = malloc(sizeof(char) * (64 + 1));
	bnry = print_binary(bnry, i_input, check, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = print_x_arr(bnry, hexadecimal, 0, 16);
	buffer_idx = concat_buffer(buff, '0', buffer_idx);
	buffer_idx = concat_buffer(buff, 'x', buffer_idx);
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
	return (count + 2);
}

/**
 * print_space_i - prints int begining with space
 * @argts: input string
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: total characters printed
 */
int print_space_i(va_list argts, char *buff, unsigned int buffer_idx)
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
		buffer_idx = concat_buffer(buff, ' ', buffer_idx);
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

/**
 * print_S - prints a string and values of
 * non-printed chars
 * @argts: input string
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: total characters printed
 */
int print_S(va_list argts, char *buff, unsigned int buffer_idx)
{
	unsigned char *str;
	char *hexadecimal, *bnry;
	unsigned int idx, total, count;

	str = va_arg(argts, unsigned char *);
	bnry = malloc(sizeof(char) * (32 + 1));
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	for (total = idx = 0; str[idx]; idx++)
	{
		if (str[idx] < 32 || str[idx] >= 127)
		{
			buffer_idx = concat_buffer(buff, '\\', buffer_idx);
			buffer_idx = concat_buffer(buff, 'x', buffer_idx);
			count = str[idx];
			bnry = print_binary(bnry, count, 0, 32);
			hexadecimal = print_x_arr(bnry, hexadecimal, 1, 8);
			buffer_idx = concat_buffer(buff, hexadecimal[6], buffer_idx);
			buffer_idx = concat_buffer(buff, hexadecimal[7], buffer_idx);
			total += 3;
		}
		else
			buffer_idx = concat_buffer(buff, str[idx], buffer_idx);
	}
	free(bnry);
	free(hexadecimal);
	return (idx + total);
}

