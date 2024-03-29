/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:09:17 by groka             #+#    #+#             */
/*   Updated: 2023/10/11 01:02:31 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	executor(t_central *central)
{
	t_cmd	*cmd;

	cmd = central->cmd;
	if (cmd)
	{
		heredoc(central, cmd);
		if (central->status != 0)
			return (0);
		if (cmd->next == NULL)
			single_cmd(central);
		else
		{
			multi_cmd(central);
		}
	}
	return (0);
}
