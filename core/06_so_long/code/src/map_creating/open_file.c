/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:38:53 by groka             #+#    #+#             */
/*   Updated: 2023/07/30 05:40:19 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../lib/libft/libft.h"
#include "../../lib/libft/get_next_line.h"
#include <fcntl.h>

static t_boolean	extension_check(char *file);

int	open_file(char *file)
{
	int	fd;

	if (extension_check(file) == false)
		error_msg_exit(ERRMSG_FILE_EXTENSION);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_msg_exit(ERRMSG_FILE_OPEN);
	return (fd);
}

t_boolean	extension_check(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4)
		return (false);
	if (ft_strcmp(".ber", file + len - 4))
		return (false);
	return (true);
}
