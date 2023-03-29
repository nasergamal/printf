#include "main.h"
/**
 * _puthi - print short int
 * @li: variadic list
 *
 * Return: count
 */
int _puthi(va_list li)
{

	unsigned short int  m;
	short int in, c = 0, i = 1, o;


	in = va_arg(li, int);
	if (in < 0)
	{
		_putchar('-');
		m = in * -1;
		c++;
	}
	else
		m = in;
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
/**
 * _putli - print long int
 * @li: variadic list
 *
 * Return: count
 */
int _putli(va_list li)
{
	long int in, c = 0;
	unsigned long int m, i = 1, o;

	in = va_arg(li, long int);
	if (in < 0)
	{
		_putchar('-');
		m = in * -1;
		c++;
	}
	else
		m = in;
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
/**
 * _puthu - print short unsigned
 * @li: variadic list
 *
 * Return: count
 */
int _puthu(va_list li)
{
	unsigned short int m, c = 0, i = 1, o;

	m = va_arg(li, unsigned int);
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
/**
 * _putlu - print long unsigned
 * @li: variadic list
 *
 * Return: count
 */
int _putlu(va_list li)
{
	unsigned long int m, c = 0, i = 1, o;

	m = va_arg(li, unsigned long int);
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
/**
 * _putho - print short octal int
 * @li: variadic list
 *
 * Return: count
 */
int _putho(va_list li)
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
	if (!c)
	{
		_putchar('0');
		return (1);
	}
	if (c > 5)
	{
		c = 5;
		m = c;
	}
	if (o[m - 1] == 0)
	{
		c -= 1;
		m -= 1;
	}
	else if (o[m - 1] >= 5)
	{
		_putchar('1');
		m += 1;
	}
	for (c -= 1; c >= 0; c--)
		_putchar(o[c] + '0');
	return (m);
}
