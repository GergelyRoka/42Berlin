/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:38:54 by groka             #+#    #+#             */
/*   Updated: 2023/02/09 17:52:08 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	in_conv(const char c);
static int	write_param(const char *s, va_list *parameters);

int	ft_printf(const char *string, ...)
{
	va_list	parameters;
	int		out;

	va_start(parameters, string);
	out = 0;
	while (*string)
	{
		if (*string == '%')
		{
			if (in_conv(*(string + 1)))
			{
				out += write_param(string + 1, &parameters);
				string++;
			}
			else
				out += my_putchr('%');
			string++;
		}
		else
			out += my_putchr(*string++);
	}
	va_end(parameters);
	return (out);
}

static int	in_conv(const char c)
{
	char	*set;

	set = "cspdiuxX%";
	while (*set)
	{
		if (*set == c)
			return (1);
		++set;
	}
	return (0);
}

static int	write_param(const char *s, va_list *parameters)
{
	if (*s == 'c')
		return (my_putchr((char)va_arg(*parameters, int)));
	else if (*s == 's')
		return (my_putstr(va_arg(*parameters, char *)));
	else if (*s == 'p')
		return (my_putp(va_arg(*parameters, void *)));
	else if (*s == 'd')
		return (my_putdint((int)va_arg(*parameters, int)));
	else if (*s == 'i')
		return (my_putint((int)va_arg(*parameters, int)));
	else if (*s == 'u')
		return (my_putuint((unsigned int)va_arg(*parameters, unsigned int)));
	else if (*s == 'x')
		return (my_putxint((unsigned int)va_arg(*parameters, unsigned int)));
	else if (*s == 'X')
		return (my_putx2int((unsigned int)va_arg(*parameters, unsigned int)));
	else if (*s == '%')
		return (my_putchr('%'));
	else
		return (my_putchr('%'));
}
