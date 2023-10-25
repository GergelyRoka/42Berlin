/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:48:33 by groka             #+#    #+#             */
/*   Updated: 2023/10/10 13:53:34 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>

int	is_executable_file(const char *path)
{
	struct stat	file_info;

	if (access(path, X_OK) == 0)
	{
		if (stat(path, &file_info) == 0)
		{
			if (S_ISREG(file_info.st_mode))
			{
				return (true);
			}
		}
	}
	return (false);
}
