/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_for_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saimar <saimar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:26:53 by groka             #+#    #+#             */
/*   Updated: 2023/10/09 19:49:38 by saimar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief freeing t_redirection*
 * 	free function for ft_lstdelone()
 *
 * @param redir 
 * 
 * @note not tested
 */
void	free_for_redir(void *redir)
{
	t_redirection	*r;

	r = redir;
	free(r->filename);
	free(r);
}
