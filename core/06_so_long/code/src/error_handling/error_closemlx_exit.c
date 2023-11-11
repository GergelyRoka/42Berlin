/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_closemlx_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:35:50 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 18:02:31 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	error_closemlx_exit(char *msg)
{
	mlx_close_window(get_mlx());
	mlx_terminate(class_mlx());
	destructor_of_board();
	error_msg_exit(msg);
}
