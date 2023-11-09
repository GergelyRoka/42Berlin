/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:59:40 by groka             #+#    #+#             */
/*   Updated: 2023/07/29 19:59:55 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	set_row(size_t row)
{
	(class_board(NULL, false)->dim.row) = row;
}

void	set_col(size_t col)
{
	(class_board(NULL, false)->dim.col) = col;
}

size_t	get_row(void)
{
	return (class_board(NULL, false)->dim.row);
}

size_t	get_col(void)
{
	return (class_board(NULL, false)->dim.col);
}
