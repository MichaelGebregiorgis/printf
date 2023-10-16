#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - produces output according to a format.
 * Need to handle c, s,and % conversion specifiers.
 *
 * @format: Data type
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	unsigned int count_char = 0, inc = 0;
	va_list lst_args;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(lst_args, format);

	while (format[inc] != '\0')
	{
		if (format[inc] == '%')
		{
			inc++;
			if (format[inc] == 'c')
			{
				_putchar(va_arg(lst_args, int));
				count_char++;
			}
			else if (format[inc] == 's')
			{
				const char *str = va_arg(lst_args, const char *);

				while (*str)
				{
					_putchar(*str);
					str++;
					count_char++;
				}
			}
			else if (format[inc] == '%')
			{
				_putchar('%');
				count_char++;
			}
		}
		inc++;
	}
	va_end(lst_args);
	return (count_char);
}
