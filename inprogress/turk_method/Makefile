# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groka <groka@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 20:26:36 by tnakajo           #+#    #+#              #
#    Updated: 2023/06/16 08:35:54 by groka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
# CFLAGS	= -Wall -Werror -Wextra
CFLAGS	= -Wall -Wextra
NAME	= push_swap
## CHECKER = checker

SRCS	= checkers.c \
			create_array.c \
			operations.c \
			push_swap.c \
			sort_3.c \
			sort_5.c \
			sort_big.c \
			utils.c \
			turk_method/turk_method.c \
			turk_method/push_form_a_to_b.c \
			turk_method/is_ordered.c \
			turk_method/fill_moves_n_steps.c \
			turk_method/position_in_b.c \
			turk_method/distance_from_top.c \
			turk_method/position_in_a.c \

OBJS	= $(SRCS:.c=.o)

DEPS	=	./push_swap.h \
			/turk_method/turk_method.h

%.o: %.c
		$(CC) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
