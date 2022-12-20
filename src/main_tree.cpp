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
#include "RBNode.hpp"
#include "RBTree.hpp"
#include "comp.hpp"
#include "pair.hpp"

int main()
{
	ft::RBNode< ft::pair< int, int > >			node1( ft::make_pair( 3, 3 ) );
	ft::RBNode< const ft::pair< int, int > >*	node2 = &static_cast< ft::RBNode< const ft::pair< int, int > > >( node1 );

	return (0);
}