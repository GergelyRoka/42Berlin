# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groka <groka@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 19:24:27 by groka             #+#    #+#              #
#    Updated: 2023/09/09 20:21:59 by groka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		:= philo
CC			:= cc
FLAGS		:= -Wall -Wextra -Werror
HEADER		:= includes/philosophers.h
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      src/printing/printing.c \
						  src/creates_n_frees/create_philosophers.c \
						  src/creates_n_frees/free_everything.c \
						  src/creates_n_frees/create_threads.c \
						  src/creates_n_frees/create_forks.c \
						  src/creates_n_frees/free_philosophers.c \
						  src/creates_n_frees/release_the_beasts.c \
						  src/creates_n_frees/free_forks.c \
						  src/creates_n_frees/free_threads.c \
						  src/creates_n_frees/creation.c \
						  src/timing/timing.c \
						  src/argumentum/ft_strcmp.c \
						  src/argumentum/argumentum.c \
						  src/argumentum/ft_itoa.c \
						  src/argumentum/ft_atoi.c \
						  src/philosopher/do_sleep.c \
						  src/philosopher/do_eat.c \
						  src/philosopher/do_think.c \
						  src/philosopher/philosopher.c \
						  src/main.c \
						  
OBJS        := $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


