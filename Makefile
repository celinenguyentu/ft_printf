# -------------------------------- VARIABLES --------------------------------- #
NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS			=	rcs
RM				=	rm
RMFLAGS			=	-rf

HFILES_DIR		=	./includes/

SRCS_DIR		=	./srcs/
ASRCS_FILES		=	ft_atoi_digits.c \
					ft_nbrlen.c \
					ft_putchar.c \
					ft_putstr.c \
					ft_putuint.c \
					ft_uintlen.c \
					ft_printf.c \
					print_arg.c \
					print_char.c \
					print_str.c \
					print_ptr.c \
					print_int.c \
					print_uint.c \
					print_percent.c \
					print_unknown.c \
					print_intprefix.c \
					init_formatspec.c \
					clean_formatspec.c \
					specsargs.c 
ASRCS			=	$(addprefix $(SRCS_DIR), $(ASRCS_FILES))

MSRCS_FILES		=	get_formatspec.c 
MSRCS 			=	$(addprefix $(SRCS_DIR), $(MSRCS_FILES))

BSRCS_FILES		=	get_formatspec_bonus.c
BSRCS			=	$(addprefix $(SRCS_DIR), $(BSRCS_FILES))

AOBJS			=	$(ASRCS:.c=.o)
MOBJS			=	$(MSRCS:.c=.o)
BOBJS			=	$(BSRCS:.c=.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

# -------------------------------- RULES --------------------------------- #

.c.o: 
				${CC} ${CFLAGS} -c -I ${HFILES_DIR} $< -o $@

all:			${NAME}

${LIBFT}:
				make -C ${LIBFT_PATH} all

${NAME}: 		${LIBFT} ${AOBJS} ${MOBJS}
				cp ${LIBFT} ${NAME}
				${AR} ${ARFLAGS} ${NAME} ${AOBJS} ${MOBJS}

bonus:			${LIBFT} ${AOBJS} ${BOBJS}
				cp ${LIBFT} ${NAME}
				${AR} ${ARFLAGS} ${NAME} ${AOBJS} ${BOBJS}

clean:
				make -C ${LIBFT_PATH} clean
				${RM} ${RMFLAGS} ${AOBJS} ${MOBJS} ${BOBJS}

fclean:			clean
				make -C ${LIBFT_PATH} fclean
				${RM} ${RM_FLAGS} ${NAME}

re:				fclean all

.PHONY:			all bonus clean fclean re libft
