/*-----------------------JUNK---------------------------*/

#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

/*
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


#include "includes/ft_printf.h"
#include <stdio.h>
void	print_formatspec(t_specs specs)
{
	printf("Format specifier : \'%c\' (%i)\n", specs.specif, specs.specif);
	printf("dash : %d\t", specs.dash);
	printf("zero : %d\t", specs.zero);
	printf("hash : %d\t", specs.hash);
	printf("blank : %d\t", specs.blank);
	printf("plus : %d\n", specs.plus);
	printf("width : %d\n", specs.width);
	printf("precision : (%s)	%ld\n", (specs.precis > -1 ? "true" : "false"), specs.precis);
	printf("n_chars : %d\n", specs.n_chars);
	printf("n_unknowns : %d\n", specs.n_unknowns);
}
*/

/* SAVE

int	print_ptr(t_specs specs, va_list *args)
{
	int			n_chars;
	uintptr_t	address;
	int			output_len;

	fetch_star_args(&specs, args);
	clean_formatspec(&specs);
	n_chars = 0;
	address = (unsigned long int)va_arg(*args, void *);
	output_len = 2;
	if (address || specs.precis != 0)
		output_len += ft_uintlen(address, 16);
	while (specs.dash == 0 && n_chars < specs.width - output_len)
		n_chars += ft_putchar(' ');
	n_chars += ft_putstr("0x");
	if (address || specs.precis != 0)
		n_chars += ft_putuint(address, 'x');
	while (specs.dash == 1 && n_chars < specs.width)
		n_chars += ft_putchar(' ');
	return (n_chars);
}
*/
int	ft_atoi_digits(const char *str)
{
	int	number;

	number = 0;
	while (*str > '0' && *str < '9')
	{
		number = number * 10 + *str - '0';
		str++;
		if (number < 0)
			return (-2);
	}
	return (number);
}

int	main(void)
{
	int res = INT_MAX;
	int read;

	read = printf("%3000000000d", 42);
	printf("\t (%d)\n", read);
	//read = printf("%.2147483649d", 1);
	//printf("\t (%d)\n", read);
	return (0);
}