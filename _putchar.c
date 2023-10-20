#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 *
 * Return: number of characters printed (1)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - prints a character
 * @args: argument list containing the character to print
 * @counter: pointer to the counter of characters printed
 *
 * Return: updated counter value
 */
int print_char(va_list args, int *counter)
{
	char c = va_arg(args, char);

	_putchar(c);
	(*counter)++;
	return (*counter);
}

/**
 * _puts - prints a string followed by a new line
 * @str: the string to print
 *
 * Return: 0 (Success)
 */
int _puts(char *str)
{
	while (*str)
		_putchar(*str++);
	return (0);
}

/**
 * print_string - prints a string
 * @args: argument list containing the string to print
 * @counter: pointer to the counter of characters printed
 *
 * Return: updated counter value
 */
int print_string(va_list args, int *counter)
{
	char *s = va_arg(args, char*);

	if (s)
	{
		while (*s)
		{
			_putchar(*s);
			s++;
			(*counter)++;
		}
		return (*counter);
	}
	else
	{
		_puts("null");
		return (*counter + 4);
	}
}

/**
 * print_only_string - prints non-printable characters ..
 * @args: argument list containing the string to print
 * @counter: pointer to the counter of characters printed
 *
 * Return: void
 */
int print_only_string(va_list args, int *counter)
{
	char *str = va_arg(args, char*);
	int i = 0;

while (str[i] != '\0')
{
	if ((str[i] < 32) || (str[i] >= 127))
	{
		char hex[3];

		write(1, "\\x", 2);
		hex[0] = (str[i] / 16) < 10 ? (str[i] / 16) + '0' : (str[i] / 16) - 10 + 'A';
		hex[1] = (str[i] % 16) < 10 ? (str[i] % 16) + '0' : (str[i] % 16) - 10 + 'A';
		write(1, hex, 2);
			*counter += 4;
		}
		else
		{
			write(1, &str[i], 1);
			(*counter)++;
		}
		i++;
	}
	return (*counter);
}
