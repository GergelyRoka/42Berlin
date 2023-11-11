/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:37:53 by groka             #+#    #+#             */
/*   Updated: 2023/11/10 09:37:53 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class	Program
{
	public:
		Program( std::string filename, std::string str_to_replace, std::string str_for_replace );
		~Program( void );

		int	run( void ) const;

	private:
		std::string	_fileName;
		std::string	_str_to_replace;
		std::string	_str_for_replace;
};
