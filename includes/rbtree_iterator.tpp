/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_iterator.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:05:39 by aalleon           #+#    #+#             */
/*   Updated: 2023/01/06 12:57:30 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ITERATOR_TPP
# define RBTREE_ITERATOR_TPP

/*==============================================================================
							********************
							* RBTREE ITERATOR. *
							********************
==============================================================================*/

/*==============================================================================
	Constructors.
==============================================================================*/

template< typename T, bool Const >
rbtree_iterator< T, Const >::rbtree_iterator( void )
{
	return ;
}

template< typename T, bool Const >
rbtree_iterator< T, Const >::rbtree_iterator( node_pointer node, const_node_pointer sentinel )
	: _node( node )
	, _sentinel( sentinel )
{
	return ;
}

template< typename T, bool Const >
rbtree_iterator< T, Const >::rbtree_iterator( const rbtree_iterator& other )
{
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

template< typename T, bool Const >
rbtree_iterator< T, Const >::~rbtree_iterator( void )
{
	return ;
}

/*==============================================================================
	Base getter.
==============================================================================*/

/*
Get base.
*/
template< typename T, bool Const >
typename rbtree_iterator< T, Const >::node_pointer	rbtree_iterator< T, Const >::base( void ) const
{
	return ( _node );
}

/*==============================================================================
	Assignation operator.
==============================================================================*/

template< typename T, bool Const >
rbtree_iterator< T, Const >&	rbtree_iterator< T, Const >::operator=( const rbtree_iterator< T, Const >& other )
{
	if ( this != &other )
	{
		_node = other._node;
		_sentinel = other._sentinel;
	}
	return ( *this );
}

/*==============================================================================
	Reference and dereference operators.
==============================================================================*/

/*
Reference operator.
*/
template< typename T, bool Const >
typename rbtree_iterator< T, Const >::reference	rbtree_iterator< T, Const >::operator*( void ) const
{
	return ( _node->content );
}

/*
Dereferencement operator.
*/
template< typename T, bool Const >
typename rbtree_iterator< T, Const >::pointer	rbtree_iterator< T, Const >::operator->( void ) const
{
	return ( &( _node->content ) );
}

/*==============================================================================
	Increment & decrement operators.
==============================================================================*/

template< typename T, bool Const >
rbtree_iterator< T, Const >&	rbtree_iterator< T, Const >::operator++( void )
{
	_node = _node->successor( _sentinel );
	return ( *this );
}

template< typename T , bool Const> 
rbtree_iterator< T, Const >	rbtree_iterator< T, Const >::operator++( int )
{
	rbtree_iterator< T, Const >	tmp( *this );

	_node = _node->successor( _sentinel );
	return (tmp);
}

template< typename T, bool Const >
rbtree_iterator< T, Const >&	rbtree_iterator< T, Const >::operator--( void )
{
	_node = _node->predecessor( _sentinel );
	return ( *this );
}

template< typename T , bool Const> 
rbtree_iterator< T, Const >	rbtree_iterator< T, Const >::operator--( int )
{
	rbtree_iterator< T, Const >	tmp( *this );

	_node = _node->predecessor( _sentinel );
	return (tmp);
}

/*==============================================================================
	Conversion operators.
==============================================================================*/

template< typename T, bool Const >
rbtree_iterator< T, Const >::operator	rbtree_iterator< const T, true >( void ) const
{
	return ( rbtree_iterator< const T, true >( _node, _sentinel ) );
}

/*==============================================================================
							*************************
							* NON-MEMBER FUNCTIONS. *
							*************************
==============================================================================*/

/*==============================================================================
	Comparison operators.
==============================================================================*/

template< typename T, typename U, bool B1, bool B2 >
bool	operator==( const rbtree_iterator< T, B1 >& it1, const rbtree_iterator< U, B2 >& it2 )
{
	return ( it1.base() == it2.base() );
}

template< typename T, typename U, bool B1, bool B2 >
bool	operator!=( const rbtree_iterator< T, B1 >& it1, const rbtree_iterator< U, B2 >& it2 )
{
	return ( !( it1 == it2 ) );
}

#endif