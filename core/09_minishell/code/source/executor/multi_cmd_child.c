/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_cmd_child.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:46:39 by groka             #+#    #+#             */
/*   Updated: 2023/10/12 12:52:21 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_child_fds(t_central *central, t_cmd *cmd);
char		*path_of_cmd(char *cmd);
static int	open_input(t_central *central, t_cmd *cmd, t_list *inputs);
static int	open_output(t_central *central, t_cmd *cmd, t_list *outputs);

void	child(t_central *central, t_cmd *cmd)
{
	signal_child();
	set_child_fds(central, cmd);
	if (cmd->builtin_ft)
		exit(cmd->builtin_ft(central, cmd));
	cmd->cmd_path = path_of_cmd(cmd->words->content);
	if (cmd->cmd_path == NULL)
	{
		error_msg_p(CMD_NOT_FOUND, cmd->words->content);
		exit(127);
	}
	execve(cmd->cmd_path, cmd->cmd_args, get_envp_2d_array());
	exit(1);
}

static void	set_child_fds(t_central *central, t_cmd *cmd)
{
	if (cmd->next == NULL)
		dup2(central->fds.std_output, STDOUT_FILENO);
	else
		dup2(central->pipefd[1], STDOUT_FILENO);
	close(central->pipefd[0]);
	close(central->pipefd[1]);
	dup2(central->fds.input, STDIN_FILENO);
	close(central->fds.input);
	open_output(central, cmd, cmd->output);
	open_input(central, cmd, cmd->input);
}

static int	open_input(t_central *central, t_cmd *cmd, t_list *inputs)
{
	t_redirection	*redir;
	int				tmp_fd;

	(void)central;
	while (inputs)
	{
		redir = inputs->content;
		if (redir->type == HEREDOC)
			tmp_fd = open_rdonly(cmd->heredoc);
		else
			tmp_fd = open_rdonly(redir->filename);
		if (tmp_fd == -1)
		{
			error_msg(ERRMSG_OPENINPUT);
			exit(1);
		}
		dup2(tmp_fd, STDIN_FILENO);
		close(tmp_fd);
		inputs = inputs->next;
	}
	return (0);
}

static int	open_output(t_central *central, t_cmd *cmd, t_list *outputs)
{
	t_redirection	*redir;
	int				tmp_fd;

	(void)cmd;
	(void)central;
	while (outputs)
	{
		redir = outputs->content;
		if (redir->type == APPEND)
			tmp_fd = open_append(redir->filename);
		else
			tmp_fd = open_wronly(redir->filename);
		if (tmp_fd == -1)
		{
			error_msg(ERRMSG_OPENINPUT);
			exit(1);
		}
		dup2(tmp_fd, STDOUT_FILENO);
		close(tmp_fd);
		outputs = outputs->next;
	}
	return (0);
}
