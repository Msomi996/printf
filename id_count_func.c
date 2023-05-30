#include "main.h"
/**
 * id_count_func - returns specifier count
 * @s: argument specifier
 * @index: index of specifer
 * Return: specifier count
 */
int id_count_func(const char *s, int index)
{
	conversions_t conv[] = {
		{"c", print_c}, {"s", print_s}, {"i", print_i},
		{"d", print_i},	{"b", print_b}, {"u", print_u},
		{"o", print_o}, {"x", print_x},	{"X", print_X},
		{"S", print_S},	{"#x", print_num_x}, {"#X", print_num_X},
		{"#i", print_i}, {"#d", print_i}, {"#u", print_u},
		{"+i", print_plus_i}, {"+d", print_plus_i}, {"+u", print_u},
		{"+o", print_o}, {"+x", print_x}, {"+X", print_X},
		{" i", print_space_i}, {" d", print_space_i}, {" u", print_u},
		{" o", print_o}, {" x", print_x}, {" X", print_X},
		{"R", print_rot}, {"r", print_rev}, {"%", print_char},
		{"l", print_char}, {"h", print_char}, {" +i", print_plus_i},
		{" +d", print_plus_i}, {"+ i", print_plus_i},
		{"+ d", print_plus_i}, {"p", print_add}, {"li", print_l_i},
		{"ld", print_l_i}, {"lu", print_l_u}, {"lo", print_l_o},
		{"lx", print_l_x}, {"lX", print_l_X}, {"hi", print_h_i},
		{"hd", print_h_i}, {"hu", print_h_u}, {"ho", print_h_o},
		{"hx", print_h_x}, {"hX", print_h_X}, {"#o", print_num_o},
		{" %", print_char}, {NULL, NULL},
	};
	int idx = 0, idy = 0, first_idx;

	first_idx = index;
	while (conv[idx].spec)
	{
		if (s[index] == conv[idx].spec[idy])
		{
			if (conv[idx].spec[idy + 1] != '\0')
				index++, idy++;
			else
				break;
		}
		else
		{
			idy = 0;
			idx++;
			index = first_idx;
		}
	}
	return (idy);
}

