/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:19:15 by groka             #+#    #+#             */
/*   Updated: 2023/10/12 12:45:02 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * print the error msg, free everything, and exit
*/
void	error_exit(char *msg)
{
	ft_putstr_fd(RED "ERROR EXIT : ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	free_all();
	exit(42);
}

void	error_exit_child(char *msg, int code)
{
	ft_putstr_fd("ERROR EXIT CHILD: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit (code);
}
