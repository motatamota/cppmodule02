/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:36:15 by tashiget          #+#    #+#             */
/*   Updated: 2024/12/10 18:36:15 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int num)
{
	setRawBits(num<<_fractionalBits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float num)
{
	setRawBits(roundf(num * (1<<_fractionalBits)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointValue = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixedPointValue) / static_cast<float>((1<<_fractionalBits)));
}

int		Fixed::toInt(void) const
{
	return (_fixedPointValue>>_fractionalBits);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return stream;
}
