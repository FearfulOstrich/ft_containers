/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:33:09 by antoine           #+#    #+#             */
/*   Updated: 2022/11/18 10:32:19 by antoine          ###   ########.fr       */
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
Iterator< T >::Iterator( void )
	: _elem( NULL )
{
	return ;
}

template< typename T >
Iterator< T >::Iterator( pointer ptr )
	: _elem( ptr )
{
	return ;
}

template< typename T >
Iterator< T >::Iterator( const Iterator< T >& other )
{
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

template< typename T >
Iterator< T >::~Iterator( void )
{
	return ;
}

/*==============================================================================
	Assignation functions.
==============================================================================*/

template< typename T >
const typename Iterator< T >::pointer	Iterator< T >::base( void ) const
{
	return ( _elem );
}

/*==============================================================================
	Assignation functions.
==============================================================================*/

template< typename T >
Iterator< T >&	Iterator< T >::operator=( const Iterator< T >& other )
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
typename Iterator< T >::reference	Iterator< T >::operator*( void ) const
{
	return ( *_elem );
}

template< typename T >
typename Iterator< T >::pointer	Iterator< T >::operator->( void )
{
	return ( _elem );
}

/*==============================================================================
	Increment & decrement operators.
==============================================================================*/

template< typename T >
Iterator< T >&	Iterator< T >::operator++( void )
{
	++_elem;
	return ( *this );
}

template< typename T > 
Iterator< T >	Iterator< T >::operator++( int )
{
	Iterator< T >	tmp( *this );

	++_elem;
	return (tmp);
}

template< typename T >
Iterator< T >&	Iterator< T >::operator--( void )
{
	--_elem;
	return ( *this );
}

template< typename T > 
Iterator< T >	Iterator< T >::operator--( int )
{
	Iterator< T >	tmp( *this );

	--_elem;
	return (tmp);
}

/*==============================================================================
	Conversion operators.
==============================================================================*/

template< typename T >
Iterator< T >::operator	Iterator< const T >( void ) const
{
	return ( Iterator< const T >( this->_elem ) );
}

/*==============================================================================
	Comparison operators.
==============================================================================*/

template< typename T >
bool	operator==( const Iterator< T >& it1, const Iterator< T >& it2 )
{
	return ( it1.base() == it2.base() );
}

template< typename T >
bool	operator!=( const Iterator< T >& it1, const Iterator< T >& it2 )
{
	return ( !( it1 == it2 ) );
}

template< typename T >
bool	operator>( const Iterator< T >& it1, const Iterator< T >& it2 )
{
	return ( it1.base() > it2.base() );
}

template< typename T >
bool	operator>=( const Iterator< T >& it1, const Iterator< T >& it2 )
{
	return ( it1.base() >= it2.base() );
}

template< typename T >
bool	operator<( const Iterator< T >& it1, const Iterator< T >& it2 )
{
	return ( !( it1 >= it2 ) );
}

template< typename T >
bool	operator<=( const Iterator< T >& it1, const Iterator< T >& it2 )
{
	return ( !( it1 > it2 ) );
}

/*==============================================================================
	Arithmetic operators.
==============================================================================*/

template< typename T >
Iterator< T >&	Iterator< T >::operator+=( const difference_type n )
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
Iterator< T >&	Iterator< T >::operator-=( const difference_type n )
{
	return ( *this += -n );
}

template< typename T >
Iterator< T >	Iterator< T >::operator+( const difference_type n ) const
{
	Iterator< T >	tmp = *this;
	
	return ( tmp += n );
}

template< typename T >
Iterator< T >	operator+( const typename Iterator< T >::difference_type n, const Iterator< T >& it)
{
	return ( it + n );
}

template< typename T >
Iterator< T >	Iterator< T >::operator-( const difference_type n ) const
{
	Iterator< T >	tmp( *this );
	
	return ( tmp -= n );
}

template< typename T >
typename Iterator< T >::difference_type	Iterator< T >::\
		operator-( const Iterator& other ) const
{
	return ( _elem - other._elem );
}

/*==============================================================================
	Subscript operators.
==============================================================================*/

template< typename T >
typename Iterator< T >::reference	Iterator< T >::operator[]( const difference_type n ) const
{
	return ( *( *this + n ) );
}

#endif