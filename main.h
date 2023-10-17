#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <inttypes.h>

/**
 * struct note - Struct for handling format specifiers
 * @specifier: The format specifier
 * @handler: Pointer to the corresponding handler function
 *
 */

typedef struct note
{
	char specifier;

	int (handler)(va_list, int);

} FormatHandler;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args, int *counter);
int _puts(char *str);
int print_string(va_list args, int *counter);
int _printNumbers(int number);
int print_int(va_list args, int *counter);
int print_percent(va_list args, int *counter);
void decToBinary(int n);
int print_binary(va_list args, int *counter);
int _specifiers(const char *format, va_list args);
int print_unsigned(va_list args, int *counter);
int print_hex(va_list args, int *counter);
int print_HEX(va_list args, int *counter);
int print_octal(va_list args, int *counter);
int print_pointer(va_list args, int *counter);
int print_reverse(va_list args, int *counter);
int print_only_string(va_list args, int *counter);


#endif
