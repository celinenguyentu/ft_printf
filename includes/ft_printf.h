/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:33 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/18 17:30:49 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

# if defined(__APPLE__)
#  define NULLPTR "0x0"
# else
#  define NULLPTR "0x0"
# endif

typedef struct s_flags
{
	int		dash; // true 1 or false 0 // %c %s %p %d %i %u %x %X
	int		zero; // true 1 or false 0  // %d %i %u %x %X
	int		hash; // true 1 or false 0 // %x %X
	int		blank; // true 1 or false 0 // %d %i 
	int		plus; // true 1 or false 0 // %d %i 
}	t_flags;

typedef struct s_formatspec
{
	t_flags	flags;
	int		width; // -1 next arg, 0 none, m > 0 value // %c %s %p %d %i %u %x %X
	int		precision; // true 1 or false 0 // %s %d %i %u %x %X
	int		precision_n; // - 1 next arg, m >= 0 value
	char	specifier; // c, s, p, d, i, u, x, X, %
	size_t	n_chars;
}	t_formatspec;

// Utility functions
int		ft_atoi_digits(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_nbrlen(const char *str);
int		put_uint(unsigned long n, int base);
int		uint_len(unsigned long n, int base);
int		print_intprefix(t_formatspec specs, int uarg_len, int negative);

// ft_printf
int		ft_printf(const char *format, ...);
int		ft_vprintf(const char *format, va_list ap);
int		print_arg(t_formatspec specs, va_list *args);
int		print_char(t_formatspec specs, va_list *args);
int		print_str(t_formatspec specs, va_list *args);
int		print_ptr(t_formatspec specs, va_list *args);
int		print_int(t_formatspec specs, va_list *args);
int		print_uint(t_formatspec specs, va_list *args);
int		print_xint(t_formatspec specs, va_list *args);

// specsargs
void	fetch_next_args(t_formatspec *specs, va_list *args);

// formatspec
t_formatspec	get_formatspec(const char *format);
void			init_formatspec(t_formatspec *specs);


#endif