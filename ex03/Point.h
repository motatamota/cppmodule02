/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:53:16 by tashiget          #+#    #+#             */
/*   Updated: 2024/12/10 21:53:16 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# include "Fixed.h"

class	Point
{
private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	Point(const float a, const float b);
	Point(const Point& other);
	Point	operator=(const Point& other);
	~Point();
	static Fixed	area(Point const a, Point const b, Point const c);
};

bool	bsp(Point const a, Point const b, Point const c, Point const d);

#endif
