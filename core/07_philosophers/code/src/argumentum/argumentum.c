/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argumentum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:22:13 by groka             #+#    #+#             */
/*   Updated: 2023/09/09 19:53:48 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int			ft_atoi(const char *str);
char		*ft_itoa(int n);
int			ft_strcmp(const char *s1, const char *s2);
static int	argumentum_check(int ac, char **av);
static int	argumentum_fill(int ac, char **av, t_data *data);

/**
 * @brief 
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int	argumentum(int ac, char **av, t_data *data)
{
	if (argumentum_check(ac, av) == false \
			|| argumentum_fill(ac, av, data) == false)
	{
		printf("ERROR: The program requires ");
		printf("4 or 5 positive integers as parameters.\n");
		printf("1) Number of philosophers (1..n)\n");
		printf("2) Time to die in milliseconds\n");
		printf("3) Time to eat in milliseconds\n");
		printf("4) Time to sleep in milliseconds\n");
		printf("OPTIONAL) Needed meals per philosopher\n");
		return (false);
	}
	return (true);
}

static int	argumentum_check(int ac, char **av)
{
	char	*tmp;
	int		i;

	if (ac != 5 && ac != 6)
		return (false);
	i = 1;
	while (i < ac)
	{
		tmp = ft_itoa(ft_atoi(av[i]));
		if (ft_strcmp(tmp, av[i]) != 0 || ft_atoi(av[i]) < 0)
		{
			free(tmp);
			return (false);
		}
		free(tmp);
		++i;
	}
	return (true);
}

static int	argumentum_fill(int ac, char **av, t_data *data)
{
	data->number_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->full_meals = ft_atoi(av[5]);
	else
		data->full_meals = -1;
	if (data->number_of_philos == 0)
		return (false);
	number_of_philo(data->number_of_philos);
	return (true);
}
