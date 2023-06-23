/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 01:38:23 by groka             #+#    #+#             */
/*   Updated: 2023/06/23 10:38:11 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line_bonus.h"
#include "../argument_validation/argument_validation.h"
#include "../linked_list/linked_list.h"
#include "../turk_method/turk_method.h"

static void	error_exit(t_node **a, t_node **b, char *line);
static void	do_rules(t_node **a, t_node **b, char *line);
static void	arg_check(int ac, char **av);

/**
 * @brief
 * 	1) The checker gets the numbers of the stack as command-line parameters.
 * 	2) Creates the stack a.
 * 	3) Reads the rules from standard input one by one, and execute them.
 * 	4) After the rules, check that stack is sorted and writes out the result.
 * 
 * @note use BASH, if you want to use terminal variables for input parameter
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int	main(int ac, char **av)
{
	char	*line;
	t_node	*a;
	t_node	*b;

	arg_check(ac, av);
	a = create_stack(av);
	b = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		do_rules(&a, &b, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (is_a_sorted(a) && (b == NULL))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(&a, &b);
	return (0);
}

static void	arg_check(int ac, char **av)
{
	if (ac == 1)
		exit(0);
	if (!argument_validation(av))
	{
		write(2, "Error\n", 6);
		exit(42);
	}
}

/**
 * @brief Execute the rules from standard input.
 * 
 * @param a Stack a.
 * @param b Stack b.
 * @param line Input from standard input.
 */
static void	do_rules(t_node **a, t_node **b, char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		do_pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		do_pb(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		do_ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		do_rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		do_rr(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		do_rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		do_rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		do_rrr(a, b);
	else if (ft_strcmp(line, "sa\n") == 0)
		do_sa(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		do_sb(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		do_ss(a, b);
	else
		error_exit(a, b, line);
}

/**
 * @brief If a rule from the standard input is wrong,
 * 		this function is called to free the memory and shutdown the program.
 * 
 * @param a Stack a.
 * @param b Stack b.
 * @param line The location of the wrong input.
 */
static void	error_exit(t_node **a, t_node **b, char *line)
{
	free(line);
	free_stacks(a, b);
	write(2, "Error\n", 6);
	exit(42);
}
