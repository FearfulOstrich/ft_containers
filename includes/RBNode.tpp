/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:34:03 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/28 16:54:06 by aalleon          ###   ########.fr       */
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
Takes default content `T()`, default parent `NULL` and color to black.
*/
template< typename T >
RBNode< T >::RBNode( value_type content, RBNode* parent, bool color )
	: color( color )
	, p( parent )
	, l( RBNode< void >() )
	, r( RBNode< void >() )
	, content( content )
{
	return ;
}

/*
Constructor by copy.
*/
template< typename T >
RBNode< T >::RBNode( const RBNode& other )
	: color( other.color )
	, p( other.p )
	, l( other.l )
	, r( other.r )
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
RBNode< T >&	RBNode< T >::operator=( const RBNode& other )
{
	if ( this != &other )
	{
		color = other.color;
		p = other.p;
		l = other.l;
		r = other.r;
		content = other.content;
	}
	return ( *this );
}

/*
Equality operator.
Check equality of content of nodes.
*/
template< typename T >
bool	operator==( const RBNode& other ) const
{
	if ( content == other.content )
		return ( true );
	return ( false );
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

/*==============================================================================
					**********************************
					* VOID SPECIALIZATION FUNCTIONS. *
					**********************************
==============================================================================*/

template< >
bool	operator==( const RBNode< >& lhs, const RBNode< >& rhs )
{
	return ( true );
}


#endif