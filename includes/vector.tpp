/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:59:11 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/21 16:50:52 by aalleon          ###   ########.fr       */
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
template< typename T >
vector< T >::vector( void )
	: _array( NULL )
	, _size( 0 )
	, _capacity( 0 )
	, _allocator( std::allocator< T >() )
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
	: _array( NULL )
	, _size( 0 )
	, _capacity( 0 )
	, _allocator( alloc )
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
						typename const allocator_type& alloc )
	: _size( count )
	, _capacity( _req_capacity( count ) )
	, _allocator( alloc )
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
	: _size( last - first )
	, _capacity( _req_capacity( _size ) )
	, _allocator( alloc )
	, _array( _allocator.allocate( _capacity ) )
{
	this->assign( first, last );
	return ;
}

/*
Copy constructor.
*/
template< typename T >
vector( const vector& other )
	: _size( other._size )
	, _capacity( other._capacity )
	, _allocator( other._allocator )
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
	_allocator.deallocate( _array );
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
	if (this != &other)
	{
		_size = other._size;
		if ( _capacity < other._size )
		{
			_capacity = other._capacity;
			this->reserve( _capacity );
		}
		this->assign( other.begin( ), other.end( ) )
	}
	return (*this);
}

/*
Assign values to vector.
Assign `value` to `count` first elements of _array.
If `count` > _capacity, increasse _capacity.
*/
template< typename T >
void	vectot< T >::assign( size_type count, const T& value )
{
	_size = count;
	if ( _capacity < count )
	{
		_capacity = count;
		this->reserve( _capacity );
	}
	for ( size_type i = 0, i < _size, i++ )
		_array[i] = value;
	return ;
}

/*==============================================================================
	Private functions.
==============================================================================*/

/*
Get next capacity cap.
Capacity increases in powers of 2.
*/
template< typename T >
vector< T >::size_type	vector< T >::_next_capacity( void )
{
	return ( _capacity * 2 );
}

/*
Get minimum capacity to store `size` elements.
Capacity increases in powers of 2.
*/
template< typename T >
vector< T >::size_type	vector< T >::_req_capacity( size_t size )
{
	size_t	capacity;
	
	capacity = 1;
	while ( capacity < size )
		capacity *= 2;
	return ( capacity );
}

#endif