/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:28:54 by groka             #+#    #+#             */
/*   Updated: 2023/11/10 09:28:54 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Program.class.hpp"

Program::Program( std::string filename, std::string str_to_replace, std::string str_for_replace )
	: _fileName(filename), _str_to_replace(str_to_replace), _str_for_replace(str_for_replace) {};

Program::~Program( void ) {};

int	Program::run( void ) const
{
	std::string		line;

	std::ifstream	file_in(_fileName);
	if (!file_in.is_open())
	{
		std::cout << "ERROR: opening the file" << std::endl;
		return (1);
	}
	std::ofstream	file_out(_fileName + ".replace");
	if (!file_out.is_open())
	{
		std::cout << "ERROR: opening the output file" << std::endl;
		return (1);
	}
	while (std::getline(file_in, line))
	{
		size_t	found = line.find(_str_to_replace);
		std::string	new_line;

		if (std::string::npos == found)
		{
			file_out << line << std::endl;
			continue ;
		}
		while ( found != std::string::npos )
		{
			file_out << line.substr(0, found) << _str_for_replace;
			line = line.substr(found + _str_to_replace.length());
			found = line.find(_str_to_replace);
		}
		file_out << line << std::endl;
	}
	std::cout << "DONE" << std::endl;
	return (0);
}
