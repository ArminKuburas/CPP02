/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:30:50 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/11 01:04:36 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	std::cout << "Point created with x: " << this->_x << " and y: " << this->_y << std::endl;
}

Point::Point(const Point& original) : _x(original._x), _y(original._y)
{
	std::cout << "Point copied with x: " << this->_x << " and y: " << this->_y << std::endl;
}

Point::~Point()
{
}

Point& Point::operator=(const Point& point)
{
	if (this != &point)
	{
		std::cout << "Point assigned with x: " << point._x << " and y: " << point._y << std::endl;
		
		const_cast<Fixed&>(this->_x) = point._x;
		const_cast<Fixed&>(this->_y) = point._y;
		return (*this);
	}
	return (*this);
}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}