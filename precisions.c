#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @format: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *format, params_t *params, va_list ap)
{
	int precision = 0;

	if (*format != '.')
		return (format);
	format++;
	if (*format == '*')
	{
		precision = va_arg(ap, int);
		format++;
	}
	else
	{
		while (_isdigit(*format))
			precision = precision * 10 + (*format++ - '0');
	}
	params->precision = precision;
	return (format);
}

