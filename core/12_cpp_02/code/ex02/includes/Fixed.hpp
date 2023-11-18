/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 03:45:20 by groka             #+#    #+#             */
/*   Updated: 2023/11/15 04:01:06 by groka            ###   ########.fr       */
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

			// Overloaded comparison operators
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
			// Overloaded arithmetic operators

		Fixed	operator-(const Fixed& other) const;
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		// Overloaded increment/decrement operators
		Fixed&	operator++(); // pre-increment
		Fixed	operator++(int); // post-increment
		Fixed&	operator--(); // pre-decrement
		Fixed	operator--(int); // post-decrement

		// Static member functions
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b, const Fixed& c);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b, const Fixed& c);

	private:
		int					raw;
		static const int	fractionalBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

const Fixed&	min(const Fixed& a, const Fixed& b);
const Fixed&	min(const Fixed& a, const Fixed& b, const Fixed& c);
const Fixed&	max(const Fixed& a, const Fixed& b);
const Fixed&	max(const Fixed& a, const Fixed& b, const Fixed& c);