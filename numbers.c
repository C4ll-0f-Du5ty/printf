#include "main.h"

/**
 * _printNumbers - Prints an integer number
 * @number: The number to print
 *
 * Return: The number of digits printed
 */
int _printNumbers(int number)
{
	int i;
	char buffer[20];
	int index = 0;

	if (number < 0)
	{
		_putchar('-');
		number = -number;
	}

	if (number == 0)
	{
		_putchar('0');
		return (0);
	}

	while (number > 0)
	{
		buffer[index++] = '0' + (number % 10);
		number /= 10;
	}

	for (i = index - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}

	return (index);
}

/**
 * print_int - Prints an integer
 * @args: A va_list of arguments
 * @counter: A pointer to the character count
 *
 * Return: The updated character count
 */
int print_int(va_list args, int *counter)
{
	int number = va_arg(args, int);
	*counter += _printNumbers(number);
	return (*counter);
}

/**
 * print_percent - Prints a percent character
 * @args: A va_list of arguments
 * @counter: A pointer to the character count
 *
 * Return: The updated character count
 */
int print_percent(va_list args, int *counter)
{
	(void)args;
	_putchar('%');
	(*counter)++;
	return (0);
}

/**
 * decToBinary - Converts a decimal number to binary and prints it
 * @n: The decimal number
 */
void decToBinary(int n)
{
	int j;
	int binary[32];
	int i = 0;

	if (n == 0)
	{
		printf("0");
		return;
	}
	if (n < 0)
	{
		printf("-");
		n = -n;
	}

	while (n > 0)
	{
		binary[i] = n % 2;
		n /= 2;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		printf("%d", binary[j]);
	}
}

/**
 * print_binary - Prints an integer in binary format
 * @args: A va_list of arguments
 * @counter: A pointer to the character count
 *
 * Return: The updated character count
 */
int print_binary(va_list args, int *counter)
{
	int number = va_arg(args, int);

	decToBinary(number);
	while (number != 0)
	{
		number /= 2;
		(*counter)++;
	}
	if (*counter == 0)
	{
		return (1);
	}
	else
	{
		return (*counter);
	}
}
