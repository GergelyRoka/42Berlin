/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:38:03 by saimar            #+#    #+#             */
/*   Updated: 2023/10/12 19:55:26 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define TO_MANY_ARGS " too many arguments"
#define MSG_CDERROR " : No such file or directory or any other errors"
#define NO_HOME "NO HOME *sad face*"
#define NO_HOME_KEY "not able to go HOME"

static int	e_msg(t_central *central, char *name, char *msg);

/**
 * @note: no update for PATH/OLD_PATH of envp
 */
int	do_cd(t_central *central, t_cmd *cmd)
{
	char	*path;
	char	buffer[BUFFER_SIZE];

	if (cmd->words->next == NULL)
	{
		path = my_getenv("HOME");
		if (!path)
			return (e_msg(central, NULL, NO_HOME));
		if (chdir(path) == -1)
			return (e_msg(central, NULL, NO_HOME_KEY));
		my_setenv("OLDPWD", my_getenv("PWD"));
		my_setenv("PWD", path);
	}
	if (cmd->words->next && cmd->words->next->next)
		return (e_msg(central, NULL, TO_MANY_ARGS));
	if (cmd->words->next && cmd->words->next->content)
	{
		path = (char *)cmd->words->next->content;
		if (chdir(path) == -1)
			return (e_msg(central, cmd->words->next->content, MSG_CDERROR));
		my_setenv("OLDPWD", my_getenv("PWD"));
		my_setenv("PWD", getcwd(buffer, BUFFER_SIZE));
	}
	return (0);
}

static int	e_msg(t_central *central, char *name, char *msg)
{
	ft_putstr_fd(MAGENTA "Minishell" RESET ": cd: ", STDERR_FILENO);
	if (name)
		ft_putstr_fd(name, STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (central->status = 1);
}
