/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saimar <saimar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:38:43 by saimar            #+#    #+#             */
/*   Updated: 2023/10/09 20:25:39 by saimar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//to consider statuses, interaction with redir, fd files
// line 28: pseudo {word1, word2, word3, NULL}
						//if the first word is echo
						// word = word->next
static int	minus_n(t_list *w);

int	do_echo(t_central *central, t_cmd *cmd)
{
	t_list	*w;
	int		flag;

	(void)central;
	w = cmd->words->next; 
	flag = 0;
	while (minus_n(w) == 1)
	{
		w = w->next;
		flag = 1;
	}
	while (w)
	{
		ft_putstr_fd((char *)w->content, STDOUT_FILENO);
		if (w->next)
			ft_putstr_fd(" ", STDOUT_FILENO);
		w = w->next;
	}
	if (flag == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}

static int	minus_n(t_list *w)
{
	int	i;

	i = 0;
	if (w == NULL)
		return (0);
	if (((char *)((w)->content))[i] == '-')
	{
		++i;
		while (((char *)((w)->content))[i] == 'n')
			++i;
		if (((char *)((w)->content))[i] == '\0' && i > 1)
			return (1);
	}
	return (0);
}
