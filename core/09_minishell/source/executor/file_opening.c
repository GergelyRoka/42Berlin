/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opening.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:31:53 by groka             #+#    #+#             */
/*   Updated: 2023/09/30 23:57:00 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_wronly(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (fd);
}

int	open_rdonly(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY, 0644);
	return (fd);
}

int	open_append(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	return (fd);
}
