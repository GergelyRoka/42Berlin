# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groka <groka@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 16:51:14 by groka             #+#    #+#              #
#    Updated: 2023/05/17 19:00:58 by groka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror

RM	= rm -f

#libft - library
LIBFT		= libft.a
LIBFT_DIR	= ./libft
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

#ft_printf - library
PRINTF		= libftprintf.a
PRINTF_DIR	= ./ft_printf
PRINTF_PATH	= $(PRINTF_DIR)/$(PRINTF)

#server
NAME_S = server
SRC_NAME_S = server.c
OBJ_NAME_S = $(SRC_NAME_S:.c=.o)
#client
NAME_C = client
SRC_NAME_C = client.c client_extend.c
OBJ_NAME_C = $(SRC_NAME_C:.c=.o)

#bonus part - server
NAME_S_B = server_bonus
SRC_NAME_S_B = server_bonus.c
OBJ_NAME_S_B = $(SRC_NAME_S_B:.c=.o)
#bonus part - client
NAME_C_B = client_bonus
SRC_NAME_C_B = client_bonus.c client_extend_bonus.c
OBJ_NAME_C_B = $(SRC_NAME_C_B:.c=.o)

%.o: %.c
		$(CC) -c -o $@ $<

#first rule
all:	$(NAME_S) $(NAME_C)

$(LIBFT):
	make -C $(LIBFT_DIR)
	mv $(LIBFT_PATH) ./

$(PRINTF):
	make -C $(PRINTF_DIR)
	mv $(PRINTF_PATH) ./

$(NAME_S): $(OBJ_NAME_S) $(LIBFT) $(PRINTF)
	$(CC) -o $@ $^

$(NAME_C): $(OBJ_NAME_C) $(LIBFT) $(PRINTF)
	$(CC) -o $@ $^

$(NAME_S_B): $(OBJ_NAME_S_B) $(LIBFT) $(PRINTF)
	$(CC) -o $@ $^

$(NAME_C_B): $(OBJ_NAME_C_B) $(LIBFT) $(PRINTF)
	$(CC) -o $@ $^

bonus:	$(NAME_S_B) $(NAME_C_B)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	$(RM) $(OBJ_NAME_S) $(OBJ_NAME_C)
	$(RM) $(OBJ_NAME_S_B) $(OBJ_NAME_CB)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	$(RM) $(LIBFT)
	$(RM) $(PRINTF)
	$(RM) $(OBJ_NAME_S) $(OBJ_NAME_C)
	$(RM) $(OBJ_NAME_S_B) $(OBJ_NAME_C_B)
	$(RM) $(NAME_S) $(NAME_C)
	$(RM) $(NAME_S_B) $(NAME_C_B)

re: fclean all

.PHONY: all clean fclean re bonus 
