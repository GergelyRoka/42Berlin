/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:23:24 by groka             #+#    #+#             */
/*   Updated: 2023/10/12 19:00:35 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		non_builtin_cmd(t_central *central, t_cmd *cmd);
void	single_child(t_cmd *cmd);
char	*path_of_cmd(char *cmd);
char	*path_of_cmd_2(char *cmd);

/**
 * @brief 
 * 
 * @param central 
 * @return int 
 * 
 * @dev :	1st idea of non-builtin
 * 			checking for cmd path in child
 */
int	single_cmd(t_central *central)
{
	t_cmd	*cmd;
	int		error;

	cmd = central->cmd;
	make_cmd_args(central, cmd);
	error = set_fds_cmd(central, cmd);
	if (error != 0)
	{
		central->status = error;
		return (error);
	}
	if (cmd->builtin_ft)
	{
		central->status = cmd->builtin_ft(central, cmd);
	}
	else 
	{
		non_builtin_cmd(central, cmd);
	}
	reset_fds(central);
	return (0);
}

int	non_builtin_cmd(t_central *central, t_cmd *cmd)
{
	int		pid;
	int		status;

	(void)central;
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		single_child(cmd);
	waitpid(pid, &status, WUNTRACED);
	if (WIFSIGNALED(status) && central->status != 130)
		central->status = WTERMSIG(status) + 128;
	if (WIFEXITED(status) && central->status != 130)
		central->status = WEXITSTATUS(status);
	if (WIFSTOPPED(status) && central->status != 130)
		central->status = 1;
	return (0);
}

void	single_child(t_cmd *cmd)
{
	signal_child();
	cmd->cmd_path = path_of_cmd(cmd->words->content);
	if (cmd->cmd_path == NULL)
	{
		error_msg_p((char *)cmd->words->content, CMD_NOT_FOUND);
		exit(127);
	}
	execve(cmd->cmd_path, cmd->cmd_args, get_envp_2d_array());
	exit(1);
}

char	*path_of_cmd(char *cmd)
{
	if (ft_strncmp("./", cmd, 2) == 0 && is_executable_file(cmd))
		return (cmd);
	if (ft_strncmp("/", cmd, 1) == 0 && is_executable_file(cmd))
		return (cmd);
	if (ft_strncmp("./", cmd, 2) == 0)
		return (NULL);
	return (path_of_cmd_2(cmd));
}

char	*path_of_cmd_2(char *cmd)
{
	char	**folders;
	char	*path;
	char	*halfway;
	int		i;

	halfway = my_getenv("PATH");
	if (halfway == NULL)
		return (error_msg("error to reach PATH"), NULL);
	folders = ft_split(halfway, ':');
	if (folders == NULL)
		return (error_msg("error to create PATH (malloc())"), NULL);
	i = 0;
	while (folders[i])
	{
		halfway = ft_strjoin(folders[i], "/");
		path = ft_strjoin(halfway, cmd);
		if (halfway == NULL || path == NULL)
			return (NULL);
		free(halfway);
		if (is_executable_file(path))
			return (free_charpp(&folders), path);
		free(path);
		++i;
	}
	return (free_charpp(&folders), NULL);
}
