/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saimar <saimar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:55:13 by saimar            #+#    #+#             */
/*   Updated: 2023/10/09 20:29:00 by saimar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define NOTVALID "export: not valid in this context"
#define NULLARG "export: null argument"

static void	print_env_var(void *content)
{
	char	*env_var;
	char	*value;
	size_t	name_len;
	size_t	value_len;

	env_var = (char *)content;
	value = ft_strchr(env_var, '=');
	if (value == NULL)
		return ;
	if (value)
	{
		name_len = value - env_var;
		value_len = ft_strlen(value + 1);
		printf("declare -x %.*s=\"%.*s\"\n", \
			(int)name_len, env_var, (int)value_len, value + 1);
	}
}

// Check if the character is a letter (uppercase or lowercase), 
//a digit, or a symbol allowed in variable names
/*
static bool	is_alphanumeric_symbol(char c)
{
	return (isalnum(c) || c == '_' || c == '=' || \
	c == '-' || c == '.' || c == '+' || c == '!' || \
	c == '%' || c == '@' || c == '#' || c == '$' || \
	c == '^' || c == '&' || c == '*' || c == '(' || \
	c == ')' || c == '{' || c == '}' || c == '[' || \
	c == ']' || c == ';' || c == ':' || c == ',' || \
	c == '?' || c == '<' || c == '>' || c == '\\');
}
*/
static int	is_valid_env_name(const char *arg)
{
	size_t	i;

	if (!isalpha(arg[0]) && arg[0] != '_')
		return (0);
	i = 1;
	while (arg[i] && arg[i] != '=')
	{
		if (!(ft_isalnum(arg[i]) || arg[i] == '_' || arg[i] == '='))
			return (0);
		i++;
	}
	return (1);
}

static int	set_env_var(char *arg)
{
	char	*name; 
	char	*value;
	char	*equal_sign;

	name = arg;
	value = NULL;
	equal_sign = ft_strchr(arg, '=');
	if (equal_sign)
	{
		*equal_sign = '\0';
		value = equal_sign + 1;
		if (!is_valid_env_name(name))
			return (-1);
		if (value[0] == '"' && value[strlen(value) - 1] == '"')
		{
			value++;
			value[strlen(value) - 1] = '\0';
		}
		if (my_setenv(name, value) != 0)
			return (-1);
	}
	return (0);
}

int	do_export(t_central *central, t_cmd *cmd)
{
	t_list	*word;
	char	*arg;

	(void)central;
	word = cmd->words->next;
	if (word == NULL)
		ft_lstiter(central->envp_list, print_env_var); 
	else
	{
		while (word)
		{
			arg = (char *)(word->content);
			if (arg == NULL) 
				return (error_msg(NULLARG), \
				EXIT_FAILURE);
			if (!is_valid_env_name(arg))
				error_msg_p(NOTVALID, arg);
			else if (set_env_var(arg) != 0)
				return (EXIT_FAILURE);
			word = word->next;
		}
	}
	return (EXIT_SUCCESS);
}

/*
Explanation of formatting

"declare -x ": This is a constant string that is printed as-is. 
In Bash, when you use export to display environment variables, 
they are prefixed with "declare -x".

%.*s: This is a format specifier used with printf to print 
a string with a specified length. It's used twice in this line, 
once for the name part of the environment variable and once 
for the value part.

(int)name_len: This is the width specifier for the first %.*s. 
It specifies the maximum number of characters to be printed from
 the corresponding string argument (in this case, env_var).

env_var: This is the first string argument to be printed using %.*s. 
It represents the name part of the environment variable.

(int)value_len: This is the width specifier for the second %.*s. 
It specifies the maximum number of characters to be printed from 
the corresponding string argument (in this case, value + 1, which 
represents the value part of the environment variable, excluding 
the first character).

value + 1: This is the second string argument to be printed using
 %.*s. It represents the value part of the environment variable, 
 but the + 1 is used to skip the first character (usually an "=" sign), 
 so it starts from the actual value.

"\"\n": These are constant characters that are printed as-is. They 
represent the closing double quote and a newline character, which 
are part of the Bash-like format.

So, this line of code is printing the environment variable in the 
format "declare -x NAME="VALUE"\n", where NAME is the name part of
 the variable (limited to name_len characters), and VALUE is the 
 value part of the variable (limited to value_len characters, 
 excluding the first character which is typically an "=" sign). 
 The \n represents a newline character to move to the next line,
  making the output look similar to how Bash displays environment
   variables.
   		printf("declare -x %.*s=\"%.*s\"\n", \
			(int)name_len, env_var, (int)value_len, value + 1);
*/