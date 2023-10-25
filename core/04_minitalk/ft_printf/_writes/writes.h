/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:41:03 by groka             #+#    #+#             */
/*   Updated: 2023/02/09 17:53:01 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cspdiuxX%
#ifndef WRITES_H
# define WRITES_H
# include <unistd.h>

int	my_putchr(char c);
int	my_putstr(char *s);
int	my_putp(void *pointer);
int	my_putdint(int number);
int	my_putint(int number);
int	my_putuint(unsigned int number);
//int	my_putxint(unsigned int number);
//int	my_putx2int(unsigned int number);

#endif