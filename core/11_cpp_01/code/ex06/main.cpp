/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:59:54 by groka             #+#    #+#             */
/*   Updated: 2023/11/11 00:27:29 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <string>
#include <iostream>

static int	param_check(int argc, char const *argv[]);

int main(int argc, char const *argv[])
{
	int	param = param_check(argc, argv);

	if (param == -1)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	Harl harl;
	switch (param)
	{
		case (0):
			harl.complain("DEBUG");
		case (1):
			harl.complain("INFO");
		case (2):
			harl.complain("WARNING");
		case (3):
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}

static int	param_check(int argc, char const *argv[])
{
	if (argc == 1)
		return (0);
	
	enum level_enum {INVALID = -1, DEBUG, INFO, WARNING, ERROR};
	std::string param = argv[1];
	if (param == "DEBUG")
		return (0);
	if (param == "INFO")
		return (1);
	if (param == "WARNING")
		return (2);
	if (param == "ERROR")
		return (3);
	return (-1);
}
