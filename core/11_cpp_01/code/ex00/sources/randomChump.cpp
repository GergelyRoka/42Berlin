/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:01:07 by groka             #+#    #+#             */
/*   Updated: 2023/11/09 11:01:07 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie *newZombie(std::string name);

void	randomChump( std::string name )
{
	Zombie	*dummy;

	dummy = newZombie(name);
	dummy->announce();
	delete dummy;
}
