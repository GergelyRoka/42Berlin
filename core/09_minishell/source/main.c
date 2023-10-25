/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saimar <saimar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:53:16 by saimar            #+#    #+#             */
/*   Updated: 2023/08/26 18:53:16 by saimar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	main_loop(void);
static int	main_core(char *line);

int	main(int ac, char **av, char **envp)
{
	if (!isatty(STDIN_FILENO))
		return (error_msg("Please launch from terminal."), 1);
	if (ac != 1 || av[1])
		return (error_msg("We want NO argument, ok?"), 1);
	set_the_central(store_envp(envp), ac, av);
	if (dup_std_fds() == false)
		return (error_msg("exit error (dup)"), 42);
	signals();
	main_loop();
	rl_clear_history();
	free_central(get_central());
	return (0);
}

static void	main_loop(void)
{
	char	*line;

	line = NULL;
	while (1)
	{
		get_central()->old_status = get_central()->status;
		get_central()->status = 0;
		if (main_core(line) == -1)
			break ;
	}
}

static int	main_core(char *line)
{
	free(line);
	line = readline(PROMPT);
	if (line && line[0] == 0)
		;
	else if (line)
		add_history(line);
	else
		return (printf("exit\n"), -1);
	if (!valid_by_lexer(line))
	{
		error_msg("Invalid command line");
		return (reset(), 0);
	}
	get_central()->lexer = input_lexer(line);
	if (!is_valid_op(get_central()->lexer))
	{
		error_msg("Syntax error");
		return (reset(), 0);
	}
	parser(get_central(), get_central()->lexer);
	executor(get_central());
	return (reset(), 0);
}

//ENVP: just store the double pointer **envp in central

/*char **envp:  stands for "environment pointer" and 
is an array of strings (character pointers) that hold the 
environment variables passed to the program*/

/*
int isatty(int file_descriptor);
 a C library function that checks
whether a given file descriptor is 
associated with a terminal. Its 
purpose is to determine whether 
the file descriptor corresponds 
to an interactive terminal session, 
which typically means that a person 
is using the program interactively 
through a command-line interface.

Library: unistd.h
*/