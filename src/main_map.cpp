/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:07:15 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/13 11:41:28 by antoine          ###   ########.fr       */
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
	
	return ;
}

void	accessors()
{
	return ;
}

void	capacity()
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
	// std::cout << "-------------------Modifiers-------------------" << std::endl;
	// modifiers();
	// std::cout << "-----------------------------------------------" << std::endl;
	// std::cout << "-------------------Accessors-------------------" << std::endl;
	// accessors();
	// std::cout << "-----------------------------------------------" << std::endl;
	// std::cout << "--------------------Capacity-------------------" << std::endl;
	// capacity();
	// std::cout << "-----------------------------------------------" << std::endl;
}