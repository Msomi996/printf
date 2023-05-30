#include "main.h"
#include <stdio.h>

/**
 * print_add - prints the address input
 * @argts: input address.
 * @buff: pointer to buffer
 * @buff_idx: buffer index
 * Return: total characters printed.
 */
int print_add(va_list argts, char *buff, unsigned int buff_idx)
{
	void *add;
	long int i_input;
	int idx, count, is_first, check;
	char *hexadecimal, *bnry;
	char empty[] = "(nil)";

	add = (va_arg(argts, void *));
	if (add == NULL)
	{
		for (idx = 0; empty[idx]; idx++)
			buff_idx = cc_buffer(buff, empty[idx], buff_idx);
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
	buff_idx = cc_buffer(buff, '0', buff_idx);
	buff_idx = cc_buffer(buff, 'x', buff_idx);
	for (is_first = idx = count = 0; hexadecimal[idx]; idx++)
	{
		if (hexadecimal[idx] != '0' && is_first == 0)
			is_first = 1;
		if (is_first)
		{
			buff_idx = cc_buffer(buff, hexadecimal[idx], buff_idx);
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
 * @buff_idx: buffer index
 * Return: total characters printed
 */
int print_space_i(va_list argts, char *buff, unsigned int buff_idx)
{
	int i_input;
	unsigned int input_int, curr, idx, mult;

	i_input = va_arg(argts, int);
	if (i_input < 0)
	{
		input_int = i_input * -1;
		buff_idx = cc_buffer(buff, '-', buff_idx);
	}
	else
	{
		input_int = i_input;
		buff_idx = cc_buffer(buff, ' ', buff_idx);
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
		buff_idx = cc_buffer(buff, ((input_int / mult) % 10) + '0', buff_idx);
	}
	return (idx + 1);
}

/**
 * print_S - prints a string and values of
 * non-printed chars
 * @argts: input string
 * @buff: pointer to buffer
 * @buff_idx: buffer index
 * Return: total characters printed
 */
int print_S(va_list argts, char *buff, unsigned int buff_idx)
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
			buff_idx = cc_buffer(buff, '\\', buff_idx);
			buff_idx = cc_buffer(buff, 'x', buff_idx);
			count = str[idx];
			bnry = print_binary(bnry, count, 0, 32);
			hexadecimal = print_x_arr(bnry, hexadecimal, 1, 8);
			buff_idx = cc_buffer(buff, hexadecimal[6], buff_idx);
			buff_idx = cc_buffer(buff, hexadecimal[7], buff_idx);
			total += 3;
		}
		else
			buff_idx = cc_buffer(buff, str[idx], buff_idx);
	}
	free(bnry);
	free(hexadecimal);
	return (idx + total);
}

