#include "main.h"

/**
 * print_b - converts decimal to binary
 * @argts: input value
 * @buff: pointer to buffer
 * @buff_idx: buffer index
 * Return: total characters printed.
 */
int print_b(va_list argts, char *buff, unsigned int buff_idx)
{
	int i_input, count, idx, first_one, check;
	char *bnry;

	i_input = va_arg(argts, int);
	check = 0;
	if (i_input == 0)
	{
		buff_idx = cc_buffer(buff, '0', buff_idx);
		return (1);
	}
	if (i_input < 0)
	{
		i_input = (i_input * -1) - 1;
		check = 1;
	}
	bnry = malloc(sizeof(char) * (32 + 1));
	bnry = print_binary(bnry, i_input, check, 32);
	first_one = 0;
	for (count = idx = 0; bnry[idx]; idx++)
	{
		if (first_one == 0 && bnry[idx] == '1')
			first_one = 1;
		if (first_one == 1)
		{
			buff_idx = cc_buffer(buff, bnry[idx], buff_idx);
			count++;
		}
	}
	free(bnry);
	return (count);
}

/**
 * print_o - converts decimal to octal
 * @argts: input number
 * @buff: pointer to buffer
 * @buff_idx: buffer index
 * Return: total characters printed.
 */
int print_o(va_list argts, char *buff, unsigned int buff_idx)
{
	int i_input, idx, check, count, is_first;
	char *octal, *bnry;

	i_input = va_arg(argts, int);
	check = 0;
	if (i_input == 0)
	{
		buff_idx = cc_buffer(buff, '0', buff_idx);
		return (1);
	}
	if (i_input < 0)
	{
		i_input = (i_input * -1) - 1;
		check = 1;
	}
	bnry = malloc(sizeof(char) * (32 + 1));
	bnry = print_binary(bnry, i_input, check, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = print_o_arr(bnry, octal);
	for (is_first = idx = count = 0; octal[idx]; idx++)
	{
		if (octal[idx] != '0' && is_first == 0)
			is_first = 1;
		if (is_first)
		{
			buff_idx = cc_buffer(buff, octal[idx], buff_idx);
			count++;
		}
	}
	free(bnry);
	free(octal);
	return (count);
}

/**
 * print_x - converts decimal to hexadecimal
 * @argts: input string
 * @buff: pointer to buffer
 * @buff_idx: buffer index
 * Return: total characters printed
 */
int print_x(va_list argts, char *buff, unsigned int buff_idx)
{
	int i_input, idx, check, count, is_first;
	char *hexadecimal, *bnry;

	i_input = va_arg(argts, int);
	check = 0;
	if (i_input == 0)
	{
		buff_idx = cc_buffer(buff, '0', buff_idx);
		return (1);
	}
	if (i_input < 0)
	{
		i_input = (i_input * -1) - 1;
		check = 1;
	}
	bnry = malloc(sizeof(char) * (32 + 1));
	bnry = print_binary(bnry, i_input, check, 32);
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = print_x_arr(bnry, hexadecimal, 0, 8);
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
	return (count);
}

