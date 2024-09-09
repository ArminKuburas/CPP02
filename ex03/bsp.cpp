/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:32:53 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/09 09:01:17 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed a1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
	Fixed a2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
	Fixed a3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());

	if ((a1 > 0 && a2 > 0 && a3 > 0) || (a1 < 0 && a2 < 0 && a3 < 0))
		return true;
	else if (a1 == 0 || a2 == 0 || a3 == 0)
		return false;
	else
		return false;
}