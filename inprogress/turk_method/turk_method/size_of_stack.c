#include "turk_method.h"

/**
 * @brief Calculate the size of a stack.
 * 
 * @param stack		A stack.
 * @return int		Size of a stack.
 */
int size_of_stack(t_node *stack)
{
	int size;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (1);
	stack = stack->next;
	size = 1;
	while(stack->title != 'h')
	{
		stack = stack->next;
		++size;
	}
	return (size);
}
