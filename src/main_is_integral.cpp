/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_is_integral.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:39:37 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/13 15:49:29 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#if STL
	#include <type_traits>
	namespace ft = std;
#else
	#include "is_integral.hpp"
#endif

class A {};
 
enum E : int {};

template < typename T >
T f( T i )
{
	if ( ft::is_integral< T >::value == false )
		return ( false );
	return ( i );
}

int	main()
{
#if STL
	std::cout << "Using STL" << std::endl;
#else
	std::cout << "Using ft" << std::endl;
#endif
	std::cout << std::setw( 29 ) << "std::is_integral< A >::value";
	std::cout << std::is_integral< A >::value << std::endl;
	std::cout << std::setw( 29 ) << "std::is_integral_v< E >";
	std::cout << std::is_integral_v< E > << std::endl;
	std::cout << std::setw( 29 ) << "std::is_integral_v< float >";
	std::cout << std::is_integral_v< float > << std::endl;
	std::cout << std::setw( 29 ) << "std::is_integral_v< int >";
	std::cout << std::is_integral_v< int > << std::endl;
	std::cout << std::setw( 29 ) << "std::is_integral_v< const int >";
	std::cout << std::is_integral_v< const int > << std::endl;
	std::cout << std::setw( 29 ) << "std::is_integral_v< bool >";
	std::cout << std::is_integral_v< bool > << std::endl;
	std::cout << std::setw( 29 ) << "f( 123 )" << f( 123 ) << std::endl;
	return ( 0 );
}