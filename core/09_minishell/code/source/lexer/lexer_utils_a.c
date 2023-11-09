/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saimar <saimar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:27:03 by saimar            #+#    #+#             */
/*   Updated: 2023/10/11 00:56:05 by saimar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			valid_by_lexer(char *input);
int			is_valid_op(t_lex_node *lexer);
int			is_valid_op_sub1(t_lex_node *lexer, t_tmp tmp);
void		is_valid_op_sub2(t_lex_node *lexer, t_tmp *tmp);
t_lex_node	*new_lex_node(t_sem_type type, char *value, t_lex_node *prev);

int	valid_by_lexer(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\"')
		{
			++i;
			while (input[i] != '\"' && input[i] != '\0')
				++i;
			if (input[i] == '\0')
				return (0);
		}
		if (input[i] == '\'')
		{
			++i;
			while (input[i] != '\'' && input[i] != '\0')
				++i;
			if (input[i] == '\0')
				return (0);
		}
		++i;
	}
	return (1);
}

int	is_valid_op(t_lex_node *lexer)
{
	t_tmp	tmp;

	tmp.pipe = 1;
	tmp.op = 0;
	tmp.cmd = 0;
	if (lexer == NULL)
		return (true);
	while (lexer)
	{
		if (is_valid_op_sub1(lexer, tmp) == false)
			return (false);
		is_valid_op_sub2(lexer, &tmp);
		lexer = lexer->next;
	}
	if (tmp.cmd == 0)
		return (false);
	return (true);
}

int	is_valid_op_sub1(t_lex_node *lexer, t_tmp tmp)
{
	if (tmp.pipe && lexer->type == PIPE)
		return (false);
	else if (tmp.op && (lexer->type == HEREDOC || lexer->type == APPEND \
		|| lexer->type == REDIR_IN || lexer->type == REDIR_OUT))
		return (false);
	else if (tmp.op && lexer->type == PIPE)
		return (false);
	else if (tmp.cmd == 0 && lexer->type == PIPE)
		return (false);
	else
		return (true);
}

void	is_valid_op_sub2(t_lex_node *lexer, t_tmp *tmp)
{
	if (lexer->type == WORD)
	{
		if (tmp->pipe)
		{
			tmp->pipe = 0;
			tmp->cmd = 1;
		}
		else if (tmp->op)
			tmp->op = 0;
		else
			tmp->cmd = 1;
	}
	else if (lexer->type == HEREDOC || lexer->type == APPEND \
	|| lexer->type == REDIR_IN || lexer->type == REDIR_OUT)
	{
		tmp->op = 1;
		tmp->pipe = 0;
	}
	else if (lexer->type == PIPE && tmp->cmd)
	{
		tmp->cmd = 0;
		tmp->pipe = 1;
	}
}

t_lex_node	*new_lex_node(t_sem_type type, char *value, t_lex_node *prev)
{
	t_lex_node	*lex_node;

	lex_node = ft_calloc(1, sizeof(t_lex_node));
	if (!lex_node)
		return (NULL);
	lex_node->type = type;
	lex_node->value = value;
	lex_node->prev = prev;
	lex_node->next = NULL;
	if (prev)
		prev->next = lex_node;
	return (lex_node);
}
