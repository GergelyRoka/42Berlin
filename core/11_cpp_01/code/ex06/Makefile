# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groka <groka@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 12:44:59 by groka             #+#    #+#              #
#    Updated: 2023/11/15 03:38:02 by groka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		:= harlFilter
CC			:= c++
FLAGS		:= -Wall -Wextra -Werror -std=c++98
INCLUDE	= -I./includes
VPATH		= sources

OBJ_DIR = objects
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

GENERAL = main Harl

SRCS	=	$(addsuffix .cpp, $(GENERAL))\

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -rf



all:		${NAME} ${SRCS}

$(OBJ_DIR):
	mkdir -p objects

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE)

${NAME}:	$(OBJ_DIR) $(OBJS)
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ ${RM} $(OBJ_DIR)
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

run:		all clean
			./$(NAME)

.PHONY:		all clean fclean re run
