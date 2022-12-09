/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:25:44 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/09 17:06:29 by aalleon          ###   ########.fr       */
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

/*==============================================================================
	Iterators.
==============================================================================*/

/*
Begin iterator.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::iterator	SELF::begin( void )
{
	return ( iterator( _tree.minimum() ) );
}

/*
Begin iterator const.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::const_iterator	SELF::begin( void ) const
{
	return ( iterator( _tree.minimum() ) );
}

/*
End iterator.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::iterator	SELF::end( void )
{
	return ( iterator( _tree.get_sentinel() ) );
}

/*
End iterator const.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::const_iterator	SELF::end( void ) const
{
	return ( iterator( _tree.get_sentinel() ) );
}

/*
Reverse begin iterator.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::reverse_iterator	SELF::rbegin( void )
{
	return (reverse_iterator( _tree.maximum() ) );
}

/*
Reverse begin iterator const.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::const_reverse_iterator	SELF::rbegin( void ) const
{
	return ( reverse_iterator( _tree.maximum() ) );
}

/*
Reverse end iterator.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::reverse_iterator	SELF::rend( void )
{
	return (reverse_iterator( _tree.get_sentinel() ) );
}

/*
Reverse end iterator cont.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::const_reverse_iterator	SELF::rend( void ) const
{
	return ( reverse_iterator( _tree.get_sentinel() ) );
}

/*==============================================================================
	Capacity functions.
==============================================================================*/

/*
Check for empty container.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
bool	SELF::empty( void ) const
{
	if ( _size == 0 )
		return ( true );
	return ( false );
}

/*
Check size of container.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::size_type	SELF::size( void ) const
{
	return ( _size );
}

/*
Check max possible size of container.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::size_type	max_size( void ) const
{
	return ( _tree.max_size() );
}

/*==============================================================================
	Container modifiers.
==============================================================================*/

/*
Clear container.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
void	SELF::clear( void )
{
	_tree.clear();
	_size = 0;
	return ;
}

/*
insert pair in container.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
ft::pair< SELF::iterator, bool >	SELF::insert( const value_type& value )
{
	node_pointer	node = _tree.find( value );
	
	if ( node != _tree.get_sentinel() )
		return ( ft::make_pair( iterator( node ), false ) );
	node = _tree.insert( value, value_compare() );
	return ( ft::make_pair( iterator( node ), true ) );
}

/*
Insert pair in container.
Take a position as hint for node insertion.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::iterator	SELF::insert( iterator pos, const value_type& value )
{
	(void)pos;
	return ( insert( value ) );
}

/*
Insert nodes from iterator.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
template< typename InputIt >
void	SELF::insert( InputIt first, InputIt last )
{
	while ( first != last )
	{
		
		if ( _tree.find( first->first ) == _tree.get_sentinel() )
			_tree.insert( *first );
		first++;
	}
	return ;
}

/*
Erase element from iterator.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
void	SELF::erase( iterator pos )
{
	_tree.remove( *pos );
	return ;
}

/*
Erase elements from first iterator to last not included.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
void	SELF::erase( iterator first, iterator last )
{
	while ( first != last )
		_tree.remove( ( first++ ).base() );
	return ;
}

/*
Erase element given key.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::size_type	SELF::erase( const Key& key )
{
	return ( _tree.erase( ft::make_pair( key, mapped_type() ) ) );
}

/*
Swap two map objects.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
void	SELF::swap( map& other )
{
	map< Key, T, Compare, Allocator >	tmp;
	
	tmp = other;
	other = *this;
	*this = tmp;
	return ;
}

/*==============================================================================
	Lookup functions.
==============================================================================*/

/*
Count number of elements with given key in tree.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::size_type	SELF::count( const Key& key ) const
{
	if ( _tree.find( ft::make_pair( key, mapped_type() ) ) == _tree.get_sentinel() )
		return ( 0 );
	return ( 1 );
}

/*
Find element from key.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::iterator	SELF::find( const Key& key )
{
	return ( iterator( _tree.find( ft::make_pair( key, mapped_type() ) ) ) );
}

/*
Find element from key const.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::const_iterator	SELF::find( const Key& key ) const
{
	return ( const_iterator( _tree.find( ft::make_pair( key, mapped_type() ) ) ) );
}

/*
*/
template< typename Key, typename T, typename Compare, typename Allocator >
ft::pair< SELF::iterator, SELF::iterator >	SELF::equal_range( const Key& key )
{
	RBTree< T >*	pos = _tree.find( ft::make_pair( key, mapped_type() ) );
	
	return 
}

/*
Find lower bound with given key.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::iterator	SELF::lower_bound( const Key& key )
{
	iterator		it = begin();
	const_iterator	ite = end();

	while ( ( it != ite ) )
		if ( value_compare()( *it++, key ) )
			return ( iterator( it - 1 ) );
	return ( iterator( ite ) );
}

/*
Find lower bound with given key const.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::const_iterator	SELF::lower_bound( const Key& key ) const
{
	const_iterator	it = begin();
	const_iterator	ite = end();

	while ( ( it != ite ) )
		if ( value_compare()( *it++, key ) )
			return ( const_iterator( it - 1 ) );
	return ( const_iterator( ite ) );
}

/*
Find upper bound with given key.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::iterator	SELF::lower_bound( const Key& key )
{
	iterator		it = rbegin();
	const_iterator	ite = rend();

	while ( ( it != ite ) )
		if ( value_compare()( *it++, key ) )
			return ( iterator( *( it - 1 ) ) );
	return ( iterator( ite ) );
}

/*
Find upper bound with given key const.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::const_iterator	SELF::lower_bound( const Key& key ) const
{
	const_iterator	it = rbegin();
	const_iterator	ite = rend();

	while ( ( it != ite ) )
		if ( value_compare()( *it++, key ) )
			return ( const_iterator( *( it - 1 ) ) );
	return ( const_iterator( ite ) );
}
#endif