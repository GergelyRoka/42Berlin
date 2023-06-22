# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groka <groka@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 20:26:36 by tnakajo           #+#    #+#              #
#    Updated: 2023/06/22 03:00:41 by groka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_BONUS	= checker
CC			= cc -Wall -Wextra
RM			= rm -f

#libft - library
LIBFT		= libft.a
LIBFT_DIR	= ./libft
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

SRCS	=	push_swap.c \
			argument_validation/argument_validation.c \
			linked_list/create_node.c \
			linked_list/create_stack.c \
			linked_list/free_stack.c \
			rules/swap.c \
			rules/push.c \
			rules/rotate.c \
			rules/reverse_rotate.c \
			turk_method/turk_method.c \
			turk_method/sort_three.c \
			turk_method/push_form_a_to_b.c \
			turk_method/is_ordered.c \
			turk_method/is_sorted.c \
			turk_method/fill_moves_n_steps.c \
			turk_method/position_in_b.c \
			turk_method/distance_from_top.c \
			turk_method/position_in_a.c \
			turk_method/size_of_stack.c \
			turk_method/empty_b.c \
			turk_method/finish_a.c \

SRCS_BONUS	=	bonus/checker_bonus.c \
				bonus/get_next_line/get_next_line_bonus.c \
				bonus/get_next_line/get_next_line_utils_bonus.c \
				bonus/rules/push_bonus.c \
				bonus/rules/rotate_bonus.c \
				bonus/rules/reverse_rotate_bonus.c \
				bonus/rules/swap_bonus.c \
				argument_validation/argument_validation.c \
				linked_list/create_node.c \
				linked_list/create_stack.c \
				linked_list/free_stack.c \
				turk_method/is_sorted.c \

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

DEPS	=	push_swap.h \
			push_swap_types.h \
			argument_validation.h \
			linked_list/linked_list.h \
			rules/rules.h \
			turk_method/turk_method.h \

DEPS_BONUS	=	bonus/rules/rules.h \
				bonus/get_next_line/get_next_line_bonus.h \
				argument_validation/argument_validation.h \
				linked_list/linked_list.h \
				turk_method/turk_method.h \

%.o: %.c
		$(CC) -c -o $@ $<

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $@ $(LIBFT)

all: $(NAME) $(NAME_BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)
	mv $(LIBFT_PATH) ./


$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(OBJS_BONUS) -o $@ $(LIBFT)

bonus: $(NAME_BONUS)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(LIBFT)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
