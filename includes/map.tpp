/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:25:44 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/07 18:44:57 by antoine          ###   ########.fr       */
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

/*==============================================================================
	Getter.
==============================================================================*/

/*
Getter for allocator member.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
SELF::allocator_type	SELF::get_allocator( void ) const
{
	return ( _allocator );
}

/*==============================================================================
	Assignment operator.
==============================================================================*/

template< typename Key, typename T, typename Compare, typename Allocator >
SELF&	SELF::operator=( const self& other )
{
	if ( &other != this )
	{
		_allocator = other._allocator;
		_compare = other._compare;
		_tree = other._tree;
		_size = other._size;
	}
	return ( *this );
}

/*==============================================================================
	Element Access.
==============================================================================*/

/*
at function.
Return mapped value at given key.
Takes first node found in _tree.
If no node with key is found, throw exception.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
SELF::mapped_type&	SELF::at( const Key& key )
{
	RBNode< T >*	node = _tree.find( key );
	
	if ( node == tree.get_sentinel() )
		throw ( std::out_of_range( "OOps change message." ) );
	return ( node->content.second );
}

/*
Const at function.
See above.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
const SELF::mapped_type&	SELF::at( const Key& key ) const
{
	RBNode< T >*	node = _tree.find( key, _compare );
	
	if ( node == tree.get_sentinel() )
		throw ( std::out_of_range( "OOps change message." ) );
	return ( node->content.second );
}

/*
Subscript operator.
Return mapped value at given key.
Takes first node found in _tree.
If no node with key is found, create value initialized value_type and insert it.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
SELF::mapped_type&	SELF::operator[]( const Key& key )
{
	RBNode< T >*	node = _tree.find( key, _compare );

	if ( node == _tree.get_sentinel() )
		return ( insert(ft::make_pair( key, mapped_type() ) ).first->second );
	return ( node->content.second )
}

#endif