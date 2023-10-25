/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:14:34 by groka             #+#    #+#             */
/*   Updated: 2023/09/27 15:17:47 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lexer(t_lex_node **lexer)
{
	t_lex_node	*tmp;

	while (*lexer)
	{
		tmp = *lexer;
		*lexer = (*lexer)->next;
		free(tmp->value);
		free(tmp);
	}
	*lexer = NULL;
}
