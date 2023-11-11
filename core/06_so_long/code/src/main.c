/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:26:23 by groka             #+#    #+#             */
/*   Updated: 2023/08/06 16:12:45 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

static void	set_the_board(char *file);

int	main(int argc, char *argv[])
{
	if (argc != 2)
		error_msg_exit(ERRMSG_NO_ARGUMENT);
	set_the_board(argv[1]);
	run_mlx();
	mother_of_destructors();
	return (0);
}

static void	set_the_board(char *file)
{
	dimension_fill(file);
	create_map(file);
	map_validation();
}
