# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groka <groka@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 22:27:38 by saimar            #+#    #+#              #
#    Updated: 2023/10/12 20:00:41 by groka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell

#DIRECTORIES
SRCDIR	:= source
INCDIR	:= include
OBJDIR	:= obj
SUBDIR	:= utils lexer parser expander executor builtins central signals error
LIBDIR	:= libft

#LIBRARIES
LIBFT	:= $(LIBDIR)/libft.a

#SOURCES
SRC		:= main.c \
			central/central.c \
			central/central_utils.c \
			central/free_central.c \
			builtins/do_env.c \
			builtins/do_pwd.c \
			builtins/do_echo.c \
			builtins/do_exit.c \
			builtins/do_cd.c \
			builtins/do_unset.c \
			builtins/do_export.c \
			lexer/lexer.c \
			lexer/lexer_utils_b.c \
			lexer/lexer_utils_a.c \
			parser/parser.c \
			parser/parser_utils.c \
			expander/expander.c \
			expander/expander_utils.c \
			executor/executor.c \
			executor/heredoc.c \
			executor/heredoc_to_files.c \
			executor/heredoc_do.c \
			executor/file_opening.c \
			executor/single_cmd.c \
			executor/multi_cmd.c \
			executor/multi_cmd_child.c \
			executor/f_make_cmd_args.c \
			executor/f_is_executable.c \
			executor/set_redirections.c \
			signals/signals.c \
			signals/signal_child.c \
			utils/free_all.c \
			utils/envp_handlers.c \
			utils/my_unsetenv.c \
			utils/free.c \
			utils/free_lexer.c \
			utils/free_for_redir.c \
			utils/ft_atoll.c \
			utils/ft_atol.c \
			utils/ft_ltoa.c \
			utils/reset.c \
			error/error_exit.c \
			error/error_msg.c \

SRCS	:=	$(addprefix $(SRCDIR)/, $(SRC))

#OBJECTS
OBJS	:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

#HEADERS
HEADER	:=	minishell.h
HEADERS	:=	$(addprefix $(INCDIR)/, $(HEADER))
LIBFTH	:=	$(addprefix $(LIBDIR)/, libft.h)

#FLAGS
CFLAGS	:=	-Wall -Wextra -Werror -I$(INCDIR) -I$(LIBDIR)
#-ggdb3 #-fsanitize=address
#debug: CFLAGS += -ggdb3 
LDLIBS	:=	-L$(LIBDIR) -lft -lreadline

#CMDS
CC		:=	cc
RM		:=	/bin/rm -rf
MUTE	:=	>/dev/null

#RULES
.PHONY: all clean debug fclean re run val

all: $(NAME)

$(NAME): $(HEADERS) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)
	
$(LIBFT): $(LIBFTH)
	$(MAKE) -C $(LIBDIR) all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR) && cd $(OBJDIR) && mkdir -p $(SUBDIR)
	$(CC) $(CFLAGS) -c $< -o $@

debug: $(NAME)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBDIR) $@ $(MUTE)

fclean: clean
	@$(MAKE) -C $(LIBDIR) $@ $(MUTE)
	$(RM) $(OBJDIR)
	$(RM) $(NAME)

re: fclean all

#run:
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./minishell

#val:
#	valgrind --suppressions=my_supp.supp --leak-check=full --show-leak-kinds=all --log-file="log" ./minishell

#valgrind --suppressions=my_supp.supp --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="log" ./minishell
