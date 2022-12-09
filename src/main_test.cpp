/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:54:37 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/09 08:35:31 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>
# include <limits>

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
	std::vector< std::pair< int, int > >	my_vector = { std::make_pair(1, 1), std::make_pair(2, 2), std::make_pair(2, 3)};
	std::map< int, int >	my_map;
	
	my_map.insert(my_vector.begin(), my_vector.end());
	std::cout << "my_map size: " << my_map.size() << std::endl;
	for	( std::map< int, int >::iterator it = my_map.begin(); it != my_map.end(); it++ )
		std::cout << "my_map element: " << it-> first << ", " << it->second << std::endl;
	// std::cout << "Insert worked: " << (verif_it.second ? "yes" : "no") << std::endl;
	// std::cout << verif_it.first->first << ", " << verif_it.first->second << std::endl;
	return ( 0 );
}