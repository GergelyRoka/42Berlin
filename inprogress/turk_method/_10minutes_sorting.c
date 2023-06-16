#include "push_swap.h"

int smallest(t_node *stack);

void _10minutes_sort(t_node **a, t_node **b)
{
	int nbr;

	while (*a)
	{
		nbr = smallest(*a);
		while((*a)->value != nbr)
			do_ra(a);
		do_pb(a, b);
	}
	while(*b)
	{
		do_pa(a,b);
	}
}


int smallest(t_node *stack)
{
	int smallest;

	smallest = stack->value;
	while(stack->title != 'h')
	{
		if (stack->value < smallest)
			smallest = stack->value;
		stack = stack->next;
	}
	return (smallest);
}
