/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_make_cmd_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 04:17:53 by groka             #+#    #+#             */
/*   Updated: 2023/09/28 04:51:40 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	len_of_list(t_list *list);
static int	fill_with_args(t_central *central, t_cmd *cmd, int len);

int	make_cmd_args(t_central *central, t_cmd *cmd)
{
	int		len;

	len = len_of_list(cmd->words);
	cmd->cmd_args = ft_calloc(len + 1, sizeof(char *));
	if (cmd->cmd_args == NULL)
	{
		if (central->status == 0)
			central->status = 1;
		return (1);
	}
	fill_with_args(central, cmd, len);
	return (central->status);
}

static int	len_of_list(t_list *list)
{
	int	len;

	len = 0;
	while (list)
	{
		++len;
		list = list->next;
	}
	return (len);
}

static int	fill_with_args(t_central *central, t_cmd *cmd, int len)
{
	int		i;
	t_list	*words;

	i = 0;
	words = cmd->words;
	while (i < len)
	{
		cmd->cmd_args[i] = ft_strdup(words->content);
		if (cmd->cmd_args[i] == NULL)
		{
			if (central->status == 0)
				central->status = 1;
			free_double_arr(cmd->cmd_args);
			free(cmd->cmd_args);
			cmd->cmd_args = NULL;
			return (central->status);
		}
		words = words->next;
		++i;
	}
	return (central->status);
}
