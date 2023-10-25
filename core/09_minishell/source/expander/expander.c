/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:42:50 by saimar            #+#    #+#             */
/*   Updated: 2023/10/12 15:16:21 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef enum e_status
{
	noquote,
	dquote,
	squote
}	t_status;

/*table of contents*/
t_lex_node	*replace_variables(t_lex_node *last);
static void	put_env_value(char *old_string, char *new_string, int *i, int *j);
static int	varname_not_expandable(char *old_string, \
char *new_string, int *i, int *j);
static int	varname_digit(char *old_string, char *new_string, int *i, int *j);
static int	loop_core_replace_variables(char c, t_status *status);
void		free_old_string_if(t_sem_type type, char *old_string);

/**
 * skipping the quotes we should delete:
 * new_string[j++] = old_string[i];
*/
t_lex_node	*replace_variables(t_lex_node *last)
{
	char		*old_string;
	char		*new_string;
	int			i;
	int			j;
	t_status	status;

	old_string = last->value;
	new_string = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!new_string)
		return (NULL);
	i = -1;
	j = 0;
	status = noquote;
	while (old_string[++i] && j < BUFFER_SIZE - 1)
	{
		if (loop_core_replace_variables(old_string[i], &status))
			continue ;
		else if (old_string[i] == '$' && status != squote)
			put_env_value(ft_strdup(old_string), new_string, &i, &j);
		else
			new_string[j++] = old_string[i];
	}
	last->value = new_string;
	free_old_string_if(last->type, old_string);
	return (last);
}

static int	loop_core_replace_variables(char c, t_status *status)
{
	if (c == '"' && *status == noquote)
		return (*status = dquote, true);
	else if (c == '"' && *status == dquote)
		return (*status = noquote, true);
	else if (c == '\'' && *status == noquote)
		return (*status = squote, true);
	else if (c == '\'' && *status == squote)
		return (*status = noquote, true);
	return (false);
}

static void	put_env_value(char *old_string, char *new_string, int *i, int *j)
{
	char	*temp_str;
	char	env_name[ENVNAME_MAX];	

	if (varname_not_expandable(old_string, new_string, i, j))
		return (free(old_string));
	if (varname_digit(old_string, new_string, i, j))
		return (free(old_string));
	*i += get_envname(&old_string[*i], env_name) - 1;
	if (ft_strncmp(env_name, "?", 1) == 0)
	{
		temp_str = special_itoa(get_central()->old_status);
		*j = ft_strlcat(new_string, temp_str, BUFFER_SIZE);
		free(temp_str);
	}
	else if (my_getenv(env_name))
		*j = ft_strlcat(new_string, my_getenv(env_name), BUFFER_SIZE);
	free(old_string);
}

static int	varname_digit(char *old_string, char *new_string, int *i, int *j)
{
	int		ac;
	char	*temp;

	if (ft_isdigit(old_string[*i + 1]))
	{
		ac = old_string[(*i)++ + 1] - '0';
		if (ac > get_central()->ac - 1)
			return (1);
		temp = ft_strdup(get_central()->av[ac]);
		*j = ft_strlcat(new_string, temp, BUFFER_SIZE);
		free(temp);
		return (1);
	}
	return (0);
}

static int	varname_not_expandable(char *old_string, \
char *new_string, int *i, int *j)
{
	if (!old_string[*i + 1] || old_string[*i + 1] == ' ' || \
	(!ft_isalnum(old_string[*i + 1]) && (old_string[*i + 1] != '_') && \
	old_string[*i + 1] != '?' && \
	old_string[*i + 1] != '\''))
	{
		new_string[(*j)++] = '$';
		return (1);
	}
	return (0);
}
