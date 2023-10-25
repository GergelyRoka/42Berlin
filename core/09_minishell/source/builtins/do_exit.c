/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:56:51 by saimar            #+#    #+#             */
/*   Updated: 2023/10/12 18:41:49 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define EXIT_MSG_1 "exit : too many arguments"
#define EXIT_MSG_2A "Minishell: exit: "
#define EXIT_MSG_2B "numeric argument required"

static int	is_integer(char *arg);
static void	exit_with_clear(int code);
long		ft_atol(const char *str);
char		*ft_ltoa(long long n);

int	do_exit(t_central *central, t_cmd *cmd)
{
	(void)central;
	if (cmd->cmd_args[1] && cmd->cmd_args[2])
	{
		error_msg(EXIT_MSG_1);
		central->status = 1;
		return (1);
	}
	if (cmd->words->next)
	{
		if (cmd->next == NULL)
			printf("exit\n");
		if (is_integer(cmd->cmd_args[1]))
			exit(ft_atol(cmd->cmd_args[1]) % 256);
		error_msg_p(cmd->cmd_args[1], EXIT_MSG_2B);
		return (exit_with_clear(2), 2);
	}
	if (cmd->next == NULL)
		printf("exit\n");
	return (exit_with_clear(0), 0);
}

static int	is_integer(char *arg)
{
	long	num;
	char	*num_str;
	char	*num_str_plus;
	int		result;

	num = ft_atol(arg);
	num_str = ft_ltoa(num);
	num_str_plus = ft_strjoin("+", num_str);
	result = false;
	if (ft_strcmp(arg, num_str) == 0
		|| ft_strcmp(arg, num_str_plus) == 0)
		result = true;
	free(num_str);
	free(num_str_plus);
	return (result);
}

static void	exit_with_clear(int code)
{
	reset();
	rl_clear_history();
	free_central(get_central());
	exit (code);
}
