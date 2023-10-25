/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:10:28 by groka             #+#    #+#             */
/*   Updated: 2023/10/12 15:45:37 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(t_central *central, t_cmd *cmd)
{
	int	pid;
	int	status;

	(void)central;
	heredoc_to_files(cmd);
	pid = fork();
	if (pid == -1)
		error_exit("fork() fail");
	if (pid == 0)
	{
		signal_child();
		heredoc_do_input(cmd);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && central->status != 130)
		central->status = WTERMSIG(status);
	else if (WIFEXITED(status) && central->status != 130)
		central->status = WEXITSTATUS(status);
	else if (WIFSTOPPED(status) && central->status != 130)
		central->status = 1;
}
