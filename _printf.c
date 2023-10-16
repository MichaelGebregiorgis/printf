#include "main.h"
#include <stdarg.h>
#include <stdio.h>

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
	unsigned int count_char = 0;
	va_list lst_args;

	va_start(lst_args, format);

	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format += 1;
			if (*format == 'c')
				_putchar(va_arg(lst_args, int));
				count_char++;
			else if (*format == 's')
			{
				const char *str = va_arg(lst_args, const char *);

				while (*str)
					_putchar(*str);
					str++;
					count_char++;
			}
			else if (*format == '%')
				_putchar('%');
				count_char++;
			else
				_putchar('%');
				_putchar(*format);
				count_char += 2;
		}
		else
		{
			_putchar(*format);
			count_char += 1;
		}
	}

	va_end(lst_args);
	return (count_char);
}
