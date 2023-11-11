/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:07:02 by saimar            #+#    #+#             */
/*   Updated: 2023/10/12 14:27:06 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_double_arr(char **split_arr)
{
	int	i;

	i = 0;
	if (split_arr == NULL)
		return ;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
	*split_arr = NULL;
}

void	free_charpp(char ***charpp)
{
	int	i;

	i = 0;
	if (charpp == NULL || *charpp == NULL)
		return ;
	while ((*charpp)[i])
	{
		free((*charpp)[i]);
		++i;
	}
	free(*charpp);
	*charpp = NULL;
}

// void	free_lexer(t_lex_node **lexer)
// {
// 	t_lex_node	*tmp;

// 	while (*lexer)
// 	{
// 		tmp = *lexer;
// 		*lexer = (*lexer)->next;
// 		free(tmp->value);
// 		free(tmp);
// 	}
// }

void	free_cmd(t_cmd **cmd)
{
	t_cmd	*tmp;

	while (*cmd)
	{
		tmp = *cmd;
		*cmd = (*cmd)->next;
		if (tmp->cmd_path)
			free(tmp->cmd_path);
		if (tmp->builtin)
			free(tmp->builtin);
		ft_lstclear(&tmp->words, free);
		ft_lstclear(&tmp->infile, free);
		ft_lstclear(&tmp->outfile, free);
		ft_lstclear(&tmp->appendfile, free);
		ft_lstclear(&tmp->input, free_for_redir);
		ft_lstclear(&tmp->output, free_for_redir);
		free_charpp(&tmp->cmd_args);
		free(tmp->cmd_path);
		free(tmp);
	}
	*cmd = NULL;
}
