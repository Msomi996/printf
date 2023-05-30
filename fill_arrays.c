#include "main.h"

/**
 * print_binary - prints decimal in binary
 * @bnry: pointer to binary
 * @input_int: input number
 * @check: checks negative input
 * @bnry_size: binary sizs
 * Return: total characters printed.
 */
char *print_binary(char *bnry, long int input_int, int check, int bnry_size)
{
	int idx;

	for (idx = 0; idx < bnry_size; idx++)
		bnry[idx] = '0';
	bnry[bnry_size] = '\0';
	for (idx = bnry_size - 1; input_int > 1; idx--)
	{
		if (input_int == 2)
			bnry[idx] = '0';
		else
			bnry[idx] = (input_int % 2) + '0';
		input_int /= 2;
	}
	if (input_int != 0)
		bnry[idx] = '1';
	if (check)
	{
		for (idx = 0; bnry[idx]; idx++)
			if (bnry[idx] == '0')
				bnry[idx] = '1';
			else
				bnry[idx] = '0';
	}
	return (bnry);
}

/**
 * print_x_arr - converts decimal to hex
 * @bnry: binary array.
 * @hex: hex array.
 * @is_uppercase: check capital letter of hex character
 * @hex_size: size of hex
 * Return: binary array.
 */
char *print_x_arr(char *bnry, char *hex, int is_uppercase, int hex_size)
{
	int count, idx, idy, alph_num;

	hex[hex_size] = '\0';
	if (is_uppercase)
		alph_num = 55;
	else
		alph_num = 87;
	for (idx = (hex_size * 4) - 1; idx >= 0; idx--)
	{
		for (count = 0, idy = 1; idy <= 8; idy *= 2, idx--)
			count = ((bnry[idx] - '0') * idy) + count;
		idx++;
		if (count < 10)
			hex[idx / 4] = count + 48;
		else
			hex[idx / 4] = count + alph_num;
	}
	return (hex);
}

/**
 * print_l_oct_arr - calculates a long octal number
 * @bnry: binary array.
 * @oct: array where is stored the octal.
 * Return: binary array.
 */

char *print_l_oct_arr(char *bnry, char *oct)
{
	int count, idx, idy, oct_idx, limit;

	oct[22] = '\0';
	for (idx = 63, oct_idx = 21; idx >= 0; idx--, oct_idx--)
	{
		if (idx > 0)
			limit = 4;
		else
			limit = 1;
		for (count = 0, idy = 1; idy <= limit; idy *= 2, idx--)
			count = ((bnry[idx] - '0') * idy) + count;
		idx++;
		oct[oct_idx] = count + '0';
	}
	return (oct);
}

/**
 * print_o_arr - converts binary to oct
 * @bnry: binary array.
 * @oct: octal array.
 * Return: binary array.
 */
char *print_o_arr(char *bnry, char *oct)
{
	int count, idx, idy, oct_idx, limit;

	oct[11] = '\0';
	for (idx = 31, oct_idx = 10; idx >= 0; idx--, oct_idx--)
	{
		if (idx > 1)
			limit = 4;
		else
			limit = 2;
		for (count = 0, idy = 1; idy <= limit; idy *= 2, idx--)
			count = ((bnry[idx] - '0') * idy) + count;
		idx++;
		oct[oct_idx] = count + '0';
	}
	return (oct);
}

/**
 * print_s_oct_arr - calculates a short octal number
 * @bnry: binary array.
 * @oct: array where is stored the octal.
 * Return: binary array.
 */
char *print_s_oct_arr(char *bnry, char *oct)
{
	int count, idx, idy, oct_idx, limit;

	oct[6] = '\0';
	for (idx = 15, oct_idx = 5; idx >= 0; idx--, oct_idx--)
	{
		if (idx > 0)
			limit = 4;
		else
			limit = 1;
		for (count = 0, idy = 1; idy <= limit; idy *= 2, idx--)
			count = ((bnry[idx] - '0') * idy) + count;
		idx++;
		oct[oct_idx] = count + '0';
	}
	return (oct);
}

