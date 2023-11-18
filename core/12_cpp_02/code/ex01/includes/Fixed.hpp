/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 03:45:20 by groka             #+#    #+#             */
/*   Updated: 2023/11/15 03:54:43 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include	<iostream>

class Fixed
{
	public:
		Fixed ( void );
		Fixed ( const int number);
		Fixed ( const float number );
		Fixed ( const Fixed& other);
		Fixed& operator=( const Fixed& other );
		~Fixed ( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					raw;
		static const int	fractionalBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);