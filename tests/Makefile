# -------------------------------- VARIABLES --------------------------------- #

EXEC			=	output

CC				=	cc
RM				=	rm
RMFLAGS			=	-rf

HFILES_DIR		=	../includes/

MSRCS			=	mandatory_tests
BSRCS			=	bonus_tests
CSRCS			=	custom_tests
MSRCS_FILES		=	$(addsuffix .c, $(MSRCS))
BSRCS_FILES		=	$(addsuffix .c, $(BSRCS))
CSRCS_FILES		=	$(addsuffix .c, $(CSRCS))
MOBJS			=	$(addsuffix .o, $(MSRCS))
BOBJS			=	$(addsuffix .o, $(BSRCS))
COBJS			=	$(addsuffix .o, $(CSRCS))

PRINTF_PATH		=	..
PRINTF			=	$(PRINTF_PATH)/libftprintf.a

# ---------------------------------- RULES ----------------------------------- #

.c.o: 
				@$(CC) $(CFLAGS) -c -I $(HFILES_DIR) $< -o $@

all:			a

a:				m b

m:				$(MSRCS_FILES) $(MOBJS)
ifneq ("$(wildcard $(PRINTF))","")
	@$(RM) $(RM_FLAGS) $(PRINTF)
endif
				@make -C >/dev/null $(PRINTF_PATH)
				@$(CC) $(MOBJS) -I $(HFILES_DIR) $(PRINTF) -o $(EXEC) -g
				@./$(EXEC)

b:				$(BSRCS_FILES) $(BOBJS)
				@make -C >/dev/null $(PRINTF_PATH) bonus
				@$(CC) $(BOBJS) -I $(HFILES_DIR) $(PRINTF) -o $(EXEC) -g
				@./$(EXEC)

custom:			$(CSRCS_FILES) $(COBJS)
				@make -C >/dev/null $(PRINTF_PATH) bonus
				@$(CC) $(COBJS) -I $(HFILES_DIR) $(PRINTF) -o $(EXEC) -g
				@./$(EXEC)

clean:
				@make -C >/dev/null $(PRINTF_PATH) clean
				@$(RM) $(RMFLAGS) $(MOBJS) $(BOBJS) $(COBJS)

fclean:			clean
				@make -C >/dev/null $(PRINTF_PATH) fclean
				@$(RM) $(RMFLAGS) $(EXEC)

re:				fclean all

.PHONY:			all a m b custom clean fclean re
