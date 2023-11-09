/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:12:42 by groka             #+#    #+#             */
/*   Updated: 2023/05/17 19:12:28 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
//write
//pid_t getpid(void);
//int pause(void);
//unsigned int sleep(unsigned int seconds);
//int usleep(useconds_t usec);

# include <signal.h>
//signal
//sighandler_t signal(int signum, sighandler_t handler);
//int sigemptyset(sigset_t *set);
//int sigaddset(sigset_t *set, int signum);
//int sigaction(int signum, const struct sigaction *act, 
//													struct sigaction *oldact);
//int kill(pid_t pid, int sig);

# include <stdlib.h>
//void *malloc(size_t size);
//void free(void *ptr);
//void exit(int status);

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define BLACK    "\033[30m"
# define RED      "\033[31m"
# define GREEN    "\033[32m"
# define YELLOW   "\033[33m"
# define BLUE     "\033[34m"
# define MAGENTA  "\033[35m"
# define CYAN     "\033[36m"
# define WHITE    "\033[37m"

# define BLACK_BG    "\033[40m"
# define RED_BG      "\033[41m"
# define GREEN_BG    "\033[42m"
# define YELLOW_BG   "\033[43m"
# define BLUE_BG     "\033[44m"
# define MAGENTA_BG  "\033[45m"
# define CYAN_BG     "\033[46m"
# define WHITE_BG    "\033[47m"

# define RESET       "\033[0m"

# define STYLE_0	"\033[31m\033[40m\033[1m"
# define STYLE_1	"\033[35m\033[40m\033[1m"

# define BOLD        "\033[1m"
# define DIM         "\033[2m"
# define ITALIC      "\033[3m"
# define UNDERLINE   "\033[4m"
# define BLINK       "\033[5m"
# define REVERSE     "\033[7m"
# define HIDDEN      "\033[8m"

typedef struct s_connection
{
	struct sigaction	sigact;
	struct sigaction	sigact2;
	unsigned int		len;
	char				c;
	int					n;
	int					active;
	long long			sent_bit;
	long long			received_bit;
	int					waiter;
}						t_connection;

#endif
