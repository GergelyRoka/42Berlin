/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:36:48 by groka             #+#    #+#             */
/*   Updated: 2023/02/09 17:50:14 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writes.h"

int	my_putstr(char *s)
{
	int	out;

	out = 0;
	if (s == NULL)
	{
		return (my_putstr("(null)"));
	}
	while (*s)
		out += my_putchr(*s++);
	return (out);
}
