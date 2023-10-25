/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saimar <saimar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:51:40 by saimar            #+#    #+#             */
/*   Updated: 2023/10/10 19:47:30 by saimar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lex_node	*input_lexer(char *input);
int			ft_create_op_node(char *s, t_lex_node **last, int operator);
int			ft_is_op(char *input);
int			ft_create_word_node(char *s, t_lex_node **last);
int			measure_str(char *s);
int			input_lexer_sub(int is_first_char, char **input, t_lex_node **last);

t_lex_node	*input_lexer(char *input)
{
	t_lex_node	*start;
	t_lex_node	*last;
	int			is_first_char;

	is_first_char = 1;
	start = NULL;
	last = NULL;
	while (*input)
	{
		if (input[0] == '\n')
			break ;
		while (*input == ' ' || (*input >= 9 && *input <= 13))
			++input;
		if (*input == '\0')
			break ;
		if (!input_lexer_sub(is_first_char, &input, &last))
			break ;
		last = replace_variables(last);
		if (!start && last)
			start = last;
		if (is_first_char)
			is_first_char = 0;
	}
	return (start);
}

int	input_lexer_sub(int is_first_char, char **input, t_lex_node **last)
{
	int			i;

	i = ft_is_op(*input);
	if (i > 0)
	{
		if (is_first_char && i == PIPE && (*(*input + 1) == ' ' \
		|| *(*input + 1) == '\0'))
		{
			error_msg("syntax error near unexpected token `|'");
			return (0);
		}
		*input += ft_create_op_node(*input, last, i);
	}
	else
		*input += ft_create_word_node(*input, last);
	return (1);
}

int	ft_create_word_node(char *s, t_lex_node **last)
{
	int	len;

	len = measure_str(s) + 1;
	if (len == 0)
		return (0);
	else
	{
		*last = new_lex_node(WORD, ft_substr(s, 0, len), *last);
		s += len;
	}
	return (len);
}

int	ft_create_op_node(char *s, t_lex_node **last, int operator)
{
	int	len;

	len = 0;
	if (operator == APPEND && (s + 3))
	{
		len = 1;
		*last = new_lex_node(APPEND, ">>\0", *last);
	}
	else if (operator == HEREDOC && (s + 3))
	{
		len = 1;
		*last = new_lex_node(HEREDOC, "<<\0", *last);
	}
	else if (operator == REDIR_IN && (s + 2))
		*last = new_lex_node(REDIR_IN, "<\0", *last);
	else if (operator == REDIR_OUT && (s + 2))
		*last = new_lex_node(REDIR_OUT, ">\0", *last);
	else if (operator == PIPE && (s + 2))
		*last = new_lex_node(PIPE, "|\0", *last);
	len += 1;
	return (len);
}

int	ft_is_op(char *s)
{
	if (ft_strncmp(s, ">>", 2) == 0)
		return (APPEND);
	if (ft_strncmp(s, "<<", 2) == 0)
		return (HEREDOC);
	if (*s == '<')
		return (REDIR_IN);
	if (*s == '>')
		return (REDIR_OUT);
	if (*s == '|' )
		return (PIPE);
	return (0);
}
