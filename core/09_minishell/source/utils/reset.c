/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:37:44 by groka             #+#    #+#             */
/*   Updated: 2023/10/12 17:38:03 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_heredoc_files(void);
void	free_cmd(t_cmd **cmd);

void	reset(void)
{
	delete_heredoc_files();
	free_lexer(&get_central()->lexer);
	free_cmd(&get_central()->cmd);
}

void	delete_heredoc_files(void)
{
	t_cmd	*cmd;

	cmd = get_central()->cmd;
	while (cmd)
	{
		unlink(cmd->heredoc);
		cmd = cmd->next;
	}
}
