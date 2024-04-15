NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_isdigit.c \
		ft_strlen.c \
		ft_strchr.c \
		ft_atoi.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_nbrlen.c \
		formatspec.c \
		ft_printf.c

#SRCS_BONUS = 	

HFILES = ft_printf.h

OFILES = $(SRCS:.c=.o)

#OFILES_BONUS = $(SRCS_BONUS:.c=.o)

all: ${NAME}

${NAME}: ${OFILES}
	ar rc ${NAME} ${OFILES}

#bonus : ${OFILES} ${OFILES_BONUS}
#	ar rc ${NAME} ${OFILES} ${OFILES_BONUS}

clean:
	rm -rf ${OFILES}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
