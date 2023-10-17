#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable number of arguments
 *
 * Return: Number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int result;

	va_start(args, format);

	if (!format)
	{
		return (-1);
	}

	result = _specifiers(format, args);

	va_end(args);
	return (result);
}

/**
 * print_reverse - Prints a string in reverse.
 * @args: A list of arguments containing the string to be printed.
 * @counter: A pointer to the counter for tracking
 * the number of characters printed.
 *
 * Return: The total number of characters printed.
 */

int print_reverse(va_list args, int *counter)
{
	char *s = va_arg(args, char*);

	if (s)
	{
		int len = strlen(s);

		for (int i = len - 1; i >= 0; i--)
		{
			_putchar(s[i]);
			(*counter)++;
		}
		return (*counter);
	}
	return (*counter);
}
