/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 02:45:41 by groka             #+#    #+#             */
/*   Updated: 2023/06/20 03:40:40 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argument_validation.h"

static int	duplicate_check(char **av);
static int	number_check(char **av);

/**
 * @brief	Check the argument list for okayish.
 * 			No duplications, only valid numbers
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int	argument_validation(char **av)
{
	return (duplicate_check(av) && number_check(av));
}

/**
 * @brief		Check the argument list for duplications.
 * 
 * @param av	Command line argument list.
 * @return int	(1 - true) if there are no duplications
 * 				(0 - false) if there are two or more same argument
 */
static int	duplicate_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}

/**
 * @brief	Check the arguments that they are valid integers.
 * 
 * @param av Command line arguments.
 * @return int	(1 - true) if every argument is a valid integer.
 * 				(0 - false) if there is at least one invalid argument.
 */
static int	number_check(char **av)
{
	int		i;
	char	*str_nbr;

	i = 1;
	while (av[i])
	{
		str_nbr = ft_itoa(ft_atoi(av[i]));
		if (ft_strcmp(av[i], str_nbr) != 0)
		{
			free(str_nbr);
			return (false);
		}
		free(str_nbr);
		++i;
	}
	return (true);
}
