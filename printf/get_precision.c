#include "main.h"

/* Function: get_precision
 * Description: Extracts precision value from the format string and returns it.
 * Parameters:
 *   - format: The format string.
 *   - i: Pointer to the current index in the format string (updated to the end of the precision).
 *   - list: Variable argument list.
 * Return: The precision value.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}