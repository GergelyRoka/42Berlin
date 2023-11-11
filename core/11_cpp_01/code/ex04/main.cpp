/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:27:47 by groka             #+#    #+#             */
/*   Updated: 2023/11/10 09:27:47 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Program.hpp"

int main(int argc, char const *argv[])
{
	{
		if (argc != 4)
		{
			std::cout << "The Program requires 3 parameters: <filename> <string_to_replace> <string_for_replace>" << std::endl;
			return (42);
		}
	}
	{
		std::string	filename = argv[1];
		std::string	str_to_replace = argv[2];
		std::string	str_for_replace = argv[3];

		if (filename.empty())
		{
			std::cout << "ERROR: The filename is empty." << std::endl;
			return (42);
		}
		if (str_to_replace.empty())
		{
			std::cout << "ERROR: The 2nd parameter is an empty string." << std::endl;
			return (42);
		}

		Program program(filename, str_to_replace, str_for_replace);

		return (program.run());
	}
}
