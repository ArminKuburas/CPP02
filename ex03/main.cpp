/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:59:45 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/11 00:59:07 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point a(0, 0);
	Point b(0.5, 1);
	Point c(1, 0);
	Point point(0.5, 0.5);
	Point point2;

	point2 = point;

	std::cout << "Point 1 x: " << point.getX() << " y: " << point.getY() << std::endl;
	std::cout << "Point 2 x: " << point2.getX() << " y: " << point2.getY() << std::endl;
	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;
}