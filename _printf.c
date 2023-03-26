#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - high-copy of printf
 * @format: to be printed
 *
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int n = -1;
	va_list li;
	pr p[] = {
	{'c', _putc},
	{'s', _puts},
	{'i', _puti},
	{'d', _puti},
	{'u', _putu},
	{'o', _puto},
	{'x', _putx},
	{'X', _putX},
	{'p', _putp},
	{'b', _putb},
	{'R', _putR},
	{'0', NULL}
};
	if (format)
	{
		va_start(li, format);
		n = pri(format, p, li);
		va_end(li);
	}
	return (n);
}
/**
 * pri - complement _printf function
 * @format: to be printed
 * @p: struct
 * @li: variadic list
 *
 * Return: count
 */
int pri(const char *format, pr p[], va_list li)
{
	int i, c, n = 0, a = 0;

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (c = 0; p[c].func; c++)
			{
				if (p[c].spc == format[i + 1])
				{
					n += p[c].func(li);
					i++;
					a = 1;
					break;
				}
				else if ((format[i + 1] == '\0' || format[i + 1] == ' ') && a)
					return (-1);
				else if (format[i + 1] == '%')
				{
					i++;
					n += _putchar(format[i]);
					break;
				}
			}
			if (p[c].func == NULL)
			{
				_putchar(format[i]);
				n++;
			}
		}
		else
		{
			_putchar(format[i]);
			n++;
		}
	}
	return (n);
}
