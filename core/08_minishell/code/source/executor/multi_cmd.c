/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:20:42 by groka             #+#    #+#             */
/*   Updated: 2023/10/08 17:34:05 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child(t_central *central, t_cmd *cmd);
char	*path_of_cmd(char *cmd);
char	*path_of_cmd_2(char *cmd);
int		open_input_multi(t_central *central, t_list *inputs);
int		open_output_multi(t_central *central, t_list *outputs);
void	waiting_for_children(t_central *central);

int	multi_cmd(t_central *central)
{
	t_cmd	*cmd;

	central->fds.input = dup(STDIN_FILENO);
	cmd = central->cmd;
	while (cmd)
	{
		make_cmd_args(central, cmd);
		if (pipe(central->pipefd) == -1)
			break ;
		cmd->pid = fork();
		if (cmd->pid == -1)
			break ;
		if (cmd->pid == 0)
			child(central, cmd);
		close(central->pipefd[1]);
		close(central->fds.input);
		central->fds.input = central->pipefd[0];
		cmd = cmd->next;
	}
	close(central->fds.input);
	waiting_for_children(central);
	central->fds.input = dup(STDIN_FILENO);
	return (0);
}

void	waiting_for_children(t_central *central)
{
	t_cmd	*cmd;
	int		status;

	cmd = central->cmd;
	while (cmd)
	{
		waitpid(cmd->pid, &status, WUNTRACED);
		if (WIFSIGNALED(status) && central->status != 130)
			central->status = WTERMSIG(status);
		else if (WIFEXITED(status) && central->status != 130)
			central->status = WEXITSTATUS(status);
		else if (WIFSTOPPED(status) && central->status != 130)
			central->status = 1;
		cmd = cmd->next;
	}
}
