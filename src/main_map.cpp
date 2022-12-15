/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:07:15 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/15 16:48:23 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <stdexcept>
# include <algorithm>
# include <iterator>
# include <vector>
# if STL
	# include <map>
	namespace ft = std;
# else
	# include "map.hpp"
# endif

typedef struct s
{
	long int	l1;
	long int	l2;
	long int	l3;
}	t_s;

void	constructors()
{
	{
		ft::map< int, int >	my_map;
		std::cout << "ft::map< int >	my_map;" << std::endl;
		ft::map< int, int >	my_map2( ft::less< int > );
		std::cout << "ft::map< int >	my_map2( ft::less< int > );" << std::endl;
		ft::map< int, int >	other_map( my_map );
		std::cout << "ft::map< int >	other_map( my_map );" << std::endl;
	}
	{
		std::vector< ft::pair< int, int > >	my_vector( 5, ft::make_pair( 3, 3 ) );
		ft::map< int, int >	my_map( my_vector.begin(), my_vector.end() );
		std::cout << "ft::map< int, int >	my_map( my_vector.begin(), my_vector.end() );" << std::endl;
	}
	return ;
}

void	modifiers()
{
	{
		ft::map< int, int >								my_map;
		ft::pair< ft::map< int, int >::iterator, bool >	res;
		ft::map< int, int >::size_type					res2;

		std::cout << "my_map.insert( ft::make_pair( 1, 1 ) );" << std::endl;
		res = my_map.insert( ft::make_pair( 1, 1 ) );
		std::cout << "insert done: " << (res.second ? "yes" : "no") << std::endl;
		std::cout << "my_map.insert( ft::make_pair( 2, 2 ) );" << std::endl;
		res = my_map.insert( ft::make_pair( 2, 2 ) );
		std::cout << "insert done: " << (res.second ? "yes" : "no") << std::endl;
		std::cout << "my_map.insert( ft::make_pair( 2, 3 ) );" << std::endl;
		res = my_map.insert( ft::make_pair( 2, 3 ) );
		std::cout << "insert done: " << (res.second ? "yes" : "no") << std::endl;
		std::cout << "my_map.erase( 2 );" << std::endl;
		res2 = my_map.erase( 2 );
		std::cout << "No of element erased: " << res2 << std::endl;
		std::cout << "my_map.erase( 2 );" << std::endl;
		res2 = my_map.erase( 2 );
		std::cout << "No of element erased: " << res2 << std::endl;
		std::cout << "my_map.clear();" << std::endl;
		my_map.clear();
	}
	return ;
}

void	capacity()
{
	{
		ft::map< int, int >	my_map;

		std::cout << "ft::map< int, int >	my_map;" << std::endl;
		std::cout << "is map empty ? " << (my_map.empty() ? "yes" : "no" ) << std::endl;
		my_map.insert( ft::make_pair( 1, 1 ) );
		std::cout << "inserted element: map size: " << my_map.size() << std::endl;
		my_map.insert( ft::make_pair( 2, 2 ) );
		std::cout << "inserted element: map size: " << my_map.size() << std::endl;
		std::cout << "is map empty ? " << (my_map.empty() ? "yes" : "no" ) << std::endl;
		my_map.insert( ft::make_pair( 3, 3 ) );
		std::cout << "inserted element: map size: " << my_map.size() << std::endl;
		my_map.clear();
		std::cout << "cleared map: map size: " << my_map.size() << std::endl;
		std::cout << "is map empty ? " << (my_map.empty() ? "yes" : "no" ) << std::endl;
		std::cout << "map max size: " << my_map.max_size() << std::endl;
	}
	{
		ft::map< int, t_s >	my_map;

		std::cout << "ft::map< int, t_s >	my_map;" << std::endl;
		std::cout << "map max size: " << my_map.max_size() << std::endl;
	}
	return ;
}

void	iterators()
{
	ft::map< int, int >	my_map;

	my_map.insert( ft::make_pair( 1, 1 ) );
	my_map.insert( ft::make_pair( 2, 2 ) );
	my_map.insert( ft::make_pair( 3, 3 ) );
	my_map.insert( ft::make_pair( 65, 56 ) );
	my_map.insert( ft::make_pair( 12, 12 ) );
	my_map.insert( ft::make_pair( -42, -42 ) );
	
	ft::map< int, int >::iterator		it = my_map.begin();
	ft::map< int, int >::const_iterator	itc = my_map.begin();
	ft::map< int, int >::const_iterator	ite = my_map.end();
	
	while ( it != ite )
	{
		std::cout << (*it).first << ", " << (*it).second << std::endl;
		it++;
	}
	while ( itc != ite )
	{
		std::cout << (*itc).first << ", " << (*itc).second << std::endl;
		itc++;
	}
	while ( it != my_map.begin() )
	{
		it--;
		it->second = 42;
	}
	while ( it != ite )
	{
		std::cout << it->first << ", " << it->second << std::endl;
		it++;
	}
	
	ft::map< int, int >::reverse_iterator		itr = my_map.rbegin();
	ft::map< int, int >::const_reverse_iterator	itre = my_map.rend();

	while ( itr != itre )
	{
		std::cout << itr->first << ", " << itr->second << std::endl;
		itr++;
	}
}

void	accessors()
{
	return ;
}

int	main()
{
	# if STL
		std::cout << "Using STL" << std::endl;
	# else
		std::cout << "Using FT" << std::endl;
	# endif
	std::cout << "<================ STACK MAIN =================>" << std::endl;
	std::cout << "-----------------Constructors------------------" << std::endl;
	constructors();
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "-------------------Modifiers-------------------" << std::endl;
	modifiers();
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "--------------------Capacity-------------------" << std::endl;
	capacity();
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "--------------------Iterators------------------" << std::endl;
	iterators();
	std::cout << "-----------------------------------------------" << std::endl;
	// std::cout << "-------------------Accessors-------------------" << std::endl;
	// accessors();
	// std::cout << "-----------------------------------------------" << std::endl;
}