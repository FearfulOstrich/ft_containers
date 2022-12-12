/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:54:37 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/12 14:00:56 by aalleon          ###   ########.fr       */
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
	std::vector< std::pair< int, int > >	my_vector = { std::make_pair(1, 1), std::make_pair(2, 2), std::make_pair(3, 3), std::make_pair(6, 2), std::make_pair(7, 3) };
	std::map< int, int >	my_map;
	
	my_map.insert(my_vector.begin(), my_vector.end());
	// my_map[4] = 4;
	my_map[5] = 5;
	std::cout << "my_map size: " << my_map.size() << std::endl;
	for	( std::map< int, int >::iterator it = my_map.begin(); it != my_map.end(); it++ )
		std::cout << "my_map element: " << it->first << ", " << it->second << std::endl;
	// std::cout << "equal_range(2).second == end() -> " << (my_map.equal_range(2).second == my_map.end() ? "yes" : "no") << std::endl;
	// std::cout << "equal_range(3).first == end() -> " << (my_map.equal_range(3).first == my_map.end() ? "yes" : "no") << std::endl;
	// std::cout << "equal_range.first: " << my_map.equal_range(1).first->first << ", " << my_map.equal_range(1).first->second << std::endl;
	// std::cout << "equal_range.second: " << my_map.equal_range(1).second->first << ", " << my_map.equal_range(1).second->second << std::endl;
	// std::cout << "equal_range(0).first == end() -> " << (my_map.equal_range(0).second == my_map.end() ? "yes" : "no") << std::endl;
	// std::cout << "equal_range(0).second == end() -> " << (my_map.equal_range(0).second == my_map.end() ? "yes" : "no") << std::endl;
	// std::cout << "equal_range.first: " << my_map.equal_range(0).first->first << ", " << my_map.equal_range(0).first->second << std::endl;
	// std::cout << "equal_range.second: " << my_map.equal_range(0).second->first << ", " << my_map.equal_range(0).second->second << std::endl;
	std::cout << "lower_bound(3): " << my_map.lower_bound(3)->first << std::endl;
	std::cout << "upper_bound(3): " << my_map.upper_bound(3)->first << std::endl;
	std::cout << "lower_bound(4): " << my_map.lower_bound(4)->first << std::endl;
	std::cout << "upper_bound(4): " << my_map.upper_bound(4)->first << std::endl;
	std::cout << "lower_bound(9): " << my_map.lower_bound(9)->first << " but: ";
	std::cout << "lower_bound(9) == end(): " << (my_map.lower_bound(9) == my_map.end()) << std::endl;
	std::cout << "upper_bound(9): " << my_map.upper_bound(9)->first << " but: ";
	std::cout << "upper_bound(9) == end(): " << (my_map.upper_bound(9) == my_map.end()) << std::endl;
	std::cout << "lower_bound(-1): " << my_map.lower_bound(-1)->first << std::endl;
	std::cout << "upper_bound(-1): " << my_map.upper_bound(-1)->first << std::endl;

	return ( 0 );
}