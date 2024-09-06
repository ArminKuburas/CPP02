/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:18:28 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/06 18:34:58 by akuburas         ###   ########.fr       */
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

bool Fixed::operator>(const Fixed& fixed) const
{
	return (this->_FixedPointValue > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return (this->_FixedPointValue < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return (this->_FixedPointValue >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return (this->_FixedPointValue <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return (this->_FixedPointValue == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return (this->_FixedPointValue != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	Fixed tmp;
	
	tmp._FixedPointValue = this->_FixedPointValue + fixed.getRawBits();
	return (tmp);
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	Fixed tmp;

	tmp._FixedPointValue = this->_FixedPointValue - fixed.getRawBits();
	return (tmp);
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	Fixed tmp;
	
	tmp._FixedPointValue = (this->_FixedPointValue * fixed.getRawBits()) >> this->_FractionalBits;
	return (tmp);
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	if (fixed.getRawBits() == 0)
	{
		std::cout << "Division by zero" << std::endl;
		return (Fixed(0));
	}
	Fixed tmp;
	
	tmp._FixedPointValue = (this->_FixedPointValue << this->_FractionalBits) / fixed.getRawBits();
	return (tmp);
}

Fixed& Fixed::operator++()
{
	++this->_FixedPointValue;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed& Fixed::operator--()
{
	--this->_FixedPointValue;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}