#include "main.h"

/**
 * _writechar - prints char
 * @c: pointer to char
 *
 * Return: characther
 */

int _writechar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - prints everything
 * @format: string containg types for argument
 *
 * Return: prints
 */

int _printf(const char *format, ...)
{
	va_list args;

	int count;

	va_start(args, format);

	count = 0;
	while (*format == '\0')
	{
		if (*format == '%')
		{
			format++;
			switch(*format)
			{
				case 'c':
					_writechar(va_arg(args, int));
					count++;
					break;
			}
		}
		else
		{
			_writechar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

