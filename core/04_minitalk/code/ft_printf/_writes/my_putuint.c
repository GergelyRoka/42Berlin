/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:26:56 by groka             #+#    #+#             */
/*   Updated: 2023/02/09 11:49:29 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writes.h"

int	my_putuint(unsigned int number)
{
	unsigned long int	num;
	int					out;

	num = number;
	out = 0;
	if (num / 10 != 0)
		out += my_putuint(num / 10);
	out += my_putchr(num % 10 + '0');
	return (out);
}
