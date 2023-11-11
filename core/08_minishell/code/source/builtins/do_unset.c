/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 04:34:48 by saimar            #+#    #+#             */
/*   Updated: 2023/10/07 11:21:45 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_unset(t_central *central, t_cmd *cmd)
{
	t_list	*word;
	char	*arg;

	(void)central;
	word = cmd->words->next;
	while (word)
	{
		arg = (char *)(word->content);
		my_unsetenv(arg);
		word = word->next;
	}
	return (EXIT_SUCCESS);
}
