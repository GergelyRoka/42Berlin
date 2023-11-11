/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_freemap_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:43:53 by groka             #+#    #+#             */
/*   Updated: 2023/07/26 20:43:54 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	error_freemap_exit(char *msg)
{
	destructor_of_board();
	error_msg_exit(msg);
}
