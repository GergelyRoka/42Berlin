/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:00:25 by groka             #+#    #+#             */
/*   Updated: 2023/11/09 11:00:25 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie
{
	public:

		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );

		void	announce( void ) const;
		void	setName( std::string );

	private:
		std::string	name;
};
