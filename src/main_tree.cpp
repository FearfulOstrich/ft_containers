/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tree.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 08:53:44 by antoine           #+#    #+#             */
/*   Updated: 2022/12/16 14:30:51 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "binary_function.hpp"
#include "RBNode.hpp"
#include "RBTree.hpp"
#include "comp.hpp"
#include "pair.hpp"

void printBT( const std::string& prefix, const ft::RBNode< const int >* node, bool isLeft, const ft::RBNode< const int >* sentinel )
{
    if( node != sentinel )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->content << " (" << (node->color ? "R" : "B") << ")" << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true, sentinel );
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false, sentinel );
    }
}

void printBT( const ft::RBNode< const int >* node, const ft::RBNode< const int >* sentinel )
{
    printBT( "", node, false, sentinel );    
}

int main()
{
	ft::RBTree< const int, ft::less< int >, std::allocator< int > >	my_tree = ft::RBTree< const int, ft::less< int >, std::allocator< int > >( ft::less< int >(), std::allocator< int >() );

	std::cout << "root :" << my_tree.get_root() << std::endl;
	my_tree.insert( 1 );
	my_tree.insert( 5 );
	my_tree.insert( 2 );
	my_tree.insert( 3 );
	my_tree.insert( 6 );
	my_tree.insert( 4 );
	my_tree.insert( 7 );
	my_tree.insert( 8 );
	my_tree.insert( 9 );
	my_tree.insert( -1 );
	my_tree.insert( 0 );
	printBT( my_tree.get_root(), my_tree.get_sentinel() );

	my_tree.remove( 5 );
	printBT( my_tree.get_root(), my_tree.get_sentinel() );

	return (0);
}