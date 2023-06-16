#include "push_swap.h"

static int swap(t_node **stack);

void do_sa(t_node **a)
{
	if(swap(a))
		write(1, "sa\n", 3);

}

void do_sb(t_node **b)
{
	if(swap(b))
		write(1, "sb\n", 3);
}

void do_ss(t_node **a, t_node **b)
{
	if(swap(a) + swap(b))
		write(1, "ss\n", 3);
}

static int swap(t_node **stack)
{
	if(!(*stack) || (*stack)->next == *stack)
	{
		return(0);
	}
	if((*stack) && (*stack)->next != *stack)
	{
		int tmp;
		tmp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = tmp;
	}
	return(1);
}

void do_pa(t_node **a, t_node **b)
{
	if (push(a, b))
		write(1, "pa\n", 3);
}

void do_pb(t_node **a, t_node **b)
{
	if (push(b, a))
		write(1, "pb\n", 3);
}

int push(t_node **dest, t_node **src)
{
	t_node *new_head;

	if(*src == NULL)
		return(0);
	if(!(*dest))
	{
		*dest = pull(src);
		(*dest)->next = *dest;
		(*dest)->prev = *dest;
	}
	else if(*dest)
	{
		new_head = pull(src);
		(*dest)->prev->next = new_head;
		new_head->prev = (*dest)->prev; 
		new_head->next = (*dest);
		(*dest)->prev = new_head;
		(*dest)->title = '\0';
		(*dest) = new_head;
	}   
	return (1);
}

t_node	*pull(t_node **src)
{
	t_node *top;

	if(*src == (*src)->next)
	{
		top = *src;
		*src = NULL;
		return (top);
	}
	else
	{	
		top = *src;
		(*src)->prev->next = (*src)->next; 
		(*src)->next->prev = (*src)->prev;
		(*src) = (*src)->next;
		(*src)->title = 'h'; //do i change title when nULL or I put this 2 lines above
	}
	return(top);
}

void do_ra(t_node **a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}

void do_rb(t_node **b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

void do_rr(t_node **a, t_node **b)
{
	if (rotate(a) + rotate(b))
		write(1, "rr\n", 3);

}
int rotate(t_node **stack)
{
	if (*stack == NULL || *stack == (*stack)->next)
		return (0);
	(*stack)->title = '\0';
	(*stack) = (*stack)->next;
	(*stack)->title = 'h';
	return(1);
}

void do_rra(t_node **a)
{
	if (rrotate(a))
		write(1, "rra\n", 4);
}

void do_rrb(t_node **b)
{
	if (rrotate(b))
		write(1, "rrb\n", 4);
}

void do_rrr(t_node **a, t_node **b)
{
	if (rrotate(a) + rrotate(b))
		write(1, "rrr\n", 4);

}

int rrotate(t_node **stack)
{
	if (*stack == NULL || *stack == (*stack)->next)
		return (0);
	(*stack)->title = '\0';
	(*stack) = (*stack)->prev;
	(*stack)->title = 'h';
	return(1);
}
