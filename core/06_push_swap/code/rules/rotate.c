#include "../push_swap.h"

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time
*/

static int rotate(t_stack *stack);

void	do_ra(t_stack *a)
{
	if (rotate(a))
		printf("ra\n");
}

void	do_rb(t_stack *b)
{
	if (rotate(b))
		printf("rb\n");
}

void	do_rr(t_stack *a, t_stack *b)
{
	if (rotate(a) + rotate(b))
		printf("rr\n");
}

static int rotate(t_stack *stack)
{
	if (stack->head == NULL || stack->head == stack->last)
		return (0);
	stack->head = stack->head->next;
	stack->last = stack->last->next;
	return (1);
}