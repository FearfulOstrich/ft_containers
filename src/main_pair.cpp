/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:04:25 by antoine           #+#    #+#             */
/*   Updated: 2022/10/12 23:05:54 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#if STL
	#include <map>
	#include <stack>
	#include <vector>
	#include <utility>
	namespace ft = std;
#else
	// #include "pair.hpp"
#endif

#include <stdlib.h>

int main()
{
	ft::pair<int, char>	p1(0, '0');

	std::cout << "my pair: " << "(" << p1.first << ", " << p1.second <<\
		 ")" << std::endl;
	return (0);
}