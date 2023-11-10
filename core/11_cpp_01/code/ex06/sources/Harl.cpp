/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:46:22 by groka             #+#    #+#             */
/*   Updated: 2023/11/11 00:34:52 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {}

void	Harl::complain( std::string level )
{
	void		(Harl::*complains[4])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i])
			(this->*complains[i])();
	}
}

void	Harl::debug( void )
{
	std::cout << DEBUG_MSG << std::endl;
}

void	Harl::info( void )
{
	std::cout << INFO_MSG << std::endl;
}

void	Harl::warning( void )
{
	std::cout << WARNING_MSG << std::endl;
}

void	Harl::error( void )
{
	std::cout << ERROR_MSG << std::endl;
}
