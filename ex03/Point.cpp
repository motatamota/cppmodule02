/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:53:06 by tashiget          #+#    #+#             */
/*   Updated: 2024/12/10 21:53:06 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

Point::Point() : x(0), y(0)
{

}

Point::Point(const float a, const float b) : x(a), y(b)
{

}

Point::Point(const Point& other) : x(other.x), y(other.y)
{

}

Point	Point::operator=(const Point& other)
{
	Point tmp(other);
	return (tmp);
}

Point::~Point()
{

}

Fixed	Point::area(Point const a, Point const b, Point const c)
{
	Fixed tmp((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
	tmp.upside();
	return (tmp);
}

bool	bsp(Point const a, Point const b, Point const c, Point const d)
{
	if (Point::area(a, b, d) != 0 && Point::area(b, c, d) != 0 && Point::area(c, a, d) != 0
		&& Point::area(a, b, c) == Point::area(a, b, d) + Point::area(b, c, d) + Point::area(c, a, d))
		return (true);
	return (false);
}
