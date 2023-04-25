#include "main.h"
#include <stdarg.h>

/**
 *_writechar - prints char
 *@c: pinter to char
 *
 *Return: character
 */

 int _writechar(char c)
 {
    return (write(1, &c, 1);
 }

/**
 *_writechar - prints char
 *@c: pinter to char
 *
 *Return: character
 */

int _printf(const char *format, ...)
{
    va_list args;

    int count, i;

    va_start(args, format);

    count = 0;
    while (*format == '\0')
    {
        if(*format == '%')
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
