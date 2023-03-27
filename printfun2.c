#include "main.h"
/**
 * _puto - writes octal value equivalent to given decimal to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _puto(va_list li)
{
	int c, o[100], m;
	unsigned long int n;

	n = (va_arg(li, unsigned long int));

	for (c = 0; n != 0 ; c++)
	{
		o[c] = n % 8;
		n /= 8;
	}
	m = c;
	for (c -= 1; c >= 0; c--)
		_putchar(o[c] + '0');

	return (m);
}
/**
 * _putx - writes Hex equivalent to given decimal to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _putx(va_list li)
{
	int c, m;
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
	m = c;
	for (c -= 1; c >= 0; c--)
		_putchar(h[c]);
	return (m);
}
/**
 * _putX - writes Hex(capital) equivalent to given decimal to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _putX(va_list li)
{
	int c, m;
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
	m = c;
	for (c -= 1; c >= 0; c--)
		_putchar(h[c]);
	return (m);
}
/**
 * _putp - writes address to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _putp(va_list li)
{
	int c, m = 2;
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
	m += c;
	for (c -= 1; c >= 0; c--)
		_putchar(p[c]);
	return (m);
}
/**
 * print_n - writes digits to stdout
 * @in: integer
 *
 * Return: void
 */
int print_n(int in)
{
	int c = 0, i = 1, o;
	unsigned int m = in;

	if (in < 0)
	{
		_putchar('-');
		m = m * -1;
		c++;
	}
	while ((m / i) > 9)
		i *= 10;
	while (i > 0)
	{
		o = (m / i) % 10;
		c++;
		_putchar(o + '0');
		i /= 10;
	}
	return (c);
}
