/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:30:04 by groka             #+#    #+#             */
/*   Updated: 2023/02/02 14:42:12 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	void	*newcontent;

	if (!f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		newcontent = f(lst -> content);
		newnode = ft_lstnew(newcontent);
		if (!newnode)
		{
			ft_lstclear(&newlst, del);
			del(newcontent);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst -> next;
	}
	return (newlst);
}
