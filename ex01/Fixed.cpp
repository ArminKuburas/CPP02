/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:39:27 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/06 16:45:23 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _FixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& original) : _FixedPointValue(original._FixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_FixedPointValue = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_FixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_FixedPointValue = raw;
}

Fixed::Fixed(const int intvalue)
{
	std::cout << "Int constructor called" << std::endl;
	this->_FixedPointValue = intvalue << this->_FractionalBits;
}

Fixed::Fixed(const float floatvalue)
{
	std::cout << "Float constructor called" << std::endl;
	this->_FixedPointValue = roundf(floatvalue * (1 << this->_FractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_FixedPointValue >> this->_FractionalBits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_FixedPointValue / (1 << this->_FractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}