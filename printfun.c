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
	int c = 0;
	unsigned int n, m, i = 1;

	n = (va_arg(li, unsigned int));
	while ((n / i) > 9)
		i *= 10;
	while (i > 0)
	{
		m = (n / i) % 10;
		c++;
		_putchar(m + '0');
		i /= 10;
	}
	return (c);
}
