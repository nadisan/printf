#include "main.h"

int printInt(int num, unsigned int n);

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
  * printnum - prints different number system
  * @num: number inputted
  * @type: type specier
  * Return: count
  */
int printnum(int num, char type)
{
	int count = 0;
	unsigned int a, b = num, c = 1, d, f, n;

	if (num == '\0')
	{
		return (_writechar('0'));
	}
	if (num < 0)
		num = num * -1;
	if (type == 'b')
		return (printInt(num, 2));
	else if (type == 'o')
		return (printInt(num, 8));
	else if (type == 'u')
		return (printInt(num, 10));
	n = 16;
	for (a = 1; b > (n - 1); a++)
	{
		b = b / n;
		c = c * n;
	}
	for (f = 1; f <= a; f++)
	{
		d = num / c;
		num = num % c;
		c = c / n;
		if (d < 10)
			count += _writechar(d + '0');
		else
		{
			if (type == 'X')
				d = 'A' + (d - 10);
			else if (type == 'x')
				d = 'a' + (d - 10);
			count += _writechar(d);
		}
	}
	return (count);
}
/**
  * printInt - prints ints
  * @num: number parameter
  * @n: number system
  * Return: count
  */

int printInt(int num, unsigned int n)
{
	int count = 0;
	unsigned int a, b, c, d, f;

	if (num == '\0')
	{
		return (_writechar('0'));
	}
	if (num < 0)
	{
		count += _writechar('-');
		num = num * -1;
	}
	b = num;
	c = 1;
	for (a = 1; b > (n - 1); a++)
	{
		b = b / n;
		c = c * n;
	}
	for (f = 1; f <= a; f++)
	{
		d = num / c;
		num = num % c;
		c = c / n;
		count += _writechar(d + '0');
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

	char *j = malloc(sizeof(char) * 100);

	va_start(args, format);
	count = 0;
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			*j = *format;
			if (*j == 'X' || *j == 'x' || *j == 'u' || *j == 'o' || *j == 'b')
				count += printnum((va_arg(args, int)), *format);
			else if (*j == 'i' || *j == 'd')
				count += printInt((va_arg(args, int)), 10);
			else if (*format == 'c')
				count += _writechar(va_arg(args, int));
			else if (*format == 's')
				count += _puts(va_arg(args, char*));
			else if (*format == '%')
				count += _writechar('%');
			else
			{
				count +=  _writechar('%');
						format--;
			}
		}
		else
			count += _writechar(*format);
		format++;
	}
	va_end(args);
	free(j);
	return (count);
}
