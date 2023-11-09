/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:25:20 by groka             #+#    #+#             */
/*   Updated: 2023/01/21 13:25:20 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*memory;
	size_t	i;

	memory = malloc(nmemb * size);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		memory[i] = '\0';
		i++;
	}
	return (memory);
}
