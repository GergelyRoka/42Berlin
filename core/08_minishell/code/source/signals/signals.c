/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:24:16 by saimar            #+#    #+#             */
/*   Updated: 2023/10/12 19:11:03 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//to do: handle interaction with child processeS
//ISSUES
//1)interaction with child processes
//right now if I do echo a | grep a ctrlC it works but then
//ctrl D does not work
//2) ctrl D does not write exit (should it?)

//a volatile sig_atomic_t variable to track received signals?
// volatile sig_atomic_t	received_signal = 0;

/*setup signal handlers*/
void	signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, catch_sigint);
}

static void	catch_sigint_part_two(void);

//ctrl + C handler
//some play with this signal bussiness
void	catch_sigint(int signum)
{
	t_cmd	*cmd;

	cmd = get_central()->cmd;
	while (cmd)
	{
		if (cmd->pid != 0)
		{
			kill(cmd->pid, SIGPIPE);
			waitpid(cmd->pid, NULL, 0);
		}
		cmd = cmd->next;
	}
	(void)signum;
	catch_sigint_part_two();
}

static void	catch_sigint_part_two(void)
{
	get_central()->old_status = 130;
	get_central()->status = 0;
	if (get_central()->cmd == NULL)
		rl_on_new_line();
	if (get_central()->cmd && get_central()->cmd->next == NULL)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		ft_putendl_fd("", get_central()->fds.std_output);
	}
	else
	{
		ft_putendl_fd("", get_central()->fds.std_output);
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signal_suspend(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}
/*
ALTERNATIVE
void signals(void) {
	struct sigaction sa;
	sa.sa_handler = SIG_IGN; // Ignore SIGQUIT
	sa.sa_flags = 0;
	sigaction(SIGQUIT, &sa, NULL);

	sa.sa_handler = sigint_handler; // Register Ctrl+C handler
	sigaction(SIGINT, &sa, NULL);

	sa.sa_handler = sigterm_handler; // Register Ctrl+D handler
	sigaction(SIGTERM, &sa, NULL);
}
*/
//SIGQUIT ctrl + '\'