# -------------------------------- VARIABLES --------------------------------- #
NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS			=	rc
RM				=	rm
RMFLAGS			=	-rf

SRCS_DIR		=	./srcs/
SRCS_FILES		=	ft_atoi_digits.c \
					ft_putchar.c \
					ft_putstr.c \
					ft_nbrlen.c \
					formatspec.c \
					specsargs.c \
					ft_printf.c
SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))

HFILES_DIR		=	./includes/

OFILES			=	$(SRCS:.c=.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

# -------------------------------- RULES --------------------------------- #

.c.o: 
				${CC} ${CFLAGS} -c -I ${HFILES_DIR} $< -o $@

all:			${NAME}

bonus:			all

${LIBFT}:
				make -C ${LIBFT_PATH} all

${NAME}: 		${LIBFT} ${OFILES}
				cp ${LIBFT} ${NAME}
				${AR} ${ARFLAGS} ${NAME} ${OFILES}

clean:
				make -C ${LIBFT_PATH} clean
				${RM} ${RMFLAGS} ${OFILES}

fclean:			clean
				make -C ${LIBFT_PATH} fclean
				${RM} ${RM_FLAGS} ${NAME}

re:				fclean all

.PHONY:			all bonus clean fclean re libft
