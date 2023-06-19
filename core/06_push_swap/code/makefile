# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groka <groka@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 20:26:36 by tnakajo           #+#    #+#              #
#    Updated: 2023/06/20 00:58:59 by groka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc -Wall -Wextra -Werror
NAME	= push_swap
RM		= rm -f

#libft - library
LIBFT		= libft.a
LIBFT_DIR	= ./libft
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

SRCS	= checkers.c \
			push_swap.c \
			sort_3.c \
			sort_5.c \
			linked_list/create_node.c \
			linked_list/create_stack.c \
			linked_list/free_stack.c \
			rules/swap.c \
			rules/push.c \
			rules/rotate.c \
			rules/reverse_rotate.c \
			turk_method/turk_method.c \
			turk_method/push_form_a_to_b.c \
			turk_method/is_ordered.c \
			turk_method/fill_moves_n_steps.c \
			turk_method/position_in_b.c \
			turk_method/distance_from_top.c \
			turk_method/position_in_a.c \
			turk_method/size_of_stack.c \
			turk_method/empty_b.c \
			turk_method/finish_a.c \

OBJS	= $(SRCS:.c=.o)

DEPS	=	push_swap.h \
			push_swap_types.h \
			linked_list/linked_list.h \
			rules/rules.h \
			turk_method/turk_method.h \

%.o: %.c
		$(CC) -c -o $@ $<

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	mv $(LIBFT_PATH) ./

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $@ $(LIBFT)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
