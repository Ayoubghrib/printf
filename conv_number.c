#include "main.h"

/**
 * print_octal - prints unsigned octal numbers
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long num;
	char *str;
	int bytes_printed = 0;

	if (params->l_modifier)
		num = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		num = (unsigned short int)va_arg(ap, unsigned int);
	else
		num = (unsigned int)va_arg(ap, unsigned int);

	str = convert(num, 8, CONV_UNSIGNED, params);

	if (params->hashtag_flag && num)
		*--str = '0';
	params->unsign = 1;
	return (bytes_printed += print_number(str, params));
}

/**
 * print_binary - prints unsigned binary number
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *str = convert(num, 2, CONV_UNSIGNED, params);
	int bytes_printed = 0;

	if (params->hashtag_flag && num)
		*--str = '0';
	params->unsign = 1;
	return (bytes_printed += print_number(str, params));
}

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long num;
	int bytes_printed = 0;
	char *str;

	if (params->l_modifier)
		num = (unsigned long)va_arg(ap,

