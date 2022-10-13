/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_equal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:29:47 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/13 14:26:35 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#if STL
	#include <algorithm>
	namespace ft = std;
#else
	#include "equal.hpp"
	#include "lexicographical_compare.hpp"
#endif

template< typename T>
void	print_vector( std::vector< T > v )
{
	typename std::vector< T >::iterator	it;

	it = v.begin();
	for ( ; it != v.end(); it++ )
	{
		std::cout << *it;
		if ( it + 1 != v.end() )
			std::cout << " | ";
	}
	std::cout << std::endl;
	return ;
}

bool	binary_predicate( int a, int b )
{
	return ( a == b );
}

bool	my_compare( char a, char b )
{
	return ( a < b );
}

int	main()
{
#if STL
	std::cout << "Using STL" << std::endl;
#else
	std::cout << "Using ft" << std::endl;
#endif
	{
		std::cout << "============ EQUAL =============" << std::endl;
		std::vector< int >	v1( 3, 100 );
		std::vector< int >	v2( 3, 100 );
		std::vector< int >	v3( 4, 100 );
		std::vector< int >	v4( 3, 200 );
		
		print_vector<int>(v1);
		print_vector<int>(v2);
		print_vector<int>(v3);
		print_vector<int>(v4);
		std::cout << "v1 == v2 : ";
		std::cout << ( ft::equal( v1.begin(), v1.end(), v2.begin() ) ?\
						"TRUE" : "FALSE" );
		std::cout << std::endl;
		std::cout << "v1 == v3 : ";
		std::cout << ( ft::equal( v1.begin(), v1.end(), v3.begin() ) ?\
						"TRUE" : "FALSE" );
		std::cout << std::endl;
		std::cout << "v1 == v4 : ";
		std::cout << ( ft::equal( v1.begin(), v1.end(), v4.begin() ) ?\
						"TRUE" : "FALSE" );
		std::cout << std::endl;
		std::cout << "v1 bp v2 : ";
		std::cout << ( ft::equal( v1.begin(), v1.end(), v2.begin(),\
									binary_predicate ) ? "TRUE" : "FALSE" );
		std::cout << std::endl;
		std::cout << "v1 bp v3 : ";
		std::cout << ( ft::equal( v1.begin(), v1.end(), v3.begin(),\
									binary_predicate ) ? "TRUE" : "FALSE" );
		std::cout << std::endl;
		std::cout << "v1 bp v4 : ";
		std::cout << ( ft::equal( v1.begin(), v1.end(), v4.begin(),\
									binary_predicate ) ? "TRUE" : "FALSE" );
		std::cout << std::endl;
	}
	{
		std::cout << "========= lexico compare =========" << std::endl;
		std::string			str1 = "abcdef";
		std::string			str2 = "aabcdef";
		std::string			str3 = "bcdef";
		std::vector< char >	v1( str1.begin(), str1.end() );
		std::vector< char >	v2( str2.begin(), str2.end() );
		std::vector< char >	v3( str2.begin(), str2.end() - 1 );
		std::vector< char >	v4( str3.begin(), str3.end() );
		
		print_vector< char >(v1);
		print_vector< char >(v2);
		print_vector< char >(v3);
		print_vector< char >(v4);
		std::cout << "v1 lex comp v1 : ";
		std::cout << ( ft::lexicographical_compare( v1.begin(), v1.end(),\
							v1.begin(), v1.end() ) ? "TRUE" : "FALSE" );
		std::cout << std::endl;
		std::cout << "v1 lex comp v2 : ";
		std::cout << ( ft::lexicographical_compare( v1.begin(), v1.end(),\
							v2.begin(), v2.end() ) ? "TRUE" : "FALSE" );
		std::cout << std::endl;
		std::cout << "v1 lex comp v3 : ";
		std::cout << ( ft::lexicographical_compare( v1.begin(), v1.end(),\
							v3.begin(), v3.end() ) ? "TRUE" : "FALSE" );
		std::cout << std::endl;
		std::cout << "v1 lex comp v4 : ";
		std::cout << ( ft::lexicographical_compare( v1.begin(), v1.end(),\
							v4.begin(), v4.end() ) ? "TRUE" : "FALSE" );
		std::cout << std::endl;
		std::cout << "v1 lex comp f v1 : ";
		std::cout << ( ft::lexicographical_compare( v1.begin(), v1.end(),\
							v1.begin(), v1.end() , my_compare )\
								? "TRUE" : "FALSE" );
		std::cout << std::endl;
		std::cout << "v1 lex comp f v2 : ";
		std::cout << ( ft::lexicographical_compare( v1.begin(), v1.end(),\
							v2.begin(), v2.end() , my_compare )\
								? "TRUE" : "FALSE" );
		std::cout << std::endl;
		std::cout << "v1 lex comp f v3 : ";
		std::cout << ( ft::lexicographical_compare( v1.begin(), v1.end(),\
							v3.begin(), v3.end(), my_compare )\
								? "TRUE" : "FALSE" );
		std::cout << std::endl;
		std::cout << "v1 lex comp f v4 : ";
		std::cout << ( ft::lexicographical_compare( v1.begin(), v1.end(),\
							v4.begin(), v4.end(), my_compare )\
								? "TRUE" : "FALSE" );
		std::cout << std::endl;
	}
	return ( 0 );
}
