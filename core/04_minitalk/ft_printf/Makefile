# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groka <groka@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 17:12:44 by groka             #+#    #+#              #
#    Updated: 2023/02/09 18:01:48 by groka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CCFLAG = -Wall -Wextra -Werror

AR = ar
ARFLAG = crs

RM = rm -f

DEPS = ./ft_printf.h \
		./_writes/writes.h \

SRCS = ./ft_printf.c \
		./_writes/my_putchr.c \
		./_writes/my_putstr.c \
		./_writes/my_putp.c \
		./_writes/my_putdint.c \
		./_writes/my_putint.c \
		./_writes/my_putuint.c \
		./_writes/my_putxint.c \
		./_writes/my_putXint.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(DEPS)
	$(CC) $(CCFLAG) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAG) $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ${NAME}

re: fclean all

.PHONY: all clean fclean re