/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:37:48 by groka             #+#    #+#             */
/*   Updated: 2023/11/09 15:37:48 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( void )
{
	name = "nameless";
	weapon = NULL;
}

HumanB::HumanB( std::string name )
{
	this->name = name;
	weapon = NULL;
}

HumanB::HumanB( std::string name, Weapon& weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

HumanB::~HumanB( void )
{
	this->name = "nameless";
}

void	HumanB::setWeapon( Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack( void ) const
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " is unarmed" << std::endl;
}
