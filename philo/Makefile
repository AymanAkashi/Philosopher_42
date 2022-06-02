# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 03:54:31 by akashi            #+#    #+#              #
#    Updated: 2022/06/01 16:52:48 by aaggoujj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *********************************** Colors ***********************************
NC				:= \033[m
RED				:= \033[0;31m
GREEN			:= \033[1;32m
YELLOW			:= \033[1;33m
BLUE			:= \033[0;34m
PURPLE			:= \033[1;35m
CYAN			:= \033[1;36m

# ******************************** Directories *********************************
OBJ_DIR			:= obj

# *********************************** Files ************************************
NAME			:= philo
SRC				:= allocation.c\
					check_arg.c\
					create_treads.c\
					ft_free.c\
					ft_routine.c\
					init_data.c\
					mutex.c\
					operation.c\
					philo.c\
					w_operation.c\

OBJ				:= $(SRC:.c=.o)
INC				:= .

# ****************************** Compiler Options ******************************
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -g

# ******************************* Other commands *******************************
RM				:= rm -rf
MKDIR			:= mkdir -p

# ******************************** Dependencies ********************************
OBJ_DEP			:= $(addprefix $(OBJ_DIR)/, $(OBJ))
INC_DEP			:= philosopher.h

# ********************************** Targets ***********************************
all: $(NAME)

$(NAME): $(OBJ_DEP) $(INC_DEP)
	@echo "$(BLUE)Building	$(PURPLE)$(NAME)$(NC)"
	@$(CC) $(CFLAGS) $(LIBFLAGS) $(OBJ_DEP) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(INC_DEP)
	@$(MKDIR) $(OBJ_DIR)
	@echo "$(GREEN)Compiling	$(YELLOW)$(shell basename $<)$(NC)"
	@$(CC) $(CFLAGS) $(INCFLAGS) -c -o $@ $<

clean:
	@echo "$(RED)Removing	$(YELLOW)Object files$(NC)"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing	$(PURPLE)$(NAME)$(NC)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re