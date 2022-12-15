/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:34:03 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/15 17:25:40 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNode_TPP
# define RBNode_TPP

/*==============================================================================
							*********************
							* MEMBER FUNCTIONS. *
							*********************
==============================================================================*/

/*
Default constructor.
Takes default content `T()`, default parent `NULL` and color to BLACK.
*/
template< typename T >
RBNode< T >::RBNode( value_type content, bool color )
	: color( color )
	, content( content )
{
	return ;
}

/*
Constructor by copy.
*/
template< typename T >
RBNode< T >::RBNode( const RBNode< T >& other )
	: parent( other.parent )
	, left( other.left )
	, right( other.right )
	, color( other.color )
	, content( other.content )
{
	return ;
}

/*
Default destructor.
*/
template< typename T >
RBNode< T >::~RBNode( void )
{
	return ;
}

/*
Assignment operator=
*/
template< typename T >
RBNode< T >&	RBNode< T >::operator=( const RBNode< T >& other )
{
	if ( this != &other )
	{
		color = other.color;
		parent = other.parent;
		left = other.left;
		right = other.right;
		content = other.content;
	}
	return ( *this );
}

/*
Convert RBNode to RBNode with constant content.
*/
template< typename T >
RBNode< T >::operator	ft::RBNode< const T >( void )
{
	return ( ft::RBNode< const T >( content, color ) );
}

/*
Equality operator.
Check equality of content of nodes.
*/
template< typename T >
bool	RBNode< T >::operator==( const RBNode< T >& other ) const
{
	if ( content == other.content )
		return ( true );
	return ( false );
}

/*
dereferencing operator.
*/
template< typename T >
typename RBNode< T >::reference	RBNode< T >::operator*( void )
{
	return ( this->content );
}

/*
Dereferencing operator const.
*/
template< typename T >
typename RBNode< T >::const_reference	RBNode< T >::operator*( void ) const
{
	return ( this->content );
}

/*
Find root of node's tree.
*/
template< typename T >
const RBNode< T >*	RBNode< T >::_root( const RBNode< T >* sentinel ) const
{
	if ( parent == sentinel )
		return ( this );
	return ( parent->_root( sentinel ) );
}

/*
Minimum in node's subtree.
*/
template< typename T >
const RBNode< T >*	RBNode< T >::_minimum( const RBNode< T >* sentinel ) const
{
	if ( left == sentinel )
		return ( this );
	return ( left->_minimum( sentinel ) );
}

/*
Maximum in node's subtree.
*/
template< typename T >
const RBNode< T >*	RBNode< T >::_maximum( const RBNode< T >* sentinel ) const
{
	if ( right == sentinel )
		return ( this );
	return ( right->_maximum( sentinel ) );
}

/*
Successor of node.
*/
template< typename T >
const RBNode< T >*	RBNode< T >::successor( const RBNode< T >* sentinel ) const
{
	const RBNode< T >*	parent_node;
	const RBNode< T >*	node;
	
	if ( right != sentinel )
		return ( right->_minimum( sentinel ) );
	parent_node = parent;
	node = const_cast< RBNode< T >* >( this );
	while ( ( parent_node != sentinel ) && ( node == parent_node->right ) )
	{
		node = parent_node;
		parent_node = node->parent;
	}
	return ( parent_node );
}

/*
Predecessor of node.
*/
template< typename T >
const RBNode< T >*	RBNode< T >::predecessor( const RBNode< T >* sentinel ) const
{
	RBNode< T >*	parent_node;
	RBNode< T >*	node;
	
	if ( left != sentinel )
		return ( left->_maximum( sentinel ) );
	parent_node = parent;
	node = const_cast< RBNode< T >* >( this );
	while ( ( parent_node != sentinel ) && ( node == parent_node->left ) )
	{
		node = parent_node;
		parent_node = node->parent;
	}
	return ( parent_node );
}

/*==============================================================================
							*************************
							* NON-MEMBER FUNCTIONS. *
							*************************
==============================================================================*/

/*==============================================================================
							* Comparison operators. *
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

// Swap two RBNodes.
template< typename T >
void	swap( RBNode< T >& lhs, RBNode< T >& rhs )
{
	RBNode< T > tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

#endif