/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:27:03 by saimar            #+#    #+#             */
/*   Updated: 2023/10/12 14:00:57 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*skip_whitespace(char *input);
int			measure_str(char *s);

char	*skip_whitespace(char *input)
{
	while (*input == ' ' || (*input >= 9 && *input <= 13))
		++input;
	return (input);
}

int	measure_str(char *s)
{
	int		i;
	char	c;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\"' || s[i] == '\'')
		{
			c = s[i];
			++i;
			while (s[i] != c && s[i] != '\0')
				++i;
			++i;
		}
		else if (s[i] == '\0')
			return (i - 1);
		else if (i > 0 && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
			return (i - 1);
		else if (i > 0 && (s[i] == '|' || s[i] == '>' || s[i] == '<'))
			return (i - 1);
		else
			i++;
	}
	return (i - 1);
}
