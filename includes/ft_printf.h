/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:33 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/24 01:04:40 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define SPECIFIERS "cspdiuxX%"
# define FLAGS "-0# +"
# define LOWHEXADECIMAL "0123456789abcdef"
# define UPHEXADECIMAL "0123456789ABCDEF"
# define DECIMAL "0123456789"

# if defined(__APPLE__)
#  define NULLPTR "0x0"
# else
#  define NULLPTR "(nil)"
# endif

typedef struct s_specs
{
	int		dash; // true 1 or false 0
	int		zero; // true 1 or false 0
	int		hash; // true 1 or false 0
	int		blank; // true 1 or false 0
	int		plus; // true 1 or false 0 
	int		star_width; // -1 none, 0 next arg, m > 0 m-th arg
	int		width; // 0 none, 1, 2, 3, 4 ... value
	int		star_precision; // -1 none, 0 next arg, m > 0 m-th arg
	int		precision; // - 1 none, 0, 1, 2, 3... value
	char	specifier; // c, s, p, d, i, u, x, X, %, unknown
	size_t	n_chars;
}	t_specs;

// ft_printf
int		ft_printf(const char *format, ...);
int		ft_vprintf(const char *format, va_list ap); // apple, linux
int		print_arg(t_specs specs, va_list *args);
int		print_char(t_specs specs, va_list *args); // apple, linux
int		print_str(t_specs specs, va_list *args); // apple, linux
int		print_ptr(t_specs specs, va_list *args);
int		print_int(t_specs specs, va_list *args);
int		print_uint(t_specs specs, va_list *args, int baselen);
int		print_percent(t_specs specs, va_list *args); // apple, linux
int		print_unknown(t_specs specs); // apple, linux
int		print_intprefix(t_specs specs, int uarg_len, int negative, int nul);

// formatspec
void	init_formatspec(t_specs *specs);
t_specs	get_formatspec(const char *format); // apple, linux
void	clean_formatspec(t_specs *specs);
void	fetch_next_args(t_specs *specs, va_list *args);

// Utility functions
int		ft_atoi_digits(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_nbrlen(const char *str);
int		ft_putuint(unsigned long n, int base);
int		ft_uintlen(unsigned long n, int base);

#endif