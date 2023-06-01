/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putdint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:27:17 by groka             #+#    #+#             */
/*   Updated: 2023/02/08 14:52:10 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writes.h"

int	my_putdint(int number)
{
	long	num;
	int		out;

	num = number;
	out = 0;
	if (num < 0)
	{
		my_putchr('-');
		num = -num;
		out++;
	}
	if (num / 10 != 0)
		out += my_putdint(num / 10);
	my_putchr(num % 10 + '0');
	out++;
	return (out);
}
