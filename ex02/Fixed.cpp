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
}

Fixed::Fixed(int num)
{
	setRawBits(num<<_fractionalBits);
}

Fixed::Fixed(float num)
{
	setRawBits(roundf(num * (1<<_fractionalBits)));
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	_fixedPointValue = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
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

bool	Fixed::operator>(const Fixed& left) const
{
	return (this->getRawBits() > left.getRawBits());
}

bool	Fixed::operator<(const Fixed& left) const
{
	return (this->getRawBits() < left.getRawBits());
}

bool	Fixed::operator>=(const Fixed& left) const
{
	return (this->getRawBits() >= left.getRawBits());
}

bool	Fixed::operator<=(const Fixed& left) const
{
	return (this->getRawBits() <= left.getRawBits());
}

bool	Fixed::operator==(const Fixed& left) const
{
	return (this->getRawBits() == left.getRawBits());
}

bool	Fixed::operator!=(const Fixed& left) const
{
	return (this->getRawBits() != left.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& left) const
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() + left.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed& left) const
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() - left.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed& left) const
{
	Fixed tmp;
	tmp.setRawBits(roundf(this->toFloat() * left.toFloat() * (1<<_fractionalBits)));
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed& left) const
{
	Fixed tmp;
	tmp.setRawBits(roundf(this->toFloat() / left.toFloat() * (1<<_fractionalBits)));
	return (tmp);
}

Fixed& Fixed::min(Fixed& left, Fixed& right) {
	return ((left <= right) ? left : right);
}

const Fixed& Fixed::min(const Fixed& left, const Fixed& right) {
	return ((left <= right) ? left : right);
}

Fixed& Fixed::max(Fixed& left, Fixed& right) {
	return ((left >= right) ? left : right);
}

const Fixed& Fixed::max(const Fixed& left, const Fixed& right) {
	return ((left >= right) ? left : right);
}

Fixed&	Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);

	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);

	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}
