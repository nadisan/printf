#include "main.h"

/**
 * _writechar - prints char
 * @c: pointer to char
 *
 * Return: characther
 */

int _writechar(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * _puts - prints char
 * @str: pointer to char
 *
 * Return: characther
 */

int _puts(char *str)
{
	int len = 0;

	if (str == NULL || str == 0)
		str = "(null)";
	while (*str != '\0')
	{
		_writechar(*str);
		str++;
		len++;
	}
	return (len);
}

/**
 * printInt - prints integer and double
 * @num: number
 *
 * Return: number of printed character
 */

int printInt(int num)
{
	int count = 0;
	unsigned int a, b, c, d, f;

	if (num < 0)
	{
		_writechar('-');
		num = num * -1;
	}

	b = num;
	c = 1;
	for (a = 1; b > 9; a++)
	{
		b = b / 10;
		c = c * 10;
	}
	for (f = 1; f <= a; f++)
	{
		d = num / c;
		num = num % c;
		c = c / 10;
		_writechar(d + '0');
		count++;
	}
	return (count);
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

	int count = 0;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += _writechar(va_arg(args, int));
					break;
				case 's':
					count += _puts(va_arg(args, char *));
					break;
				case '%':
					count += _writechar('%');
					break;
				case 'i':
				case 'd':
					if (!va_arg(args, int))
						count += _writechar('0');
					else
						count += printInt(va_arg(args, int));
					break;
				default:
					break;
			}
		}
		else
			count += _writechar(*format);
		format++;
	}
	va_end(args);
	return (count);
}

