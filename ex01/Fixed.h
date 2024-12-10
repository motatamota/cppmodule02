/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:36:22 by tashiget          #+#    #+#             */
/*   Updated: 2024/12/10 18:36:22 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <cmath>
# include <bitset>

class	Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits;
public:
	Fixed();
	Fixed(int num);
	Fixed(float num);
	Fixed(const Fixed& fixed);
	Fixed&	operator=(const Fixed& other);
	~Fixed();
	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	float		toFloat(void) const;
	int			toInt(void) const;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed);

#endif
