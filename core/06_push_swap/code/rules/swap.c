#include "../push_swap.h"

static int swap(t_stack *stack);

/**
 * @brief sa (swap a): Swap the first 2 elements at the top of stack a.
 *	Do nothing if there is only one or no elements.
 *  Do nothing also means in our case neither print "sa"
 * 
 * @param a
 */
void do_sa(t_stack *a)
{
	if (swap(a))
		ft_printf("sa\n");
}

void do_sb(t_stack *b)
{
	if (swap(b))
		ft_printf("sb\n");
}

void do_ss(t_stack *a, t_stack *b)
{
	if (swap(a) + swap(b))
		ft_printf("ss\n");
}

static int swap(t_stack *stack)
{
	if ((stack->head == NULL) || (stack->head == stack->last))
		return (0);
	else if (stack->head->next == stack->last)
	{
		stack->head = stack->last;
		stack->last = stack->head->prev;
	}
	else
	{
		stack->last->next = stack->head->next;
		stack->head->next->prev = stack->last;
		stack->head->prev = stack->head->next;
		stack->head->next = stack->head->next->next;
		stack->head->prev->next = stack->head;
		stack->head->next->prev = stack->head;
		stack->head = stack->head->prev;
	}
	return (1);
}
