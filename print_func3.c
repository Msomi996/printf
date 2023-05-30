#include "main.h"
#include <stdio.h>
/**
 * print_char - prints character
 * @c: input char
 * @buff: pointer to buffer
 * @idx: buffer index
 * Return: 1.
 */
int print_char(va_list c __attribute__((unused)), char *buff, unsigned int idx)
{
	concat_buffer(buff, '%', idx);

	return (1);
}


/**
 * print_rev - writes the str in reverse
 * @argts: input string
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: total characters printed.
 */
int print_rev(va_list argts, char *buff, unsigned int buffer_idx)
{
	char *str;
	unsigned int idx;
	int idy = 0;
	char nill[] = "(llun)";

	str = va_arg(argts, char *);
	if (str == NULL)
	{
		for (idx = 0; nill[idx]; idx++)
			buffer_idx = concat_buffer(buff, nill[idx], buffer_idx);
		return (6);
	}
	for (idx = 0; str[idx]; idx++)
		;
	idy = idx - 1;
	for (; idy >= 0; idy--)
	{
		buffer_idx = concat_buffer(buff, str[idy], buffer_idx);
	}
	return (idx);
}


/**
 * print_rot - writes the str in ROT13
 * @argts: input string
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: total characters printed.
 */

int print_rot(va_list argts, char *buff, unsigned int buffer_idx)
{
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	unsigned int idx, idy, idz;
	char *str;
	char nill[] = "(null)";

	str = va_arg(argts, char *);
	if (str == NULL)
	{
		for (idx = 0; nill[idx]; idx++)
			buffer_idx = concat_buffer(buff, nill[idx], buffer_idx);
		return (6);
	}
	for (idx = 0; str[idx]; idx++)
	{
		for (idz = idy = 0; alph[idy]; idy++)
		{
			if (str[idx] == alph[idy])
			{
				idz = 1;
				buffer_idx = concat_buffer(buff, rot13[idy], buffer_idx);
				break;
			}
		}
		if (idz == 0)
			buffer_idx = concat_buffer(buff, str[idx], buffer_idx);
	}
	return (idx);
}

/**
 * print_X - prints a decimal in hexadecimal
 * @argts: The character to print
 * @buff: pointer to buffer
 * @buffer_idx: buffer index
 * Return: total characters printed
 */
int print_X(va_list argts, char *buff, unsigned int buffer_idx)
{
	int i_input, idx, check, count, is_first;
	char *hexadecimal, *bnry;

	i_input = va_arg(argts, int);
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
	bnry = malloc(sizeof(char) * (32 + 1));
	bnry = print_binary(bnry, i_input, check, 32);
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = print_x_arr(bnry, hexadecimal, 1, 8);
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

