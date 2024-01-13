#include "main.h"

/**
 * _printf - Custom printf function with basic format specifiers.
 * @format: Format string with conversion specifiers.
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				putchar(va_arg(args, int));
				count++;
				break;
			case 's':
				count += printf("%s", va_arg(args, char *));
				break;
			case '%':
				putchar('%');
				count++;
				break;
			default:
				break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
