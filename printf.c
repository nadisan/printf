#include "main.h"

/**
 *_writechar - prints char
 *@c: pointer to char
 *Return: character
 */
int _writechar(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 *_puts - prints strings
 *@str: pointer to string
 *Return: length of string
 */

int _puts(char *str)
{
	int len = 0;

	if (str == NULL)
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
  * printInt - prints ints
  * @num: number parameter
  * Return: count
  */

int printInt(int num)
{
	int count = 0;
	unsigned int a, b, c, d, f;

	if (num == '\0')
	{
		_writechar('0');
		return (1);
	}
	if (num < 0)
	{
		_writechar('-');
		num = num * -1;
		count++;
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
 *_printf - prints c, s, %, d and i
 *@format: pointer to  character string
 *Return: length of string
 */

int _printf(const char *format, ...)
{
	va_list args;

	int count;

	va_start(args, format);
	count = 0;
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
					count += _puts(va_arg(args, char*));
					break;
				case '%':
					count += _writechar('%');
					break;
				case 'i':
				case 'd':
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
