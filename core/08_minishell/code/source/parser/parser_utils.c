/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:20:53 by saimar            #+#    #+#             */
/*   Updated: 2023/10/12 18:21:21 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->id = -1;
	cmd->words = (NULL);
	cmd->cmd_path = (NULL);
	cmd->cmd_args = (NULL);
	cmd->builtin = (NULL);
	cmd->builtin_ft = (NULL);
	cmd->infile = (NULL);
	cmd->outfile = (NULL);
	cmd->appendfile = (NULL);
	cmd->heredoc_name = (NULL);
	cmd->heredoc_text = (NULL);
	cmd->next = (NULL);
	return (cmd);
}

/*
void pipes_counter(t_central *central)
{
    central->pipes = 0;
    while(central->lexer)
    {
        if(central->lexer->type == PIPE)
            central->pipes++;
        central->lexer = central->lexer->next;
    }
}
*/