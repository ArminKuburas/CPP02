/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 08:24:03 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/06 08:29:53 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& original);
		~Fixed();
		Fixed& operator=(const Fixed& fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int _FixedPointValue;
		static const int _FractionalBits = 8;
};

#endif