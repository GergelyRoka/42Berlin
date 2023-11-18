/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 03:44:52 by groka             #+#    #+#             */
/*   Updated: 2023/11/15 03:44:53 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include	<iostream>

class Fixed
{
	public:
		Fixed (void );
		Fixed (const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed ( void );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int					raw;
		static const int	fractionalBits;
};
