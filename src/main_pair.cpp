/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:04:25 by antoine           #+#    #+#             */
/*   Updated: 2022/10/19 10:30:35 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#if STL
	#include <utility>
	namespace ft = std;
#else
	#include "pair.hpp"
#endif

int main()
{
#if STL
	std::cout << "Using STL" << std::endl;
#else
	std::cout << "Using ft" << std::endl;
#endif
	{
		ft::pair<int, char>	p1(0, '0');
		std::cout << "my pair: " << "(" << p1.first << ", " << p1.second <<\
			")" << std::endl;
		ft::pair<float, float> p2(0, 0);
		std::cout << "my pair: " << "(" << p2.first << ", " << p2.second <<\
			")" << std::endl;
		ft::pair<int, float> p3(0, 3.14f);
		std::cout << "my pair: " << "(" << p3.first << ", " << p3.second <<\
			")" << std::endl;
		ft::pair<int, float> p4;
		std::cout << "my pair: " << "(" << p4.first << ", " << p4.second <<\
			")" << std::endl;
		ft::pair<int, float> p5 = p3;
		std::cout << "my pair: " << "(" << p5.first << ", " << p5.second <<\
			")" << std::endl;
		ft::pair<int, float> p6 = p1;
		std::cout << "my pair: " << "(" << p6.first << ", " << p6.second <<\
			")" << std::endl;
		ft::pair<float, char> p7 = p3;
		std::cout << "my pair: " << "(" << p7.first << ", " << p7.second <<\
			")" << std::endl;
		ft::pair<float, char> p8;
		p8 = ft::make_pair(3.14f, 'p');
		std::cout << "my pair: " << "(" << p8.first << ", " << p8.second <<\
			")" << std::endl;
		ft::pair<int, int> p9;
		p9 = ft::make_pair(3.14f, 'p');
		std::cout << "my pair: " << "(" << p9.first << ", " << p9.second <<\
			")" << std::endl;
		ft::pair<int, int> p10;
		p10 = ft::make_pair(3.14f, 3.14f);
		std::cout << "my pair: " << "(" << p10.first << ", " << p10.second <<\
			")" << std::endl;
	}
	{
		ft::pair< int, int > p0(3, 3);
		ft::pair< int, int > p1(3, 3);
		ft::pair< int, int > p2(4, 4);
		ft::pair< int, int > p3(3, 4);
		ft::pair< int, int > p4(4, 3);
		std::cout << "p0: (" << p0.first << ", " << p0.second << ")";
		std::cout << std::endl;
		std::cout << "p1: (" << p1.first << ", " << p1.second << ")";
		std::cout << std::endl;
		std::cout << "p2: (" << p2.first << ", " << p2.second << ")";
		std::cout << std::endl;
		std::cout << "p3: (" << p3.first << ", " << p3.second << ")";
		std::cout << std::endl;
		std::cout << "p4: (" << p4.first << ", " << p4.second << ")";
		std::cout << std::endl;
		std::cout << "p0 == p1 : " << ( p0 == p1 ? "true" : "false" );
		std::cout << std::endl;
		std::cout << "p0 == p2 : " << ( p0 == p2 ? "true" : "false" );
		std::cout << std::endl;
		std::cout << "p0 != p2 : " << ( p0 != p2 ? "true" : "false" );
		std::cout << std::endl;
		std::cout << "p0 != p1 : " << ( p0 != p1 ? "true" : "false" );
		std::cout << std::endl;
		std::cout << "p0 != p3 : " << ( p0 != p3 ? "true" : "false" );
		std::cout << std::endl;
		std::cout << "p1 < p3 : " << ( p1 < p3 ? "true" : "false" );
		std::cout << std::endl;
		std::cout << "p1 < p2 : " << ( p1 < p2 ? "true" : "false" );
		std::cout << std::endl;
		std::cout << "p1 <= p3 : " << ( p1 <= p3 ? "true" : "false" );
		std::cout << std::endl;
		std::cout << "p2 > p3 : " << ( p2 > p3 ? "true" : "false" );
		std::cout << std::endl;
		std::cout << "p2 > p0 : " << ( p2 > p0 ? "true" : "false" );
		std::cout << std::endl;
		std::cout << "p1 >= p4 : " << ( p1 >= p4 ? "true" : "false" );
		std::cout << std::endl;
		std::cout << "p4 >= p1 : " << ( p4 >= p1 ? "true" : "false" );
		std::cout << std::endl;
		std::cout << "p4 >= p3 : " << ( p4 >= p3 ? "true" : "false" );
		std::cout << std::endl;
	}
	return (0);
}