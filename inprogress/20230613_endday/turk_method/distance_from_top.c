#include "turk_method.h"

/**
 * @brief		Calculate the distance of a node from top using rotate.
 * 				How many do_ra/do_rb needed to reach top position for a node.
 * @note		The node should be an item of the stack.
 * @param node 	A node to the top!
 * @return int 	Steps to the top.
 */
int dist_w_rot(t_node *node)
{
	int dist;

	dist = 0;
	if	(node == NULL || node->title == 'h')
		return (dist);
	while(node->title != 'h')
	{
		++dist;
		node = node->prev;
	}
	return(dist);
}

/**
 * @brief		Calculate the distance of a node from top using rotate.
 * 				How many do_ra/do_rb needed to reach top position for a node.
 * @note		The node should be an item of the stack.
 * @param node	A node to the top!
 * @return int	Steps to the top.
 */
int dist_w_rev_rot(t_node *node)
{
	int dist;

	dist = 0;
	if	(node == NULL || node->title == 'h')
		return (dist);
	while(node->title != 'h')
	{
		++dist;
		node = node->next;
	}
	return(dist);
}
