/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:07:15 by aalleon           #+#    #+#             */
/*   Updated: 2023/01/09 13:18:20 by aalleon          ###   ########.fr       */
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

void	print_map( const ft::map< int, int >&	my_map )
{
	ft::map< int, int >::const_iterator	it;

	it = my_map.begin();
	while ( it != my_map.end() )
	{
		std::cout << "\t" << (*it).first << ", " << (*it).second << std::endl;
		it++;
	}
	return ;
}

void	constructors()
{
	{
		ft::map< int, int >	my_map;
		std::cout << "ft::map< int >	my_map;" << std::endl;
		ft::map< int, int >	my_map2( ft::less< int > );
		std::cout << "ft::map< int >	my_map2( ft::less< int > );" << std::endl;
		std::cout << "ft::map< int >	other_map( my_map );" << std::endl;
		ft::map< int, int >	other_map( my_map );
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
	// {
	// 	ft::map< int, t_s >	my_map;

	// 	std::cout << "ft::map< int, t_s >	my_map;" << std::endl;
	// 	std::cout << "map max size: " << my_map.max_size() << std::endl;
	// }
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
	{
		ft::map< int, int >	my_map;
		my_map.insert( ft::make_pair( 1, 1 ) );
		my_map.insert( ft::make_pair( 2, 2 ) );
		my_map.insert( ft::make_pair( 3, 3 ) );
		
		std::cout << "my_map[1]: " << my_map[1] << std::endl;
		std::cout << "my_map[2]: " << my_map[2] << std::endl;
		std::cout << "my_map[3]: " << my_map[3] << std::endl;
		
		std::cout << "my_map[4] = 4;" << std::endl;
		my_map[4] = 4;
		std::cout << "my_map.at(4): " << my_map.at( 4 ) << std::endl;
		try
		{
			std::cout << my_map.at( 5 ) << std::endl;
		}
		catch ( std::exception& e )
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::vector< ft::pair< int, int > >	my_vector( 4, ft::make_pair( 2, 2 ) );
		const ft::map< int, int >	const_map( my_vector.begin(), my_vector.end() );
		
		// std::cout << "const_map[1]: " << const_map[1] << std::endl; // COMPILE ERROR
		std::cout << "const_map.at( 2 ): " << const_map.at( 2 ) << std::endl;
		// const_map[3] = 3; // COMPILE ERROR
	}
	return ;
}

void	modifiers2( void )
{
	{
		std::vector< ft::pair< int, int > >	my_vector;
		ft::map< int, int >					my_map;
		ft::map< int, int >::iterator		it;
		
		my_vector.insert( my_vector.begin(), ft::make_pair( 42, 42 ) );
		my_vector.insert( my_vector.begin(), ft::make_pair( 43, 43 ) );
		my_vector.insert( my_vector.begin(), ft::make_pair( 44, 44 ) );
		my_vector.insert( my_vector.begin(), ft::make_pair( 45, 45 ) );
		my_vector.insert( my_vector.begin(), ft::make_pair( 46, 46 ) );
		my_map.insert( my_vector.begin(), my_vector.end() );
		it = my_map.begin();
		while ( it != my_map.end() )
		{
			std::cout << (*it).first << ", " << (*it).second << std::endl;
			it++;
		}
	}
	{
		ft::map< int, int >				my_map;
		ft::map< int, int >::iterator	it;
		
		my_map[1] = 1;
		my_map[2] = 2;
		my_map[3] = 3;
		my_map[4] = 4;
		my_map[5] = 5;
		
		std::cout << "my_map with 5 elements." << std::endl;
		print_map( my_map );

		it = my_map.insert( my_map.begin(), ft::make_pair( 6, 6 ) );
		std::cout << "it = my_map.insert( my_map.begin(), ft::make_pair( 6, 6 ) );" << std::endl;
		std::cout << "it : " << it->first << ", " << it->second << std::endl;
		print_map( my_map );
		
		++( it = my_map.begin() );
		my_map.erase( it, my_map.end() );
		std::cout << "my_map.erase( my_map.begin() + 1, my_map.last() );" << std::endl;
		print_map( my_map );

		my_map.erase( my_map.begin() );
		std::cout << "my_map.erase( my_map.begin() );" << std::endl;
		std::cout << "empty map: " << ( my_map.empty() ? "yes" : "no" ) << std::endl;
	}
	{
		ft::map< int, int >	my_map;
		ft::map< int, int >	my_map2;
		
		my_map[1] = 1;
		my_map[2] = 2;
		my_map[3] = 3;
		my_map2[4] = 4;
		my_map2[5] = 5;
		
		std::cout << "map1: " << std::endl;
		print_map( my_map );
		std::cout << "map2: " << std::endl;
		print_map( my_map2 );
		my_map.swap( my_map2 );
		// std::cout << "my_map empty?" << ( my_map.empty() ? "yes" : "no" ) << std::endl;
		std::cout << "map1: " << std::endl;
		print_map( my_map );
		std::cout << "map2: " << std::endl;
		print_map( my_map2 );
	}
	return ;
}

void	lookup( void )
{
	{
		ft::map< int, int >				my_map;
		ft::map< int, int >::iterator	range_start;
		ft::map< int, int >::iterator	range_end;
		ft::map< int, int >::iterator	bound;

		my_map[1] = 1;
		my_map[2] = 2;
		my_map[3] = 3;
		my_map[4] = 4;

		print_map( my_map );
		std::cout << "No of 1 element: " << my_map.count( 1 ) << std::endl;
		std::cout << "No of 6 element: " << my_map.count( 6 ) << std::endl;

		std::cout << "element 1: " << ( *my_map.find( 1 ) ).second << std::endl;
		std::cout << "equal_range( 2 ): " << std::endl;
		range_start = my_map.equal_range( 2 ).first;
		range_end = my_map.equal_range( 2 ).second;
		std::cout << "\tstart: " << ( range_start == my_map.end() ? -999999 : range_start->first ) << std::endl;
		std::cout << "\tend: " << ( range_end == my_map.end() ? -999999 : range_end->first ) << std::endl;
		std::cout << "equal_range( -3 ): " << std::endl;
		range_start = my_map.equal_range( -3 ).first;
		range_end = my_map.equal_range( -3 ).second;
		std::cout << "\tstart: " << ( range_start == my_map.end() ? -999999 : range_start->first ) << std::endl;
		std::cout << "\tend: " << ( range_end == my_map.end() ? -999999 : range_end->first ) << std::endl;
		std::cout << "equal_range( 9 ): " << std::endl;
		range_start = my_map.equal_range( 9 ).first;
		range_end = my_map.equal_range( 9 ).second;
		std::cout << "\tstart: " << ( range_start == my_map.end() ? -999999 : range_start->first ) << std::endl;
		std::cout << "\tend: " << ( range_end == my_map.end() ? -999999 : range_end->first ) << std::endl;
		std::cout << std::endl;
		bound = my_map.lower_bound( 2 );
		std::cout << "lower_bound( 2 ): " << ( bound == my_map.end() ? -999999 : bound->first ) << std::endl;
		bound = my_map.lower_bound( -3 );
		std::cout << "lower_bound( -3 ): " << ( bound == my_map.end() ? -999999 : bound->first ) << std::endl;
		bound = my_map.lower_bound( 9 );
		std::cout << "lower_bound( 9 ): " << ( bound == my_map.end() ? -999999 : bound->first ) << std::endl;
		bound = my_map.upper_bound( 2 );
		std::cout << "upper_bound( 2 ): " << ( bound == my_map.end() ? -999999 : bound->first ) << std::endl;
		bound = my_map.upper_bound( -3 );
		std::cout << "upper_bound( -3 ): " << ( bound == my_map.end() ? -999999 : bound->first ) << std::endl;
		bound = my_map.upper_bound( 9 );
		std::cout << "upper_bound( 9 ): " << ( bound == my_map.end() ? -999999 : bound->first ) << std::endl;
	}
	{
		ft::map< int, int >	my_map;

		my_map[1] = 1;
		my_map[2] = 2;
		my_map[3] = 3;
		my_map[4] = 4;

		const ft::map< int, int >			const_map( my_map );
		ft::map< int, int >::const_iterator	range_start;
		ft::map< int, int >::const_iterator	range_end;
		ft::map< int, int >::const_iterator	bound;

		print_map( const_map );
		std::cout << "No of 1 element: " << const_map.count( 1 ) << std::endl;
		std::cout << "No of 6 element: " << const_map.count( 6 ) << std::endl;

		std::cout << "element 1: " << ( *const_map.find( 1 ) ).second << std::endl;
		std::cout << "equal_range( 2 ): " << std::endl;
		range_start = const_map.equal_range( 2 ).first;
		range_end = const_map.equal_range( 2 ).second;
		std::cout << "\tstart: " << ( range_start == const_map.end() ? -999999 : range_start->first ) << std::endl;
		std::cout << "\tend: " << ( range_end == const_map.end() ? -999999 : range_end->first ) << std::endl;
		std::cout << "equal_range( -3 ): " << std::endl;
		range_start = const_map.equal_range( -3 ).first;
		range_end = const_map.equal_range( -3 ).second;
		std::cout << "\tstart: " << ( range_start == const_map.end() ? -999999 : range_start->first ) << std::endl;
		std::cout << "\tend: " << ( range_end == const_map.end() ? -999999 : range_end->first ) << std::endl;
		std::cout << "equal_range( 9 ): " << std::endl;
		range_start = const_map.equal_range( 9 ).first;
		range_end = const_map.equal_range( 9 ).second;
		std::cout << "\tstart: " << ( range_start == const_map.end() ? -999999 : range_start->first ) << std::endl;
		std::cout << "\tend: " << ( range_end == const_map.end() ? -999999 : range_end->first ) << std::endl;
		std::cout << std::endl;
		bound = const_map.lower_bound( 2 );
		std::cout << "lower_bound( 2 ): " << ( bound == const_map.end() ? -999999 : bound->first ) << std::endl;
		bound = const_map.lower_bound( -3 );
		std::cout << "lower_bound( -3 ): " << ( bound == const_map.end() ? -999999 : bound->first ) << std::endl;
		bound = const_map.lower_bound( 9 );
		std::cout << "lower_bound( 9 ): " << ( bound == const_map.end() ? -999999 : bound->first ) << std::endl;
		bound = const_map.upper_bound( 2 );
		std::cout << "upper_bound( 2 ): " << ( bound == const_map.end() ? -999999 : bound->first ) << std::endl;
		bound = const_map.upper_bound( -3 );
		std::cout << "upper_bound( -3 ): " << ( bound == const_map.end() ? -999999 : bound->first ) << std::endl;
		bound = const_map.upper_bound( 9 );
		std::cout << "upper_bound( 9 ): " << ( bound == const_map.end() ? -999999 : bound->first ) << std::endl;
	}
	return ;
}

void	comparison( void )
{
	{
		ft::map< int, int >	map1;
		ft::map< int, int >	map2;

		map1[1] = 1;
		map2[1] = 1;
		map1[2] = 2;
		map2[2] = 2;
		std::cout << "map1 == map2 : " << ( map1 == map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 != map2 : " << ( map1 != map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 < map2 : " << ( map1 < map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 > map2 : " << ( map1 > map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 <= map2 : " << ( map1 <= map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 >= map2 : " << ( map1 >= map2 ? "yes" : "no" ) << std::endl;
		std::cout << std::endl;
		map1[3] = 3;
		map2[3] = 4;
		std::cout << "map1 == map2 : " << ( map1 == map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 != map2 : " << ( map1 != map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 < map2 : " << ( map1 < map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 > map2 : " << ( map1 > map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 <= map2 : " << ( map1 <= map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 >= map2 : " << ( map1 >= map2 ? "yes" : "no" ) << std::endl;
		std::cout << std::endl;
		map2.erase( 3 );
		std::cout << "map1 == map2 : " << ( map1 == map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 != map2 : " << ( map1 != map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 < map2 : " << ( map1 < map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 > map2 : " << ( map1 > map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 <= map2 : " << ( map1 <= map2 ? "yes" : "no" ) << std::endl;
		std::cout << "map1 >= map2 : " << ( map1 >= map2 ? "yes" : "no" ) << std::endl;
	}
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
	std::cout << "-------------------Accessors-------------------" << std::endl;
	accessors();
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "-------------------Modifiers2------------------" << std::endl;
	modifiers2();
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "---------------------Lookup--------------------" << std::endl;
	lookup();
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "---------------------Lookup--------------------" << std::endl;
	comparison();
	std::cout << "-----------------------------------------------" << std::endl;
}