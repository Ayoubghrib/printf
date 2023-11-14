#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUFF_SIZE 1024
#define BUFF_FLUSH -1

#define NULL_STR "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONV_LOWER 1
#define CONV_UNSIGNED 2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if + flag specified
 * @space_flag: on if space flag specified
 * @hashtag_flag: on if # flag specified
 * @zero_flag: on if 0 flag specified
 * @minus_flag: on if - flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h modifier is specified
 * @l_modifier: on if l modifier is specified
 */
typedef struct parameters
{
	unsigned int is_unsigned : 1;

	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;

} params_t;

/**
 * struct specifier - struct token
 *
 * @specifier: format token
 * @function: the function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*function)(va_list, params_t *);
} specifier_t;

/* _put.c module */
int _puts(char *string);
int _putchar(int character);

/* print_functions.c module */
int print_character(va_list args, params_t *params);
int print_integer(va_list args, params_t *params);
int print_custom_string(va_list args, params_t *params);
int print_percent_sign(va_list args, params_t *params);
int print_custom_S(va_list args, params_t *params);

/* number.c module */
char *convert_to_base(long int number, int base, int flags, params_t *params);
int print_unsigned_integer(va_list args, params_t *params);
int print_memory_address(va_list args, params_t *params);

/* specifier.c module */
int (*get_specifier(char *s))(va_list args, params_t *params);
int get_print_func(char *s, va_list args, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list args);

/* convert_number.c module */
int print_hexadecimal(va_list args, params_t *params);
int print_HEXADECIMAL(va_list args, params_t *params);
int print_binary_number(va_list args, params_t *params);
int print_octal_number(va_list args, params_t *params);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_reverse(va_list args, params_t *params);
int print_rot13_encoding(va_list args, params_t *params);

/* print_number.c module */
int is_digit(int character);
int string_length(char *string);
int print_number_string(char *number_str, params_t *params);
int print_number_right_shift(char *number_str, params_t *params);
int print_number_left_shift(char *number_str, params_t *params);

/* params.c module */
void initialize_params(params_t *params, va_list args);

/* string_fields.c module */
char *get_precision(char *precision, params_t *params, va_list args);

/* _printf.c module */
int _printf(const char *format, ...);

#endif

