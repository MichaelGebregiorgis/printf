#include <stdio.h>
#include <stdarg.h>
#include <limits.h>


/**
 *
 *
 *
 */

void print_int(int num)
{
	if (num == 0)
	{
		_putchar('0');
		return;
	}
	else if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	int count = 0;
	int rev = 0;
	while (num > 0)
	{
		rev = rev * 10 + num % 10;
		num /= 10;
		count++;
	}
	while (rev > 0)
	{
		_putchar('0' + rev % 10);
		rev /= 10;
	}
}

int _printf(const char* format, ...)
{
	va_list lst_args;
	va_start(lst_args, format);

	int count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'd' || *format == 'i')
			{
				int num =
