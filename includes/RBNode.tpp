/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:34:03 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/03 10:46:37 by antoine          ###   ########.fr       */
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
	: color( other.color )
	, parent( other.parent )
	, left( other.left )
	, right( other.right )
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
RBNode< T >::operator	RBNode< const T >( void ) const
{
	return ( RBNode< const T >( content, color ) );
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