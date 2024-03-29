
-include ./Config/Sources.mk
-include ./Config/Header.mk

#################################################################################
#									Colors										#
#################################################################################

GREY		= \033[4;34m
RED			= \033[1;31m
GREEN		= \033[3;32m
YELLOW		= \033[2;49;33m
BLUE		= \033[4;34m
BLUEE		= \033[3;34m
PURPLE		= \033[3;35m
CYAN		= \033[3;36m
RESET		= \033[0m
ICONOK		= \033[1;32m
ICONKO		= \033[1;31m
CO_DELET	= \033[4;31m
CO_A_OUT	= \033[96m
WHITE		= \033[1;49;97m


#################################################################################
#									Variables									#
#################################################################################

NAME		= philo
OBJS		= $(SRCS:%.c=%.o)
# LIBFT		= libft/libft.a
CFLAGS		= -Wall -Werror -Wextra -glldb -I ./Includes #-lpthread#
OBJ_DIR 	= Objects
OBJ_PATH	= $(addprefix $(OBJ_DIR)/, $(OBJS))


#################################################################################
#									Compilation Objects							#
#################################################################################

$(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	@mkdir -p $(@D)
	@gcc $(CFLAGS) -c $< -o $@
	@printf "\033[2K\r$(PURPLE)$<: $(CYAN)loading..$(RESET)"

#################################################################################
#									Compilation C								#
#################################################################################

$(NAME): $(OBJ_PATH) $(HEADER)
#	@$(MAKE) -C libft/
	@gcc $(CFLAGS) $(OBJ_PATH) -o $(NAME)
	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n"

all: gmk $(NAME) $(HEADER)

#################################################################################
#									Prerequis									#
#################################################################################

# $(LIBFT):
# 	$(MAKE) -C libft/

$(OBJ_DIR):
	@printf "\033[1;32mCreate OBJS_DIR $(CO_DELET)\033[3;32m [√]\033[0m\n"

#################################################################################
#									Clean										#
#################################################################################

clean:
	@$(RM) $(OBJ_PATH)
	@printf "\033[1;31mDelete OBJS $(CO_DELET)$(NAME)\033[3;32m [√]\033[0m\n"

fclean:
	@$(RM) $(OBJ_PATH)
	@$(RM) $(NAME)
	@$(RM) -rf $(NAME).dSYM a.out
	@printf "\033[1;31mDelete $(CO_DELET)$(NAME)\033[3;32m [√]\033[0m\n"

#################################################################################
#									Gen MK										#
#################################################################################

gmk:
	@echo "SRCS += " > ./Config/Sources.mk
	@find Sources -name '*.c' | sed 's/^/SRCS += /' >> ./Config/Sources.mk
	@echo "HEADER += " > ./Config/Header.mk
	@find Includes -name '*.h' | sed 's/^/HEADER += /' >> ./Config/Header.mk

#################################################################################
#									Norminette									#
#################################################################################

norme:
	@printf "\033[1;36m"
	norminette -R CheckDefine ./includes/
	@printf "\n\033[1;32m"
	norminette -R CheckForbiddenSourceHeader ./sources/

#################################################################################
#									Clena & Compilation							#
#################################################################################

re: fclean all

.PHONY: re fclean clean all gmk norme
