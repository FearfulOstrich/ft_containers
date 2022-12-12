/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:07:15 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/12 17:11:57 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <stdexcept>
# include <algorithm>
# include <iterator>
# if STL
	# include <stack>
	# include <vector>
	namespace ft = std;
# else
	# include "stack.hpp"
	# include "vector.hpp"
# endif

void	constructors()
{
	{
		ft::stack< int >	my_stack;
		std::cout << "ft::stack< int >	my_stack;" << std::endl;
		ft::stack< int >	other_stack( my_stack );
		std::cout << "ft::stack< int >	other_stack( my_stack );" << std::endl;
	}
	{
		ft::stack< ft::vector< int > >	vector_stack;
		std::cout << "ft::stack< ft::vector< int > >	vector_stack;" << std::endl;
		ft::stack< ft::vector< int > >	other_vector_stack = vector_stack;
		std::cout << "ft::stack< ft::vector< int > >	other_vector_stack = vector_stack;" << std::endl;
	}
	return ;
}

void	modifiers()
{
	ft::stack< int >	my_stack;
	
	std::cout << "my_stack.push( 1 );" << std::endl;
	my_stack.push( 1 );
	std::cout << "my_stack.push( 2 );" << std::endl;
	my_stack.push( 2 );
	std::cout << "my_stack.pop();" << std::endl;
	my_stack.pop();
	std::cout << "my_stack.pop();" << std::endl;
	my_stack.pop();
	return ;
}

void	accessors()
{
	{
		ft::stack< int >	my_stack;

		std::cout << "my_stack.push( 1 );" << std::endl;
		my_stack.push( 1 );
		std::cout << "my_stack.top(): " << my_stack.top() << std::endl;
		std::cout << "my_stack.push( 2 );" << std::endl;
		my_stack.push(2);
		std::cout << "my_stack.top(): " << my_stack.top() << std::endl;
		std::cout << "my_stack.pop();" << std::endl;
		my_stack.pop();
		std::cout << "my_stack.top(): " << my_stack.top() << std::endl;
		std::cout << "my_stack.pop();" << std::endl;
		my_stack.pop();
		// std::cout << "my_stack.top(): " << my_stack.top() << std::endl; // Segfault ?
	}
	{
		ft::stack< int >					my_stack;
		
		std::cout << "my_stack.push( 1 );" << std::endl;
		my_stack.push( 1 );
		std::cout << "top = my_stack.top();" << std::endl;
		ft::stack< int >::const_reference	top( my_stack.top() );
		std::cout << "top: " << top << std::endl;
		std::cout << "top = 3; --> Does not compile !" << std::endl;
	}
	return ;
}

void	capacity()
{
	ft::stack< int >	my_stack;

	std::cout << "empty stack? " << (my_stack.empty() ? "yes" : "no") << std::endl;
	std::cout << "my_stack size: " << my_stack.size() << std::endl;
	std::cout << "my_stack.push( 1 );" << std::endl;
	my_stack.push( 1 );
	std::cout << "my_stack size: " << my_stack.size() << std::endl;
	std::cout << "my_stack.push( 2 );" << std::endl;
	my_stack.push( 2 );
	std::cout << "empty stack? " << (my_stack.empty() ? "yes" : "no") << std::endl;
	std::cout << "my_stack size: " << my_stack.size() << std::endl;
	std::cout << "my_stack.pop();" << std::endl;
	my_stack.pop();
	std::cout << "my_stack size: " << my_stack.size() << std::endl;
	std::cout << "my_stack.pop();" << std::endl;
	my_stack.pop();
	std::cout << "empty stack? " << (my_stack.empty() ? "yes" : "no") << std::endl;
	std::cout << "my_stack size: " << my_stack.size() << std::endl;
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
	std::cout << "-------------------Accessors-------------------" << std::endl;
	accessors();
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "--------------------Capacity-------------------" << std::endl;
	capacity();
	std::cout << "-----------------------------------------------" << std::endl;
}