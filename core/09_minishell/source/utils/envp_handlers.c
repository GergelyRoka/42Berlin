/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saimar <saimar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:28:41 by saimar            #+#    #+#             */
/*   Updated: 2023/10/09 19:49:26 by saimar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Table of contents*/
t_list	*store_envp(char **envp);
t_list	*get_envp_list(void);
char	*my_getenv(const char *env_name);

//NEW VERSION WITH T_LIST
t_list	*store_envp(char **envp)
{
	t_list	*envp_head;
	t_list	*node;
	char	*env_var;
	size_t	i;

	i = -1;
	envp_head = NULL;
	while (envp[++i] != NULL)
	{
		env_var = ft_strdup(envp[i]);
		if (env_var == NULL)
		{
			ft_lstclear(&envp_head, free);
			return (NULL);
		}
		node = ft_lstnew(env_var);
		if (node == NULL)
		{
			free(env_var);
			ft_lstclear(&envp_head, free);
			return (NULL);
		}
		ft_lstadd_back(&envp_head, node);
	}
	return (envp_head);
}

//OLD VERSION WITH 2D ARRAY
/*char	**copy_envp(char **envp)
{
	char	**dup_envp;
	size_t	i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	dup_envp = ft_calloc(sizeof(char *), i + 1);
	if (!dup_envp)
		return (NULL);
	i = 0;
	while (envp[i] != NULL)
	{
		dup_envp[i] = ft_strdup(envp[i]);
		if (dup_envp[i] == NULL)
		{
			free_double_arr(dup_envp);
			return (dup_envp);
		}
		i++;
	}
	dup_envp[i] = '\0';
	return (dup_envp);
}*/

t_list	*get_envp_list(void)
{
	return (get_central()->envp_list);
}

t_list	**get_envp_list_head(void)
{
	return (&(get_central()->envp_list));
}

/*OLD 2D ARRAY*/
/*
char	**get_envp_list(void)
{
	return (get_central()->dup_envp);
}
*/

/*NEW VERSION TAKES T_LIST INPUT*/
char	*my_getenv(const char *env_name)
{
	t_list	*envp_list;
	t_list	*current;
	char	*env_var;
	size_t	env_name_len;

	if (env_name == NULL)
		return (NULL);
	envp_list = get_envp_list();
	current = envp_list;
	env_name_len = ft_strlen(env_name);
	while (current)
	{
		env_var = (char *)(current->content);
		if (ft_strncmp(env_var, env_name, env_name_len) == 0 && \
		env_var[env_name_len] == '=')
		{
			return (&env_var[env_name_len + 1]);
		}
		current = current->next;
	}
	return (NULL);
}

char	**get_envp_2d_array(void)
{
	t_list	*envp_list;
	char	**envp_2d_array;
	int		i;
	int		num_elements;

	envp_list = get_envp_list();
	num_elements = ft_lstsize(envp_list);
	envp_2d_array = (char **)malloc((num_elements + 1) * sizeof(char *));
	if (envp_2d_array == NULL)
		return (NULL);
	i = 0;
	while (envp_list)
	{
		envp_2d_array[i] = ft_strdup((char *)(envp_list->content));
		if (envp_2d_array[i] == NULL)
		{
			return (NULL);
		}
		i++;
		envp_list = envp_list->next;
	}
	envp_2d_array[i] = NULL;
	return (envp_2d_array);
}

/*OLD 2D ARRAY VERSION
char	*my_getenv(const char *env_name)
{
	int	i;

	if (env_name == NULL)
		return (NULL);
	i = 0;
	while (get_envp_list()[i] != NULL) 
	{
		if (ft_strncmp(get_envp_list()[i], env_name, \
ft_strlen(env_name)) == 0 && \
get_envp_list()[i][ft_strlen(env_name)] == '=')
			return (&get_envp_list()[i][ft_strlen(env_name) + 1]);
		i++;
	}
	return (NULL);
}*/