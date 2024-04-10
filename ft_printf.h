/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:33 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/10 18:35:18 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

// A supprimer
# include <stdio.h>

typedef struct s_formatspec
{
	int		dash;
	int		zero;
	int		hash;
	int		blank;
	int		plus;
	size_t	width;
	size_t	precision;
	char	specifier;
}	t_formatspec;

// Libft
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);

// ft_printf
int		ft_printf(const char *format, ...);

void	ft_putadd_hex_fd(void *ptr, int fd);
void	ft_putnbr_hexlow_fd(long unsigned int n, int fd);
void	ft_putnbr_hexup_fd(long unsigned int n, int fd);
#endif