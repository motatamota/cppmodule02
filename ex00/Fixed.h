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

class	Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits;
public:
	Fixed();
	Fixed(const Fixed& fixed);
	Fixed&	operator=(const Fixed& other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
