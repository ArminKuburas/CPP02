/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:18:45 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/06 18:57:10 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed const b(Fixed( 5.05f ) * Fixed( 2 ));
	Fixed const c (5.05f);
	Fixed const d (2);
	Fixed const e;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << c << std::endl;
	std::cout << d << std::endl;

	std::cout << "Time for additional Armin tests" << std::endl;
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	
	std::cout << "So now lets do some math!" << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	if (a > b)
		std::cout << "a is greater than b" << std::endl;
	if (a < b)
		std::cout << "a is less than b" << std::endl;
	if (a >= b)
		std::cout << "a is greater or equal to b" << std::endl;
	if (a <= b)
		std::cout << "a is less or equal to b" << std::endl;
	if (a == b)
		std::cout << "a is equal to b" << std::endl;
	if (a != b)
		std::cout << "a is not equal to b" << std::endl;
	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "lets divide a by zero" << a / 0 << std::endl;
	std::cout << "a / e = " << a / e << std::endl;
}