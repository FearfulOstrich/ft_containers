/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:33:09 by antoine           #+#    #+#             */
/*   Updated: 2022/11/04 17:11:48 by aalleon          ###   ########.fr       */
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

template< typename T, bool Const >
Iterator< T , Const >::Iterator( void )
	: _elem( NULL )
{
	return ;
}

template< typename T, bool Const >
Iterator< T , Const >::Iterator( pointer ptr )
	: _elem( ptr )
{
	return ;
}

template< typename T, bool Const >
Iterator< T , Const >::Iterator( const Iterator< T , Const >& other )
{
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

template< typename T, bool Const >
Iterator< T , Const >::~Iterator( void )
{
	return ;
}

/*==============================================================================
	Assignation functions.
==============================================================================*/

template< typename T, bool Const >
Iterator< T , Const >&	Iterator< T , Const >::
	operator=( const Iterator< T , Const >& other )
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
template< typename T, bool Const >
typename ft::enable_if< !Const, typename Iterator< T, Const >::reference >::type
	Iterator< T, Const >::operator*( void )
{
	return ( *_elem );
}

template< typename T, bool Const >
typename ft::enable_if< Const, const typename Iterator< T, Const >::reference >::type
	Iterator< T, Const >::operator*( void ) const
{
	return ( *_elem );
}

template< typename T, bool Const >
typename ft::enable_if< !Const, typename Iterator< T, Const >::pointer >::type
	Iterator< T , Const >::operator->( void )
{
	return ( _elem );
}

template< typename T, bool Const >
typename ft::enable_if< Const, const typename Iterator< T, Const >::pointer >::type
	Iterator< T , Const >::operator->( void ) const
{
	return ( _elem );
}

/*==============================================================================
	Increment & decrement operators.
==============================================================================*/

template< typename T, bool Const >
Iterator< T , Const >&	Iterator< T , Const >::operator++( void )
{
	++_elem;
	return ( *this );
}

template< typename T, bool Const > 
Iterator< T , Const >	Iterator< T , Const >::operator++( int )
{
	Iterator< T , Const >	tmp( *this );

	++_elem;
	return (tmp);
}

template< typename T, bool Const >
Iterator< T , Const >&	Iterator< T , Const >::operator--( void )
{
	--_elem;
	return ( *this );
}

template< typename T, bool Const > 
Iterator< T , Const >	Iterator< T , Const >::operator--( int )
{
	Iterator< T , Const >	tmp( *this );

	--_elem;
	return (tmp);
}

/*==============================================================================
	Comparison operators.
==============================================================================*/

template< typename T, bool Const >
bool	Iterator< T , Const >::operator==( const Iterator< T , Const >& other ) const
{
	return ( _elem == other._elem );
}

template< typename T, bool Const >
bool	Iterator< T , Const >::operator!=( const Iterator< T , Const >& other ) const
{
	return ( _elem != other._elem );
}

template< typename T, bool Const >
bool	Iterator< T , Const >::operator>( const Iterator< T , Const >& other ) const
{
	return ( _elem > other._elem );
}

template< typename T, bool Const >
bool	Iterator< T , Const >::operator>=( const Iterator< T , Const >& other ) const
{
	return ( _elem >= other._elem );
}

template< typename T, bool Const >
bool	Iterator< T , Const >::operator<( const Iterator< T , Const >& other ) const
{
	return ( _elem < other._elem );
}

template< typename T, bool Const >
bool	Iterator< T , Const >::operator<=( const Iterator< T , Const >& other ) const
{
	return ( _elem <= other._elem );
}

/*==============================================================================
	Arithmetic operators.
==============================================================================*/

template< typename T, bool Const >
Iterator< T , Const >&	Iterator< T , Const >::operator+=( const difference_type n )
{
	difference_type	m = n;
	if ( m > 0 )
		while ( m-- )
			++_elem;
	else
		while ( m++ )
			++_elem;
	return ( *this );
}

template< typename T, bool Const >
Iterator< T , Const >&	Iterator< T , Const >::operator-=( const difference_type n )
{
	return ( *this += -n );
}

template< typename T, bool Const >
Iterator< T , Const >&	Iterator< T , Const >::operator+( const difference_type n ) const
{
	Iterator< T , Const >	tmp( *this );
	
	return ( tmp += n );
}

template< typename T, bool Const >
Iterator< T , Const >&	Iterator< T , Const >::operator-( const difference_type n ) const
{
	Iterator< T , Const >	tmp( *this );
	
	return ( tmp -= n );
}

template< typename T, bool Const >
typename Iterator< T , Const >::difference_type	Iterator< T , Const >::\
		operator-( const Iterator& other ) const
{
	return ( _elem - other._elem );
}

/*==============================================================================
	Subscript operators.
==============================================================================*/

template< typename T, bool Const >
typename ft::enable_if< !Const, typename Iterator< T, Const >::reference >::type
	Iterator< T , Const >::operator[]( const difference_type n )
{
	return ( *( *this + n ) );
}

template< typename T, bool Const >
typename ft::enable_if< Const, const typename Iterator< T, Const >::reference >::type
	Iterator< T , Const >::operator[]( const difference_type n ) const
{
	return ( *( *this + n ) );
}

#endif