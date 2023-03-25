#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _putc - writes a character to stdout
 * @li: variadic list containing the char to be printed
 *
 * Return: char
 */
int _putc(va_list li)
{
	char c = va_arg(li, int);

	_putchar(c);
	return (1);
}

/**
 * _puts - writes strings to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _puts(va_list li)
{
	int i;
	char *s;

	s = (va_arg(li, char*));

	if (s == NULL)
	{
		_printf("(null)");
		return (6);
	}
	for (i = 0; s[i]; i++)
		_putchar(s[i]);
	return (i);
}
/**
 * _puti - writes integers and decimals to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _puti(va_list li)
{
	int in, c;

	in = (va_arg(li, int));

	c = print_n(in);

	return (c);
}
/**
 * _putu - writes unsigned int to stdout
 * @li: variadic list
 *
 * Return: output
 */
int _putu(va_list li)
{
	int m, j, c = 0;
	unsigned long int n, i = 100000000;

	n = (va_arg(li, unsigned long int));
	if (n > i)
	{
		m = n / i;
		j = n % i;
		c = print_n(m);
		c += print_n(j);
	}
	else
		c = print_n(n);
	return (c);
}
