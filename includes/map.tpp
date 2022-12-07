/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:25:44 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/06 10:32:38 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TPP
# define MAP_TPP

/*==============================================================================
							*********************
							* MEMBER FUNCTIONS. *
							*********************
==============================================================================*/

/*==============================================================================
	value_compare methods.
==============================================================================*/

/*
Constructor for value_compare.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
_this::value_compare::value_compare( Compare c )
	: comp( c )
{
	return ;
}

/*
Operator () for value compare.
Compare keys (first attribute of value_type)
*/
template< typename Key, typename T, typename Compare, typename Allocator >
bool	_this::value_compare::operator()( const value_type& lhs, const value_type& rhs ) const;
{
	return ( comp( lhs.first, rhs.first ) );
}

/*==============================================================================
	Constructors.
==============================================================================*/

template< typename Key, typename T, typename Compare, typename Allocator >
_this::map( void )
	: _tree( RBTree< value_type, value_compare >() )
	, _size( 0 )
{
	return ;
}

#endif