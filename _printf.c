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
	int i, c, n = 0;
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
	{'0', NULL}
};

	va_start(li, format);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (c = 0; p[c].func; c++)
			{
				if (p[c].spc == format[i + 1])
				{
					p[c].func(li);
					i++;
					break; }
				else if (format[i + 1] == '%')
				{
					n += 1;
					i++;
					_putchar(format[i]);
					break; }
			}
			if (p[c].func == NULL)
				_putchar(format[i]);
		}
		else
			_putchar(format[i]);
	} va_end(li), i -= n, return (i);
}
