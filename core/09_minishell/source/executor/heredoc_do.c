/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:08:04 by groka             #+#    #+#             */
/*   Updated: 2023/10/10 22:40:51 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_loop(char *delimiter, int fd);
static int	is_eof(char *str);

void	do_heredoc(t_cmd *cmd, char *delimiter)
{
	int	fd;

	fd = open_wronly(cmd->heredoc);
	delimiter = ft_strjoin(delimiter, "\n");
	if (delimiter == NULL)
		error_exit_child("malloc() failed", 1);
	heredoc_loop(delimiter, fd);
	free(delimiter);
}

static void	heredoc_loop(char *delimiter, int fd)
{
	char	*line;

	while (true)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
		{
			ft_putendl_fd(HEREDOC_WAR_NULL, STDERR_FILENO);
			break ;
		}
		else if (ft_strcmp(line, delimiter) == 0)
			break ;
		else if (is_eof(line))
		{
			ft_putstr_fd(HEREDOC_WAR_EOF, STDERR_FILENO);
			ft_putendl_fd(line, fd);
			break ;
		}
		else
			ft_putstr_fd(line, fd);
		free(line);
	}
	free (line);
}

static int	is_eof(char *str)
{
	int	flag;

	flag = true;
	if (str && ft_strlen(str) > 0)
		if (str[ft_strlen(str) - 1] == '\n')
			return (false);
	return (flag);
}
