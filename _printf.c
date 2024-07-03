#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int format_str(char *s);
void int_str(int num, char *s);

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
	char *int_s;

	va_start(args, format);
	int_s = malloc(sizeof(char *));

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
			else if (format[i + 1] == 'd')
			{
				int_str(va_arg(args, int), int_s);
				count += format_str(int_s);
				i++;
			}
			else
			{
				if (format[i + 1])
				{
					count += _putchar('%');
					count += _putchar(format[i + 1]);
					i++;
				}
				else
				{
					return (-1);
				}

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

/**
 * int_str - converts an integer to string
 * @num: number to convert
 * @s: string representation of the integer
 */
void int_str(int num, char *s)
{
	int i;
	int sign;
	char temp;
	int j;
	int k;

	i = 0;
	sign = num;

	if (num < 0)
	{
		num = -num;
	}

	do {
		s[i++] = num % 10 + '0';
	} while ((num /= 10) > 0);

	if (sign < 0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';

	for (j = 0, k = i - 1; j < k; j++, k--)
	{
		temp = s[j];
		s[j] = s[k];
		s[k] = temp;
	}
}
