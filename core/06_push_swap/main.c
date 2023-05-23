/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:55:47 by groka             #+#    #+#             */
/*   Updated: 2023/05/23 09:37:14 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	
	//TODO: beter arg check
	if (argv[1] == NULL){
		printf("empty input\n");
		return 0;}

	init (&a, &b, argc - 1, argv + 1 );

	dev_write_list(a);

	return	0;
}
