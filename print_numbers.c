#include "main.h"

/**
 * _is_digit - checks if character is digit
 * @ch: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _is_digit(int ch)
{
	return (ch >= '0' && ch <= '9');
}

/**
 * _str_length - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of the string
 */
int _str_length(char *str)
{
	int length = 0;

	while (*str++)
		length++;
	return (length);
}

/**
 * print_number - prints a number with options
 * @number_str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *number_str, params_t *params)
{
	unsigned int len = _str_length(number_str);
	int is_negative = (!params->unsign && *number_str == '-');

	if (!params->precision && *number_str == '0' && !number_str[1])
		number_str = "";
	if (is_negative)
	{
		number_str++;
		len--;
	}
	if (params->precision != UINT_MAX)
		while (len++ < params->precision)
			*--number_str = '0';
	if (is_negative)
		*--number_str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(number_str, params));
	else
		return (print_number_left_shift(number_str, params));
}

/**
 * print_number_right_shift - prints a number with options
 * @number_str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *number_str, params_t *params)
{
	unsigned int n = 0, is_negative, neg2, len = _str_length(number_str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	is_negative = neg2 = (!params->unsign && *number_str == '-');
	if (is_negative && len < params->width && pad_char == '0' && !params->minus_flag)
		number_str++;
	else
		is_negative = 0;
	if ((params->plus_flag && !neg2) ||
		(!params->plus_flag && params->space_flag && !neg2))
		len++;
	if (is_negative && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (len++ < params->width)
		n += _putchar(pad_char);
	if (is_negative && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(number_str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @number_str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *number_str, params_t *params)
{
	unsigned int n = 0, is_negative, neg2, len = _str_length(number_str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	is_negative = neg2 = (!params->unsign && *number_str == '-');
	if (is_negative && len < params->width && pad_char == '0' && !params->minus_flag)
		number_str++;
	else
		is_negative = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		n += _putchar('+'), len++;
	else if (params->space_flag && !neg2 && !params->unsign)
		n += _putchar(' '), len++;
	n += _puts(number_str);
	while (len++ < params->width)
		n += _putchar(pad_char);
	return (n);
}

