/*-----------------------JUNK---------------------------*/

#include <stdarg.h>
#include "includes/ft_printf.h"

int	get_argn(va_list args_cpy, int n)
{
	int	arg;

	arg = 0;
	while (n > 0)
	{
		arg = va_arg(args_cpy, int);
		n--;
	}
	va_end(args_cpy);
	return (arg);
}

void	print_formatspec(t_formatspec specs)
{
	printf("Format specifier : %c\n", specs.specifier);
	printf("dash : %d\t", specs.dash);
	printf("zero : %d\t", specs.zero);
	printf("hash : %d\t", specs.hash);
	printf("blank : %d\t", specs.blank);
	printf("plus : %d\n", specs.plus);
	printf("width : %d\n", specs.width);
	printf("precision : (%s)	%d\n", (specs.precision > -1 ? "true" : "false"), specs.precision);
	printf("n_chars : %ld\n", specs.n_chars);
}

