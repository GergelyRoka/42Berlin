/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 02:59:42 by groka             #+#    #+#             */
/*   Updated: 2023/09/30 23:41:53 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dup_std_fds(void)
{
	get_central()->fds.input = STDIN_FILENO;
	get_central()->fds.output = STDOUT_FILENO;
	get_central()->fds.std_input = dup(STDIN_FILENO);
	if (get_central()->fds.std_input < 0)
	{
		perror(" ERROR Minishell ");
		return (false);
	}
	get_central()->fds.std_output = dup(STDOUT_FILENO);
	if (get_central()->fds.std_output < 0)
	{
		perror(" ERROR Minishell ");
		return (false);
	}
	return (true);
}
