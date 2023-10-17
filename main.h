#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <inttypes.h>

/**
 * struct FormatHandler - Struct for handling format specifiers
 * @specifier: The format specifier
 * @handler: Pointer to the corresponding handler function
 *
 */

typedef struct FormatHandler
{
	char specifier;
	int (*handler)(va_list args, int *counter);
} FormatHandler;

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int _specifiers(const char *format, va_list args);

int print_char(va_list args, int *counter);
int print_string(va_list args, int *counter);
int print_percent(va_list args, int *counter);
int print_int(va_list args, int *counter);
int print_unsigned(va_list args, int *counter);
int print_binary(va_list args, int *counter);
int print_hex(va_list args, int *counter);
int print_HEX(va_list args, int *counter);
int print_octal(va_list args, int *counter);
int print_pointer(va_list args, int *counter);
int print_reverse(va_list args, int *counter);
int print_only_string(va_list args, int *counter);

#endif
