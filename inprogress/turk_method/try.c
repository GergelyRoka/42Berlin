#include "push_swap.h"

static void	ft_check_stacks(t_stack *sta, t_stack *stb)
{
	if (sta->size == 2)
		ft_two_nums(sta);
	else if (sta->size == 3)
		ft_three_nums(sta);
	else if (sta->size == 4)
		ft_four_nums(sta, stb);
	else if (sta->size == 5)
		ft_five_nums(sta, stb);
	else if (sta->size > 5)
		ft_stack_reverse(sta, stb);
}

void	ft_three_nums(t_node *stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = st->arr[2];
	middle = st->arr[1];
	bottom = st->arr[0];
	if (top > middle && middle < bottom && bottom > top)
		ft_swap(st, 'a');
	else if (top > middle && middle > bottom && bottom < top)
	{
		ft_swap(st, 'a');
		ft_reverse_rotate(st, 'a');
	}
	else if (top > middle && middle < bottom && bottom < top)
		ft_rotate(st, 'a');
	else if (top < middle && middle > bottom && bottom > top)
	{
		ft_swap(st, 'a');
		ft_rotate(st, 'a');
	}
	else if (top < middle && middle > bottom && bottom < top)
		ft_reverse_rotate(st, 'a');
	else
		return ;
}

