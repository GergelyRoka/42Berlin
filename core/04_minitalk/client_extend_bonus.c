/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_extend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:24:22 by groka             #+#    #+#             */
/*   Updated: 2023/05/14 22:03:07 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

extern t_connection	g_conn;

void	error(char *error_msg)
{
	ft_printf(RED BOLD "FAILED!\n" RESET);
	ft_printf(RED BOLD "ERROR: " RESET
		"%s\n", error_msg);
	ft_printf("Buuut " WHITE BOLD "%i" RESET
		" bytes were succesfully sent.\n", g_conn.len);
	exit(0);
}

int	waiting_for_sig(void)
{
	if (g_conn.waiter == 0)
		return (0);
	if (g_conn.waiter++ > 100)
		error("Client didn't receive a signal from the server in time.");
	return (g_conn.waiter);
}

void	argumentum_check(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf(RED BOLD "ERROR: " RESET
			"The client needs 2 arguemnts: <server pid> <message>\n");
		exit(0);
	}
	else if (!(ft_atoi(argv[1]) > 0))
	{
		ft_printf(RED BOLD "ERROR: " RESET
			"The server pid must be a valid PID of the server.\n");
		exit(0);
	}
}

void	banner(void)
{
	ft_printf(STYLE_1
		STYLE_1 "           _ _            _         " RESET "\n"
		STYLE_1 "       ___| (_) ___ _ __ | |_       " RESET "\n"
		STYLE_1 "      / __| | |/ _ \\ '_ \\| __|      " RESET "\n"
		STYLE_1 "     | (__| | |  __/ | | | |_       " RESET "\n"
		STYLE_1 "      \\___|_|_|\\___|_| |_|\\__|      " RESET "\n"
		STYLE_1 "                                    " RESET "\n\n");
}
