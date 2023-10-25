/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:09:59 by saimar            #+#    #+#             */
/*   Updated: 2023/10/12 14:00:57 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stddef.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <termios.h>
# include <errno.h>
# include <sys/ioctl.h>

# define ENVNAME_MAX	64
# define BUFFER_SIZE 1024
//pipes would be better :D
# define HEREDOC_FILE ".heredoc.siro_"
# define PROMPT "\e[1;31m Happy\e[0m 🦊 "

# define HEREDOC_ERROR_EOF "minishell: ERROR: EOF in heredoc file\n"
# define HEREDOC_WAR_NULL "\nWarning: GNL returned with NULL, maybe it's \
EOF, maybe worst. Finishing HEREDOC"
# define HEREDOC_WAR_EOF "\nWARNING: EOF is lame! NewLine added.\n"
# define ERRMSG_OPENINPUT "Can't open an input file (or heredoc)"
# define CMD_NOT_FOUND "command not found"
//COLORS for text
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

typedef enum e_sem_type		t_sem_type;
typedef struct s_lex_node	t_lex_node;
typedef struct s_central	t_central;
typedef struct s_cmd		t_cmd;
typedef struct s_words		t_words;
typedef enum e_boolean {very_false, very_true}	t_boolean;
//typedef struct s_fds		t_fds;

typedef struct s_fds
{
	int	input;
	int	output;
	int	std_input;
	int	std_output;
}	t_fds;

typedef enum e_sem_type
{
	PIPE = 1,
	HEREDOC,
	APPEND,
	REDIR_IN, 
	REDIR_OUT,
	WORD
}	t_sem_type;

typedef struct s_lex_node
{
	t_sem_type	type; 
	char		*value;
	t_lex_node	*prev;
	t_lex_node	*next;
}	t_lex_node;

typedef struct s_words
{
	char		*value;
	t_words		*prev;
	t_words		*next;
}	t_words;

typedef struct s_central
{
	int			ac;
	char		**av;
	t_list		*envp_list;
	char		*input;
	t_sem_type	sem_type;
	t_lex_node	*lexer;
	t_cmd		*cmd;
	char		**paths;
	int			pipefd[2];
	int			*pid;
	char		*pwd;
	char		*old_pwd;
	int			status;
	int			old_status;
	t_fds		fds;
	int			in_heredoc;
}	t_central;

typedef struct s_redirection
{
	t_sem_type	type;
	char		*filename;
}	t_redirection;

typedef struct s_cmd
{
	int			id;
	char		heredoc[100];
	t_list		*words;
	char		*cmd_path;
	char		**cmd_args;
	char		*builtin;
	int			(*builtin_ft)(t_central *central, t_cmd *cmd);
	t_list		*input;
	t_list		*output;
	t_list		*infile;
	t_list		*outfile;
	t_list		*appendfile;
	char		*heredoc_name;
	char		*heredoc_text;
	t_cmd		*next;
	int			pid;
	int			is_heredoc;
	int			heredocfd[2];
}	t_cmd;

typedef struct s_tmp
{
	int			pipe;
	int			op;
	int			cmd;
}	t_tmp;

/*
builtins is a function that takes a string (char *cmd) 
as input and returns a pointer to another function 
as output. This returned function takes two arguments 
as input, (t_central *central and t_cmd *cmd),
and returns an integer (int) as output.
*/

///////////////////
// CENTRAL
///////////////////

t_central	*get_central(void);
void		set_the_central(t_list *envp_list, int ac, char **av);
int			dup_std_fds(void);
void		free_central(t_central *central);

////////////////////
/// LEXER        ///
////////////////////
t_lex_node	*input_lexer(char *input);
int			ft_create_op_node(char *s, t_lex_node **last, int operator);
int			ft_is_op(char *input);
int			ft_create_word_node(char *s, t_lex_node **last);
///---LEXER UTILS---///
int			valid_by_lexer(char *input);
t_lex_node	*new_lex_node(t_sem_type type, char *value, t_lex_node *prev);
int			is_valid_op(t_lex_node *lexer);
int			handle_end_of_input_or_pipe(char *input);

////////////////////
/// PARSER       ///
//////////////////// 
void		parser(t_central *central, t_lex_node *lexer);
int			check_op(t_cmd *cmd_node, t_lex_node *lexer);
int			check_word(t_cmd *cmd_node, t_lex_node *lexer);
int			(*find_builtin(char *str))(t_central *central, t_cmd *cmd);
///-PARSER UTILS-///
t_cmd		*init_cmd(void);
//--- BUILTINS ---//
int			do_pwd(t_central *central, t_cmd *cmd);
int			do_env(t_central *central, t_cmd *cmd);
int			do_exit(t_central *central, t_cmd *cmd);
int			do_echo(t_central *central, t_cmd *cmd);
int			do_export(t_central *central, t_cmd *cmd);
int			do_unset(t_central *central, t_cmd *cmd);
int			do_cd(t_central *central, t_cmd *cmd);

//////////////////////
/// EXPANDER		//
//////////////////////
char		*my_getenv(const char *env_name);
t_lex_node	*replace_variables(t_lex_node *last);
//////////////////////
///-EXPANDER UTILS-///
////////////////////// 
char		*special_itoa(int n);
int			ft_strcmp(char *s1, char *s2);
int			get_envname(char *s, char *name);

//////////////////////
/// EXECUTOR		//
//////////////////////
int			executor(t_central *central);
// single_cmd.c
int			single_cmd(t_central *central);
// file_opening.c
int			open_wronly(char *filename);
int			open_rdonly(char *filename);
int			open_append(char *filename);
// set_redirection.c
int			reset_fds(t_central *central);
int			set_fds_cmd(t_central *central, t_cmd *cmd);
// ARG
int			make_cmd_args(t_central *central, t_cmd *cmd);
// multi_cmd.c
int			multi_cmd(t_central *central);
// f_is_executable.c
int			is_executable_file(const char *path);
// HEREDOC stuff
void		heredoc(t_central *central, t_cmd *cmd);
void		heredoc_init_pipes(t_cmd *cmd);
void		heredoc_calls(t_cmd *cmd);
void		heredoc_child(t_cmd *cmd);
//void		do_heredoc(char *delimiter, int fd);

void		do_heredoc(t_cmd *cmd, char *name);
void		heredoc_to_files(t_cmd *cmd);
void		heredoc_do_input(t_cmd *cmd);

///signals////////////IF IN CHILD i MUST UNHOOK FROM PARENT
void		signals(void);
void		catch_sigint(int signum);
void		signal_suspend(void);
void		signal_child(void);
void		catch_sigterm(int signum);
void		set_stdin_non_blocking(void);
////utils///
//int			my_unsetenv(const char *name);

///////////////////////
/// UTILS  (GENERAL) //
///////////////////////
void		free_double_arr(char **split_arr);
void		free_charpp(char ***charpp);
void		reset(void);
long long	ft_atoll(const char *str);
///-CENTRAL HANDLERS-///
char		**copy_envp(char **env);

void		free_all(void);

// ERROR
void		error_exit(char *msg);
void		error_exit_child(char *msg, int code);
void		error_msg(char *msg);
void		error_msg_p(char *msg, char *plus);

//void		destroy_central(void);
///-ENVP HANDLERS-///
t_list		*store_envp(char **envp);
t_list		*get_envp_list(void);
t_list		**get_envp_list_head(void);
char		*my_getenv(const char *env_name);
int			my_setenv(const char *name, const char *value);
int			my_unsetenv(const char *name);
char		**get_envp_2d_array(void);
void		free_for_redir(void *redir);
void		free_lexer(t_lex_node **lexer);

#endif