/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:53:15 by tashiget          #+#    #+#             */
/*   Updated: 2024/12/10 20:53:15 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.h"
#include "Point.h"

int main() {
	// 三角形の頂点
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	// **ケース1: 点が三角形の内部にある**
	Point pointInside(2, 2);
	if (bsp(a, b, c, pointInside)) {
		std::cout << "Point (2, 2) is inside the triangle" << std::endl;
	} else {
		std::cout << "Point (2, 2) is outside the triangle" << std::endl;
	}

	// **ケース2: 点が三角形の外部にある**
	Point pointOutside(15, 15);
	if (bsp(a, b, c, pointOutside)) {
		std::cout << "Point (15, 15) is inside the triangle" << std::endl;
	} else {
		std::cout << "Point (15, 15) is outside the triangle" << std::endl;
	}

	// **ケース3: 点が三角形の辺上にある**
	Point pointOnEdge(5, 0);
	if (bsp(a, b, c, pointOnEdge)) {
		std::cout << "Point (5, 0) is inside the triangle" << std::endl;
	} else {
		std::cout << "Point (5, 0) is outside the triangle" << std::endl;
	}

	// **ケース4: 点が三角形の頂点上にある**
	Point pointOnVertex(0, 0);
	if (bsp(a, b, c, pointOnVertex)) {
		std::cout << "Point (0, 0) is inside the triangle" << std::endl;
	} else {
		std::cout << "Point (0, 0) is outside the triangle" << std::endl;
	}

	// **ケース5: 三角形の重心に点がある**
	Point centroid((0 + 10 + 0) / 3.0f, (0 + 0 + 10) / 3.0f);
	if (bsp(a, b, c, centroid)) {
		std::cout << "Point (centroid) is inside the triangle" << std::endl;
	} else {
		std::cout << "Point (centroid) is outside the triangle" << std::endl;
	}

	return 0;
}

// Point (2, 2) is inside the triangle
// Point (15, 15) is outside the triangle
// Point (5, 0) is outside the triangle
// Point (0, 0) is outside the triangle
// Point (centroid) is inside the triangle
