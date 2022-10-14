/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_is_integral.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:39:37 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/14 10:24:01 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
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
	std::cout << std::setw( 32 ) << "ft::is_integral< A > : ";
	std::cout << ( ft::is_integral< A >::value ? "TRUE" : "FALSE" );
	std::cout << std::endl;
	std::cout << std::setw( 32 ) << "ft::is_integral< E > : ";
	std::cout << ( ft::is_integral< E >::value ? "TRUE" : "FALSE" );
	std::cout << std::endl;
	std::cout << std::setw( 32 ) << "ft::is_integral< float > : ";
	std::cout << ( ft::is_integral< float >::value ? "TRUE" : "FALSE" );
	std::cout << std::endl;
	std::cout << std::setw( 32 ) << "ft::is_integral< int > : ";
	std::cout << ( ft::is_integral< int >::value ? "TRUE" : "FALSE" );
	std::cout << std::endl;
	std::cout << std::setw( 32 ) << "ft::is_integral< const int > : ";
	std::cout << ( ft::is_integral< const int >::value ? "TRUE" : "FALSE" );
	std::cout << std::endl;
	std::cout << std::setw( 32 ) << "ft::is_integral< bool > : ";
	std::cout << ( ft::is_integral< bool >::value ? "TRUE" : "FALSE" );
	std::cout << std::endl;
	std::cout << std::setw( 32 ) << "f( 123 )" << f( 123 ) << std::endl;
	return ( 0 );
}