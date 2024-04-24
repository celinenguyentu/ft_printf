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

int	main(void)
{
		int	count;

	count = 0;
	count = ft_printf("Hello %!");
	printf("\t(%d)\n", count);
	count = ft_printf("Hello %42!");
	printf("\t(%d)\n", count);
	count = ft_printf("|%c|%c|%c|", 'C', "Marvin", NULL);
	printf("\t(%d)\n", count);
	count = ft_printf("|%p|%p|%.p|%.p|%.2p|", 42, NULL, 0, NULL, NULL);
	printf("\t(%d)\n", count);
	count = ft_printf("|%.-3d|%.-3d|", 42, 0);
	printf("\t(%d)\n", count);
	count = ft_printf("|%03.-3d|%03.-3d|", 42, 0);
	printf("\t(%d)\n", count);
	count = ft_printf(NULL);
	printf("\t(%d)\n", count);
	count = ft_printf("|%p|", 42);
	printf("\t(%d)\n", count);
	return (0);
}
