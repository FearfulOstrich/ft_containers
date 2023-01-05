/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:25:44 by aalleon           #+#    #+#             */
/*   Updated: 2023/01/05 16:43:22 by aalleon          ###   ########.fr       */
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
bool	SELF::value_compare::operator()( const value_type& lhs, const value_type& rhs ) const
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
	: _size( 0 )
	, _key_compare( Compare() )
	, _allocator( Allocator() )
	, _tree( tree_type( value_compare( _key_compare ), _allocator ) )
{
	return ;
}

/*
constructor with given `key_compare` function and `allocator`.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
SELF::map( const Compare& comp, const Allocator& alloc )
	: _size( 0 )
	, _key_compare( comp )
	, _allocator( alloc )
	, _tree( tree_type( value_compare( _key_compare ), _allocator ) )
{
	return ;
}

/*
Constructor from InputIterator.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
template< typename InputIt >
SELF::map( InputIt first, InputIt last, const Compare& comp, const Allocator& alloc )
	: _size( 0 )
	, _key_compare( comp )
	, _allocator( alloc )
	, _tree( tree_type( value_compare( _key_compare ), _allocator ) )
{
	insert( first, last );
	return ;
}

/*
Copy constructor.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
SELF::map( const self& other )
	: _tree( other._tree )
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
typename SELF::allocator_type	SELF::get_allocator( void ) const
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
		_key_compare = other._key_compare;
		_tree.clear();
		_tree.deallocate_node( _tree.get_sentinel() );
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
typename SELF::mapped_type&	SELF::at( const Key& key )
{
	typename tree_type::node_pointer	node = _tree.find( ft::make_pair( key, mapped_type() ) );
	
	if ( node == _tree.get_sentinel() )
		throw ( std::out_of_range( "map::at, no element with given key." ) );
	return ( node->content.second );
}

/*
Const at function.
See above.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
const typename SELF::mapped_type&	SELF::at( const Key& key ) const
{
	typename tree_type::node_pointer	node = _tree.find( ft::make_pair( key, mapped_type() ) );
	
	if ( node == _tree.get_sentinel() )
		throw ( std::out_of_range( "map::at, no element with given key." ) );
	return ( node->content.second );
}

/*
Subscript operator.
Return mapped value at given key.
Takes first node found in _tree.
If no node with key is found, create value initialized value_type and insert it.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::mapped_type&	SELF::operator[]( const Key& key )
{
	typename tree_type::node_pointer	node = _tree.find( ft::make_pair( key, mapped_type() ) );

	if ( node == _tree.get_sentinel() )
		return ( insert(ft::make_pair( key, mapped_type() ) ).first->second );
	return ( node->content.second );
}

template< typename Key, typename T, typename Compare, typename Allocator >
const typename SELF::tree_type&	SELF::get_tree( void ) const
{
	return ( _tree );
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
	return ( iterator( _tree.minimum(), _tree.get_sentinel() ) );
}

/*
Begin iterator const.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::const_iterator	SELF::begin( void ) const
{
	return ( const_iterator( _tree.minimum(), _tree.get_sentinel() ) );
}

/*
End iterator.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::iterator	SELF::end( void )
{
	return ( iterator( _tree.get_sentinel(), _tree.get_sentinel() ) );
}

/*
End iterator const.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::const_iterator	SELF::end( void ) const
{
	return ( const_iterator( _tree.get_sentinel(), _tree.get_sentinel() ) );
}

/*
Reverse begin iterator.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::reverse_iterator	SELF::rbegin( void )
{
	return ( reverse_iterator( iterator( _tree.get_sentinel(), _tree.get_sentinel() ) ) );
}

/*
Reverse begin iterator const.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::const_reverse_iterator	SELF::rbegin( void ) const
{
	return ( const_reverse_iterator( const_iterator( _tree.get_sentinel(), _tree.get_sentinel() ) ) );
}

/*
Reverse end iterator.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::reverse_iterator	SELF::rend( void )
{
	return ( reverse_iterator( iterator( _tree.minimum(), _tree.get_sentinel() ) ) );
}

/*
Reverse end iterator cont.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::const_reverse_iterator	SELF::rend( void ) const
{
	return ( const_reverse_iterator( const_iterator( _tree.minimum(), _tree.get_sentinel() ) ) );
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
typename SELF::size_type	SELF::max_size( void ) const
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
ft::pair< typename SELF::iterator, bool >	SELF::insert( const value_type& value )
{
	typename tree_type::node_pointer	node = _tree.find( value );
	
	if ( node != _tree.get_sentinel() )
		return ( ft::make_pair( iterator( node, _tree.get_sentinel() ), false ) );
	node = _tree.insert( value );
	_size++;
	return ( ft::make_pair( iterator( node, _tree.get_sentinel() ), true ) );
}

/*
Insert pair in container.
Take a position as hint for node insertion.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::iterator	SELF::insert( iterator pos, const value_type& value )
{
	(void)pos;
	return ( insert( value ).first );
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
		
		if ( _tree.find( *first ) == _tree.get_sentinel() )
		{
			_tree.insert( *first );
			_size++;
		}
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
	_tree.remove( pos.base() );
	_size--;
	return ;
}

/*
Erase elements from first iterator to last not included.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
void	SELF::erase( iterator current, iterator last )
{
	iterator	next;

	while ( current != last )
	{
		next = current;
		++next;
		erase( current );
		current = next;
	}
	return ;
}

/*
Erase element given key.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::size_type	SELF::erase( const Key& key )
{
	size_type	res = _tree.remove( ft::make_pair( key, mapped_type() ) ) ;
	
	if ( res )
		_size--;
	return ( res );
}

/*
Swap two map objects.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
void	SELF::swap( map& other )
{
	std::swap( _size, other._size );
	_tree.swap( other._tree );
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
	return ( iterator( _tree.find( ft::make_pair( key, mapped_type() ) ), _tree.get_sentinel() ) );
}

/*
Find element from key const.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::const_iterator	SELF::find( const Key& key ) const
{
	return ( const_iterator( _tree.find( ft::make_pair( key, mapped_type() ) ), _tree.get_sentinel() ) );
}

/*
Return range containing all elements with given key.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
ft::pair< typename SELF::iterator, typename SELF::iterator >	SELF::equal_range( const Key& key )
{
	return ( ft::make_pair< iterator, iterator >( lower_bound( key  ), upper_bound( key ) ) );
}

/*
Return range containing all elements with given key.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
ft::pair< typename SELF::const_iterator, typename SELF::const_iterator >	SELF::equal_range( const Key& key ) const
{
	return ( ft::make_pair< const_iterator, const_iterator >( lower_bound( key  ), upper_bound( key ) ) );
}

/*
Find lower bound with given key.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::iterator	SELF::lower_bound( const Key& key )
{
	iterator		it = begin();
	const_iterator	ite = end();

	while ( it != ite )
	{
		if ( !_key_compare( it->first, key ) )
			return ( it );
		it++;
	}
	return ( iterator( _tree.maximum(), _tree.get_sentinel() ) );
}

/*
Find lower bound with given key const.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::const_iterator	SELF::lower_bound( const Key& key ) const
{
	const_iterator	it = begin();
	const_iterator	ite = end();

	while ( it != ite )
	{
		if ( _key_compare( it->first, key ) )
			return ( it );
		it++;
	}
	return ( const_iterator( _tree.maximum(), _tree.get_sentinel() ) );
}

/*
Find upper bound with given key.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::iterator	SELF::upper_bound( const Key& key )
{
	iterator		it = begin();
	const_iterator	ite = end();

	while ( it != ite )
	{
		if ( _key_compare( key, it->first ) )
			return ( it );
		it++;
	}
	return ( iterator( _tree.maximum(), _tree.get_sentinel() ) );
}

/*
Find upper bound with given key const.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::const_iterator	SELF::upper_bound( const Key& key ) const
{
	const_iterator	it = begin();
	const_iterator	ite = end();

	while ( it != ite )
	{
		if ( _key_compare( key, it->first ) )
			return ( it );
		it++;
	}
	return ( const_iterator( _tree.maximum(), _tree.get_sentinel() ) );
}

/*==============================================================================
	Observers.
==============================================================================*/

/*
Return a functions object that compares two instances of `Key`.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::key_compare	SELF::key_comp( void ) const
{
	return ( _key_compare );
}

/*
Return a function object that compares two instances of `value_type`.
*/
template< typename Key, typename T, typename Compare, typename Allocator >
typename SELF::value_compare	SELF::value_comp( void ) const
{
	return ( value_compare( _key_compare ) );
}

/*==============================================================================
							*************************
							* NON-MEMBER FUNCTIONS. *
							*************************
==============================================================================*/

/*==============================================================================
	Comparison functions.
==============================================================================*/

//	Equal
template< typename Key, typename T, typename Compare, typename Alloc >
bool	operator==( const map< Key, T, Compare, Alloc >& lhs, const map< Key, T, Compare, Alloc >& rhs )
{
	return ( ft::equal( lhs.begin(), lhs.end(), rhs.begin() ) );
}

//	Different
template< typename Key, typename T, typename Compare, typename Alloc >
bool	operator!=( const map< Key, T, Compare, Alloc >& lhs, const map< Key, T, Compare, Alloc >& rhs )
{
	return ( !( lhs == rhs ) );
}

//	Less
template< typename Key, typename T, typename Compare, typename Alloc >
bool	operator<( const map< Key, T, Compare, Alloc >& lhs, const map< Key, T, Compare, Alloc >& rhs )
{
	return ( ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ) );
}

//	Less or equal
template< typename Key, typename T, typename Compare, typename Alloc >
bool	operator<=( const map< Key, T, Compare, Alloc >& lhs, const map< Key, T, Compare, Alloc >& rhs )
{
	return ( ( lhs < rhs ) || ( lhs == rhs ) ); 
}

//	Greater
template< typename Key, typename T, typename Compare, typename Alloc >
bool	operator>( const map< Key, T, Compare, Alloc >& lhs, const map< Key, T, Compare, Alloc >& rhs )
{
	return ( !( lhs <= rhs ) );
}

//	Greater or equal
template< typename Key, typename T, typename Compare, typename Alloc >
bool	operator>=( const map< Key, T, Compare, Alloc >& lhs, const map< Key, T, Compare, Alloc >& rhs )
{
	return ( !( lhs < rhs ) );
}

/*==============================================================================
	swap function.
==============================================================================*/

template< typename Key, typename T, typename Compare, typename Alloc >
void	swap( map< Key, T, Compare, Alloc >& lhs, map< Key, T, Compare, Alloc >& rhs )
{
	lhs.swap( rhs );
}

#endif