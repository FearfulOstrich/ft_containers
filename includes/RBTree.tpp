/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:03:19 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/28 16:43:00 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_TPP
# define RBTREE_TPP

/*==============================================================================
							*********************
							* MEMBER FUNCTIONS. *
							*********************
==============================================================================*/

/*==============================================================================
							* PRIVATE FUNCTIONS. *
==============================================================================*/

/*
Insert node in tree.
Insert as leaf without any rotation or color change.
*/
template< typename T >
void	_insert( RBNode< T >* node )
{
	RBNode< T >*	pos = _root;
	RBNode< T >*	parent = NULL;

	while ( pos != NULL )
	{
		parent = pos;
		if ( *node < *pos )
			pos = pos->left;
		else
			pos = pos->right;
	}
	node->parent = parent;
	if ( parent == NULL )
		_root = node;
	else if ( *node < *parent )
		parent->left = node;
	else
		parent->right = node;
	return ;
}

/*
Rotate to the left node.
Node `node`'s right child becomes its parent.
Node `node` child's left child becomes its right child.
*/
template< typename T >
void	_left_rotate( RBNode< T >* left_pivot )
{
	RBNode< T >*	right_pivot = left_pivot->right;

	//	Bring right_pivot's left subtree to left_pivot's right subtree.
	left_pivot->right = right_pivot->left;
	if ( right_pivot->left != NULL )
		right_pivot->left->parent = left_pivot;
	//	Exchange parents
	right_pivot->parent = left_pivot->parent;
	if ( left_pivot->parent == NULL )
		_root = right_pivot;
	else if ( left_pivot == left_pivot->parent->left )
		left_pivot->parent->left = right_pivot;
	else
		left_pivot->parent->right = right_pivot;
	//	Bring left_pivot as right_pivot's left child
	right_pivot->left = left_pivot;
	left_pivot->parent = right_pivot;
	return ;
}

/*
Rotate to the right node.
Node `node`'s right child becomes its parent.
Node `node` child's left child becomes its right child.
*/
template< typename T >
void	_left_rotate( RBNode< T >* right_pivot )
{
	RBNode< T >*	left_pivot = right_pivot->left;

	//	Bring left_pivot's right subtree to right_pivot's left subtree.
	right_pivot->left = left_pivot->right;
	if ( left_pivot->right != NULL )
		left_pivot->right->parent = right_pivot;
	//	Exchange parents
	left_pivot->parent = right_pivot->parent;
	if ( right_pivot->parent == NULL )
		_root = left_pivot;
	else if ( right_pivot == right_pivot->parent->left )
		right_pivot->parent->left = left_pivot;
	else
		right_pivot->parent->right = left_pivot;
	//	Bring right_pivot as left_pivot's right child
	left_pivot->right = right_pivot;
	right_pivot->parent = left_pivot;
	return ;
}

/*==============================================================================
							* PUBLIC FUNCTIONS. *
==============================================================================*/

/*
Default Constructor, root default to NULL
*/
template< typename T >
RBTree::RBTree( RBNode* root )
	: _root( root )
{
	return ;
}

/*
Destructor
*/
template< typename T >
RBTree::~RBTree( void )
{
	return ;
}

/*
Assignment operator.
Shallow copy.
*/
template< typename T >
RBTree&	RBTree::operator==( const RBTree& other )
{
	if ( this != *other )
		_root = other.root;
}

#TODO
/*
Insert element `node` in tree.
*/
template< typename T >
RBNode*	RBTree::insert( RBNode< T >* node )
{
	_insert( node );
	node.color = RBNode< T >::red;
	while ( ( node != _root ) && ( node.color = RBNode< T >::red ) )
	{
		if ()
	}
	return ( node );
}

#TODO
/*
Remove element `node` from tree.
*/
template< typename T >
RBNode*	RBTree::remove( RBNode* node )
{
	return ( node );
}


/*==============================================================================
							*************************
							* NON-MEMBER FUNCTIONS. *
							*************************
==============================================================================*/

template< typename T >
bool	operator==( const RBNode< T >& lhs, const RBNode< T >& rhs )
{
	return ( lhs.content == rhs.content );
}

template< typename T >
bool	operator!=( const RBNode< T >& lhs, const RBNode< T >& rhs )
{
	return ( lhs.content != rhs.content );
}

template< typename T >
bool	operator<( const RBNode< T >& lhs, const RBNode< T >& rhs )
{
	return ( lhs.content < rhs.content );
}

template< typename T >
bool	operator<=( const RBNode< T >& lhs, const RBNode< T >& rhs )
{
	return ( lhs.content <= rhs.content );
}

template< typename T >
bool	operator>( const RBNode< T >& lhs, const RBNode< T >& rhs )
{
	return ( lhs.content > rhs.content );
}

template< typename T >
bool	operator>=( const RBNode< T >& lhs, const RBNode< T >& rhs )
{
	return ( lhs.content >= rhs.content );
}

#endif