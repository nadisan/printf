#include <stdlib.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 *print_numbers - returns the sum of all its parameters
 *@separator: string to be printed between numbers
 *@n: number of arguments
 *
 *Return: 0 when n is null else sum.
 */

void print_all(const char * const format, ...)
{
        int i;

        va_list list;

        va_start(list, format);

        i = 0;
        while(format[i])
        {
		
                if (*format == '\0')
                        break;
                printf("%d%s", va_arg(list, char *)," ");
                i++;
        }
	printf("%i\n", i);
        va_end(list);
}
