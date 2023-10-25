/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:46:58 by groka             #+#    #+#             */
/*   Updated: 2023/10/12 14:21:05 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_input(t_central *central, t_list *inputs);
static int	open_output(t_central *central, t_list *outputs);

/**
 * @brief	close input/output fds of central,
 * 			and reset STDIN STDOUT
 * 
 * @note maybe this function should be in another file
 * 
 * @param central 
 * @return int (unknown, unused)
 */
int	reset_fds(t_central *central)
{
	close(central->fds.input);
	close(central->fds.output);
	dup2(central->fds.std_input, STDIN_FILENO);
	dup2(central->fds.std_output, STDOUT_FILENO);
	return (0);
}

int	set_fds_cmd(t_central *central, t_cmd *cmd)
{
	int	error;

	dup2(central->fds.std_input, STDIN_FILENO);
	dup2(central->fds.std_output, STDOUT_FILENO);
	central->fds.input = STDIN_FILENO;
	central->fds.output = STDOUT_FILENO;
	error = open_input(central, cmd->input);
	if (error)
	{
		return (1);
	}
	error = open_output(central, cmd->output);
	if (error)
	{
		return (1);
	}
	return (central->status);
}

/**
 * @note (?) error msg needed, if file not found, cant be opened
 * using access would be nice
 */
static int	open_input(t_central *central, t_list *inputs)
{
	t_redirection	*redir;
	int				tmp_fd;

	while (inputs)
	{
		redir = inputs->content;
		if (redir->type == HEREDOC)
			tmp_fd = open_rdonly(central->cmd->heredoc);
		else
			tmp_fd = open_rdonly(redir->filename);
		if (tmp_fd == -1)
		{
			error_msg(ERRMSG_OPENINPUT);
			return (1);
		}
		dup2(tmp_fd, STDIN_FILENO);
		close(tmp_fd);
		inputs = inputs->next;
	}
	return (0);
}

static int	open_output(t_central *central, t_list *outputs)
{
	t_redirection	*redir;
	int				tmp_fd;

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
			return (1);
		}
		dup2(tmp_fd, STDOUT_FILENO);
		close(tmp_fd);
		outputs = outputs->next;
	}
	return (0);
}
