#include "main.h"
/**
 * _putS - print string with non-printable codes converted to ascii
 * @li: variadic list
 *
 * Return: count
 */
int _putS(va_list li)
{
	int i, c = 0, m, n = 0;
	char *s, b[2];

	s = va_arg(li, char *);
	for (i = 0; s[i]; i++)
	{
		if (!(s[i] > 0 && s[i] < 32) && !((s[i] >= 127)))
		{
			_putchar(s[i]);
			c += 1;
		}
		else
		{
			m = s[i];
			_putchar('\\');
			_putchar('x');
			for (n = 0; m > 0; n++)
			{
				if (m  % 16 < 10)
					b[n] = (m % 16) + 48;
				else
					b[n] = (m % 16) + 55;
				m /= 16;
			}
			c += 4;
		if (n == 1)
			b[n] = '0';
		for (; n >= 0; n--)
			_putchar(b[n]);
		}
	}
	return (c);
}
