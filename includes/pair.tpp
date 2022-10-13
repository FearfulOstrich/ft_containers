/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:21:16 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/13 11:34:28 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_TPP
# define PAIR_TPP

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

template< typename T1, typename T2 >
pair< T1, T2 >	make_pair( T1 t, T2 u )
{
	return ( pair< T1, T2 >( t, u ) );
}

#endif