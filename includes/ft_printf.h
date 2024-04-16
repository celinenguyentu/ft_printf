/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:33 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/16 14:46:39 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

// A supprimer
# include <stdio.h>

# if defined (__linux__)
#  define PTRNULL "(nil)"
# elif defined (__APPLE__)
#  define PTRNULL "0x0"
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

// Libft
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);

int		ft_atoi_digits(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *s);

// utils
int		ft_nbrlen(const char *str);

// Maybe libft



// ft_printf
int		ft_printf(const char *format, ...);


// specsargs
void	fetch_next_args(t_formatspec *specs, va_list *args);

// formatspec
//void			print_formatspec(t_formatspec specs);
void			init_formatspec(t_formatspec *specs);
const char		*read_flags(const char *format, t_formatspec *specs);
const char		*read_width(const char *format, t_formatspec *specs);
const char		*read_precision(const char *format, t_formatspec *specs);
t_formatspec	get_formatspec(const char *format);


#endif