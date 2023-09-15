#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: format string
 * Return: number of bytes to be printed
 */

int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int p = 0;

	while (specifiers[p].specifier)
	{
		if (*s == specificers[p].specifier[0])
		{
		return (specifiers[p].f);
		}
		p++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the formet function
 * @s: format string
 * @ap: argument pointer
 * @params: parameters struct
 * Return: number of bytes printed
 */

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);
	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - finds flag func
 * @s: format string
 * @params: parameters struct
 * Return: flag was valid
 */

int get_flag(char *s, params_t *params)
{
	int p = 0;

	switch (*s)
	{
		case '+':
			p = params->plus_flag = 1;
			break;
		case ' ':
			p = params->space_flag = 1;
			break;
		case '#':
			p = params->hashtag_flag = 1;
			break;
		case '-':
			p = params->minus_flag = 1;
			break;
		case '0':
			p = params->zero_flag = 1;
			break;
	}
	return (p);
}

/**
 *get_modifier -find the modifier func
 *@s: format string
 *@params: parameters struct
 *
 * Return: if modifier was valid
 */

int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - ger the width form the format string
 * @s: format string
 * @params: parameters struct
 * @ap: argument prointer
 * Return: new pointer
 */

char *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*S++ - '0');
	}
	params->width = d;
	return (s);
}


