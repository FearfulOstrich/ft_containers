/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:21:05 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/09 14:59:47 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include "map.hpp"
#include <map>
#include <iostream>
#include <limits>
#include <cstddef>

struct structure {
	std::pair< int, int >	p;
	void*					p1;
	void*					p2;
	void*					p3;
	bool					a;
};

int main()
{
	std::map< int, int >	my_map;
	std::allocator< structure >	allocator;

	std::cout << "sizeof( pair ): " << sizeof( std::pair< int, int > ) << std::endl;
	std::cout << "sizeof( size_t ): " << sizeof( std::size_t ) << std::endl;
	std::cout << "sizeof( ptrdiff_t ): " << sizeof( std::ptrdiff_t ) << std::endl;
	std::cout << "map max_size: " << my_map.max_size() << std::endl;
	std::cout << "numerical limit: " << std::numeric_limits< std::ptrdiff_t >::max() << std::endl;
	std::cout << "ratio ptrdiff_t: " << std::numeric_limits< std::ptrdiff_t >::max() / sizeof(structure) << std::endl;
	std::cout << "allocator max_size: " << allocator.max_size() << std::endl;
	std::cout << "numerical limit: " << std::numeric_limits< std::size_t >::max() << std::endl;
	std::cout << "ratio size_t: " << std::numeric_limits< std::size_t >::max() / my_map.max_size() << std::endl;
	return ( 0 );
}