/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:33:15 by groka             #+#    #+#             */
/*   Updated: 2023/06/22 03:19:48 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

//get_next_line.c
char	*get_next_line(int fd);
char	*gnl_next_line(int fd, char *buffer, char	*output);
char	*gnl_buffer_grinder(char *buffer);
//get_next_line_utils.c
int		is_ended(char *string);
char	*join_output_substr(char *output, char *substr);

#endif