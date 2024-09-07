/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:18:45 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/07 10:58:34 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	{
		Fixed	a;
		Fixed const b(Fixed( 5.05f ) * Fixed( 2 ));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}
	std::cout << "Now we test all comparison operators" << std::endl;
	{
		Fixed	a(5);
		Fixed	b(5.5f);

		if (a > b)
			std::cout << "a > b" << std::endl;
		if (a < b)
			std::cout << "a < b" << std::endl;
		if (a >= b)
			std::cout << "a >= b" << std::endl;
		if (a <= b)
			std::cout << "a <= b" << std::endl;
		if (a == b)
			std::cout << "a == b" << std::endl;
		if (a != b)
			std::cout << "a != b" << std::endl;
	}
	std::cout << "Now we test all arithmetic operators" << std::endl;
	{
		Fixed	a(5);
		Fixed	b(5.5f);

		std::cout << "a + b = " << a + b << std::endl;
		std::cout << "a - b = " << a - b << std::endl;
		std::cout << "a * b = " << a * b << std::endl;
		std::cout << "a / b = " << a / b << std::endl;
	}
	std::cout << "Now we test all increment/Decrement operators" << std::endl;
	{
		Fixed a;

		std::cout << "a = " << a << std::endl;

		std::cout << "a++ = " << a++ << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "++a = " << ++a << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "a-- = " << a-- << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "--a = " << --a << std::endl;
		std::cout << "a = " << a << std::endl;
	}
	std::cout << "Now we test min/max functions" << std::endl;
	{
		Fixed a(5);
		Fixed b(5.5f);
		const Fixed c(5.5f);
		const Fixed d(5);

		std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
		std::cout << "min(c, d) = " << Fixed::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl;
	}
}