/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:04:25 by antoine           #+#    #+#             */
/*   Updated: 2022/10/13 15:40:45 by aalleon          ###   ########.fr       */
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
	return (0);
}