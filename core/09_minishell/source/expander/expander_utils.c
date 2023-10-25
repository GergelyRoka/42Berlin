/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:39:21 by saimar            #+#    #+#             */
/*   Updated: 2023/10/12 15:15:17 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef enum e_status
{
	noquote,
	dquote,
	squote
}	t_status;

int	get_envname(char *s, char *name)
{
	int	i;

	if (!s || *s != '$')
		return (0);
	i = 0;
	if (s[1] == '?')
	{
		name[0] = '?';
		name[1] = '\0';
		return (2);
	}
	while (s[++i] && (ft_isalnum(s[i]) || s[i] == '_') && i < ENVNAME_MAX)
		name[i - 1] = s[i];
	name[i - 1] = '\0';
	return (i);
}

static int	ft_intlen(int n)
{
	int		len;

	len = 1;
	if (n < 0)
		++len;
	while (n && ++len)
		n /= 10;
	return (len);
}

char	*special_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;

	if (!n)
		return (ft_strdup("0"));
	len = ft_intlen(n);
	str = ft_calloc(len, 1);
	if (!str)
		return (NULL);
	str[--len] = '\0';
	neg = 1;
	if (n < 0)
		neg = -1;
	while (n)
	{
		str[--len] = (n % 10) * neg + '0';
		n /= 10;
	}
	if (neg == -1)
		str[0] = '-';
	return (str);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	free_old_string_if(t_sem_type type, char *old_string)
{
	if (type == WORD)
		free(old_string);
}
