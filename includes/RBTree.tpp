/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:03:19 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/23 14:46:19 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_TPP
# define RBTREE_TPP

/*
Default Constructor, root default to NULL
*/
RBTree::RBTree( RBNode* root )
	: _root( root )
{
	return ;
}

/*
Destructor
*/
RBTree::~RBTree( void )
{
	return ;
}

/*
Assignment operator.
Shallow copy.
*/
RBTree&	RBTree::operator==( const RBTree& other )
{
	if ( this != *other )
		_root = other.root;
}

#TODO
/*
Insert element `node` in tree.
*/
RBNode*	RBTree::insert( RBNode* node )
{
	return ( node );
}

#TODO
/*
Remove element `node` from tree.
*/
RBNode*	RBTree::remove( RBNode* node )
{
	return ( node );
}

#endif