#include "main.h"

/**
 * _puthx - writes Hex equivalent to given decimal to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _puthx(va_list li)
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
	if (c > 4)
	{
		c = 4;
		m = c;
	}
	for (c -= 1; c >= 0; c--)
		_putchar(h[c]);
	return (m);
}
/**
 * _putlx - writes Hex equivalent to given decimal to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _putlx(va_list li)
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
	if (c > 16)
	{
		c = 16;
		m = c;
	}

	for (c -= 1; c >= 0; c--)
		_putchar(h[c]);
	return (m);
}
/**
 * _puthX - writes Hex(capital) equivalent to given decimal to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _puthX(va_list li)
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
	if (c > 8)
	{
		c = 8;
		m = c;
	}
	for (c -= 1; c >= 0; c--)
		_putchar(h[c]);
	return (m);
}
/**
 * _putlX - writes Hex(capital) equivalent to given decimal to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _putlX(va_list li)
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
	if (c > 16)
	{
		c = 16;
		m = c;
	}

	for (c -= 1; c >= 0; c--)
		_putchar(h[c]);
	return (m);
}
/**
 * _putlo - print long octal int
 * @li: variadic list
 *
 * Return: count
 */
int _putlo(va_list li)
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
	if (o[m - 1] == 0)
	{
		c -= 1;
		m -= 1;
	}
	for (c -= 1; c >= 0; c--)
		_putchar(o[c] + '0');
	return (m);
}
