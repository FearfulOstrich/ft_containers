/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:25:44 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/07 15:41:42 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TPP
# define MAP_TPP

# define SELF map< Key, T, Compare, Allocator >

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
SELF::value_compare::value_compare( Compare c )
	: comp( c )
{
	return ;
}

/*
Operator () for value compare.
Compare keys (first attribute of value_type)
*/
template< typename Key, typename T, typename Compare, typename Allocator >
bool	SELF::value_compare::operator()( const value_type& lhs, const value_type& rhs ) const;
{
	return ( comp( lhs.first, rhs.first ) );
}

/*==============================================================================
	Constructors.
==============================================================================*/

/*
Default constructor.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
SELF::map( void )
	: _tree( RBTree< value_type, value_compare >() )
	, _size( 0 )
	, _compare( Compare() )
	, _allocator( Allocator() )
{
	return ;
}

/*
constructor with given `key_compare` function and `allocator`.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
SELF::map( const Compare& comp, const Allocator& alloc )
	: _tree( RBTree< value_type, value_compare >() )
	, _size( 0 )
	, _compare( comp )
	, _allocator( alloc )
{
	return ;
}

/*
Constructor from InputIterator.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
template< typename InputIt >
SELF::map( InputIt first, InputIt last, const Compare& comp, const Allocator& alloc )
	: _tree( RBTree< value_type, value_compare >() )
	, _size( 0 )
	, _compare( comp )
	, _allocator( alloc )
{
	insert( first, last );
	return ;
}

/*
Copy constructor.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
SELF::map( const self& other )
{
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

template< typename Key, typename T, typename Compare, typename Allocator >
SELF::~map( void )
{
	
	return ;
}



#endif