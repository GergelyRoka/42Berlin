/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 04:34:08 by saimar            #+#    #+#             */
/*   Updated: 2023/09/27 19:39:19 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_pwd(t_central *central, t_cmd *cmd)
{
	char	buffer[BUFFER_SIZE];

	(void)cmd;
	(void)central;
	ft_putendl_fd(getcwd(buffer, BUFFER_SIZE), STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
