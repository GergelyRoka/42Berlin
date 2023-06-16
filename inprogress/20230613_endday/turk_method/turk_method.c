#include "turk_method.h"

void	empty_b(t_node **a, t_node **b);
void finish_a(t_node **a);

/**
 * @brief https://medium.com/@ayogun/push-swap-c1f5d2d41e97
 * 
 * @param a Stack A
 * @param b Stack B
 */
void turk_method(t_node **a, t_node **b)
{
	while (size_of_stack(*a) > 5 && !is_a_ordered(*a))
	{
		if (is_a_ordered(*a))
			break ;
		push_from_a_to_b(a, b);
	}
	if (size_of_stack(*a) == 5 && !is_a_ordered(*a))
		ft_five_nums(a, b);
	empty_b(a, b);
	//finish_a(a);
	
}

void	empty_b(t_node **a, t_node **b)
{
	t_node	*max_node_b;

	max_node_b = max_node_in_stack(*b);
	if (dist_w_rot(max_node_b) > dist_w_rev_rot(max_node_b))
		while(max_node_b->title != 'h')
			do_rrb(b);
	else
		while(max_node_b->title != 'h')
			do_ra(b);
	while(*b)
	{
		do_pa(a, b);
	}
}

void finish_a(t_node **a)
{
	t_node * min_node;
	
	min_node = min_node_in_stack(*a);
	if (dist_w_rot(min_node) > dist_w_rev_rot(min_node))
		while(min_node->title != 'h')
			*a = (*a)->prev;
	else
		while(min_node->title != 'h')
			*a = (*a)->next;
}
