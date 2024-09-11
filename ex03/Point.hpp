/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:29:29 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/11 00:31:25 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& original);
		~Point();
		Point& operator=(const Point& point);

		Fixed getX(void) const;
		Fixed getY(void) const;

	private:
		const Fixed _x;
		const Fixed _y;
};

#endif