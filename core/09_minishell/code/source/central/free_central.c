/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_central.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 05:23:22 by groka             #+#    #+#             */
/*   Updated: 2023/09/28 05:55:00 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_central(t_central *central)
{
	ft_lstclear(&central->envp_list, free);
	free(central->envp_list);
}
