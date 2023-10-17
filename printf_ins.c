#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "main.h"

/**
 * print_int - prints int
 * @num: Data type
 * Return: num values
 */

void print_int(int num)
{
	int count = 0;
	int rev = 0;
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
