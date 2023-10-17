#include <stdio.h>
#include <stdarg.h>
#include <limits.h>


/**
 * print_int - prints int
 * @num: Data type
 * Return: num values
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

/**
 * _printf - Handle d and i specifier
 * @format: Datat type
 * Return: number
 */
int _printf(const char *format, ...)
{
	va_list lst_args;

	va_start(lst_args, format);
	int count = 0;

	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(lst_args, int);

				print_int(num);
				count++;
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
	}

	va_end(lst_args);
	return (count);
}
