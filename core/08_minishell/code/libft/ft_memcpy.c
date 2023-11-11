/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:37:34 by groka             #+#    #+#             */
/*   Updated: 2022/12/07 16:37:34 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n--)
		*d++ = *s++;
	return (dest);
}

/*
The memcpy() function copies n bytes from memory area src to memory area dest.
The memory areas must not overlap. Use memmove(3) if the memory areas do overlap.
*/
