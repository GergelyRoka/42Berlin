/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putxint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:10:30 by groka             #+#    #+#             */
/*   Updated: 2023/06/10 04:12:17 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writes.h"

int	my_putxint(unsigned int number)
{
	char	*base;
	long	num;
	int		out;

	base = "0123456789abcdef";
	num = number;
	out = 0;
	if (num / 16 != 0)
		out += my_putx2int(num / 16);
	out += my_putchr(base[num % 16]);
	return (out);
}

int	my_putx2int(unsigned int number)
{
	char	*base;
	long	num;
	int		out;

	base = "0123456789ABCDEF";
	num = number;
	out = 0;
	if (num / 16 != 0)
		out += my_putx2int(num / 16);
	out += my_putchr(base[num % 16]);
	return (out);
}
