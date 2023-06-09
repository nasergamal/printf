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
	int n;
	va_list li;
	pr p[] = {
	{"c", _putc},
	{"s", _puts}, {"S", _putS},
	{"i", _puti}, {"hi", _puthi}, {"li", _putli},
	{"d", _puti}, {"hd", _puthi}, {"ld", _putli},
	{"u", _putu}, {"hu", _puthu}, {"lu", _putlu},
	{"o", _puto}, {"ho", _putho}, {"lo", _putlo},
	{"x", _putx}, {"hx", _puthx}, {"lx", _putlx},
	{"X", _putX}, {"hX", _puthX}, {"lX", _putlX},
	{"p", _putp},
	{"b", _putb},
	{"R", _putR},
	{"r", _putr},
	{NULL, NULL}
};

	va_start(li, format);
	n = pri(format, p, li);
	va_end(li);

	return (n);
}
/**
 * pri - process the info given to _printf
 * @format: content to be printed
 * @p: struct containing specifiers and corresponding functions
 * @li: variadic list
 *
 * Return: count
 */
int pri(const char *format, pr p[], va_list li)
{
	int i = 0, n = 0;
	int (*function)(va_list);

	if (!format)
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if ((format[i + 1] == '\0'))
				return (-1);
			else if (format[i + 1] == '%')
			{
				i++;
				n += _putchar(format[i]);
			}
			else
			{
				function = funcget(format, p, &i);
				if (function != NULL)
				{
					n += function(li);
					i++;
				}
				else
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					n += _putchar(format[i]);
				}
			}
		}
		else
		{
			n += _putchar(format[i]);
		}
	}
	return (n);
}
/**
 * funcget - function that determine the print function to be used
 * @fmt: content to be printed
 * @p: struct containing specifiers and corresponding functions
 * @i: index
 *
 * Return: printing function
 */
int (*funcget(const char *fmt, pr p[], int *i))(va_list)
{
	int n = 0, in = *i + 1, m = 0;

	while (p[n].spc)
	{
		if (fmt[in] == p[n].spc[m])
		{
			if (p[n].spc[m + 1] != '\0')
				in++, m++;
			else
				break;
		}
		else
		{
			in = *i + 1;
			m = 0;
			n++;
		}
	}
	*i = in - 1;
	return (p[n].func);
}
