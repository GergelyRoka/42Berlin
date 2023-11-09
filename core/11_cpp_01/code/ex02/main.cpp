/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:28:47 by groka             #+#    #+#             */
/*   Updated: 2023/11/09 12:28:47 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

int main( void )
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << std::left << std::setw(47) << "The memory address of the string variable is "	<< &string		<< std::endl;
	std::cout << std::left << std::setw(47) << "The memory address held by stringPTR is "		<< stringPTR	<< std::endl;
	std::cout << std::left << std::setw(47) << "The memory address held by stringREF is "		<< &stringREF	<< std::endl;
	std::cout << std::endl;
	std::cout << std::left << std::setw(47) << "The value of the string variable is "			<< string		<< std::endl;
	std::cout << std::left << std::setw(47) << "The value pointed to by stringPTR is "			<< *stringPTR	<< std::endl;
	std::cout << std::left << std::setw(47) << "The value pointed to by stringREF is "			<< stringREF	<< std::endl;

	return (0);
}
