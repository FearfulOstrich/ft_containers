/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:16:54 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/19 12:43:18 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_TPP
# define REVERSE_ITERATOR_TPP

/*==============================================================================
							*********************
							* MEMBER FUNCTIONS. *
							*********************
==============================================================================*/

/*==============================================================================
	Constructors.
==============================================================================*/

template< typename Iter >
reverse_iterator< Iter >::reverse_iterator( void )
	: _current( )
{
	return ;
}

template< typename Iter >
reverse_iterator< Iter >::reverse_iterator( iterator_type x )
	: _current( x )
{
	return ;
}

template< typename Iter >
template< typename U >
reverse_iterator< Iter >::reverse_iterator( const reverse_iterator< U >& other )
	: _current( other.base() )
{
	return ;
}

/*==============================================================================
	Assignation operator.
==============================================================================*/

template< typename Iter >
reverse_iterator< Iter >&	reverse_iterator< Iter >::operator=( const reverse_iterator< Iter >& other)
{
	if ( this != &other )
		_current = other.base();
	return ( *this );
}

/*==============================================================================
	Getter.
==============================================================================*/

template< typename Iter >
typename reverse_iterator< Iter >::iterator_type	reverse_iterator< Iter >::base( void ) const
{
	return ( _current );
}

/*==============================================================================
	Reference & Pointer operators.
==============================================================================*/

template< typename Iter >
typename reverse_iterator< Iter >::reference	reverse_iterator< Iter >::operator*( void ) const
{
	iterator_type	tmp = _current;
	return ( *( tmp-- ) );
}

template< typename Iter >
typename reverse_iterator< Iter >::pointer	reverse_iterator< Iter >::operator->( void ) const
{
	return ( &(operator*() ) );
}

/*==============================================================================
	Indexing operator.
==============================================================================*/

template< typename Iter >
typename reverse_iterator< Iter >::reference	reverse_iterator< Iter >::operator[]( difference_type n ) const
{
	return ( *( _current - n - 1 ) );
}

/*==============================================================================
	Arithmetic operators.
==============================================================================*/

template< typename Iter >
reverse_iterator< Iter >&	reverse_iterator< Iter >::operator++( void )
{
	_current--;
	return ( *this );
}

template< typename Iter >
reverse_iterator< Iter >&	reverse_iterator< Iter >::operator--( void )
{
	_current++;
	return ( *this );
}

template< typename Iter >
reverse_iterator< Iter >	reverse_iterator< Iter >::operator++( int )
{
	reverse_iterator< Iter >	tmp( *this );
	_current--;
	return ( tmp );
}

template< typename Iter >
reverse_iterator< Iter >	reverse_iterator< Iter >::operator--( int )
{
	reverse_iterator< Iter >	tmp( *this );
	_current++;
	return ( tmp );
}

template< typename Iter >
reverse_iterator< Iter >	reverse_iterator< Iter >::operator+( difference_type n ) const
{
	return ( reverse_iterator< Iter >( _current - n ) );
}

template< typename Iter >
reverse_iterator< Iter >	reverse_iterator< Iter >::operator-( difference_type n ) const
{
	return ( reverse_iterator< Iter >( _current + n ) );
}

template< typename Iter >
reverse_iterator< Iter >&	reverse_iterator< Iter >::operator+=( difference_type n )
{
	_current -= n;
	return ( *this );
}

template< typename Iter >
reverse_iterator< Iter >&	reverse_iterator< Iter >::operator-=( difference_type n )
{
	_current += n;
	return ( *this );
}

/*==============================================================================
						*************************
						* NON-MEMBER FUNCTIONS. *
						*************************
==============================================================================*/

/*==============================================================================
	Comparison operators.
==============================================================================*/

template< typename Iterator1, typename Iterator2 >
bool	operator==( const reverse_iterator< Iterator1 >& lhs, const reverse_iterator< Iterator2 >& rhs )
{
	return ( lhs.base() == rhs.base() );
}

template< typename Iterator1, typename Iterator2 >
bool	operator!=( const reverse_iterator< Iterator1 >& lhs, const reverse_iterator< Iterator2 >& rhs )
{
	return ( lhs.base() != rhs.base() );
}

template< typename Iterator1, typename Iterator2 >
bool	operator<( const reverse_iterator< Iterator1 >& lhs, const reverse_iterator< Iterator2 >& rhs )
{
	return ( lhs.base() > rhs.base() );
}

template< typename Iterator1, typename Iterator2 >
bool	operator<=( const reverse_iterator< Iterator1 >& lhs, const reverse_iterator< Iterator2 >& rhs )
{
	return ( lhs.base() >= rhs.base() );
}

template< typename Iterator1, typename Iterator2 >
bool	operator>( const reverse_iterator< Iterator1 >& lhs, const reverse_iterator< Iterator2 >& rhs )
{
	return ( lhs.base() < rhs.base() );
}

template< typename Iterator1, typename Iterator2 >
bool	operator>=( const reverse_iterator< Iterator1 >& lhs, const reverse_iterator< Iterator2 >& rhs )
{
	return ( lhs.base() <= rhs.base() );
}

/*==============================================================================
	Arithmetic operators.
==============================================================================*/

template< typename Iter >
reverse_iterator< Iter >	operator+( typename reverse_iterator< Iter >::difference_type n,\
											const reverse_iterator< Iter >& it )
{
	return ( reverse_iterator< Iter >( it.base() - n ) );
}

template< class Iter >
typename reverse_iterator< Iter >::difference_type	operator-( const reverse_iterator< Iter >& lhs,
																const reverse_iterator< Iter >& rhs )
{
	return ( rhs.base() - lhs.base() );
}

#endif