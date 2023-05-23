#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Print out the members of a list/stack starting with the top one.
 * 			Tagging them with a number starting with zero.
 * 
 * @param list t_node type, usually the head of a stack
 */
void	dev_write_list(t_node	*list)
{
	int i;

	i = 0;
	while(list)
	{
		printf("%i. [%i]\n", i , list->value);
		++i;
		list = list->next;
	}
}
