#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int format_str(char *s);

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
	count = 0;
	if (format == NULL)
	{
		return (-1);
	}
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
		}
		else
		{
			if (format[i + 1] == 's')
			{
				count += format_str(va_arg(args, char *));
				i++;
			}
			else if (format[i + 1] == 'c')
			{
				count += _putchar(va_arg(args, int));
				i++;
			}
			else if (format[i + 1] == '%')
			{
				count += _putchar('%');
				i++;
			}
		}
		i++;
	}

	va_end(args);

	return (count);
}

/**
 * format_str - prints a string to stdout
 * @s: string to print
 *
 * Return: number bytes printed to stdout
 */
int format_str(char *s)
{
	int count;
	int i;
	char *non_num;

	non_num = "(null)";

	i = 0;
	count = 0;
	if (s == (char *)0)
	{
		s = non_num;
	}
	while (s[i] != '\0')
	{
		count += _putchar(s[i]);
		i++;
	}

	return (count);
}
