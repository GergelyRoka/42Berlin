/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:09:48 by groka             #+#    #+#             */
/*   Updated: 2023/10/12 19:10:00 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_child_handler(int sig)
{
	if (sig == SIGINT)
	{
		exit(130);
	}
}

void	signal_child(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_child_handler);
}
