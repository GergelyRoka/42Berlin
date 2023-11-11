/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_to_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:51:16 by groka             #+#    #+#             */
/*   Updated: 2023/10/10 21:58:49 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_do_input(t_cmd *cmd);

void	heredoc_to_files(t_cmd *cmd)
{
	char	*name;
	int		id;
	char	*postfix;
	int		fd;

	id = 1;
	while (cmd)
	{
		cmd->id = id;
		postfix = ft_itoa(id);
		name = ft_strjoin(HEREDOC_FILE, postfix);
		ft_strlcpy(cmd->heredoc, name, 100);
		free(postfix);
		free(name);
		fd = open_wronly(cmd->heredoc);
		close(fd);
		++id;
		cmd = cmd->next;
	}
}

void	heredoc_do_input(t_cmd *cmd)
{
	t_list			*input;
	t_redirection	*redir;

	while (cmd)
	{
		input = cmd->input;
		while (input)
		{
			redir = (t_redirection *)input->content;
			if (redir->type == HEREDOC)
				do_heredoc(cmd, redir->filename);
			input = input->next;
		}
		cmd = cmd->next;
	}
}
