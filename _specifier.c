#include "main.h"

/**
 * _specifiers - A function to parse format specifiers
 * @format: The format string to be parsed
 * @args: A va_list of arguments to be printed
 *
 * Return: The number of characters printed
 */
int _specifiers(const char *format, va_list args)
{
	int counter = 0;
	int i;
	int found = 0;

				FormatHandler formatHandlers[] = {
				{'c', print_char}, {'s', print_string}, {'%', print_percent},
				{'d', print_int}, {'i', print_int}, {'u', print_unsigned},
				{'b', print_binary}, {'x', print_hex}, {'X', print_HEX},
				{'o', print_octal}, {'p', print_pointer}, {'S', print_only_string},
				{'\0', NULL}, };
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			for (i = 0; formatHandlers[i].specifier != '\0'; i++)
			{
				if (formatHandlers[i].specifier == *format)
				{counter += formatHandlers[i].handler(args, &counter);
					found = 1;
					break;
				}
				if (*format == 'c')
					counter -= 1;
			}
			if (found == 0)
			{_putchar(37);
				_putchar(*format);
				counter++;
			}
		}
		else
		{_putchar(*format);
			counter++;
		}
		format++;
	}
	return (counter);
}
