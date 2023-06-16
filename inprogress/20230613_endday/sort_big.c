#include "push_swap.h"

#include <stdio.h>

//43 76 28 14 99 57 86 19 65 10 30 35 90 25 68 47 59 72 16 88 64 8 6 70 49 93 91 26 48 92 39 55 77 11 83 24 44 15 81 13 73 74 61 40 67 89 23 42 17 7 12 56 80 98 29 9 50 63 51 32 97 53 36 5 78 38 37 69 87 95 54 66 75 22 3 96 1 31 45 58 33 21 71 60 2 79 34 4 27 84 94 46 85 20 62 18 82 52 41 100 97

t_node *find_first(t_node *stack, int *array, int chunk);
t_node *find_second(t_node *stack, int *array, int chunk);
int distance_ra(t_node *stack, t_node *node);
int distance_rra(t_node *stack, t_node *node);
void moving_to_top(t_node **stack, t_node *node, void(*rotate)(t_node **a));
void magic(t_node **a, t_node **b, int *array, int chunk);
t_node *max_of_stack(t_node *stack);
void find_pos_in_b(t_node **b, t_node *node);

void	ft_sort_big(t_node **a, t_node **b, int *array, int size)
{
	int i;

	i = 0;
	
	// hold_first = first_find(*a, array, chunk);
	// hold_second = second_find(*a, array, chunk);
	// printf("ra: %i - %i\n",distance_ra(*a, find_first(*a, array, size/5)), find_first(*a, array, size/5)->value);
	// write(1,"done\n", 5 );
	// printf("rra: %i - %i\n", distance_rra(*a, find_second(*a, array, size/5)), find_second(*a, array, size/5)->value);
	// moving_to_top(a, find_first(*a, array, size/5), do_ra);
	// print_stack(*a);

	while (i < 6)
	{
		magic(a, b, &array[i * (size / 6)], size / 6);   // 0 * (100 / 5) == 0
														// 1 * (100 / 5) == 20
														// 2 * (100 / 5) == 40
														// 3 * (100 / 5) == 60
														// 4 * (100 / 5) == 80                                    
		i++;
	}
	ft_five_nums(a, b);

	t_node *pos_max_b;
	pos_max_b = max_of_stack(*b);
	if (distance_ra(*b, pos_max_b)
		   <= distance_rra(*b, pos_max_b))
	{
			moving_to_top(b, pos_max_b, do_rb);
		//    write(1, "a\n", 2);
	}
	else
	{
			moving_to_top(b, pos_max_b, do_rrb);
		 //   write(1, "b\n", 2);
	}

	while (*b)
	{
		do_pa(a, b);
	}
}
/**
 * @brief awesome function
 * 
 * @param value 
 * @param array 
 * @param chunk 
 * @return int 
 */
int is_member_of_chunk(int value, int *array, int chunk)
{
	int i;

	i = 0;
	while (i < chunk)
	{
		if (array[i] == value)
			return (1);
		++i;
	}
	return (0);
}

/**
 * @brief 
 * 
 * @param stack 
 * @param array 
 * @param chunk 
 * @return t_node* 
 */
t_node *find_first(t_node *stack, int *array, int chunk)
{
	if (stack == NULL)
		return (NULL);
	if (is_member_of_chunk(stack->value, array, chunk) && stack->biggest != 1)
		return(stack);
	stack = stack->next;
	while (stack->title != 'h')
	{
		if (is_member_of_chunk(stack->value, array, chunk) && stack->biggest != 1)
			return(stack);
		stack = stack->next;
	}
	return (NULL);
}

/**
 * @brief 
 * 
 * @param stack 
 * @param array 
 * @param chunk 
 * @return t_node* 
 */
t_node *find_second(t_node *stack, int *array, int chunk)
{
	t_node *last;

	if (stack == NULL)
		return (NULL);
	last = stack->prev;
	stack = stack->prev;
	if (is_member_of_chunk(stack->value, array, chunk) && stack->biggest != 1)
		return(stack);
	stack = stack->prev;
	while (stack != last)
	{
		if (is_member_of_chunk(stack->value, array, chunk) && stack->biggest != 1)
			return(stack);
		stack = stack->prev;
	}
	return (NULL);
}

void moving_to_top(t_node **stack, t_node *node, void(*rotate)(t_node **a))
{
	while (*stack != node)
	{
		rotate(stack);
	}
}


t_node *max_of_stack(t_node *stack)
{
	t_node  *max;
	
	if (stack == NULL)
		return (0);
	max = stack;
	stack = stack->next;
	while (stack->title != 'h')
	{
		if (max->value < stack->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_node *min_of_stack(t_node *stack)
{
	t_node *min;
	
	if (stack == NULL)
		return (0);
	min = stack;
	stack = stack->next;
	while (stack->title != 'h')
	{
		if (min->value > stack->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
/**
 * @brief 
 * 
 * @param stack 
 * @param node 
 * @return t_node* 
 */
t_node  *mid_of_stack(t_node *stack, t_node *node)
{
	while (!(stack->value < node->value
		&& stack->prev->value > node->value))
		stack = stack->next;
	return (stack);
}
/**
 * @brief 
 * 
 * @param b 
 * @param node 
 */
void find_pos_in_b(t_node **b, t_node *node)
{
	t_node  *pos_b;
	t_node  *pos_max_b;

	if (*b == NULL)
		return ;
	if (*b == (*b)->next)
		return ;
	pos_b = min_of_stack(*b);
	if (pos_b->value > node->value)
	{
		pos_max_b = max_of_stack(*b);
		if (distance_ra(*b, pos_max_b)
			<= distance_rra(*b, pos_max_b))
		{
			moving_to_top(b, pos_max_b, do_rb);
		}
		else
		{
			moving_to_top(b, pos_max_b, do_rrb);
		}
		return ;
	}
	pos_b = max_of_stack(*b);
	if (pos_b->value < node->value)
	{
		if (distance_ra(*b, pos_b)
			<= distance_rra(*b, pos_b))
		{
			moving_to_top(b, pos_b, do_rb);
		}
		else
		{
			moving_to_top(b, pos_b, do_rrb);
		}
		return ;
	}
	pos_b = mid_of_stack(*b, node);
	if (distance_ra(*b, pos_b)
		<= distance_rra(*b, pos_b))
		moving_to_top(b, pos_b, do_rb);
	else
		moving_to_top(b, pos_b, do_rrb);
}

// t_node *find_pos_b_2(t_node **b, t_node  *node)
// {
// }

/**
 * @brief 
 * 
 */
int max_of_two(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/**
 * @brief it gives 
 * 
 * @param b ad
 * @param node 
 * @return t_node* 
 */
t_node *find_pos_b(t_node **b, t_node *node)
{
	t_node  *pos_b;
	t_node  *pos_max_b;

	if (*b == NULL)
		return (*b);
	if (*b == (*b)->next)
		return (*b);
	pos_b = min_of_stack(*b);
	pos_max_b = max_of_stack(*b);
	if (pos_b->value > node->value)
		return(pos_max_b);
	if (pos_max_b->value < node->value)
		return(pos_max_b);
	return(mid_of_stack(*b, node));
}

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @param hold_first 
 * @param hold_second 
 */
// void    glitters(t_node **a, t_node **b, t_node *hold_first, t_node *hold_second)
// {
//     int case_1;
//     int case_2;
//     int case_3;
//     int case_4;

//     case_1 = max(distance_ra(*a, hold_first), distance_ra(*b, find_pos_b_2(*b, hold_first)));
//     case_2
// }


void do_rotates(t_node **a, t_node **b, int rotate_a, int rotate_b)
{
	//printf("ra: %i rb %i\n", rotate_a, rotate_b);
	while(rotate_a > 0 && rotate_b > 0)
	{
		rotate_a--;
		rotate_b--;
		do_rr(a,b);
	}
	while(rotate_a > 0)
	{
		rotate_a--;
		do_ra(a);
	}
	while(rotate_b > 0)
	{
		rotate_b--;
		do_rb(b);
	}
	while(rotate_a < 0 && rotate_b < 0)
	{
		rotate_a++;
		rotate_b++;
		do_rrr(a,b);
	}
	while(rotate_a < 0)
	{
		rotate_a++;
		do_rra(a);
	}
	while(rotate_b < 0)
	{
		rotate_b++;
		do_rrb(b);
	}
}

void fill_rotates_rotate_a(t_rotates *rotates, t_node **a, t_node *hold_first, t_node *hold_second)
{
	rotates[0].rotate_a = distance_ra(*a, hold_first);
	rotates[1].rotate_a = distance_ra(*a, hold_first);
	rotates[2].rotate_a = -distance_rra(*a, hold_first);
	rotates[3].rotate_a = -distance_rra(*a, hold_first);
	rotates[4].rotate_a = distance_ra(*a, hold_second);
	rotates[5].rotate_a = distance_ra(*a, hold_second);
	rotates[6].rotate_a = -distance_rra(*a, hold_second);
	rotates[7].rotate_a = -distance_rra(*a, hold_second);
}

void fill_rotates_rotate_b(t_rotates *rotates, t_node **b, t_node *hold_first, t_node *hold_second)
{
	rotates[0].rotate_b = distance_ra(*b, find_pos_b(b, hold_first));
	rotates[1].rotate_b = -distance_rra(*b, find_pos_b(b, hold_first));
	rotates[2].rotate_b = distance_ra(*b, find_pos_b(b, hold_first));
	rotates[3].rotate_b = -distance_rra(*b, find_pos_b(b, hold_first));
	rotates[4].rotate_b = distance_ra(*b, find_pos_b(b, hold_second));
	rotates[5].rotate_b = -distance_rra(*b, find_pos_b(b, hold_second));
	rotates[6].rotate_b = distance_ra(*b, find_pos_b(b, hold_second));
	rotates[7].rotate_b = -distance_rra(*b, find_pos_b(b, hold_second));
}

int	sum_steps(int x, int y)
{
	if (x >= 0 && y >= 0)
		return (max_of_two(x, y));
	if (x < 0 && y < 0)
		return (max_of_two(-x, -y));
	if (x < 0)
		return ( (-1*x) + y);
	return (x + (-1*y));
}

void	fill_rotates_steps(t_rotates *rotates)
{
	int	i;

	i = 0;
	while(i < 8)
	{
		rotates[i].steps = sum_steps(rotates[i].rotate_a, rotates[i].rotate_b);
		++i;
	}
}

t_rotates	*fill_rotates(t_node **a, t_node **b, t_node *hold_first, t_node *hold_second)
{
	t_rotates	*rotates;

	rotates = malloc(8 * sizeof(t_rotates));
	fill_rotates_rotate_a(rotates, a, hold_first, hold_second);
	fill_rotates_rotate_b(rotates, b, hold_first, hold_second);
	fill_rotates_steps(rotates);
	return(rotates);	
}

int	cheapest_steps(t_rotates	*rotates)
{
	int min_i;
	int i;
	
	min_i = 0;
	i = 1;
	while (i < 8)
	{
		if (rotates[min_i].steps > rotates[i].steps)
			min_i= i;
		++i;
	}
	return (min_i);
}

void print_struct(t_rotates *rotates)
{
	int i = 0;

	while (i < 8)
	{
		printf("%i)\nrotate_a %i\nrotate_b %i\nsteps%i\n", i, rotates[i].rotate_a, rotates[i].rotate_b, rotates[i].steps);
		++i;
	}
}

int size_of_stack(t_node *stack)
{
	int i;

	if (stack == NULL)
		return (0);
	i = 1;
	stack = stack->next;
	while(stack->title != 'h')
	{
		stack = stack->next;
		++i;
	}
	return (i);
}

//int shortest_distance()
/**
 * int size - size of a chunk
*/
void magic(t_node **a, t_node **b, int *array, int chunk) //step 1 - step 5
{
	t_node  *hold_first;
	t_node  *hold_second;
	int		cheapest;
	// int     steps_b;
	// int		steps_b_2;
	t_rotates	*rotates;

	hold_first = find_first(*a, array, chunk);
	hold_second = find_second(*a, array, chunk);
	
	while (hold_first)
	{
		//write(1, "1\n",2);
		if (size_of_stack(*a) == 5)
		{
			
			break ;
		}
		rotates = fill_rotates(a, b, hold_first, hold_second);
		cheapest = cheapest_steps(rotates);
		// printf("hold_first: %i\n, cheapest: %i \n", hold_first->value, cheapest);
		// print_stack(*a);
		// print_struct(rotates);
		do_rotates(a, b, rotates[cheapest].rotate_a, rotates[cheapest].rotate_b);
		do_pb(a, b);
		// steps_b = distance_ra(*b, find_pos_b(b, hold_first));
		// do_rotates(a, b, distance_ra(*a, hold_first), steps_b);
		// do_pb(a, b);
		// if (distance_ra(*b, find_pos_b(b, hold_first)) < distance_rra(*b, find_pos_b(b, hold_first)))
		// {
		// 	steps_b = distance_ra(*b, find_pos_b(b, hold_first));
		// }
		// else
		// {
		// 	steps_b = -distance_rra(*b, find_pos_b(b, hold_first));
		// }
		// if (distance_ra(*b, find_pos_b(b, hold_second)) <= distance_rra(*b, find_pos_b(b, hold_second)))
		// {
		// 	steps_b_2 = distance_ra(*b, find_pos_b(b, hold_second));
		// }
		// else if(distance_ra(*b, find_pos_b(b, hold_second)) > distance_rra(*b, find_pos_b(b, hold_second)))
		// {
		// 	steps_b_2 = -distance_rra(*b, find_pos_b(b, hold_second));
		// }
		// if (distance_ra(*a, hold_first)
		// 	< distance_rra(*a, hold_second))
		// {
		// 	do_rotates(a, b, distance_ra(*a, hold_first), steps_b);
		// 	do_pb(a, b);
		// }
		// else
		// {
		// 	do_rotates(a, b, -distance_rra(*a, hold_second), steps_b_2);
		// 	do_pb(a, b);
		// }
		hold_first = find_first(*a, array, chunk);
		hold_second = find_second(*a, array, chunk);
		free(rotates);
		rotates = NULL;
	}
}

int distance_ra(t_node *stack, t_node *node)
{
	int dist;

	if	(node == NULL)
		return (0);
	if (stack == node)
	{
		return (0);
	}
	dist = 1;
	stack = stack->next;
	while(stack->title != 'h' && stack != node)
	{
		++dist;
		stack = stack->next;
	}
	return(dist);
}

int distance_rra(t_node *stack, t_node *node)
{
	int dist;

	if	(node == NULL)
		return (0);
	if (stack == node)
	{
		return (0);
	}
	dist = 1;
	stack = stack->prev;
	while(stack->title != 'h' && stack != node)
	{
		++dist;
		stack = stack->prev;
	}
	return(dist);
}