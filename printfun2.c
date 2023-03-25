#include "main.h"
/**
 * _puto - writes octal value equivalent to given decimal to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _puto(va_list li)
{
	int c, o[100];
	unsigned long int n;

	n = (va_arg(li, unsigned long int));

	for (c = 0; n != 0 ; c++)
	{
		o[c] = n % 8;
		n /= 8;
	}
	for (c -= 1; c >= 0; c--)
		_putchar(o[c] + '0');

	return (0);
}
/**
 * _putx - writes Hex equivalent to given decimal to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _putx(va_list li)
{
	int c;
	char h[100];
	unsigned long int n;

	n = (va_arg(li, unsigned long int));

	for (c = 0; n != 0 ; c++)
	{
		if (n % 16 < 10)
			h[c] = (n % 16) + 48;
		else
			h[c] = ((n % 16) + 87);
		n /= 16;
	}
	for (c -= 1; c >= 0; c--)
		_putchar(h[c]);
	return (0);
}
/**
 * _putX - writes Hex(capital) equivalent to given decimal to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _putX(va_list li)
{
	int c;
	char h[100];
	unsigned long int n;

	n = (va_arg(li, unsigned long int));

	for (c = 0; n != 0 ; c++)
	{
		if (n % 16 < 10)
			h[c] = (n % 16) + 48;
		else
			h[c] = (n % 16) + 55;
		n /= 16;
	}
	for (c -= 1; c >= 0; c--)
		_putchar(h[c]);
	return (0);
}
/**
 * _putp - writes address to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _putp(va_list li)
{
	int c;
	char p[100];

	unsigned long int n;

	n = (va_arg(li, unsigned long int));

	for (c = 0; n != 0 ; c++)
	{
		if (n % 16 < 10)
			p[c] = ((n % 16) + 48);
		else
			p[c] = ((n % 16) + 87);
		n /= 16;
	}
	_putchar('0');
	_putchar('x');
	for (c -= 1; c >= 0; c--)
		_putchar(p[c]);
	return (0);
}
/**
 * print_n - writes digits to stdout
 * @in: integer
 *
 * Return: void
 */
void print_n(int in)
{
	int m = in;

	if (in < 0)
	{
		_putchar('-');
		m = -m;
	}

	if (m / 10)
	{
		print_n(m / 10);
	}
	_putchar((m % 10) + '0');
}
