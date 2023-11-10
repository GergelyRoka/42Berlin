/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:25:10 by groka             #+#    #+#             */
/*   Updated: 2023/11/09 15:25:10 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
}

HumanA::~HumanA()
{
	
}

void	HumanA::attack( void ) const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}