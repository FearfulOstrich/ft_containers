/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:58:19 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/25 22:17:54 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
// # include "vector"
// #if STL
	#include <vector>
	namespace ft = std;
// #else
	// #include "vector.hpp"
// #endif

class S
{
	int		_n;
	char	_c;

public:
	S( int n = 0,  char c = 0 ) : _n( n ), _c( c ) { return ; }
	S( const S& other ) : _n( other._n ), _c( other._c ) { return ; }
	~S() { return ; }
	
	int		getN() const { return _n; }
	char	getC() const { return _c; }
};

std::ostream&	operator<<( std::ostream& os, const S& obj )
{
	os << "_n{" << obj.getN() << "} _c{" << obj.getC() << "}";
	return (os);
}

void	constructors( void )
{
	// Create empty vector.
	ft::vector< S >	first;
	std::cout << "std::vector< S >	first;" << std::endl;
	std::cout << "first capacity: " << first.capacity() << std::endl;
	std::cout << "first size: " << first.size() << std::endl;
	
	// Create value vector.
	ft::vector< S >	second( 10, S( 42, 42 ) );
	std::cout << "std::vector< S >	second( 10, S( 42, 42 ) );" << std::endl;
	std::cout << "second capacity: " << second.capacity() << std::endl;
	std::cout << "second size: " << second.size() << std::endl;
	
	// Create copy vector
	ft::vector< S >	third( second );
	std::cout << "std::vector< S >	third( second );" << std::endl;
	std::cout << "third capacity: " << third.capacity() << std::endl;
	std::cout << "third size: " << third.size() << std::endl;
	std::cout << "third alloc == second alloc : ";
	std::cout << ( second.get_allocator() == third.get_allocator() ?\
					"true" : "false" ) << std::endl; 

	std::cout << "===============================================" << std::endl;

	// Assign operator
	ft::vector< S >	fourth( 13, S( 41, 41 ) );
	std::cout << "std::vector< S >	fourth( 13, S( 41, 41 ) );" << std::endl;
	fourth = second;
	std::cout << "fourth = second" << std::endl;
	std::cout << "fourth capacity: " << fourth.capacity() << std::endl;
	std::cout << "fourth size: " << fourth.size() << std::endl;
	std::cout << "second[9]: " << second[9] << std::endl;
	std::cout << "fourth[9]: " << fourth[9] << std::endl;
	std::cout << "fourth[10]: " << fourth[10] << std::endl;
	
	ft::vector< S >	fifth( 3, S( 41, 41 ) );
	std::cout << "std::vector< S >	fifth( 3, S( 41, 41 ) );" << std::endl;
	fifth = second;
	std::cout << "fifth = second" << std::endl;
	std::cout << "fifth capacity: " << fifth.capacity() << std::endl;
	std::cout << "fifth size: " << fifth.size() << std::endl;
	std::cout << "fifth[0]: " << fifth[0] << std::endl;
	
	std::cout << "===============================================" << std::endl;
	return ;
}

void	assignment( void )
{
	// Assign function
	ft::vector< S >	first( 13, S( 41, 41 ) );
	std::cout << "std::vector< S >	first( 13, S( 41, 41 ) );" << std::endl;
	first.assign( 10, S( 42, 42 ) );
	std::cout << "first.assign( 10, S( 42, 42 ) )" << std::endl;
	std::cout << "first capacity: " << first.capacity() << std::endl;
	std::cout << "first size: " << first.size() << std::endl;
	std::cout << "first[9]: " << first[9] << std::endl;
	std::cout << "first[10]: " << first[10] << std::endl;
	
	ft::vector< S >	second( 3, S( 41, 41 ) );
	std::cout << "std::vector< S >	second( 3, S( 41, 41 ) );" << std::endl;
	second.assign( 10 , S( 42, 42 ) );
	std::cout << "second.assign( 10 , S( 42, 42 ) );" << std::endl;
	std::cout << "second capacity: " << second.capacity() << std::endl;
	std::cout << "second size: " << second.size() << std::endl;

	// ft::vector< S >	third;
	// third.assign( first.begin(), first.end() );
	// std::cout << "third.assign( first.begin(), first.end() );" << std::endl;
	// std::cout << "third capacity: " << third.capacity() << std::endl;
	// std::cout << "third size: " << third.size() << std::endl;

	std::cout << "===============================================" << std::endl;
	return ;
}

int main()
{
#if STL
	std::cout << "Using STL" << std::endl;
#else
	std::cout << "Using ft" << std::endl;
#endif
	std::cout << "=========== TEST CONSTRUCTORS ================ " << std::endl;
	constructors();
	std::cout << "=============== TEST ASSIGN ================== " << std::endl;
	assignment();
	return (0);
}