/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:15:49 by groka             #+#    #+#             */
/*   Updated: 2023/11/09 15:15:49 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Weapon
{
	public:

		Weapon( void );
		Weapon( std::string type );
		~Weapon( void );

		const	std::string &getType( void ) const;
		void	setType( std::string type );

	private:

		std::string	type;

};
