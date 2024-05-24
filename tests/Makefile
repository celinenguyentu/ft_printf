# -------------------------------- VARIABLES --------------------------------- #

EXEC			=	tests

CC				=	cc
RM				=	rm
RMFLAGS			=	-rf

HFILES_DIR		=	../includes/

MSRCS			=	mandatory_tests
BSRCS			=	bonus_tests
MSRCS_FILES		=	$(addsuffix .c, $(MSRCS))
BSRCS_FILES		=	$(addsuffix .c, $(BSRCS))
MOBJS			=	$(addsuffix .o, $(MSRCS))
BOBJS			=	$(addsuffix .o, $(BSRCS))

PRINTF_PATH		=	..
PRINTF			=	$(PRINTF_PATH)/libftprintf.a

# ---------------------------------- RULES ----------------------------------- #

.c.o: 
				@$(CC) $(CFLAGS) -c -I $(HFILES_DIR) $< -o $@

all:			a

a:				m b

m:				$(MSRCS_FILES) $(MOBJS)
				@make -C $(PRINTF_PATH)
				@$(CC) $(MOBJS) -I $(HFILES_DIR) $(PRINTF) -o $(EXEC)
				@./$(EXEC)

b:				$(BSRCS_FILES) $(BOBJS)
				@make -C $(PRINTF_PATH) bonus
				@$(CC) $(BOBJS) -I $(HFILES_DIR) $(PRINTF) -o $(EXEC)
				@./$(EXEC)
clean:
				@make -C $(PRINTF_PATH) clean
				@$(RM) $(RMFLAGS) $(MOBJS) $(BOBJS)

fclean:			clean
				@make -C $(PRINTF_PATH) fclean
				@$(RM) $(RM_FLAGS) $(EXEC)

re:				fclean all

.PHONY:			all a m b clean fclean re
