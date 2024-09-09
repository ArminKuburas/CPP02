/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:18:28 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/09 12:05:44 by akuburas         ###   ########.fr       */
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
	std::cout << "toInt member function called" << std::endl;
	return (this->_FixedPointValue >> this->_FractionalBits);
}

float Fixed::toFloat(void) const
{
	std::cout << "toFloat member function called" << std::endl;
	return ((float)this->_FixedPointValue / (1 << this->_FractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	std::cout << "insertion operator called" << std::endl;
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed& fixed) const
{
	std::cout << "Greater than operator called" << std::endl;
	return (this->_FixedPointValue > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed& fixed) const
{
	std::cout << "Less than operator called" << std::endl;
	return (this->_FixedPointValue < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	std::cout << "Greater than or equal operator called" << std::endl;
	return (this->_FixedPointValue >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	std::cout << "Less than or equal operator called" << std::endl;
	return (this->_FixedPointValue <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed& fixed) const
{
	std::cout << "Equal operator called" << std::endl;
	return (this->_FixedPointValue == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	std::cout << "Not equal operator called" << std::endl;
	return (this->_FixedPointValue != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	std::cout << "Addition operator called" << std::endl;
	Fixed tmp;
	
	tmp._FixedPointValue = this->_FixedPointValue + fixed.getRawBits();
	return (tmp);
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	std::cout << "Subtraction operator called" << std::endl;
	Fixed tmp;

	tmp._FixedPointValue = this->_FixedPointValue - fixed.getRawBits();
	return (tmp);
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	std::cout << "Multiplication operator called" << std::endl;
	Fixed tmp;
	
	tmp._FixedPointValue = (this->_FixedPointValue * fixed.getRawBits()) >> this->_FractionalBits;
	return (tmp);
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	std::cout << "Division operator called" << std::endl;
	if (fixed.getRawBits() == 0)
	{
		std::cout << "Division by zero detected" << std::endl;
		return (Fixed(0));
	}
	Fixed tmp;
	
	tmp._FixedPointValue = (this->_FixedPointValue << this->_FractionalBits) / fixed.getRawBits();
	return (tmp);
}

Fixed& Fixed::operator++()
{
	std::cout << "Increment operator called" << std::endl;
	++this->_FixedPointValue;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	std::cout << "Post increment operator called" << std::endl;
	Fixed tmp(*this);
	++this->_FixedPointValue;
	return (tmp);
}

Fixed& Fixed::operator--()
{
	std::cout << "Decrement operator called" << std::endl;
	--this->_FixedPointValue;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	std::cout << "Post decrement operator called" << std::endl;
	Fixed tmp(*this);
	--this->_FixedPointValue;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	std::cout << "Min function called" << std::endl;
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	std::cout << "const Min function called" << std::endl;
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	std::cout << "Max function called" << std::endl;
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	std::cout << "const Max function called" << std::endl;
	return (a > b ? a : b);
}