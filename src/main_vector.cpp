/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:58:19 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/21 16:43:30 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "vector"
namespace ft = std;

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

int main()
{
	// Create empty vector.
	std::vector< S >	first;
	std::cout << "std::vector< S >	first;" << std::endl;
	std::cout << "first capacity: " << first.capacity() << std::endl;
	std::cout << "first size: " << first.size() << std::endl;
	
	// Create value vector.
	std::vector< S >	second( 10, S( 42, 42 ) );
	std::cout << "std::vector< S >	second( 10, S( 42, 42 ) );" << std::endl;
	std::cout << "second capacity: " << second.capacity() << std::endl;
	std::cout << "second size: " << second.size() << std::endl;
	
	// Create copy vector
	std::vector< S >	third( second );
	std::cout << "std::vector< S >	third( second );" << std::endl;
	std::cout << "third capacity: " << third.capacity() << std::endl;
	std::cout << "third size: " << third.size() << std::endl;
	std::cout << "third alloc == second alloc : ";
	std::cout << ( second.get_allocator() == third.get_allocator() ?\
					"true" : "false" ) << std::endl; 

	std::cout << "===============================================" << std::endl;

	// Assign operator
	std::vector< S >	fourth( 13, S( 41, 41 ) );
	std::cout << "std::vector< S >	fourth( 13, S( 41, 41 ) );" << std::endl;
	fourth = second;
	std::cout << "fourth = second" << std::endl;
	std::cout << "fourth capacity: " << fourth.capacity() << std::endl;
	std::cout << "fourth size: " << fourth.size() << std::endl;
	std::cout << "second[9]: " << second[9] << std::endl;
	std::cout << "fourth[9]: " << fourth[9] << std::endl;
	std::cout << "fourth[10]: " << fourth[10] << std::endl;
	
	std::vector< S >	fifth( 3, S( 41, 41 ) );
	std::cout << "std::vector< S >	fifth( 3, S( 41, 41 ) );" << std::endl;
	fifth = second;
	std::cout << "fifth = second" << std::endl;
	std::cout << "fifth capacity: " << fifth.capacity() << std::endl;
	std::cout << "fifth size: " << fifth.size() << std::endl;
	std::cout << "fifth[0]: " << fifth[0] << std::endl;
	
	std::cout << "===============================================" << std::endl;

	// Assign function
	std::vector< S >	sixth( 13, S( 41, 41 ) );
	std::cout << "std::vector< S >	sixth( 13, S( 41, 41 ) );" << std::endl;
	sixth.assign( 10, S( 42, 42 ) );
	std::cout << "sixth.assign( 10, S( 42, 42 ) )" << std::endl;
	std::cout << "sixth capacity: " << sixth.capacity() << std::endl;
	std::cout << "sixth size: " << sixth.size() << std::endl;
	std::cout << "sixth[9]: " << sixth[9] << std::endl;
	std::cout << "sixth[10]: " << sixth[10] << std::endl;
	
	std::vector< S >	seventh( 3, S( 41, 41 ) );
	std::cout << "std::vector< S >	seventh( 3, S( 41, 41 ) );" << std::endl;
	seventh.assign( 10 , S( 42, 42 ) );
	std::cout << "seventh = second" << std::endl;
	std::cout << "seventh capacity: " << seventh.capacity() << std::endl;
	std::cout << "seventh size: " << seventh.size() << std::endl;
	std::cout << "fifth[0]: " << fifth[0] << std::endl;

	return (0);
}