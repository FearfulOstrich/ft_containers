/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:59:11 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/04 10:20:02 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

# include <stdexcept>

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
template< typename T >
vector< T >::vector( void )
	: _allocator( std::allocator< T >() )
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
template< typename T >
vector< T >::vector( const allocator_type& alloc )
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
template< typename T >
vector< T >::vector(	typename vector< T >::size_type count,
						typename vector< T >::const_reference value,
						const allocator_type& alloc )
	: _allocator( alloc )
	, _capacity( count )
	, _size( count )
	, _array( _allocator.allocate( _capacity ) )
{
	this->assign( count, value );
	return ;
}

/*
Create vector from iterator (first to last).
Allocate memory with alloc.
Copy dereferenced iterators to _array.
Set _capacity and _size to `last - first` (ptrdiff_t -> size_t) !!!!!
*/
template< typename T >
template< class InputIt >
vector< T >::vector( InputIt first, InputIt last, const allocator_type& alloc )
	: _allocator( alloc )
	, _capacity( _size )
	, _size( last - first )
	, _array( _allocator.allocate( _capacity ) )
{
	this->assign( first, last );
	return ;
}

/*
Copy constructor.
*/
template< typename T >
vector< T >::vector( const vector< T >& other )
	: _allocator( other._allocator )
	, _capacity( other._capacity )
	, _size( other._size )
	, _array( _allocator.allocate( _capacity ) )
{
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

/*
Vector destructor.
*/
template< typename T >
vector< T >::~vector( void )
{
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
template< typename T >
vector< T >&	vector< T >::operator=( const vector< T >& other )
{
	size_type	i = 0;
	
	if (this != &other)
	{
		_size = other._size;
		if ( _capacity < other._size )
			this->reserve( other._capacity );
		while ( i < _size )
		{
			this->_array[i] = other._array[i];
			i++;
		}
	}
	return ( *this );
}

/*
Assign values to vector.
Assign `value` to `count` first elements of _array.
If `count` > _capacity, increasse _capacity.
*/
template< typename T >
void	vector< T >::assign( size_type count, const T& value )
{
	_size = count;
	if ( _capacity < count )
		this->reserve( count );
	for ( size_type i = 0; i < _size; i++ )
		_array[i] = value;
	return ;
}

/*
Assign values to vector.
Assign from iterator `start`.
Assign until `last` - 1.
If difference is greater than _capacity, increase _capacity.
*/
template< typename T >
template< typename InputIt >
void	vector< T >::assign( InputIt first, InputIt last )
{
	InputIt		copy( first );
	size_type	it_size = 0;

	while ( copy != last )
	{
		it_size++;
		copy++;
	}
	if ( _capacity < it_size )
		this->reserve( it_size );
	_size = it_size;
	it_size = 0;
	while ( first != last )
		_array[it_size++] = *first++;
	return ;
}

/*==============================================================================
	Getter.
==============================================================================*/

template< typename T >
typename vector< T >::allocator_type	vector< T >::get_allocator( void ) const
{
	return ( _allocator );
}

/*==============================================================================
	Element access.
==============================================================================*/

template< typename T >
typename vector< T >::reference		vector< T >::at( size_type pos )
{
	if ( pos >= _size )
		throw (std::out_of_range( "pos is out of range." ));
	return ( _array[pos] );
}

template< typename T >
typename vector< T >::const_reference	vector< T >::at( size_type pos ) const
{
	if ( pos >= _size )
		throw (std::out_of_range( "pos is out of range." ));
	return ( _array[pos] );
}

template< typename T >
typename vector< T >::reference		vector< T >::operator[]( size_type pos )
{
	return ( _array[pos] );
}

template< typename T >
typename vector< T >::const_reference	vector< T >::operator[]( 
													size_type pos ) const
{
	return ( _array[pos] );
}

template< typename T >
typename vector< T >::reference		vector< T >::front( void )
{
	return ( _array[0] );
}

template< typename T >
typename vector< T >::const_reference	vector< T >::front( ) const
{
	return ( _array[0] );
}

template< typename T >
typename vector< T >::reference		vector< T >::back( void )
{
	return ( _array[_size - 1] );
}

template< typename T >
typename vector< T >::const_reference	vector< T >::back( ) const
{
	return ( _array[_size - 1] );
}

template< typename T >
typename vector< T >::pointer	vector< T >::data( void )
{
	return ( _array );
}

template< typename T >
typename vector< T >::const_pointer	vector< T >::data( void ) const
{
	return ( _array );
}

/*==============================================================================
	Iterator functions.
==============================================================================*/

/*
Begin
*/
template< typename T >
typename vector< T >::iterator	vector< T >::begin( void )
{
	return ( iterator( &this->front() ) );
}

/*
Const begin
*/
template< typename T >
typename vector< T >::const_iterator	vector< T >::begin( void ) const
{
	return ( const_iterator( &this->front() ) );
}

/*
End
*/
template< typename T >
typename vector< T >::iterator	vector< T >::end( void )
{
	return ( iterator( ( &this->back() ) + 1 ) );
}

/*
Const end
*/
template< typename T >
typename vector< T >::const_iterator	vector< T >::end( void ) const
{
	return ( const_iterator( ( &this->back() ) + 1 ) );
}

/*
Reverse begin
*/
template< typename T >
typename vector< T >::reverse_iterator	vector< T >::rbegin( void )
{
	return ( reverse_iterator( this->end() ) );
}

/*
Reverse const begin
*/
template< typename T >
typename vector< T >::const_reverse_iterator	vector< T >::rbegin( void ) const
{
	return ( reverse_iterator( this->end() ) );
}

/*
Reverse end
*/
template< typename T >
typename vector< T >::reverse_iterator	vector< T >::rend( void )
{
	return ( reverse_iterator( this->begin() ) );
}

/*
Reverse const end
*/
template< typename T >
typename vector< T >::const_reverse_iterator	vector< T >::rend( void ) const
{
	return ( reverse_iterator( this->begin() ) );
}


/*==============================================================================
	Capacity functions.
==============================================================================*/

template< typename T >
typename vector< T >::size_type	vector< T >::size( void ) const
{
	return ( _size );
}

template< typename T >
void	vector< T >::reserve( size_type new_cap )
{
	T*	tmp;
	
	if ( new_cap <= _capacity )
		return ;
	tmp = _allocator.allocate( new_cap );
	for ( size_type i = 0; i < _size; i++)
		tmp[i] = _array[i];
	_allocator.deallocate( _array, _capacity );
	_array = tmp;
	_capacity = new_cap;
	return ;
}

template< typename T >
typename vector< T >::size_type	vector< T >::capacity( void ) const
{
	return ( _capacity );
}

/*==============================================================================
	Private functions.
==============================================================================*/

/*
Get next capacity cap.
Capacity increases in powers of 2.
*/
template< typename T >
typename vector< T >::size_type	vector< T >::_next_capacity( void )
{
	return ( _capacity * 2 );
}

/*
Get minimum capacity to store `size` elements.
Capacity increases in powers of 2.
*/
template< typename T >
typename vector< T >::size_type	vector< T >::_req_capacity( size_t size )
{
	size_t	capacity;
	
	capacity = 1;
	while ( capacity < size )
		capacity *= 2;
	return ( capacity );
}

#endif