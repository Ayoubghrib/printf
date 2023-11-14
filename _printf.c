#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int custom_printf(const char *format, ...)
{
	int total_bytes = 0;
	va_list args;
	char *current_char, *start;
	params_t params = PARAMS_INIT;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (current_char = (char *)format; *current_char; current_char++)
	{
		init_params(&params, args);
		if (*current_char != '%')
		{
			total_bytes += _putchar(*current_char);
			continue;
		}
		start = current_char;
		current_char++;
		while (get_flag(current_char, &params)) /* while char at p is flag char */
		{
			current_char++; /* next char */
		}
		current_char = get_width(current_char, &params, args);
		current_char = get_precision(current_char, &params, args);
		if (get_modifier(current_char, &params))
			current_char++;
		if (!get_specifier(current_char))
			total_bytes += print_from_to(start, current_char,
				params.l_modifier || params.h_modifier ? current_char - 1 : 0);
		else
			total_bytes += get_print_func(current_char, args, &params);
	}
	_putchar(BUFF_FLUSH);
	va_end(args);
	return (total_bytes);
}

