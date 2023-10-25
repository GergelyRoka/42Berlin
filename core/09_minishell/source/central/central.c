/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:43:38 by saimar            #+#    #+#             */
/*   Updated: 2023/10/12 14:06:21 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_central	*class_central(t_list *envp_list, int ac, char **av, t_boolean fing)
{
	static t_central	new_central;

	if (fing == true)
	{
		new_central.ac = 0;
		new_central.av = NULL;
		new_central.envp_list = NULL;
		new_central.input = NULL;
		new_central.sem_type = -1;
		new_central.lexer = NULL;
		new_central.cmd = NULL;
		new_central.paths = NULL;
		new_central.pwd = NULL;
		new_central.old_pwd = NULL;
		new_central.status = 0;
	}
	if (ac > 0)
		new_central.ac = ac;
	if (av)
		new_central.av = av;
	if (envp_list != NULL)
		new_central.envp_list = envp_list;
	return (&new_central);
}

//CENTRAL (public)//
void	set_the_central(t_list *envp_list, int ac, char **av)
{
	class_central(envp_list, ac, av, false);
}

t_central	*get_central(void)
{
	return (class_central(NULL, 0, NULL, false));
}

//STATUS//
void	set_status(int n)
{
	class_central(NULL, 0, NULL, 0)->status = n;
}

int	get_status(void)
{
	return (class_central(NULL, 0, NULL, 0)->status);
}
