#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @args: A va_list of arguments
 * @counter: A pointer to the character count
 *
 * Return: The updated character count
 */
int print_unsigned(va_list args, int *counter)
{
	unsigned int number = va_arg(args, unsigned int);
	char buffer[20];
	int index = 0;
	int i;

	if (number == 0)
	{
		_putchar('0');
		return (1);
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

	*counter += index;
	return (*counter);
}

/**
 * print_hex - Prints an integer in hexadecimal format (lowercase)
 * @args: A va_list of arguments
 * @counter: A pointer to the character count
 *
 * Return: The updated character count
 */
int print_hex(va_list args, int *counter)
{
	int number = va_arg(args, int);
	char hexChars[] = "0123456789abcdef";
	char hexString[11];
	int i = 0;

	while (i < 8)
	{
		hexString[i] = hexChars[(number >> (28 - i * 4)) & 0xF];
		i++;
	}

	hexString[i] = '\0';

	_puts(hexString);
	*counter += i;
	return (*counter);
}

/**
 * print_HEX - Prints an integer in hexadecimal format (uppercase)
 * @args: A va_list of arguments
 * @counter: A pointer to the character count
 *
 * Return: The updated character count
 */
int print_HEX(va_list args, int *counter)
{
	int number = va_arg(args, int);
	char hexChars[] = "0123456789ABCDEF";
	char hexString[11];
	int i = 0;

	while (i < 8)
	{
		hexString[i] = hexChars[(number >> (28 - i * 4)) & 0xF];
		i++;
	}

	hexString[i] = '\0';

	_puts(hexString);
	*counter += i;
	return (*counter);
}

/**
 * print_octal - Prints an integer in octal format
 * @args: A va_list of arguments
 * @counter: A pointer to the character count
 *
 * Return: The updated character count
 */
int print_octal(va_list args, int *counter)
{
	unsigned int number = va_arg(args, unsigned int);
	char octalString[12];
	int i = 0;
	int j;

	do {
		octalString[i++] = '0' + (number % 8);
		number /= 8;
	} while (number > 0);

	for (j = i - 1; j >= 0; j--)
	{
		_putchar(octalString[j]);
	}

	*counter += i;
	return (*counter);
}

/**
 * print_pointer - Prints a pointer in hexadecimal format
 * @args: A va_list of arguments
 * @counter: A pointer to the character count
 *
 * Return: The updated character count
 */
int print_pointer(va_list args, int* counter) {
		uintptr_t address = (uintptr_t)va_arg(args, void*);
		char hexString[19];
		snprintf(hexString, sizeof(hexString), "0x%" PRIxPTR, address);
		_puts(hexString);
		*counter += 18;
		return *counter;
}
