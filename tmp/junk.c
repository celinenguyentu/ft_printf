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
	printf("width : %ld\n", specs.width);
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


#include "ft_printf.h"

/*
	UPDATE_FORMATSPECS
	Parses the initial portion of the format string from the percent symbol '%'
	to either a specifier or an unknown character, including optional flags,
	width and precision. It stores the conversion specifications into a struct
	specs including any options like flag, width, precision, the conversion
	specifier or the next regular character if the specifier is missing, and
	the number of characters read by the parser. The invalid flags are switched
	off by the function clean_formatspec().
	PARAMETER(S)
		The format string to control the output starting at the '%' symbol
	RETURN
	The function returns the t_specs struct that holds the information of the
	conversion specification and the number of characters read from format.
*/

static const char	*read_flags(const char *format, t_specs *specs)
{
	char	flag;

	while (*format && ft_strchr(FLAGS, *format))
	{
		flag = *ft_strchr(FLAGS, *format);
		if (flag == '-')
			specs->dash = 1;
		else if (flag == '0')
			specs->zero = 1;
		else if (flag == '#')
			specs->hash = 1;
		else if (flag == ' ')
			specs->blank = 1;
		else
			specs->plus = 1;
		format++;
		specs->n_chars += 1;
	}
	return (format);
}

static const char	*read_width(const char *format, t_specs *specs, va_list *args)
{
	if (*format == '*')
	{
		specs->star_width = 0;
		specs->n_chars += 1;
		format++;
		if (specs->star_width == 0)
		{
			specs->width = va_arg(*args, int);
			//if (specs->width == INT_MIN) // not needed on Linux check on mac
			//	specs->width++;
			if (specs->width < 0)
			{
				specs->width = -specs->width;
				specs->dash = 1;
			}
		}
	}
	else
	{
		specs->width = (int)ft_atoi_digits(format);
		specs->n_chars += ft_nbrlen(format);
		format += ft_nbrlen(format);
	}
	return (format);
}

#if defined(__APPLE__)

static const char	*read_precision(const char *format, t_specs *specs, va_list *args)
{
	while (*format && (ft_strchr(FLAGS, *format) || *format == '*'))
	{
		format = read_flags(format, specs);
		if (ft_isdigit(*format) || *format == '*')
			format = read_width(format, specs, args);
	}
	if (*format == '.')
	{
		specs->n_chars += 1;
		if (*++format == '*')
		{
			specs->star_precis = 0;
			specs->n_chars += 1;
			format++;
			if (specs->star_precis == 0)
			{
				specs->precis = (long)va_arg(*args, int); // need to check for negative precision ? yes on Linux check on mac
				if (specs->precis < 0)
					specs->precis = -1;
			}
		}
		else
		{
			specs->precis = ft_atoi_digits(format);
			specs->n_chars += ft_nbrlen(format);
			format += ft_nbrlen(format);
		}
	}
	while (*format && (ft_strchr(FLAGS, *format) || *format == '*'))
	{
		format = read_flags(format, specs);
		if (ft_isdigit(*format) || *format == '*')
			format = read_width(format, specs, args);
	}
	return (format);
}

#else

static const char	*read_precision(const char *format, t_specs *specs)
{
	if (*format == '.')
	{
		specs->n_chars += 1;
		if (*++format == '*')
		{
			specs->star_precis = 0;
			specs->n_chars += 1;
			format++;
		}
		else
		{
			specs->precis = ft_atoi_digits(format);
			specs->n_chars += ft_nbrlen(format);
			format += ft_nbrlen(format);
		}
	}
	return (format);
}

#endif

void	update_formatspecs(t_specs *specs, const char **format, va_list *args)
{
	reset_formatspecs(specs);
	(*format)++;
	*format = read_flags(*format, specs);
	*format = read_width(*format, specs, args);
	*format = read_precision(*format, specs, args);
	if (**format)
	{
		specs->specif = **format;
		specs->n_chars += 1;
		(*format)++;
	}
	clean_formatspecs(specs);
	/*
	if (specs->star_width == 0)
	{
		specs->width = va_arg(*args, int);
		//if (specs->width == INT_MIN) // not needed on Linux check on mac
		//	specs->width++;
		if (specs->width < 0)
		{
			specs->width = -specs->width;
			specs->dash = 1;
		}
	}*/
	/*
	if (specs->star_precis == 0)
	{
		specs->precis = (long)va_arg(*args, int); // need to check for negative precision ? yes on Linux check on mac
		if (specs->precis < 0)
			specs->precis = -1;
	}*/
}

/* SAVE
static const char	*read_precision(const char *format, t_specs *specs)
{
	if (*format == '.')
	{
		specs->n_chars += 1;
		if (*++format == '*')
		{
			specs->star_precis = 0;
			specs->n_chars += 1;
			format++;
		}
		else
		{
			if (*format == '-')
			{
				specs->precis = 0;
				format = read_flags(format, specs);
				specs->width = ft_atoi_digits(format);
			}
			else
				specs->precis = ft_atoi_digits(format);
			specs->n_chars += ft_nbrlen(format);
			format += ft_nbrlen(format);
		}
	}
	return (format);
}
*/
