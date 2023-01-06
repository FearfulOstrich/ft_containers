/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:30:05 by aalleon           #+#    #+#             */
/*   Updated: 2023/01/06 17:16:36 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <stdexcept>
# include <algorithm>
# include <iterator>
# include <vector>
# if STL
	# include <set>
	namespace ft = std;
# else
	# include "set.hpp"
# endif

typedef struct s
{
	long int	l1;
	long int	l2;
	long int	l3;
}	t_s;

void	print_set( const ft::set< int >&	my_set )
{
	ft::set< int >::const_iterator	it;

	it = my_set.begin();
	while ( it != my_set.end() )
	{
		std::cout << "\t" << *it << std::endl;
		it++;
	}
	return ;
}

void	constructors()
{
	{
		ft::set< int >	my_set;
		std::cout << "ft::set< int >	my_set;" << std::endl;
		ft::set< int >	my_set2( ft::less< int > );
		std::cout << "ft::set< int >	my_set2( ft::less< int > );" << std::endl;
		std::cout << "ft::set< int >	other_set( my_set );" << std::endl;
		ft::set< int >	other_set( my_set );
	}
	{
		std::vector< int >	my_vector( 5, 3 );
		ft::set< int >	my_set( my_vector.begin(), my_vector.end() );
		std::cout << "ft::set< int >	my_set( my_vector.begin(), my_vector.end() );" << std::endl;
	}
	return ;
}

void	modifiers()
{
	{
		ft::set< int >								my_set;
		ft::pair< ft::set< int >::iterator, bool >	res;
		ft::set< int >::size_type					res2;

		std::cout << "my_set.insert( 1 );" << std::endl;
		res = my_set.insert( 1 );
		std::cout << "insert done: " << (res.second ? "yes" : "no") << std::endl;
		std::cout << "my_set.insert( 2 );" << std::endl;
		res = my_set.insert( 2 );
		std::cout << "insert done: " << (res.second ? "yes" : "no") << std::endl;
		std::cout << "my_set.insert( 2 );" << std::endl;
		res = my_set.insert( 2 );
		std::cout << "insert done: " << (res.second ? "yes" : "no") << std::endl;
		std::cout << "my_set.erase( 2 );" << std::endl;
		res2 = my_set.erase( 2 );
		std::cout << "No of element erased: " << res2 << std::endl;
		std::cout << "my_set.erase( 2 );" << std::endl;
		res2 = my_set.erase( 2 );
		std::cout << "No of element erased: " << res2 << std::endl;
		std::cout << "my_set.clear();" << std::endl;
		my_set.clear();
	}
	return ;
}

void	capacity()
{
	{
		ft::set< int >	my_set;

		std::cout << "ft::set< int >	my_set;" << std::endl;
		std::cout << "is set empty ? " << (my_set.empty() ? "yes" : "no" ) << std::endl;
		my_set.insert( 1 );
		std::cout << "inserted element: set size: " << my_set.size() << std::endl;
		my_set.insert( 2 );
		std::cout << "inserted element: set size: " << my_set.size() << std::endl;
		std::cout << "is set empty ? " << (my_set.empty() ? "yes" : "no" ) << std::endl;
		my_set.insert( 3 );
		std::cout << "inserted element: set size: " << my_set.size() << std::endl;
		my_set.clear();
		std::cout << "cleared set: set size: " << my_set.size() << std::endl;
		std::cout << "is set empty ? " << (my_set.empty() ? "yes" : "no" ) << std::endl;
		std::cout << "set max size: " << my_set.max_size() << std::endl;
	}
	return ;
}

void	iterators()
{
	ft::set< int >	my_set;

	my_set.insert( 1 );
	my_set.insert( 2 );
	my_set.insert( 3 );
	my_set.insert( 65 );
	my_set.insert( 12 );
	my_set.insert( -42 );
	
	ft::set< int >::iterator		it = my_set.begin();
	ft::set< int >::const_iterator	itc = my_set.begin();
	ft::set< int >::const_iterator	ite = my_set.end();
	
	while ( it != ite )
	{
		std::cout << *it << std::endl;
		it++;
	}
	while ( itc != ite )
	{
		std::cout << *itc << std::endl;
		itc++;
	}
	while ( it != my_set.begin() )
	{
		it--;
	}
	while ( it != ite )
	{
		std::cout << *it << std::endl;
		it++;
	}
	ft::set< int >::reverse_iterator		itr = my_set.rbegin();
	ft::set< int >::const_reverse_iterator	itre = my_set.rend();

	while ( itr != itre )
	{
		std::cout << *itr << std::endl;
		itr++;
	}
}

void	modifiers2( void )
{
	{
		std::vector< int >			my_vector;
		ft::set< int >				my_set;
		ft::set< int >::iterator	it;
		
		my_vector.insert( my_vector.begin(), 42 );
		my_vector.insert( my_vector.begin(), 43 );
		my_vector.insert( my_vector.begin(), 44 );
		my_vector.insert( my_vector.begin(), 45 );
		my_vector.insert( my_vector.begin(), 46 );
		my_set.insert( my_vector.begin(), my_vector.end() );
		it = my_set.begin();
		while ( it != my_set.end() )
		{
			std::cout << *it << std::endl;
			it++;
		}
	}
	{
		ft::set< int >				my_set;
		ft::set< int >::iterator	it;
		
		my_set.insert( 1 );
		my_set.insert( 2 );
		my_set.insert( 3 );
		my_set.insert( 4 );
		my_set.insert( 5 );
		
		std::cout << "my_set with 5 elements." << std::endl;
		print_set( my_set );

		it = my_set.insert( my_set.begin(), 6 );
		std::cout << "it = my_set.insert( my_set.begin(), 6 );" << std::endl;
		std::cout << "it : " << *it << std::endl;
		print_set( my_set );
		
		++( it = my_set.begin() );
		my_set.erase( it, my_set.end() );
		std::cout << "my_set.erase( my_set.begin() + 1, my_set.last() );" << std::endl;
		print_set( my_set );

		my_set.erase( my_set.begin() );
		std::cout << "my_set.erase( my_set.begin() );" << std::endl;
		std::cout << "empty set: " << ( my_set.empty() ? "yes" : "no" ) << std::endl;
	}
	{
		ft::set< int >	my_set;
		ft::set< int >	my_set2;
		
		my_set.insert( 1 );
		my_set.insert( 2 );
		my_set.insert( 3 );
		my_set2.insert( 4 );
		my_set2.insert( 5 );

		std::cout << "set1: " << std::endl;
		print_set( my_set );
		std::cout << "set2: " << std::endl;
		print_set( my_set2 );
		my_set.swap( my_set2 );
		// std::cout << "my_set empty?" << ( my_set.empty() ? "yes" : "no" ) << std::endl;
		std::cout << "set1: " << std::endl;
		print_set( my_set );
		std::cout << "set2: " << std::endl;
		print_set( my_set2 );
	}
	return ;
}

void	lookup( void )
{
	{
		ft::set< int >				my_set;
		ft::set< int >::iterator	range_start;
		ft::set< int >::iterator	range_end;
		ft::set< int >::iterator	bound;

		my_set.insert( 1 );
		my_set.insert( 2 );
		my_set.insert( 3 );
		my_set.insert( 4 );

		print_set( my_set );
		std::cout << "No of 1 element: " << my_set.count( 1 ) << std::endl;
		std::cout << "No of 6 element: " << my_set.count( 6 ) << std::endl;

		std::cout << "element 1: " << ( *my_set.find( 1 ) ) << std::endl;
		std::cout << "equal_range( 2 ): " << std::endl;
		range_start = my_set.equal_range( 2 ).first;
		range_end = my_set.equal_range( 2 ).second;
		std::cout << "\tstart: " << *range_start << std::endl;
		std::cout << "\tend: " << *range_end << std::endl;
		std::cout << "equal_range( -3 ): " << std::endl;
		range_start = my_set.equal_range( -3 ).first;
		range_end = my_set.equal_range( -3 ).second;
		std::cout << "\tstart: " << *range_start << std::endl;
		std::cout << "\tend: " << *range_end << std::endl;
		std::cout << "equal_range( 9 ): " << std::endl;
		range_start = my_set.equal_range( 9 ).first;
		range_end = my_set.equal_range( 9 ).second;
		std::cout << "\tstart: " << *range_start << std::endl;
		std::cout << "\tend: " << *range_end << std::endl;
		std::cout << std::endl;
		bound = my_set.lower_bound( 2 );
		std::cout << "lower_bound( 2 ): " << *bound << std::endl;
		bound = my_set.lower_bound( -3 );
		std::cout << "lower_bound( -3 ): " << *bound << std::endl;
		bound = my_set.lower_bound( 9 );
		std::cout << "lower_bound( 9 ): " << *bound << std::endl;
		bound = my_set.upper_bound( 2 );
		std::cout << "upper_bound( 2 ): " << *bound << std::endl;
		bound = my_set.upper_bound( -3 );
		std::cout << "upper_bound( -3 ): " << *bound << std::endl;
		bound = my_set.upper_bound( 9 );
		std::cout << "upper_bound( 9 ): " << *bound << std::endl;
	}
	{
		ft::set< int >	my_set;

		my_set.insert( 1 );
		my_set.insert( 2 );
		my_set.insert( 3 );
		my_set.insert( 4 );

		const ft::set< int >			const_set( my_set );
		ft::set< int >::const_iterator	range_start;
		ft::set< int >::const_iterator	range_end;
		ft::set< int >::const_iterator	bound;

		print_set( const_set );
		std::cout << "No of 1 element: " << const_set.count( 1 ) << std::endl;
		std::cout << "No of 6 element: " << const_set.count( 6 ) << std::endl;

		std::cout << "element 1: " << ( *const_set.find( 1 ) ) << std::endl;
		std::cout << "equal_range( 2 ): " << std::endl;
		range_start = const_set.equal_range( 2 ).first;
		range_end = const_set.equal_range( 2 ).second;
		std::cout << "\tstart: " << *range_start << std::endl;
		std::cout << "\tend: " << *range_end << std::endl;
		std::cout << "equal_range( -3 ): " << std::endl;
		range_start = const_set.equal_range( -3 ).first;
		range_end = const_set.equal_range( -3 ).second;
		std::cout << "\tstart: " << *range_start << std::endl;
		std::cout << "\tend: " << *range_end << std::endl;
		std::cout << "equal_range( 9 ): " << std::endl;
		range_start = const_set.equal_range( 9 ).first;
		range_end = const_set.equal_range( 9 ).second;
		std::cout << "\tstart: " << *range_start << std::endl;
		std::cout << "\tend: " << *range_end << std::endl;
		std::cout << std::endl;
		bound = const_set.lower_bound( 2 );
		std::cout << "lower_bound( 2 ): " << *bound << std::endl;
		bound = const_set.lower_bound( -3 );
		std::cout << "lower_bound( -3 ): " << *bound << std::endl;
		bound = const_set.lower_bound( 9 );
		std::cout << "lower_bound( 9 ): " << *bound << std::endl;
		bound = const_set.upper_bound( 2 );
		std::cout << "upper_bound( 2 ): " << *bound << std::endl;
		bound = const_set.upper_bound( -3 );
		std::cout << "upper_bound( -3 ): " << *bound << std::endl;
		bound = const_set.upper_bound( 9 );
		std::cout << "upper_bound( 9 ): " << *bound << std::endl;
	}
	return ;
}

void	comparison( void )
{
	{
		ft::set< int >	set1;
		ft::set< int >	set2;

		set1.insert( 1 );
		set2.insert( 1 );
		set1.insert( 2 );
		set2.insert( 2 );
		std::cout << "set1 == set2 : " << ( set1 == set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 != set2 : " << ( set1 != set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 < set2 : " << ( set1 < set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 > set2 : " << ( set1 > set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 <= set2 : " << ( set1 <= set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 >= set2 : " << ( set1 >= set2 ? "yes" : "no" ) << std::endl;
		std::cout << std::endl;
		set1.insert( 3 );
		set2.insert( 3 );
		std::cout << "set1 == set2 : " << ( set1 == set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 != set2 : " << ( set1 != set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 < set2 : " << ( set1 < set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 > set2 : " << ( set1 > set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 <= set2 : " << ( set1 <= set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 >= set2 : " << ( set1 >= set2 ? "yes" : "no" ) << std::endl;
		std::cout << std::endl;
		set2.erase( 3 );
		std::cout << "set1 == set2 : " << ( set1 == set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 != set2 : " << ( set1 != set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 < set2 : " << ( set1 < set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 > set2 : " << ( set1 > set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 <= set2 : " << ( set1 <= set2 ? "yes" : "no" ) << std::endl;
		std::cout << "set1 >= set2 : " << ( set1 >= set2 ? "yes" : "no" ) << std::endl;
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
	std::cout << "-------------------Modifiers2------------------" << std::endl;
	modifiers2();
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "---------------------Lookup--------------------" << std::endl;
	lookup();
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "-------------------Comparison------------------" << std::endl;
	comparison();
	std::cout << "-----------------------------------------------" << std::endl;
}