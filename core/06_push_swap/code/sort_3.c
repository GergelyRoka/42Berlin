#include "push_swap.h"

void	ft_three_nums(t_node **stack)
{
	int	top;
	int	middle;
	int	bottom;
	
	top = (*stack)->value;
	middle = (*stack)->next->value;
	bottom = (*stack)->prev->value;

	if(middle < bottom && middle < top && bottom > top)
		do_sa(stack);	
	else if(top > middle && top > bottom && middle> bottom)
	{
		do_sa(stack);
		do_rra(stack);
	}
	else if(top > middle && top > bottom && middle < bottom)
		do_ra(stack);
	else if(top < middle && top < bottom && middle > bottom)
	{
		do_sa(stack);
		do_ra(stack);
	}
	else if(top < middle && top > bottom && middle > bottom)
		do_rra(stack);
}
