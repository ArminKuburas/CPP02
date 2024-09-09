/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:59:45 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/09 09:11:39 by akuburas         ###   ########.fr       */
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

	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;
}