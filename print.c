#include "main.h"

/**
 * print_binary - Prints a number in binary
 * @args: The argument list containing the number to print
 */
void print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int i, flag = 0;

	if (num == 0)
	{
		_putchar('0');
		return;
	}

	for (i = 31; i >= 0; i--)
	{
		if ((num >> i) & 1)
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag)
			_putchar('0');
	}
}

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);

			switch (format[i])
			{
				case 'b':
					print_binary(args);
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
