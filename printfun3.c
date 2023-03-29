#include "main.h"

/**
 * _putb - print in binary
 * @li: variadic list
 *
 * Return: count
 */

int _putb(va_list li)
{
	int c, o[100], m;
	unsigned long int n;

	n = (va_arg(li, unsigned long int));

	for (c = 0; n != 0 ; c++)
	{
		o[c] = n % 2;
		n /= 2;
	}
	m = c;
	for (c -= 1; c >= 0; c--)
		_putchar(o[c] + '0');
	return (m);
}
/**
 * _putR - change string using Rot 13
 * @li: variadic list
 *
 * Return: count
 */
int _putR(va_list li)
{
	int i, c = 0;
	char *s;

	s = va_arg(li, char *);
	if (s == NULL)
	{
		_printf("(null)");
		return (6);
	}
	for (i = 0; s[i]; i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && (s[i] <= 'Z')))
		{
			if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && (s[i] <= 'M')))
			{
				_putchar(s[i] + 13);
				c += 1;
			}
			else if ((s[i] > 'm' && s[i] <= 'z') || (s[i] > 'M' && (s[i] <= 'Z')))
			{
				_putchar(s[i] - 13);
				c += 1;
			}
		}
		else
		{
			_putchar(s[i]);
			c += 1;
		}
	}
	return (c);
}
/**
 * _putr - print string in reverse
 * @li: variadic list
 *
 * Return: count
 */
int _putr(va_list li)
{
	int i, c;
	char *r;

	r = (va_arg(li, char*));

	if (r == NULL)
	{
		_printf("(null)");
		return (6);
	}
	for (i = 0; r[i]; i++)
		;
	c = i;
	for  (; i >= 0; i--)
		_putchar(r[i]);
	return ((c - 1));
}
