/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:59:11 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/12 16:58:34 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

/*==============================================================================
							*********************
							* MEMBER FUNCTIONS. *
							*********************
==============================================================================*/

/*==============================================================================
	Constructors.
==============================================================================*/

/*
Create empty vector.
Set allocator to std::allocator< T >() (as specified in the subject) !!!!!
Set _array to NULL.
Set _size and _capacity to 0.
*/
template< typename T, typename Alloc >
vector< T, Alloc >::vector( void )
	: _allocator( allocator_type() )
	, _capacity( 0 )
	, _size( 0 )
	, _array( NULL )
{
	return ;
}

/*
Create empty vector.
Set allocator to std::allocator< T >() (as specified in the subject) !!!!!
Set _array to NULL.
Set _size and _capacity to 0.
*/
template< typename T, typename Alloc >
vector< T, Alloc >::vector( const allocator_type& alloc )
	: _allocator( alloc )
	, _capacity( 0 )
	, _size( 0 )
	, _array( NULL )
{
	return ;
}

/*
Create vector with count values.
Allocate memory with alloc.
Fill _array with values
Set _capacity and _size to `count`
*/
template< typename T, typename Alloc >
vector< T, Alloc >::vector(	typename vector< T, Alloc >::size_type count,
						typename vector< T, Alloc >::const_reference value,
						const allocator_type& alloc )
	: _allocator( alloc )
	, _capacity( count )
	, _size( count )
	, _array( NULL )
{
	if ( count > max_size() )
		throw ( std::length_error( "cannot create ft::vector larger than max_size()" ) );
	_array = _allocator.allocate( _capacity );
	this->assign( count, value );
	return ;
}

/*
Create vector from iterator (first to last).
Allocate memory with alloc.
Copy dereferenced iterators to _array.
Set _capacity and _size to `last - first` (ptrdiff_t -> size_t) !!!!!
*/
template< typename T, typename Alloc >
template< class InputIt >
vector< T, Alloc >::vector( InputIt first, InputIt last, const allocator_type& alloc,
						typename ft::enable_if< !ft::is_integral< InputIt >::value, InputIt >::type* )
	: _allocator( alloc )
	, _capacity( 0 )
	, _size( 0 )
	, _array( _allocator.allocate( _capacity ) )
{
	size_type	_s = 0;
	InputIt		_copy( first );

	while ( _copy != last )
	{
		_copy++;
		_s++;
	}
	if ( _s > max_size() )
		throw ( std::length_error( "cannot create ft::vector larger than max_size()" ) );
	this->assign( first, last );
	return ;
}

/*
Copy constructor.
*/
template< typename T, typename Alloc >
vector< T, Alloc >::vector( const vector< T, Alloc >& other )
	: _allocator( other._allocator )
	, _capacity( other._capacity )
	, _size( other._size )
	, _array( _allocator.allocate( _capacity ) )
{
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

/*
Vector destructor.
*/
template< typename T, typename Alloc >
vector< T, Alloc >::~vector( void )
{
	for ( size_type i = 0; i < _size; i++ )
		_allocator.destroy( &_array[i] );
	_allocator.deallocate( _array, _capacity );
	return ;
}

/*==============================================================================
	Assignation functions.
==============================================================================*/

/*
Assignation operator =
Copy all attributes of `other`.
deallocates _array and reallocates necessary.
*/
template< typename T, typename Alloc >
vector< T, Alloc >&	vector< T, Alloc >::operator=( const vector< T, Alloc >& other )
{
	pointer	_tmp;
	
	if ( other._size > max_size() )
		throw ( std::length_error( "cannot create ft::vector larger than max_size()" ) );
	_tmp = _array_copy( other._capacity );
	for ( size_type i = 0; i < other._size; i++ )
	{
		_allocator.destroy( &_tmp[i] );
		_allocator.construct( &_tmp[i], other[i] );
	}
	std::swap( _tmp, _array );
	for ( size_type i = 0; i < _size; i++ )
		_allocator.destroy( &_tmp[i] );
	_allocator.deallocate( _tmp, _capacity );
	_size = other._size;
	_capacity = std::max( other._capacity, _capacity );
	return ( *this );
}

/*
Assign values to vector.
Assign `value` to `count` first elements of _array.
If `count` > _capacity, increasse _capacity.
*/
template< typename T, typename Alloc >
void	vector< T, Alloc >::assign( size_type count, const T& value )
{
	pointer	_tmp;
	
	if ( count > max_size() )
		throw ( std::length_error( "cannot create ft::vector larger than max_size()" ) );
	_tmp = _array_copy( count );
	for ( size_type i = 0; i < count; i++ )
	{
		_allocator.destroy( &_tmp[i] );
		_allocator.construct( &_tmp[i], value );
	}
	std::swap( _tmp, _array );
	for ( size_type i = 0; i < _size; i++ )
		_allocator.destroy( &_tmp[i] );
	_allocator.deallocate( _tmp, _capacity );
	_size = count;
	_capacity = std::max( count, _capacity );
	return ;
}

template< typename T, typename Alloc >
template< typename InputIt >
void	vector< T, Alloc >::assign( InputIt count, InputIt value,
								typename ft::enable_if< !ft::is_integral< InputIt >::value, InputIt >::type* )
{
	pointer	_tmp;
	
	if ( count > max_size() )
		throw ( std::length_error( "cannot create ft::vector larger than max_size()" ) );
	_tmp = _array_copy( count );
	for ( size_type i = 0; i < count; i++ )
	{
		_allocator.destroy( &_tmp[i] );
		_allocator.construct( &_tmp[i], value );
	}
	std::swap( _tmp, _array );
	for ( size_type i = 0; i < _size; i++ )
		_allocator.destroy( &_tmp[i] );
	_allocator.deallocate( _tmp, _capacity );
	_size = count;
	_capacity = std::max( count, _capacity );
	return ;
}

/*==============================================================================
	Getter.
==============================================================================*/

template< typename T, typename Alloc >
typename vector< T, Alloc >::allocator_type	vector< T, Alloc >::get_allocator( void ) const
{
	return ( _allocator );
}

/*==============================================================================
	Element access.
==============================================================================*/

template< typename T, typename Alloc >
typename vector< T, Alloc >::reference		vector< T, Alloc >::at( size_type pos )
{
	if ( pos >= _size )
		throw (std::out_of_range( "pos is out of range." ));
	return ( _array[pos] );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::const_reference	vector< T, Alloc >::at( size_type pos ) const
{
	if ( pos >= _size )
		throw (std::out_of_range( "pos is out of range." ));
	return ( _array[pos] );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::reference		vector< T, Alloc >::operator[]( size_type pos )
{
	return ( _array[pos] );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::const_reference	vector< T, Alloc >::operator[]( 
													size_type pos ) const
{
	return ( _array[pos] );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::reference		vector< T, Alloc >::front( void )
{
	return ( _array[0] );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::const_reference	vector< T, Alloc >::front( ) const
{
	return ( _array[0] );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::reference		vector< T, Alloc >::back( void )
{
	return ( _array[_size - 1] );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::const_reference	vector< T, Alloc >::back( ) const
{
	return ( _array[_size - 1] );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::pointer	vector< T, Alloc >::data( void )
{
	return ( _array );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::const_pointer	vector< T, Alloc >::data( void ) const
{
	return ( _array );
}

/*==============================================================================
	Iterator functions.
==============================================================================*/

/*
Begin
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::iterator	vector< T, Alloc >::begin( void )
{
	return ( iterator( &front() ) );
}

/*
Const begin
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::const_iterator	vector< T, Alloc >::begin( void ) const
{
	return ( const_iterator( &front() ) );
}

/*
End
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::iterator	vector< T, Alloc >::end( void )
{
	return ( iterator( ( &back() ) + 1 ) );
}

/*
Const end
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::const_iterator	vector< T, Alloc >::end( void ) const
{
	return ( const_iterator( &back() + 1 ) );
}

/*
Reverse begin
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::reverse_iterator	vector< T, Alloc >::rbegin( void )
{
	return ( reverse_iterator( iterator( &back() + 1 ) ) );
}

/*
Reverse const begin
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::const_reverse_iterator	vector< T, Alloc >::rbegin( void ) const
{
	return ( reverse_iterator( const_iterator( &back() + 1 ) ) );
}

/*
Reverse end
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::reverse_iterator	vector< T, Alloc >::rend( void )
{
	return ( reverse_iterator( begin() ) );
}

/*
Reverse const end
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::const_reverse_iterator	vector< T, Alloc >::rend( void ) const
{
	return ( reverse_iterator( begin() ) );
}


/*==============================================================================
	Capacity functions.
==============================================================================*/

template< typename T, typename Alloc >
bool	vector< T, Alloc >::empty( void ) const
{
	return ( _size ? false : true );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::size_type	vector< T, Alloc >::size( void ) const
{
	return ( _size );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::size_type	vector< T, Alloc >::max_size( void ) const
{
	return ( std::numeric_limits< difference_type >::max() / sizeof( T ) );
}

template< typename T, typename Alloc >
void	vector< T, Alloc >::reserve( size_type new_cap )
{
	pointer	_tmp;
	
	if ( new_cap <= _capacity )
		return ;
	_tmp = _allocator.allocate( new_cap );
	for ( size_type i = 0; i < _size; i++)
		_allocator.construct( &_tmp[i], _array[i] );
	std::swap( _tmp, _array );
	for ( size_type i = 0; i < _size; i++ )
		_allocator.destroy( &_tmp[i] );
	_allocator.deallocate( _tmp, _capacity );
	_capacity = new_cap;
	return ;
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::size_type	vector< T, Alloc >::capacity( void ) const
{
	return ( _capacity );
}

/*==============================================================================
	Container modifier functions. 
==============================================================================*/

template< typename T, typename Alloc >
void	vector< T, Alloc >::clear( void )
{
	for ( unsigned int i = 0; i < _size; i++ )
		_allocator.destroy( &_array[i] );
	_size = 0;
	return ;
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::
	iterator	vector< T, Alloc >::insert(const_iterator pos,
											const T& value )
{
	size_type		_new_cap = _next_cap( _size + 1 );
	size_type		i = 0;
	const_iterator	it = begin();
	pointer			_copy;
	
	if ( _new_cap > max_size() )
		throw ( std::length_error( "cannot create ft::vector larger than max_size()" ) );
	_copy = _allocator.allocate( _new_cap );
	for ( ; it != pos; ++i, ++it )
		_allocator.construct( &_copy[i], _array[i] );
	_allocator.construct( &_copy[i], value );
	for (size_type j = i; j < _size; j++ )
		_allocator.construct( &_copy[j + 1], _array[j] );
	std::swap( _copy, _array );
	for ( size_type j = 0; j < _size; j++ )
		_allocator.destroy( &_copy[j] );
	_allocator.deallocate( _copy, _capacity );
	_size += 1;
	_capacity = _new_cap;
	return ( iterator( &_array[i] ) );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::
	iterator	vector< T, Alloc >::insert(const_iterator pos,
											size_type count,
											const T& value )
{
	size_type		_new_cap = _next_cap( _size + count );
	size_type		i = 0;
	const_iterator	it = begin();
	pointer			_copy;
	
	if ( count == 0 )
		return ( iterator( const_cast< pointer >( pos.base() ) ) );
	if ( _new_cap > max_size() )
		throw ( std::length_error( "cannot create ft::vector larger than max_size()" ) );
	_copy = _allocator.allocate( _new_cap );
	for ( ; it != pos; ++i, ++it )
		_allocator.construct( &_copy[i], _array[i] );
	for ( size_type j = 0; j < count; j++ )
		_allocator.construct( &_copy[i + j], value );
	for (size_type j = i; j < _size; j++ )
		_allocator.construct( &_copy[j + count], _array[j] );
	std::swap( _copy, _array );
	for ( size_type j = 0; j < _size; j++ )
		_allocator.destroy( &_copy[j] );
	_allocator.deallocate( _copy, _capacity );
	_size += count;
	_capacity = _new_cap;
	return ( iterator( &_array[i] ) );
}

template< typename T, typename Alloc >
template< typename InputIt >
typename vector< T, Alloc >::
	iterator	vector< T, Alloc >::insert( const_iterator pos,
											InputIt first,
											InputIt last,
											typename ft::enable_if< !ft::is_integral< InputIt >::value, InputIt >::type* )
{
	size_type		count = difference( first, last );
	size_type		_new_cap = _next_cap( _size + count );
	pointer			_copy;
	size_type		i = 0;
	const_iterator	it = begin();
	
	if ( first == last )
		return ( iterator( const_cast< pointer >( pos.base() ) ) );
	if ( _new_cap > max_size() )
		throw ( std::length_error( "cannot create ft::vector larger than max_size()" ) );
	_copy = _allocator.allocate( _new_cap );
	for ( ; it != pos; ++it, ++i )
		_allocator.construct( &_copy[i], _array[i] );
	for ( size_type j = 0; j < count; j++ )
		_allocator.construct( &_copy[i + j], first[j] );
	for (size_type j = i; j < _size; j++ )
		_allocator.construct( &_copy[j + count], _array[j] );
	std::swap( _copy, _array );
	for ( size_type j = 0; j < _size; j++ )
		_allocator.destroy( &_copy[j] );
	_allocator.deallocate( _copy, _capacity );
	_size += count;
	_capacity = _new_cap;
	return ( iterator( &_array[i] ) );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::
	iterator	vector< T, Alloc >::erase( iterator pos )
{
	size_type i = distance( begin(), pos );

	for ( size_type j = i + 1; j < _size; j++ )
		_array[j - 1] = _array[j];
	_allocator.destroy( &_array[_size - 1] );
	--_size;
	return ( iterator( &_array[i] ) );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::
	iterator	vector< T, Alloc >::erase( iterator first, iterator last )
{
	size_type i = first - begin();
	difference_type	count = distance( first, last );

	if ( count == 0 )
		return ( last );
	for ( size_type j = i + count; j < _size; j++ )
		_array[j - count] = _array[j];
	for ( size_type j = count ; j > 0; j-- )
		_allocator.destroy( &_array[_size - j] );
	_size -= count;
	return ( iterator( &_array[i] ) );
}

 template< typename T, typename Alloc >
void		vector< T, Alloc >::push_back( const_reference value )
{
	size_type	_old_cap = _capacity;
	size_type	_new_cap = _next_cap( _size + 1 );
	pointer		_copy = _array_copy( _new_cap );

	_allocator.construct( &_copy[_size], value );
	std::swap( _copy, _array );
	_capacity = _new_cap;
	_size++;
	for ( size_type i = 0; i < _size; i++ )
		_allocator.destroy( &_copy[i] );
	_allocator.deallocate( _copy, _old_cap );
	return ;
}

template< typename T, typename Alloc >
void		vector< T, Alloc >::pop_back( void )
{
	_allocator.destroy( &_array[--_size] );
	return ;
}

template< typename T, typename Alloc >
void		vector< T, Alloc >::resize( size_type n, const_reference value )
{
	if ( n < _size )
	{
		while ( _size > n )
			pop_back();
		return ;
	}
	pointer	_copy;
	_copy = _array_copy( n );
	for ( size_type i = _size; i < n; i++ )
		_allocator.construct( _copy[i], value );
	std::swap( _copy, _array );
	_capacity = n;
	_size = n;
	for ( size_type i = 0; i < _size; i++ )
		_allocator.destroy( _copy[i] );
	_allocator.deallocate( _copy );
	return ;
}

template< typename T, typename Alloc >
void	vector< T, Alloc >::swap( vector< T, Alloc >& other )
{
	vector< T, Alloc >	_tmp;

	_tmp = other;
	other = *this;
	*this = _tmp;
	return ;
}

/*==============================================================================
	Private functions. 
==============================================================================*/

template< typename T, typename Alloc >
typename vector< T, Alloc >::pointer	vector< T, Alloc >::_array_copy( size_type new_cap )
{
	pointer	_copy;

	if ( new_cap < _capacity )
		new_cap = _capacity;
	_copy = _allocator.allocate( new_cap );
	for ( size_type i = 0; i < _size; i++ )
		_allocator.construct( &_copy[i], _array[i] );
	return ( _copy );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::size_type	vector< T, Alloc >::_next_cap( size_type target_size )
{
	size_type	_new_cap = std::max( _capacity, static_cast< unsigned long >( 1 ) );
	
	if ( target_size <= _capacity )
		return ( _new_cap );
	while ( _new_cap < target_size )
		_new_cap *= 2;
	return ( _new_cap );
}

/*==============================================================================
							*************************
							* NON-MEMBER FUNCTIONS. *
							*************************
==============================================================================*/

/*
Equal comparison.
*/
template< typename T, typename Alloc >
bool	operator==( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs )
{
	return ( equal( lhs.begin(), lhs.end(), rhs.begin() ) );
}

/*
Different comparison
*/
template< typename T, typename Alloc >
bool	operator!=( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs )
{
	return ( !( lhs == rhs ) );
}

/*
Less than comparison
*/
template< typename T, typename Alloc >
bool	operator<( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs )
{
	return ( lexicographical_compare( rhs.begin(), rhs.end(), lhs.begin(), lhs.end() ) );
}

/*
Less than or equal to comparison
*/
template< typename T, typename Alloc >
bool	operator<=( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs )
{
	return ( ( lhs < rhs ) || ( lhs == rhs ) );
}

/*
Greater than comparison
*/
template< typename T, typename Alloc >
bool	operator>( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs )
{
	return ( !( lhs <= rhs ) );
}

/*
Greater than or equal to comparison
*/
template< typename T, typename Alloc >
bool	operator>=( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs )
{
	return ( !( lhs < rhs ) );
}

/*
Swap two vectors.
*/
template< typename T, typename Alloc >
void	swap( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs )
{
	lhs.swap( rhs );
}


#endif