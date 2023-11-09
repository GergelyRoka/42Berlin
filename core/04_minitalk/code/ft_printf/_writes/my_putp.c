/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:31:29 by groka             #+#    #+#             */
/*   Updated: 2023/02/09 17:53:41 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writes.h"

static int	my_pointertohexa(unsigned long long pointer);

int	my_putp(void *pointer)
{
	unsigned long long	p;
	int					out;

	p = (unsigned long long)pointer;
	out = 0;
	if ((unsigned long long) NULL == p)
	{
		my_putstr("(nil)");
		return (5);
	}
	out += my_putstr("0x");
	out += my_pointertohexa(p);
	return (out);
}

static int	my_pointertohexa(unsigned long long pointer)
{
	char	*base;
	int		out;

	base = "0123456789abcdef";
	out = 0;
	if (pointer / 16 != 0)
		out += my_pointertohexa(pointer / 16);
	out += my_putchr(base[pointer % 16]);
	return (out);
}
