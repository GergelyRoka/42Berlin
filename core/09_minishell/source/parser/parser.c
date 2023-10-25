/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:42:05 by saimar            #+#    #+#             */
/*   Updated: 2023/10/12 12:54:43 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//EXPLANATION: starts building t_list of commands
// ///EXPLANATION: break if double pipe (error case) TO CHECK
//EXPLANATION: 
//if operator word is found:
//fills in the node on the basis of what operator we get after the pipe

void	parser(t_central *central, t_lex_node *lexer)
{
	t_cmd	*cmd_node;

	if (lexer)
	{
		cmd_node = init_cmd();
		central->cmd = cmd_node;
	}
	while (lexer)
	{
		if (lexer->type != WORD)
		{
			if (lexer->type == PIPE)
			{
				cmd_node->next = init_cmd();
				cmd_node = cmd_node->next;
				lexer = lexer->next;
				continue ;
			}
			if (check_op(cmd_node, lexer))
				lexer = lexer->next;
		}
		else if (lexer->type == WORD)
			check_word(cmd_node, lexer);
		lexer = lexer->next;
	}
}

/**
 * @note 
 */
int	check_op(t_cmd *cmd_node, t_lex_node *lexer)
{
	t_redirection	*redir;

	if (lexer->next->type != WORD)
	{
		printf("Command not found\n");
		return (EXIT_FAILURE);
	}
	if (lexer->type == REDIR_IN || lexer->type == REDIR_OUT || \
	lexer->type == APPEND || lexer->type == HEREDOC)
	{
		redir = malloc(sizeof(t_redirection));
		if (redir == NULL)
			NULL;
		redir->type = lexer->type;
		redir->filename = ft_strdup(lexer->next->value);
		if (redir->type == REDIR_IN || redir->type == HEREDOC)
			ft_lstadd_back(&(cmd_node->input), ft_lstnew(redir));
		else
			ft_lstadd_back(&(cmd_node->output), ft_lstnew(redir));
	}
	return (1);
}

//		cmd->builtin = ft_strdup(lexer->value); EXPLANATION: stores cmd name
//		cmd->builtin_ft = builtin_function; 	EXPLANATION: stores cmd function
int	check_word(t_cmd *cmd, t_lex_node *lexer)
{
	int	(*builtin_function)(t_central *central, t_cmd *cmd);

	(void)cmd;
	(void)lexer;
	(void) builtin_function;
	builtin_function = find_builtin(lexer->value);
	if (*builtin_function && cmd->builtin_ft == NULL)
	{
		cmd->builtin = ft_strdup(lexer->value);
		cmd->builtin_ft = builtin_function;
	}
	ft_lstadd_back(&cmd->words, ft_lstnew(ft_strdup(lexer->value)));
	return (0);
}

int	(*find_builtin(char *str))(t_central *central, t_cmd *cmd)
{
	static void	*builtins[7][2] = {
	{"echo", do_echo},
	{"cd", do_cd},
	{"pwd", do_pwd},
	{"export", do_export},
	{"unset", do_unset},
	{"env", do_env},
	{"exit", do_exit}
	};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (str)
		{
			if (!ft_strncmp(builtins[i][0], str, ft_strlen((builtins[i][0]))) \
			&& ft_strlen((builtins[i][0])) == ft_strlen(str))
				return (builtins[i][1]);
		}
		i++;
	}
	return (NULL);
}
