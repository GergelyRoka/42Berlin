/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:18:52 by groka             #+#    #+#             */
/*   Updated: 2023/11/09 15:18:52 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void )
{
	type = "Mighty Air-Sword";
}

Weapon::Weapon( std::string type )
{
	this->type = type;
}

Weapon::~Weapon( void )
{

}

const std::string&	Weapon::getType( void ) const
{
	return (type);
}

void	Weapon::setType( std::string type )
{
	this->type = type;
}
