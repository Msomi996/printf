#include "main.h"

/**
 * print_h_x - prints a short decimal in hexadecimal
 * @argts: input string
 * @buff: pointer to buffer
 * @buff_idx: buffer index
 * Return: total characters printed
 */

int print_h_x(va_list argts, char *buff, unsigned int buff_idx)
{
	short int i_input, idx, check, count, is_first;
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

	bnry = malloc(sizeof(char) * (16 + 1));
	bnry = print_binary(bnry, i_input, check, 16);
	hexadecimal = malloc(sizeof(char) * (4 + 1));
	hexadecimal = print_x_arr(bnry, hexadecimal, 0, 4);
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

/**
 * print_h_i - prints a short integer
 * @argts: input string
 * @buff: pointer to buffer
 * @buff_idx: buffer index
 * Return: total characters printed.
 */

int print_h_i(va_list argts, char *buff, unsigned int buff_idx)
{
	short int i_input;
	unsigned short int input_int, curr, idx, mult, check;

	i_input = va_arg(argts, int);
	check = 0;
	if (i_input < 0)
	{
		input_int = i_input * -1;
		buff_idx = cc_buffer(buff, '-', buff_idx);
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
		buff_idx = cc_buffer(buff, ((input_int / mult) % 10) + '0', buff_idx);
	}
	return (idx + check);
}

/**
 * print_h_o - converts long decimal to octal
 * @argts: input value
 * @buff: pointer to buffer
 * @buff_idx: buffer index
 * Return: total characters printed.
 */

int print_h_o(va_list argts, char *buff, unsigned int buff_idx)
{
	short int i_input, idx, check, count, is_first;
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

	bnry = malloc(sizeof(char) * (16 + 1));
	bnry = print_binary(bnry, i_input, check, 16);
	octal = malloc(sizeof(char) * (6 + 1));
	octal = print_s_oct_arr(bnry, octal);
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
 * print_h_u - prints a short unsigned integer
 * @argts: number to print
 * @buff: pointer to buffer
 * @buff_idx: buffer index
 * Return: total characters printed.
 */

int print_h_u(va_list argts, char *buff, unsigned int buff_idx)
{
	unsigned short int input_int, curr, idx, mult;

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
		buff_idx = cc_buffer(buff, ((input_int / mult) % 10) + '0', buff_idx);
	}
	return (idx);
}

/**
 * print_h_X - prints a short decimal in hexadecimal
 * @argts: The character to print
 * @buff: pointer to buffer
 * @buff_idx: buffer index
 * Return: total characters printed
 */

int print_h_X(va_list argts, char *buff, unsigned int buff_idx)
{
	short int i_input, idx, check, count, is_first;
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

	bnry = malloc(sizeof(char) * (16 + 1));
	bnry = print_binary(bnry, i_input, check, 16);
	hexadecimal = malloc(sizeof(char) * (4 + 1));
	hexadecimal = print_x_arr(bnry, hexadecimal, 1, 4);

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



