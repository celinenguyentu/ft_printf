# -------------------------------- VARIABLES --------------------------------- #

NAME			=	libftprintf.a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS			=	rc
RM				=	rm
RMFLAGS			=	-rf

HFILES_DIR		=	./includes/

SRCS_DIR		=	./srcs/
ASRCS_FILES		=	ft_atoi_digits.c \
					ft_nbrlen.c \
					ft_putchar.c \
					ft_putnchar.c \
					ft_putnstr.c \
					ft_putuint.c \
					ft_uintlen.c \
					ft_printf.c \
					ft_vprintf.c \
					print_arg.c \
					print_char.c \
					print_str.c \
					print_ptr.c \
					print_int.c \
					print_uint.c \
					print_percent.c \
					print_unknown.c \
					print_intprefix.c \
					init_formatspecs.c \
					reset_formatspecs.c \
					clean_formatspecs.c \
					precision_overflow_handler.c \
					check.c 
ASRCS			=	$(addprefix $(SRCS_DIR), $(ASRCS_FILES))

MSRCS_FILES		=	update_formatspecs.c 
MSRCS 			=	$(addprefix $(SRCS_DIR), $(MSRCS_FILES))

BSRCS_FILES		=	update_formatspecs_bonus.c
BSRCS			=	$(addprefix $(SRCS_DIR), $(BSRCS_FILES))

AOBJS			=	$(ASRCS:.c=.o)
MOBJS			=	$(MSRCS:.c=.o)
BOBJS			=	$(BSRCS:.c=.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

# ---------------------------------- RULES ----------------------------------- #

.c.o: 
				@$(CC) $(CFLAGS) -c -I $(HFILES_DIR) $< -o $@

all:			$(NAME)

$(LIBFT):
				@make -C $(LIBFT_PATH) all

$(NAME): 		$(LIBFT) $(AOBJS) $(MOBJS) 
				@cp $(LIBFT) $(NAME)
				@$(AR) $(ARFLAGS) $(NAME) $(AOBJS) $(MOBJS)
				@echo "Created library libftprintf.a (mandatory version)."

bonus:			$(LIBFT) $(AOBJS) $(BOBJS)
				@cp $(LIBFT) $(NAME)
				@$(AR) $(ARFLAGS) $(NAME) $(AOBJS) $(BOBJS)
				@echo "Created library libftprintf.a (bonus+ version)."

clean:
				@make -C $(LIBFT_PATH) clean
				@$(RM) $(RMFLAGS) $(AOBJS) $(MOBJS) $(BOBJS)

fclean:			clean
				@make -C $(LIBFT_PATH) fclean
				@$(RM) $(RMFLAGS) $(NAME)
				@echo "Removed libftprintf.a."

re:				fclean all

.PHONY:			all bonus clean fclean re libft
