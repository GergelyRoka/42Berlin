/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saimar <saimar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:55:39 by saimar            #+#    #+#             */
/*   Updated: 2023/10/09 20:58:54 by saimar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoll(const char *str)
{
	long long	result;
	int			i;
	int			sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] != '\0' && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		++i;
	if (str[i] != '\0' && str[i] == '+')
		++i;
	else if (str[i] != '\0' && str[i] == '-')
	{
		sign = -1;
		++i;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = 10 * result + str[i] - '0';
		++i;
	}
	return (result * sign);
}
