/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tree.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 08:53:44 by antoine           #+#    #+#             */
/*   Updated: 2022/12/14 16:18:58 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RBNode.hpp"
#include "RBTree.hpp"
#include "comp.hpp"


int main()
{
	ft::RBNode< int >		node1( 3 );
	const ft::RBNode< int >	node2( node1 );

	return (0);
}