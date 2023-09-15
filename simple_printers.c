#include "main.h"

/**
 * print_from_to - prints a range of char address
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 * @char: the character
 *
 * Return: number btyes printed
 */

int print_from_to(char *start, char *stop, char, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start <= stop)
			if (start != except)
				sum += _Putchar(*start);
			start++;
	}
		return (sum);
}

/**
 * print_rev - prints string with reverse
 * @ap: string
 * @params: parameters struct
 * Return: number of bytes
 */

int print_rev(va_list ap, params_t *params)
{
	int length, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (length = 0; *str; str++)
			lebgth++;
		str--;
		for (; length > 0; length--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - prints the string.
 * @ap: string
 * @params: parameters struct
 * Return: bytes printed
 */

int print_rot13(va_list ap, params_t *params)
{
	int i;
	int index;
	int count = 0;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
