/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:45:16 by groka             #+#    #+#             */
/*   Updated: 2023/11/09 11:45:16 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie *zombieHorde( int N, std::string name );

int main( void )
{
	int			n;
	std::string	name;
	Zombie		*horde;

	n = 4;
	name = "Dalton";
	std::cout << "\n>>> Test: zombieHorde(" << n << ", " << name << ") + announce + delete >>>\n" << std::endl;

	horde = zombieHorde(n, name);
	for (int i = 0; i < n; ++i)
		horde[i].announce();

	delete [] horde;

	n = 0;
	name = "zero";
	std::cout << "\n>>> Test: zombieHorde(" << n << ", " << name << ") + announce + delete >>>\n" << std::endl;
	horde = zombieHorde(n, name);
	for (int i = 0; i < n; ++i)
		horde[i].announce();

	delete [] horde;

	n = 5;
	name.clear();
	std::cout << "\n>>> Test: zombieHorde(" << n << ", " << name << ") + announce + delete >>>\n" << std::endl;
	horde = zombieHorde(n, name);
	for (int i = 0; i < n; ++i)
		horde[i].announce();

	delete [] horde;

	return (0);
}
