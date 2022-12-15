/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_iterator.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:05:39 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/15 17:08:46 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ITERATOR_TPP
# define RBTREE_ITERATOR_TPP

/*==============================================================================
							*********************
							* MEMBER FUNCTIONS. *
							*********************
==============================================================================*/

/*==============================================================================
	Constructors.
==============================================================================*/

template< typename T >
rbtree_iterator< T >::rbtree_iterator( void )
	: _node( NULL )
	, _sentinel( NULL )
{
	return ;
}

template< typename T >
rbtree_iterator< T >::rbtree_iterator( node_pointer node, const_node_pointer sentinel )
	: _node( node )
	, _sentinel( sentinel )
{
	return ;
}

template< typename T >
rbtree_iterator< T >::rbtree_iterator( const rbtree_iterator& other )
{
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

template< typename T >
rbtree_iterator< T >::~rbtree_iterator( void )
{
	return ;
}

/*==============================================================================
	Base getter.
==============================================================================*/

/*
Get base.
*/
template< typename T >
typename rbtree_iterator< T >::node_pointer	rbtree_iterator< T >::base( void )
{
	return ( _node );
}

/*
Get base const.
*/
template< typename T >
typename rbtree_iterator< T >::const_node_pointer	rbtree_iterator< T >::base( void ) const
{
	return ( _node );
}

/*==============================================================================
	Assignation operator.
==============================================================================*/

template< typename T >
rbtree_iterator< T >&	rbtree_iterator< T >::operator=( const rbtree_iterator< T >& other )
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

template< typename T >
typename rbtree_iterator< T >::reference	rbtree_iterator< T >::operator*( void ) const
{
	return ( _node->content );
}

/*==============================================================================
	Assignation operator.
==============================================================================*/

template< typename T >
typename rbtree_iterator< T >::pointer	rbtree_iterator< T >::operator->( void )
{
	return ( &( _node->content ) );
}

/*==============================================================================
	Increment & decrement operators.
==============================================================================*/

template< typename T >
rbtree_iterator< T >&	rbtree_iterator< T >::operator++( void )
{
	_node = _node->successor( _sentinel );
	return ( *this );
}

template< typename T > 
rbtree_iterator< T >	rbtree_iterator< T >::operator++( int )
{
	rbtree_iterator< T >	tmp( *this );

	_node = _node->successor( _sentinel );
	return (tmp);
}

template< typename T >
rbtree_iterator< T >&	rbtree_iterator< T >::operator--( void )
{
	_node = _node->predecessor( _sentinel );
	return ( *this );
}

template< typename T > 
rbtree_iterator< T >	rbtree_iterator< T >::operator--( int )
{
	rbtree_iterator< T >	tmp( *this );

	_node = _node->predecessor( _sentinel );
	return (tmp);
}

/*==============================================================================
	Conversion operators.
==============================================================================*/

template< typename T >
rbtree_iterator< T >::operator	rbtree_iterator< const T >( void )
{
	return ( rbtree_iterator< const T >( _node, _sentinel ) );
}

/*==============================================================================
							*************************
							* NON-MEMBER FUNCTIONS. *
							*************************
==============================================================================*/

/*==============================================================================
	Comparison operators.
==============================================================================*/

template< typename T, typename U >
bool	operator==( const rbtree_iterator< T >& it1, const rbtree_iterator< U >& it2 )
{
	return ( it1.base() == it2.base() );
}

template< typename T, typename U >
bool	operator!=( const rbtree_iterator< T >& it1, const rbtree_iterator< U >& it2 )
{
	return ( !( it1 == it2 ) );
}

#endif