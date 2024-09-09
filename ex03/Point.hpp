/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:29:29 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/09 15:39:22 by akuburas         ###   ########.fr       */
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
		 Fixed _x;
		 Fixed _y;
};

#endif