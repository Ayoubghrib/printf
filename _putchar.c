#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int character)
{
	static int index;
	static char buffer[BUFF_SIZE];

	if (character == BUFF_FLUSH || index >= BUFF_SIZE)
	{
		write(1, buffer, index);
		index = 0;
	}
	if (character != BUFF_FLUSH)
		buffer[index++] = character;
	return (1);
}

/**
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return: void
 */
int _puts(char *string)
{
	char *currentChar = string;

	while (*string)
		_putchar(*string++);
	return (string - currentChar);
}

