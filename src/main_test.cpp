/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:54:37 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/24 14:41:29 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <map>
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
	std::map< int, int >	my_map;
	std::vector< int >		my_vector;

	std::cout << "size of vector: " << sizeof(my_vector) << std::endl;
	std::cout << "size of map: " <<  sizeof(my_map) << std::endl;
	return (0);
}