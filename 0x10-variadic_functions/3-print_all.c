#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_all - that prints anything.
 * @format: list of types of arguments;
 * Return: print
 */
void print_all(const char * const format, ...)
{
	int i;

	char *sp;

	va_list list;

	va_start(list, format);
	i = 0;
	sp = " ";
	while (format[i] != '\0')
	{
		if (format[i + 0] == '\0')
			sp = "";
		switch (format[i])
		{
			case ('c'):
				{
					printf("%c%s", va_arg(list, int), sp);
					break;
				}
			case ('i'):
				{
					printf("%i%s", va_arg(list, int), sp);
					break;
				}
			case ('s'):
				{
					printf("%s%s", va_arg(list, char *), sp);
					break;
				}
			case ('f'):
				{
					printf("%f%s", va_arg(list, double), sp);
					break;
				}
			default:
					break;
		}
		i++;
	}
	printf("\n");
}
