/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:34:05 by groka             #+#    #+#             */
/*   Updated: 2023/11/09 15:34:05 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB( void );
		HumanB( std::string name );
		HumanB( std::string name, Weapon &weapon);
		~HumanB( void );

		void	setWeapon( Weapon &weapon );
		void	attack( void ) const;

	private:

		std::string	name;
		Weapon*	weapon;
};