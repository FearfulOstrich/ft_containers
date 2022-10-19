/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_reverse_iterator.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:04:25 by antoine           #+#    #+#             */
/*   Updated: 2022/10/18 16:38:26 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#if STL
	#include <iterator>
	namespace ft = std;
#else
	#include "reverse_iterator.hpp"
#endif

int main()
{
#if STL
	std::cout << "Using STL" << std::endl;
#else
	std::cout << "Using ft" << std::endl;
#endif
	int	v[] = { 1, 2, 3, 4 };
	std::cout << "Constructors" << std::endl;
	std::cout << "\tv: " << v << std::endl;
	ft::reverse_iterator< int * >	ri1;
	ft::reverse_iterator< int * >	ri2( v + 4 );
	ft::reverse_iterator< int * >	ri3;
	ft::reverse_iterator< int * >	ri4( v );
	ri3 = ri2;
	ft::reverse_iterator< int * >	ri5( ri4 );
	std::cout << "\t*ri2: " << *ri2 << std::endl;
	std::cout << "\t*ri3: " << *ri3 << std::endl;
	std::cout << "\t*ri4: " << *ri4 << std::endl;
	std::cout << "\t*ri5: " << *ri5 << std::endl;

	std::cout << std::endl << "Operators" << std::endl;
	std::cout << "\t*ri2: " << *ri2 << std::endl;
	std::cout << "\t*((&ri4)->base()): ";
	std::cout << *( ( &ri4 )->base() ) << std::endl;
	std::cout << "\tri3[1]: " << ri3[1] << std::endl;
	std::cout << "\t*ri3: " << *ri3 << std::endl;
	std::cout << "\t*((ri3 + 1).base()): ";
	std::cout << *( ( ri3 + 1).base() ) << std::endl;
	ri3++;
	std::cout << "\t*((ri3 + 1).base()): ";
	std::cout << *( ( ri3 + 1).base() ) << std::endl;
	++ri3;
	std::cout << "\t*((ri3 + 1).base()): ";
	std::cout << *( (ri3 + 1).base() ) << std::endl;
	--ri3;
	std::cout << "\t*((ri3 + 1).base()): ";
	std::cout << *( (ri3 + 1).base() ) << std::endl;
	ri3--;
	std::cout << "\t*ri3: " << *ri3 << std::endl;
	std::cout << "\t*( ri2 + 1 ): " << *( ri2 + 1 ) << std::endl;
	std::cout << "\t*( ri4 - 1 ): " << *( ri4 - 1 ) << std::endl;
	ri3+=2;
	std::cout << "\tri3 += 2; *( ri3 ): " << *( ri3 ) << std::endl;
	ri5-=2;
	std::cout << "\tri5 -= 2; *( ri5 ): " << *( ri5 ) << std::endl;
	
	std::cout << "Comparison." << std::endl;
	std::cout << "\tri3 == ri2: " << ( ri3 == ri2 ? "true" : "false" );
	std::cout << std::endl;
	std::cout << "\tri3 == ri5: " << ( ri1 == ri1 ? "true" : "false" );
	std::cout << std::endl;
	std::cout << "\tri3 != ri2: " << ( ri3 != ri2 ? "true" : "false" );
	std::cout << std::endl;
	std::cout << "\tri3 > ri2: " << ( ri3 > ri2 ? "true" : "false" );
	std::cout << std::endl;
	std::cout << "\tri3 < ri2: " << ( ri3 < ri2 ? "true" : "false" );
	std::cout << std::endl;
	std::cout << "\tri4 <= ri5: " << ( ri4 <= ri5 ? "true" : "false" );
	std::cout << std::endl;
	std::cout << "\tri4 >= ri5: " << ( ri4 >= ri5 ? "true" : "false" );
	std::cout << std::endl;

	std::cout << "other arithmetic operators" << std::endl;
	std::cout << "\t *(1 + ri2): " <<  *(1 + ri2) << std::endl;
	std::cout << "\t *(1 + ri3): " <<  *(1 + ri3) << std::endl;
	std::cout << "\tri2 - ri4: " << ri2 - ri4 << std::endl;
	std::cout << "\tri4 - ri2: " << ri4 - ri2 << std::endl;
	std::cout << "\tri3 - ri5: " << ri3 - ri5 << std::endl;
	std::cout << "\tri5 - ri3: " << ri5 - ri3 << std::endl;
	return (0);
}