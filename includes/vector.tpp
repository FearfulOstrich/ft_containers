/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:59:11 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/14 15:11:07 by aalleon          ###   ########.fr       */
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
vector< T, Alloc >::vector( InputIt first, InputIt last, const allocator_type& alloc )
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

/*
Assign values to vector.
Assign from iterator `start`.
Assign until `last` - 1.
If difference is greater than _capacity, increase _capacity.
*/
template< typename T, typename Alloc >
template< typename InputIt >
void	vector< T, Alloc >::assign( InputIt first, InputIt last )
{
	size_type	_s = 0;
	InputIt		_copy( first );
	pointer		_tmp;
	
	while ( _copy != last )
	{
		_copy++;
		_s++;
	}
	if ( _s > max_size() )
		throw ( std::length_error("cannot create ft::vector larger than max_size()") );
	_tmp = _array_copy( _s );
	for ( size_type i = 0; first != last; first++, i++ )
	{
		_allocator.destroy( &_tmp[i] );
		_allocator.construct( &_tmp[i], *first );
	}
	std::swap( _tmp, _array );
	for ( size_type i = 0; i < _size; i++ )
		_allocator.destroy( &_tmp[i] );
	_allocator.deallocate( _tmp, _capacity );
	_size = _s;
	_capacity = std::max( _size, _capacity );
	return ;
}

template< typename T, typename Alloc >
template< typename InputIt, typename ft::enable_if< ft::is_integral< InputIt >::value, InputIt >::type >
void	vector< T, Alloc >::assign( InputIt count, InputIt value )
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
	return ( iterator( &this->front() ) );
}

/*
Const begin
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::const_iterator	vector< T, Alloc >::begin( void ) const
{
	return ( const_iterator( &this->front() ) );
}

/*
End
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::iterator	vector< T, Alloc >::end( void )
{
	return ( iterator( ( &this->back() ) + 1 ) );
}

/*
Const end
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::const_iterator	vector< T, Alloc >::end( void ) const
{
	return ( const_iterator( ( &this->back() ) + 1 ) );
}

/*
Reverse begin
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::reverse_iterator	vector< T, Alloc >::rbegin( void )
{
	return ( reverse_iterator( this->end() ) );
}

/*
Reverse const begin
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::const_reverse_iterator	vector< T, Alloc >::rbegin( void ) const
{
	return ( reverse_iterator( this->end() ) );
}

/*
Reverse end
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::reverse_iterator	vector< T, Alloc >::rend( void )
{
	return ( reverse_iterator( this->begin() ) );
}

/*
Reverse const end
*/
template< typename T, typename Alloc >
typename vector< T, Alloc >::const_reverse_iterator	vector< T, Alloc >::rend( void ) const
{
	return ( reverse_iterator( this->begin() ) );
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
		_allocator.destroy( _array[i] );
	_size = 0;
	return ;
}
/*
template< typename T, typename Alloc >
typename vector< T, Alloc >::
	iterator	vector< T, Alloc >::insert(const_iterator pos,
											const T& value )
{
	return ( pos );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::
	iterator	vector< T, Alloc >::insert(const_iterator pos,
											size_type count,
											const T& value )
{
	return ( pos );
}

template< typename T, typename Alloc >
template< typename InputIt >
typename vector< T, Alloc >::
	iterator	vector< T, Alloc >::insert( const_iterator pos,
											InputIt first,
											InputIt last )
{
	return ( pos );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::
	iterator	vector< T, Alloc >::erase( iterator pos )
{
	return ( pos );
}

template< typename T, typename Alloc >
typename vector< T, Alloc >::
	iterator	vector< T, Alloc >::erase( iterator first, iterator last )
{
	return ( last );
}
*/
template< typename T, typename Alloc >
void		vector< T, Alloc >::push_back( const_reference value )
{
	pointer		_copy;
	size_type	_new_cap;

	if ( _capacity > _size + 1 )
		_new_cap = _size + 1;
	else
		_new_cap = _capacity * 2;
	_copy = _array_copy( _new_cap );
	_allocator.construct( _copy[_size], value );
	std::swap( _copy, _array );
	_capacity = _new_cap;
	_size++;
	for ( size_type i = 0; i < _size; i++ )
		_allocator.destroy( _copy[i] );
	_allocator.deallocate( _copy );
	return ;
}

template< typename T, typename Alloc >
void		vector< T, Alloc >::pop_back( void )
{
	_allocator.destroy( _array[--_size] );
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
typename vector< T, Alloc >::
	pointer	vector< T, Alloc >::_array_copy( size_type new_cap )
{
	pointer	_copy;

	if ( new_cap < _capacity )
		new_cap = _capacity;
	_copy = _allocator.allocate( new_cap );
	for ( size_type i = 0; i < _size; i++ )
		_allocator.construct( &_copy[i], _array[i] );
	return ( _copy );
}

#endif