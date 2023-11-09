/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:12:39 by groka             #+#    #+#             */
/*   Updated: 2023/05/17 18:49:52 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_connection	g_conn;

int		waiting_for_sig(void);
void	error(char *error_msg);
void	argumentum_check(int argc, char **argv);
void	banner(void);

static void	bb_handler(int sig)
{
	(void)sig;
	ft_printf(GREEN BOLD "SUCCEEDED!" RESET);
	ft_printf("🦊\n");
	exit(0);
}

static void	conn_handler(int sig)
{
	(void)sig;
	g_conn.waiter = 0;
	if (g_conn.active)
	{
		if (++g_conn.received_bit != g_conn.sent_bit)
			error("Anomaly between sent and received signals.");
	}
}

void	transmission_msg(char *msg, pid_t server_pid)
{
	char	c;
	char	i;

	while (*msg)
	{
		c = *msg;
		i = 0;
		while (i++ < 8)
		{
			g_conn.waiter = 1;
			++g_conn.sent_bit;
			if (c & 0b10000000)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			while (waiting_for_sig())
				usleep(10);
			c = c << 1;
		}
		++g_conn.len;
		msg++;
	}
}

static void	transmission_zero(pid_t server_pid)
{
	int	i;

	i = 8;
	g_conn.active = 0;
	while (i-- > 0)
	{
		kill(server_pid, SIGUSR2);
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	banner();
	argumentum_check(argc, argv);
	sigemptyset(&g_conn.sigact.sa_mask);
	sigemptyset(&g_conn.sigact2.sa_mask);
	g_conn.sigact.sa_handler = conn_handler;
	g_conn.sigact2.sa_handler = bb_handler;
	sigaction(SIGUSR1, &g_conn.sigact, 0);
	sigaction(SIGUSR2, &g_conn.sigact2, 0);
	g_conn.active = 1;
	ft_printf("The size of the message is "
		WHITE BOLD "%i" RESET " bytes.\n", ft_strlen(argv[2]));
	ft_printf(MAGENTA "The transmission has..." RESET);
	transmission_msg(argv[2], ft_atoi(argv[1]));
	transmission_zero(ft_atoi(argv[1]));
	error("The client did not get the bye-bye signal.");
	return (0);
}
