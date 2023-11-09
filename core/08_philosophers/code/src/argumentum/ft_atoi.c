/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:29:31 by groka             #+#    #+#             */
/*   Updated: 2023/01/29 22:49:02 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

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
