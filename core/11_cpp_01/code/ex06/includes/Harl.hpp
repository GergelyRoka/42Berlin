/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:44:40 by groka             #+#    #+#             */
/*   Updated: 2023/11/11 00:34:38 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

# define DEBUG_MSG "\033[33m[DEBUG]\033[0m\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!"
# define INFO_MSG "\033[32m[INFO]\033[0m\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did,\nI wouldn't be asking for more!"
# define WARNING_MSG "\033[31m[WARNING]\033[0m\nI think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month."
# define ERROR_MSG "\033[35m[ERROR]\033[0m\nThis is unacceptable!\nI want to speak to the manager now."

class	Harl
{
	public:
		Harl( void );
		void complain( std::string level );

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};
