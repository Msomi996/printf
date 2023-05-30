#include "main.h"

/**
 * write_buffer - prints buffer
 * @buff: pointer to buffer
 * @byte_count: number of bytes to print
 * Return: total bytes printed
 */
int write_buffer(char *buff, unsigned int byte_count)
{
	return (write(1, buff, byte_count));
}


/**
 * cc_buffer - concat the buffer
 * @buff: pointer to buffer
 * @c: charcter to concatenate
 * @buff_idx: buffer index
 * Return: buffer index.
 */
unsigned int cc_buffer(char *buff, char c, unsigned int buff_idx)
{
	if (buff_idx == 1024)
	{
		write_buffer(buff, buff_idx);
		buff_idx = 0;
	}
	buff[buff_idx] = c;
	buff_idx++;
	return (buff_idx);
}

/**
 * _printf - formats input and prints to stdout
 * @format: input string.
 * Return: total characters printed.
 */

int _printf(const char *format, ...)
{
	unsigned int idx = 0, length = 0, buff_idx = 0;
	int (*func)(va_list, char *, unsigned int);
	va_list argts;
	char *buffer;

	va_start(argts, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[idx] == '%' && !format[idx + 1]))
		return (-1);
	if (!format[idx])
		return (0);
	for (idx = 0; format && format[idx]; idx++)
	{
		if (format[idx] == '%')
		{
			if (format[idx + 1] == '\0')
			{	write_buffer(buffer, buff_idx), free(buffer), va_end(argts);
				return (-1);
			}
			else
			{	func = get_funcs(format, idx + 1);
				if (func == NULL)
				{
					if (format[idx + 1] == ' ' && !format[idx + 2])
						return (-1);
					cc_buffer(buffer, format[idx], buff_idx), length++, idx--;
				}
				else
				{
					length += func(argts, buffer, buff_idx);
					idx += id_count_func(format, idx + 1);
				}
			} idx++;
		}
		else
			cc_buffer(buffer, format[idx], buff_idx), length++;
		for (buff_idx = length; buff_idx > 1024; buff_idx -= 1024)
			;
	}
	write_buffer(buffer, buff_idx), free(buffer), va_end(argts);
	return (length);
}

