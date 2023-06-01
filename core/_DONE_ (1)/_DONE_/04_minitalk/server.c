/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:12:45 by groka             #+#    #+#             */
/*   Updated: 2023/05/17 19:18:36 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_connection	g_conn;

static void	start(void);
static void	handler(int sig, siginfo_t *info, void *context);
static void	signal_to_char(int sig, pid_t client);
void		banner(void);

static void	signal_to_char(int sig, pid_t client)
{
	g_conn.active = 1;
	g_conn.c = g_conn.c << 1;
	if (sig == SIGUSR1)
		g_conn.c = g_conn.c | 0b1;
	if (++g_conn.n >= 8)
	{
		if (g_conn.c == 0)
		{
			kill(client, SIGUSR2);
			ft_printf(BOLD GREEN "\n\nSuccessful transmission!\n" RESET);
			ft_printf("The size of the message is "
				BOLD WHITE "%u" RESET " bytes.\n\n", g_conn.len);
			start();
		}
		else
		{
			++g_conn.len;
			write(1, &g_conn.c, 1);
		}
		g_conn.c = 0;
		g_conn.n = 0;
	}
	kill(client, SIGUSR1);
}

static void	handler(int sig, siginfo_t *info, void *context)
{
	sigaddset(&g_conn.sigact.sa_mask, SIGUSR1);
	sigaddset(&g_conn.sigact.sa_mask, SIGUSR2);
	(void)context;
	signal_to_char(sig, info->si_pid);
	sigemptyset(&g_conn.sigact.sa_mask);
}

static void	start(void)
{
	ft_printf("🦊 Server pid is "
		BOLD RED "%i" RESET ".\n", getpid());
	ft_printf("Waiting for the next message...\n\n" YELLOW);
	g_conn.len = 0;
	g_conn.c = 0;
	g_conn.n = 0;
	g_conn.active = 0;
	sigemptyset(&g_conn.sigact.sa_mask);
	g_conn.sigact.sa_sigaction = handler;
	g_conn.sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &g_conn.sigact, 0);
	sigaction(SIGUSR2, &g_conn.sigact, 0);
}

int	main(void)
{
	banner();
	start();
	while (1)
	{
		if (usleep(100000) == 0 && g_conn.active == 1)
		{
			ft_printf(BOLD RED "\n\nERROR:" RESET
				"Something went wrong with the connection.\n");
			ft_printf(WHITE BOLD "%i" RESET " bytes received.\n\n", g_conn.len);
			start();
		}
	}
}

void	banner(void)
{
	ft_printf(STYLE_0
		STYLE_0 "                                      " RESET "\n"
		STYLE_0 "     ___  ___ _ ____   _____ _ __     " RESET "\n"
		STYLE_0 "    / __|/ _ \\ '__\\ \\ / / _ \\ '__|    " RESET "\n"
		STYLE_0 "    \\__ \\  __/ |   \\ V /  __/ |       " RESET "\n"
		STYLE_0 "    |___/\\___|_|    \\_/ \\___|_|       " RESET "\n"
		STYLE_0 "                                      " RESET "\n"
		STYLE_0 "                                      " RESET "\n");
}
