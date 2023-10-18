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
