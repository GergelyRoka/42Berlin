/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:22:08 by groka             #+#    #+#             */
/*   Updated: 2023/11/09 15:22:08 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA( std::string name, Weapon& weapon );
		~HumanA();

		void	attack( void ) const;

	private:

		std::string	name;
		Weapon&		weapon;
};
