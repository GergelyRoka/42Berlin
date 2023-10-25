/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saimar <saimar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 04:34:32 by saimar            #+#    #+#             */
/*   Updated: 2023/09/19 21:52:50 by saimar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*NEW VERSION WITH T_LIST*/
int	do_env(t_central *central, t_cmd *cmd)
{
	t_list	*envp_list;
	t_list	*current;
	char	*env_var;
	int		i;

	(void)cmd;
	envp_list = central->envp_list;
	current = envp_list;
	i = 0;
	while (current)
	{
		env_var = (char *)(current->content);
		write(STDOUT_FILENO, env_var, ft_strlen(env_var));
		write(STDOUT_FILENO, "\n", 1);
		current = current->next;
		i++;
	}
	return (EXIT_SUCCESS);
}

/* OLD VERSION FOR 2D ARRAY
int	do_env(t_central *central, t_cmd *cmd)
{
	int	i;

	(void)central;
	(void)cmd;
	i = 0;
	while ((get_central())->dup_envp[i])
	{
		ft_putendl_fd((get_central())->dup_envp[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
*/
