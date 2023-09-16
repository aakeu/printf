#include "main.h"

/**
 * get_precision - get the precision from the format
 * @p: format string
 * @params: parameters struct
 * @ap: argument pointer
 * Return: new pointer
 */

char *get_precision(char *p, params_t *params, va_list ap)
{
	int g = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		g = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			g = g * 10 + (*p++ - '0');
	}
	params->precision = g;
	return (p);
}

