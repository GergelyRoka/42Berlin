#include "turk_method.h"

t_node			*node_new_pos_b(t_node *b, t_node *node);
t_node	*min_node_in_stack(t_node *stack);
t_node	*max_node_in_stack(t_node *stack);
static t_node	*mid_pos_in_stack(t_node *stack, t_node *node);

/**
 * @brief 	Calculate the new position of a node from stack A in stack B.
 * 
 * @param b Stack B.
 * @param node Node from stack A looking for a place in stack B.
 * @return t_node* This node will be the next of the new node.
 */
t_node *node_new_pos_b(t_node *b, t_node *node)
{
	t_node	*min_node;
	t_node	*max_node;

	if (b == NULL)
		return (b);
	if (b == (b)->next)
		return (b);
	min_node = min_node_in_stack(b);
	max_node = max_node_in_stack(b);
	if (min_node->value > node->value)
		return(max_node);
	if (max_node->value < node->value)
		return(max_node);
	return(mid_pos_in_stack(b, node));
}

/**
 * @brief The function gives back a node with the lowest value in a stack.
 * 
 * @param stack 
 * @return t_node* 
 */
t_node *min_node_in_stack(t_node *stack)
{
	t_node	*min_node;
	
	if (stack == NULL)
		return (0);
	min_node = stack;
	stack = stack->next;
	while (stack->title != 'h')
	{
		if (min_node->value > stack->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

/**
 * @brief The function gives back a node vith the highest value in the node.
 * 
 * @param stack 
 * @return t_node* 
 */
t_node	*max_node_in_stack(t_node *stack)
{
	t_node	*max_node;
	
	if (stack == NULL)
		return (0);
	max_node = stack;
	stack = stack->next;
	while (stack->title != 'h')
	{
		if (max_node->value < stack->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

/**
 * @brief	The function gives back the position of a node in a stack,
 * 			if its value not highest or lowest in the stack.
 * 
 * @note	WARNING if the node has a lower or higher value than any
 * 			of the other nodes in the stack, the function goes infinity.
 * @param stack 
 * @param node 
 * @return t_node* 
 */
static t_node	*mid_pos_in_stack(t_node *stack, t_node *node)
{
	while (!(stack->value < node->value
		&& stack->prev->value > node->value))
		stack = stack->next;
	return (stack);
}
