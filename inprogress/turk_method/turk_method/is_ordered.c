#include "turk_method.h"

/**
 * @brief	Return with true if every integer is ordered between the lowest and the highest number.
 * 			Ascending order.
 *			Example 1)	1 2 3 4 5
 *			Example 2)	3 4 5 1 2 --> 1 2 3 4 5
 *
 * @note BUG: this version gives true only if it is sorted too, like "1 2 3 4"
 * @param a Stack.
 * @return int false == 0, true == 0
 */
int is_a_ordered(t_node *a)
{
	if (a == NULL)
		return (true);
	if (a == a->next)
		return (true);
	if (a->value > a->next->value)
		return (false);
	a = a->next;
	while(a->title != 'h')
	{
		if (a->value > a->next->value)
			return (false);
		a = a -> next;
	}
	return (true);
}

/**
 * @brief	Return with true if every integer is ordered between the highest and the lowest number.
 * 			Descending order.
 *			Example 1)	5 4 3 2 1
 *			Example 2)	2 1 5 4 3 --> 5 4 3 2 1
 *
 * @note BUG: this version gives true only if it is sorted too, like "4 3 2 1"
 * @param a Stack.
 * @return int false == 0, true == 0
 */
int is_b_ordered(t_node *b)
{
	if (b == NULL)
		return (true);
	if (b == b->next)
		return (true);
	if (b->value < b->next->value)
		return (false);
	b = b->next;
	while(b->title != 'h')
	{
		if (b->value < b->next->value)
			return (false);
		b = b -> next;
	}
	return (true);
}
