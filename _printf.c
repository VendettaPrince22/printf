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
	char c;
	va_list args;

	va_start(args, format);

	if (strcmp(format, "%c") == 0)
	{
		c = va_arg(args, int);
		count = write(1, &c, 1);
	}
	else
	{
		i = 0;
		while (format[i] != '\0')
		{
			i++;
		}

		count = write(1, format, i);
	}



	va_end(args);

	return (count);
}
