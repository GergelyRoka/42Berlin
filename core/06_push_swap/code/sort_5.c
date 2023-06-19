#include "push_swap.h"

void whatever(t_node **a, t_node **b);
void whatever2(t_node **a, t_node **b);
int distance_to_smallest(t_node *stack);

static int  pos_finder(t_node **a, int b, int num_b)
{
	int pos;

	pos = 1;
	if ((*a)->value < b)
		pos++;
	if ((*a)->next->value < b)
		pos++;
	if ((*a)->next->next->value < b)
		pos++;
	if (num_b <= 1 && (*a)->next->next->next->value < b)
		pos++;
	if (num_b == 0 && (*a)->next->next->next->next->value < b)
		pos++;
	return (pos);
}

static int  do_pb_biggest_and_lowest(t_node **a, t_node **b, int num_b, int max_pos)
{
    int min_pos;
    int pos_this_a;
    int pos_next_a;
    int pos_prev_a;

    min_pos = 1;
    pos_this_a = pos_finder(a, (*a)->value, num_b);
    pos_next_a = pos_finder(a, (*a)->next->value, num_b);
    pos_prev_a = pos_finder(a, (*a)->prev->value, num_b);
	if (pos_this_a == min_pos || pos_this_a == max_pos)
	    do_pb(a, b);
    else if (pos_prev_a == min_pos || pos_prev_a == max_pos)
    {
        do_rra(a);
        do_pb(a, b);
    }
    else if (pos_next_a == min_pos || pos_next_a == max_pos)
    {
        do_ra(a);
        do_pb(a, b);
    }
    else
    {
        do_ra(a);
        do_ra(a);
        do_pb(a, b);
    }
	return (num_b + 1);
}

void	ft_five_nums(t_node **a, t_node **b)
{
	int	pos;
	int num_b;
    int i;

    i = 2;
	num_b = do_pb_biggest_and_lowest(a, b, 0, 5);
	num_b = do_pb_biggest_and_lowest(a, b, num_b, 4);
	ft_three_nums(a);
	while (i)
	{
		pos = pos_finder(a, (*b)->value, num_b);
		if (pos == 1)
			do_pa(a, b);
		else if ((num_b == 2 && pos == 4) || (num_b == 1 && pos == 5))
		{
			do_pa(a, b);
			do_ra(a);
		}
		else // else if (pos == 2)
		{
			do_ra(a);
			do_pa(a, b);
			do_rra(a);
		}
		num_b--;
        i--;
	}
}

/*
void	ft_five_nums(t_node **a, t_node **b)
{
    do_pb(a, b);
    do_pb(a, b);
    ft_three_nums(a);

    // if ((*b)->prev->value < (*b)->value)
    //     do_rb(b);
    // do_pa(a, b);
    // if ((*a)->prev->value < (*a)->value)
    //     do_ra(a);
    // do_pa(a, b);
    // if ((*a)->prev->value < (*a)->value && (*a)->prev->prev->value < (*a)->value && (*a)->prev->prev->prev->value < (*a)->value)
    //     do_ra(a);

     if ((*b)->value > (*b)->next->value)
         do_sb(b);
    //whatever(a, b);
    //whatever(a, b);
    whatever2(a, b);
    whatever2(a, b);
    if (distance_to_smallest(*a) < 4)
        while ((*a)->value > (*a)->prev->value)
        {
            do_ra(a);
        }
    else
        while ((*a)->value > (*a)->prev->value)
        {
            do_rra(a);
        }

    // if ((*a)->value > (*b)->value)
    //     do_pa(a, b);
    // else if ((*a)->prev->value < (*b)->value)
    // {
    //     do_pa(a, b);
    //     do_ra(a);
    // }
    // else if ((*a)->value > (*b)->next->value)
    // {
    //     do_rb(b);
    //     do_pa(a, b);
    // }
    // else if ((*a)->prev->value < (*b)->next->value)
    // {
    //     do_rb(b);
    //     do_pa(a, b);
    //     do_ra(a);
    // }

    // do_pa(a, b);
    // if ((*a)->prev->value > (*a)->value)
    //     do_ra(a);
    // do_pa(a, b);
    // if ((*a)->prev->value > (*a)->value)
    //     do_ra(a);
}
*/

// from here you are not using these functons below
void whatever(t_node **a, t_node **b)
{
    if ((*a)->value > (*b)->value)
        do_pa(a, b);
    else if ((*a)->prev->value < (*b)->value)
    {
        do_pa(a, b);
        do_ra(a);
    }
    else if ((*a)->value < (*b)->value && (*a)->next->value > (*b)->value)
    {
        do_pa(a, b);
        do_sa(a);
    }
    else if ((*a)->next->value < (*b)->value && (*a)->next->next->value > (*b)->value)
    {
        do_ra(a);
        do_ra(a);
        do_pa(a, b);
        do_rra(a);
        do_rra(a);
    }
    else if ((*a)->prev->value > (*b)->value && (*a)->value  )
    {
        do_rra(a);
        do_pa(a, b);
        do_ra(a);
        do_ra(a);
    }
}
void whatever2(t_node **a, t_node **b)
{
    if ((*a)->value > (*b)->value)
        do_pa(a, b);
    else
    {
        while ((*b)->value > (*a)->value)
        {
            do_ra(a);
        }
        do_pa(a, b);
    }
}

int distance_to_smallest(t_node *stack)
{
    int min_value;
    int min_pos;
    int i;

    min_value = stack->value;
    i = 2;
    min_pos = 1;
    stack = stack->next;
    while (stack->title != 'h')
    {
        if (stack->value < min_value)
        {
            min_value = stack->value;
            min_pos = i;
        }
        stack = stack->next;
        ++i;
    }
    return (min_pos);
}