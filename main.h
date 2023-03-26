#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * struct print - struct to contain specifiers and their corresponding function
 * @spc: specifiers
 * @func: functions
 */
typedef struct print
{
	char spc;
	int (*func)(va_list);
} pr;
int pri(const char *format, pr p[], va_list li);
int _putchar(char c);
int _putc(va_list li);
int _puts(va_list li);
int _puti(va_list li);
int _putd(va_list li);
int _putu(va_list li);
int _puto(va_list li);
int _putx(va_list li);
int _putX(va_list li);
int _putp(va_list li);
int _putb(va_list li);
int _putR(va_list li);
int _printf(const char *format, ...);
int print_n(int in);

#endif
