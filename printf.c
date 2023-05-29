#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0; // number of characters printed

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++; // move past the '%'

            // Handle the conversion specifiers
            switch (*format)
            {
                case 'c':
                {
                    // char argument is promoted to int when passed through va_arg
                    char c = (char) va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }

                case 's':
                {
                    char *s = va_arg(args, char *);
                    while (*s != '\0')
                    {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }

                case '%':
                {
                    putchar('%');
                    count++;
                    break;
                }

                default:
                    // Invalid format specifier, ignore it
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

    return count;
}
