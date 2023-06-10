/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:37:26 by groka             #+#    #+#             */
/*   Updated: 2023/02/09 17:28:06 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writes.h"

int	my_putint(int number)
{
	long	num;
	int		out;

	num = number;
	out = 0;
	if (num < 0)
	{
		my_putchr('-');
		num = -num;
		++out;
	}
	if (num / 10 != 0)
		out += my_putint(num / 10);
	out += my_putchr(num % 10 + '0');
	return (out);
}
