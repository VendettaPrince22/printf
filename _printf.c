#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf - produces output according to a format
 * @format: character stream composed of zero or more directives
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count;
	int i;
	va_list args;

	va_start(args, format);

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}
		else
		{
			if (format[i + 1] == 's')
			{
				_putchar(va_arg(args, int));
				i++;
			}
			else if (format[i + 1] == 'c')
			{
				_putchar(va_arg(args, int));
				i++;
			}
			else if (format[i + 1] == '%')
			{
				_putchar(va_arg(args, int));
				i++;
			}
		}
		i++;
	}
	count = i - 1;

	va_end(args);

	return (count);
}
