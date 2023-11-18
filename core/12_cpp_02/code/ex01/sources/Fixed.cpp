/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 03:45:24 by groka             #+#    #+#             */
/*   Updated: 2023/11/15 03:49:01 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>

#include <string>
#include <sstream>

const int	Fixed::fractionalBits = 8;

Fixed::Fixed ( void ) : raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const int number) : raw(number << fractionalBits)
{
	std::cout << "Int constructor called" <<std::endl;
}

Fixed::Fixed ( const float number ) : raw(static_cast<int>(roundf(number * (1 << fractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		raw = other.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (raw);
}

void	Fixed::setRawBits( int const raw )
{
	this->raw = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(raw) / (1 << fractionalBits));
}

int	Fixed::toInt( void ) const
{
	return (raw >> fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	std::stringstream   ss;

	ss <<fixed.toFloat();
	os << ss.str();
	//fixed.getRawBits();
	return os;
}