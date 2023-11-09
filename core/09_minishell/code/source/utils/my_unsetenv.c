/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_un-setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:10:28 by saimar            #+#    #+#             */
/*   Updated: 2023/10/12 20:00:16 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*Table of contents*/
int		my_setenv(const char *name, const char *value);
int		my_unsetenv(const char *name);

//--MY SETENV--//
static int	update_env_variable(const char *name, const char *value)
{
	t_list	*current;
	char	*env;
	char	*new_env;
	size_t	env_len;

	current = get_envp_list();
	while (current)
	{
		env = (char *)(current->content);
		if (ft_strncmp(env, name, ft_strlen(name)) == 0 \
		&& env[ft_strlen(name)] == '=')
		{
			env_len = ft_strlen(env);
			new_env = ft_calloc(env_len + ft_strlen(value) + 2, sizeof(char));
			if (new_env == NULL)
				return (-1);
			ft_strlcpy(new_env, name, env_len + 1);
			ft_strlcat(new_env, "=", env_len + ft_strlen(value) + 2);
			ft_strlcat(new_env, value, env_len + ft_strlen(value) + 2);
			free(current->content);
			return (current->content = new_env, 0);
		}
		current = current->next;
	}
	return (-1);
}

static int	add_new_env_variable(const char *name, const char *value)
{
	char	*new_env;
	t_list	*new_node;
	t_list	*envp_list;
	size_t	new_env_size;

	new_env_size = ft_strlen(name) + ft_strlen(value) + 2;
	new_env = ft_calloc(new_env_size, sizeof(char));
	if (new_env == NULL)
	{
		perror("malloc");
		return (-1);
	}
	ft_strlcpy(new_env, name, new_env_size);
	ft_strlcat(new_env, "=", new_env_size);
	ft_strlcat(new_env, value, new_env_size);
	new_node = ft_lstnew(new_env);
	if (new_node == NULL)
	{
		free(new_env);
		return (-1);
	}
	envp_list = get_envp_list();
	ft_lstadd_back(&envp_list, new_node);
	return (0);
}

int	my_setenv(const char *name, const char *value)
{
	char	*env_var;
	int		result;

	if (name == NULL)
		return (-1);
	env_var = my_getenv(name);
	if (env_var)
	{
		result = update_env_variable(name, value);
		if (result != 0)
			return (-1);
	}
	else
	{
		result = add_new_env_variable(name, value);
		if (result != 0)
			return (-1);
	}
	return (0);
}

////*UNSET ENV*////
/**
 * current: previous node
*/
static int	remove_node(t_list **envp_list, t_list *prev, int first)
{
	t_list	*tmp;

	if (first)
	{
		*envp_list = prev->next;
		free(prev->content);
		free(prev);
	}
	else
	{
		tmp = prev->next;
		prev->next = tmp->next;
		free(tmp->content);
		free(tmp);
	}
	return (0);
}

int	my_unsetenv(const char *name)
{
	t_list	*envp_list;
	t_list	*current;
	char	*env_var;

	envp_list = get_envp_list();
	current = envp_list;
	if (name == NULL || current == NULL)
		return (-1);
	env_var = (char *)(current->content);
	if (ft_strncmp(env_var, name, ft_strlen(name)) == 0 && \
		env_var[ft_strlen(name)] == '=')
	{
		return (remove_node(get_envp_list_head(), current, 1));
	}
	while (current->next)
	{
		env_var = (char *)(current->next->content);
		if (ft_strncmp(env_var, name, ft_strlen(name)) == 0 && \
			env_var[ft_strlen(name)] == '=')
		{
			return (remove_node(&envp_list, current, 0));
		}
		current = current->next;
	}
	return (-1);
}
