/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:54:37 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/16 16:13:54 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <stdexcept>
#include <iostream>

struct S
{
private:
	int	_n;
public:
	S( int n = 0 ) 
	{
		std::cout << "construct S instance with n = " << n << std::endl;
		if (n == 42)
			throw (std::exception());
		_n = n;
	}
	~S() { return ; }
	S( const S& other ) : _n( other._n )
	{
		std::cout << "construct S by copy with n = " << other._n << std::endl;
		return ;
	}
	S&	operator=( const S& rhs )
	{
		if ( rhs._n == 42 )
			throw (std::exception());
		_n = rhs._n;
		return (*this);
	}
	int		getN() const { return _n; }
	void	setN( int n ) { std::cout << "setting n to new value" << std::endl; _n = n; }
};

int main()
{
	std::vector< S >				v( 4, S(2) );
	std::vector< S >::iterator	it;

	std::cout << "v address: " << v.data() << std::endl;
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	v[2].setN(41);
	v[3].setN(42);
	try
	{
		it = v.erase(v.begin() + 1);
	}
	catch (std::exception& e)
	{
		std::cout << "exception thrown." << std::endl;
	}
	// it = v.insert( v.begin() + 1, 3 );
	std::cout << "v address: " << v.data() << std::endl;
	std::cout << "v[0]: " << v[0].getN() << std::endl;
	std::cout << "v[1]: " << v[1].getN() << std::endl;
	std::cout << "v[2]: " << v[2].getN() << std::endl;
	std::cout << "v[3]: " << v[3].getN() << std::endl;
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	
	return (0);
}