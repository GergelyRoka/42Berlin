/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:47:02 by groka             #+#    #+#             */
/*   Updated: 2023/01/29 22:48:01 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	dlen = 0;
	slen = ft_strlen(src);
	while (size >= 1 && *dst)
	{
		--size;
		++dst;
		++dlen;
	}
	while (size > 1 && *src)
	{
		*dst = *src;
		++dst;
		++src;
		--size;
	}
	if (size)
		*dst = '\0';
	return (dlen + slen);
}
