/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:58:19 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/10 13:53:03 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <stdexcept>
// # include "vector"
#if STL
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

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
	std::cout << ( second.get_allocator() == third.get_allocator() ?
					"true" : "false" ) << std::endl; 

	const ft::vector< S >	forth;
	std::cout << "const ft::vector< S >	forth;" << std::endl;
	std::cout << "forth capacity: " << forth.capacity() << std::endl;
	std::cout << "forth capacity: " << forth.size() << std::endl;
	const ft::vector< S >	fifth( 10, S( 42, 42 ) );
	std::cout << "const ft::vector< S > 	fifth( 10, S( 42, 42 ) );" << std::endl;
	std::cout << "fifth capacity: " << forth.capacity() << std::endl;
	std::cout << "fifth size: " << fifth.size() << std::endl;
	const ft::vector< S >	sixth( fifth );
	std::cout << "const ft::vector< S >	sixth( fifth );" << std::endl;
	std::cout << "sixth capacity: " << forth.capacity() << std::endl;
	std::cout << "sixth size: " << sixth.size() << std::endl;

	
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
	
	const ft::vector< S >	third( 13, S( 41, 41 ) );
	std::cout << "std::vector< S >	third( 13, S( 41, 41 ) );" << std::endl;
	// third.assign( 10, S( 42, 42 ) ); // Does not compile.
	std::cout << "third.assign( 10, S( 42, 42 ) ); does not compile.";

	// ft::vector< S >	third;
	// third.assign( first.begin(), first.end() );
	// std::cout << "third.assign( first.begin(), first.end() );" << std::endl;
	// std::cout << "third capacity: " << third.capacity() << std::endl;
	// std::cout << "third size: " << third.size() << std::endl;

	std::cout << "===============================================" << std::endl;
	return ;
}

void	access( void )
{
	ft::vector< S >			first( 5, S( 42, 42 ));
	const ft::vector< S >	second( 5, S( 56, 56 ) );

	std::cout << "ft::vector< S >	first( 5, ( 42, 42 ));" << std::endl;
	std::cout << "const ft::vector< S >	second( 5, ( 42, 42 ));" << std::endl;
	for ( unsigned int i = 0; i < 5; i++ )
	{
		std::cout << "first.at(" << i << "): " << first.at( i ) << std::endl;
		std::cout << "first[" << i << "]: " << first[i] << std::endl;
	}
	for ( unsigned int i = 0; i < 5; i++ )
	{
		std::cout << "second.at(" << i << "): " << second.at( i ) << std::endl;
		std::cout << "second[" << i << "]: " << second[i] << std::endl;	
	}
	try
	{
		std::cout << "first.at(6): " << first.at( 6 ) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "first.at(6): exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "second.at(6): " << second.at( 6 ) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "second.at(6): exception: " << e.what() << std::endl;
	}
	std::cout << "first.at(0) = S( 56, 56 );" << std::endl;
	first.at( 0 ) = S( 56, 56 );
	std::cout << "first.front(): " << first.front() << std::endl;
	std::cout << "second.front(): " << second.front() << std::endl;
	std::cout << "first.back(): " << first.back() << std::endl;
	std::cout << "second.back(): " << second.back() << std::endl;
	std::cout << "first[1] = S( 56, 56 );" << std::endl;
	first[1] = S( 56, 56 );
	std::cout << "first.data()[1]: " << first.data()[1] << std::endl;
	std::cout << "second.data()[1]: " << second.data()[1] << std::endl;
	std::cout << "first.back() = S( 56, 56 );" << std::endl;
	first.back() = S( 56, 56 );
	std::cout << "first.back(): " << first.back() << std::endl;
	std::cout << "===============================================" << std::endl;
	return ;
}

void	capacity( void )
{
	ft::vector< S >			first( 3, S( 63, 63 ) );
	ft::vector< S >			second;
	ft::vector< S >			third( 7, S( 63, 63 ) );
	const ft::vector< S >	forth( 4, S ( 64, 64 ) );

	std::cout << "ft::vector< int >	first( 3, S( 63, 63 ) );" << std::endl;
	std::cout << "first.empty(): " << ( first.empty() ? "true" : "false" ) << std::endl;
	std::cout << "first.size(): " << first.size() << std::endl;
	std::cout << "first.max_size(): " << first.max_size() << std::endl;
	std::cout << "first.capacity(): " << first.capacity() << std::endl;
	first.reserve( 4 );
	std::cout << "first.reserve( 4 );" << std::endl;
	std::cout << "first.size(): " << first.size() << std::endl;
	std::cout << "first.capacity(): " << first.capacity() << std::endl;
	
	std::cout << "ft::vector< int >	second;" << std::endl;
	std::cout << "second.empty(): " << ( second.empty() ? "true" : "false" ) << std::endl;
	std::cout << "second.size(): " << second.size() << std::endl;
	
	std::cout << "ft::vector< int >	third( 7, S( 63, 63 ) );" << std::endl;
	third = first;
	std::cout << "third = first;" << std::endl;
	std::cout << "third.empty(): " << ( third.empty() ? "true" : "false" ) << std::endl;
	std::cout << "third.size(): " << third.size() << std::endl;
	std::cout << "third.max_size(): " << third.max_size() << std::endl;
	std::cout << "third.capacity(): " << third.capacity() << std::endl;
		
	std::cout << "const ft::vector< int >	forth( 4, S( 64, 64 ) );" << std::endl;
	std::cout << "forth.empty(): " << ( forth.empty() ? "true" : "false" ) << std::endl;
	std::cout << "forth.size(): " << forth.size() << std::endl;
	std::cout << "forth.max_size(): " << forth.max_size() << std::endl;
	std::cout << "forth.capacity(): " << forth.capacity() << std::endl;
	std::cout << "forth.reserve( 5 ); // ->DOES NOT COMPILE" << std::endl;
	// forth.reserve( 5 ); // Does not compile

	std::cout << "===============================================" << std::endl;
	return ;
}


// void	iterator_functions( void )
// {
// 	ft::vector< S >	first;
// 	ft::vector< S >	second( 4, S( 42, 42 ) );
// 	ft::vector< S >	third( 4, S( 42, 42 ) );
	
// 	std::cout << "iterator	it1( first.begin() );" << std::endl;
// 	ft::vector< S >::iterator	it1( first.begin() );
// 	std::cout << "iterator	ite1( first.end() );" << std::endl;
// 	ft::vector< S >::iterator	ite1( first.end() );
// 	std::cout << "iterator	it2( second.begin() );" << std::endl;
// 	ft::vector< S >::iterator	it2( second.begin() );
// 	std::cout << "iterator	ite2( second.end() );" << std::endl;
// 	ft::vector< S >::iterator	ite2( second.end() );
// 	std::cout << "*it2: " << *it2 << std::endl;
// 	std::cout << "it2 == ite2 ? " << (it2 == ite2 ? "TRUE" : "FALSE") << std::endl;
// 	std::cout << "const_iterator	it3( third.begin() );" << std::endl;
// 	ft::vector< S >::const_iterator	it3( third.begin() );
// 	std::cout << "const_iterator	ite3( third.end() );" << std::endl;
// 	ft::vector< S >::const_iterator	ite3( third.end() );
// 		std::cout << "*it3: " << *it3 << std::endl;
// 	// for (; it3 != ite3; it3++)
// 	std::cout << "===============================================" << std::endl;
// 	return ;
// }

int main()
{
#if STL
	std::cout << "Using STL" << std::endl;
#else
	std::cout << "Using FT" << std::endl;
#endif
	std::cout << "=========== TEST CONSTRUCTORS ================ " << std::endl;
	constructors();
	std::cout << "=============== TEST ASSIGN ================== " << std::endl;
	assignment();
	std::cout << "=============== TEST ACCESS ================== " << std::endl;
	access();
	std::cout << "=============== TEST CAPACITY ================ " << std::endl;
	capacity();
	// std::cout << "============== TEST ITERATOR ================= " << std::endl;
	// iterator_functions();
	return (0);
}