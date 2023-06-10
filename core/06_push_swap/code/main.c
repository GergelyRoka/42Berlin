/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:55:47 by groka             #+#    #+#             */
/*   Updated: 2023/06/10 04:14:24 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char *argv[])
{
	t_stack a;
	t_stack b;
	
	init(&a, &b, argv, argc);
	do_sa(&a);
	dev_write_stack(a);

	return	0;
}
