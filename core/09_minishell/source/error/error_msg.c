/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:28:40 by groka             #+#    #+#             */
/*   Updated: 2023/10/12 12:55:18 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_msg(char *msg)
{
	ft_putstr_fd(MAGENTA "Minishell" RESET " : ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}

void	error_msg_p(char *msg, char *plus)
{
	ft_putstr_fd(MAGENTA "Minishell" RESET " : ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(" : ", STDERR_FILENO);
	ft_putendl_fd(plus, STDERR_FILENO);
}
