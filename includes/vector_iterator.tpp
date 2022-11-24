/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:33:09 by antoine           #+#    #+#             */
/*   Updated: 2022/11/23 15:02:06 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_TPP
# define VECTOR_ITERATOR_TPP

/*==============================================================================
							*********************
							* MEMBER FUNCTIONS. *
							*********************
==============================================================================*/

/*==============================================================================
	Constructors.
==============================================================================*/

template< typename T >
vector_iterator< T >::vector_iterator( void )
	: _elem( NULL )
{
	return ;
}

template< typename T >
vector_iterator< T >::vector_iterator( pointer ptr )
	: _elem( ptr )
{
	return ;
}

template< typename T >
vector_iterator< T >::vector_iterator( const vector_iterator< T >& other )
{
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

template< typename T >
vector_iterator< T >::~vector_iterator( void )
{
	return ;
}

/*==============================================================================
	Assignation functions.
==============================================================================*/

template< typename T >
const typename vector_iterator< T >::pointer	vector_iterator< T >::base( void ) const
{
	return ( _elem );
}

/*==============================================================================
	Assignation functions.
==============================================================================*/

template< typename T >
vector_iterator< T >&	vector_iterator< T >::operator=( const vector_iterator< T >& other )
{
	if ( this != &other )
	{
		_elem = other._elem;
	}
	return ( *this );
}

/*==============================================================================
	Operators.
==============================================================================*/

//		deref and ref operators
template< typename T >
typename vector_iterator< T >::reference	vector_iterator< T >::operator*( void ) const
{
	return ( *_elem );
}

template< typename T >
typename vector_iterator< T >::pointer	vector_iterator< T >::operator->( void )
{
	return ( _elem );
}

/*==============================================================================
	Increment & decrement operators.
==============================================================================*/

template< typename T >
vector_iterator< T >&	vector_iterator< T >::operator++( void )
{
	++_elem;
	return ( *this );
}

template< typename T > 
vector_iterator< T >	vector_iterator< T >::operator++( int )
{
	vector_iterator< T >	tmp( *this );

	++_elem;
	return (tmp);
}

template< typename T >
vector_iterator< T >&	vector_iterator< T >::operator--( void )
{
	--_elem;
	return ( *this );
}

template< typename T > 
vector_iterator< T >	vector_iterator< T >::operator--( int )
{
	vector_iterator< T >	tmp( *this );

	--_elem;
	return (tmp);
}

/*==============================================================================
	Conversion operators.
==============================================================================*/

template< typename T >
vector_iterator< T >::operator	vector_iterator< const T >( void ) const
{
	return ( vector_iterator< const T >( this->_elem ) );
}

/*==============================================================================
	Comparison operators.
==============================================================================*/

template< typename T, typename U >
bool	operator==( const vector_iterator< T >& it1, const vector_iterator< U >& it2 )
{
	return ( it1.base() == it2.base() );
}

template< typename T, typename U >
bool	operator!=( const vector_iterator< T >& it1, const vector_iterator< U >& it2 )
{
	return ( !( it1 == it2 ) );
}

template< typename T, typename U >
bool	operator>( const vector_iterator< T >& it1, const vector_iterator< U >& it2 )
{
	return ( it1.base() > it2.base() );
}

template< typename T, typename U >
bool	operator>=( const vector_iterator< T >& it1, const vector_iterator< U >& it2 )
{
	return ( it1.base() >= it2.base() );
}

template< typename T, typename U >
bool	operator<( const vector_iterator< T >& it1, const vector_iterator< U >& it2 )
{
	return ( !( it1 >= it2 ) );
}

template< typename T, typename U >
bool	operator<=( const vector_iterator< T >& it1, const vector_iterator< U >& it2 )
{
	return ( !( it1 > it2 ) );
}

/*==============================================================================
	Arithmetic operators.
==============================================================================*/

template< typename T >
vector_iterator< T >&	vector_iterator< T >::operator+=( const difference_type n )
{
	difference_type	m = n;
	if ( m > 0 )
		while ( m-- )
			++_elem;
	else
		while ( m++ )
			--_elem;
	return ( *this );
}

template< typename T >
vector_iterator< T >&	vector_iterator< T >::operator-=( const difference_type n )
{
	return ( *this += -n );
}

template< typename T >
vector_iterator< T >	vector_iterator< T >::operator+( const difference_type n ) const
{
	vector_iterator< T >	tmp = *this;
	
	return ( tmp += n );
}

template< typename T >
vector_iterator< T >	operator+( const typename vector_iterator< T >::difference_type n, const vector_iterator< T >& it)
{
	return ( it + n );
}

template< typename T >
vector_iterator< T >	vector_iterator< T >::operator-( const difference_type n ) const
{
	vector_iterator< T >	tmp( *this );
	
	return ( tmp -= n );
}

template< typename T >
typename vector_iterator< T >::difference_type	vector_iterator< T >::\
		operator-( const vector_iterator& other ) const
{
	return ( _elem - other._elem );
}

/*==============================================================================
	Subscript operators.
==============================================================================*/

template< typename T >
typename vector_iterator< T >::reference	vector_iterator< T >::operator[]( const difference_type n ) const
{
	return ( *( *this + n ) );
}

#endif