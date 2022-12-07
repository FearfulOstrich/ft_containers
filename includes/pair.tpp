/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:21:16 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/02 10:13:44 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_TPP
# define PAIR_TPP

/*==============================================================================
							*********************
							* MEMBER FUNCTIONS. *
							*********************
==============================================================================*/

/*==============================================================================
	Constructors.
==============================================================================*/

template< typename T1, typename T2 >
pair< T1, T2 >::pair( void )
	: first()
	, second()
{
	return ;
}

template< typename T1, typename T2 >
pair< T1, T2 >::pair( const T1& x, const T2& y )
	: first( x )
	, second( y )
{
	return ;
}

template< typename T1, typename T2 >
template< typename U1, typename U2 >
pair< T1, T2 >::pair( const pair< U1, U2 >& other )
	: first( other.first )
	, second( other.second )
{
	return ;
}

/*==============================================================================
	Assignation operator.
==============================================================================*/

template< typename T1, typename T2 >
pair< T1, T2 >&	pair< T1, T2 >::operator=( const pair< T1, T2 >& other )
{
	if ( this != &other )
	{
		first = other.first;
		second = other.second;
	}
	return ( *this );
}

/*==============================================================================
						*************************
						* NON-MEMBER FUNCTIONS. *
						*************************
==============================================================================*/

/*==============================================================================
	Create pair.
==============================================================================*/

template< typename T1, typename T2 >
pair< T1, T2 >	make_pair( T1 t, T2 u )
{
	return ( pair< T1, T2 >( t, u ) );
}

/*==============================================================================
	Comparison operators.
==============================================================================*/

template< typename T1, typename T2 >
bool	operator==( const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs )
{
	return ( ( lhs.first == rhs.first ) && ( lhs.second == rhs.second ) );
}

template< typename T1, typename T2 >
bool	operator!=( const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs )
{
	return ( ( lhs.first != rhs.first ) || ( lhs.second != rhs.second ) );
}

template< typename T1, typename T2 >
bool	operator<( const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs )
{
	if ( lhs.first < rhs.first )
		return ( true );
	return ( ( lhs.first == rhs.first ) && ( lhs.second < rhs.second ) );
}

template< typename T1, typename T2 >
bool	operator<=( const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs )
{
	return ( !( rhs < lhs ) );
}

template< typename T1, typename T2 >
bool	operator>( const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs )
{
	return ( rhs < lhs );
}

template< typename T1, typename T2 >
bool	operator>=( const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs )
{
	return ( !( lhs < rhs ) );
}

/*
Swap two pairs.
Calls swap to first and swap to second.
*/
template< typename T1, typename T2 >
void	swap( pair< T1, T2 >& lhs, pair< T1, T2 >& rhs )
{
	T1	tmp1 = rhs.first;
	T2	tmp2 = rhs.second;

	rhs.first = lhs.first;
	rhs.second = lhs.second;
	lhs.first = tmp1;
	lhs.second = tmp2;
	return ;
}

#endif