/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:59:11 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/27 17:28:15 by antoine          ###   ########.fr       */
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
	if (this != &other)
	{
		_size = other._size;
		if ( _capacity < other._size )
		{
			_capacity = other._capacity;
			this->reserve( _capacity );
		}
		this->assign( other.begin( ), other.end( ) );
	}
	return (*this);
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
	{
		_capacity = count;
		this->reserve( _capacity );
	}
	for ( size_type i = 0; i < _size; i++ )
		_array[i] = value;
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

/*==============================================================================
	Iterator functions.
==============================================================================*/

template< typename T >
typename vector< T >::iterator	begin( void )
{
	return ( Iterator( &this->front() ) );
}

template< typename T >
vector< T >::const_iterator	begin( void ) const
{
	return ( Iterator( &this->front() ) );
}

template< typename T >
vector< T >::iterator	end( void )
{
	return ( Iterator( ( &this->back() ) + 1 ) );
}

template< typename T >
vector< T >::const_iterator	end( void ) const
{
	return ( Iterator( ( &this->back() ) + 1 ) );
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

/*==============================================================================
							***********************
							* ITERATOR FUNCTIONS. *
							***********************
==============================================================================*/

/*==============================================================================
	Constructors.
==============================================================================*/

// Default constructor with null element
template< typename T >
vector< T >::Iterator::Iterator( void )
	: _elem( NULL )
{
	return ;
}

// Constructor from pointer to T
template< typename T >
vector< T >::Iterator::Iterator( typename pointer ptr )
	: _elem( ptr )
{
	return ;
}

// Copy Constrcutor 
template< typename T >
vector< T >::Iterator::Iterator( const Iterator& other )
{
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

// Destructor
template< typename T >
vector< T >::Iterator::~Iterator( void )
{
	return ;
}

/*==============================================================================
	Assignment operator.
==============================================================================*/

template< typename T >
vector< T >::Iterator&	vector< T >::Iterator::\
	operator=( const Iterator& other )
{
	if ( this != &other )
		_elem = other._elem;
	return ( *this );
}

/*==============================================================================
	Reference and pointer operator.
==============================================================================*/

template< typename T >
const typename vector< T >::Iterator::reference	operator*( void ) const
{
	return ( *_elem );
}

template< typename T >
typename vector< T >::Iterator::pointer	operator->( void ) const
{
	return ( _elem );
}

/*==============================================================================
	Increment & decrement operators.
==============================================================================*/

template< typename T >
vector< T >::Iterator&	vector< T >::Iterator::operator++( void )
{
	++_elem;
	return ( *this );
}

template< typename T > 
vector< T >::Iterator	vector< T >::Iterator::operator++( int )
{
	Iterator	tmp( *this );

	++_elem;
	return (tmp);
}

template< typename T >
vector< T >::Iterator&	vector< T >::Iterator::operator--( void )
{
	--_elem;
	return ( *this );
}

template< typename T > 
vector< T >::Iterator	vector< T >::Iterator::operator--( int )
{
	Iterator	tmp( *this );

	--_elem;
	return (tmp);
}

/*==============================================================================
	Comparison operators.
==============================================================================*/

template< typename T >
bool	vector< T >::Iterator::operator==( const Iterator& other ) const
{
	return ( _elem == other._elem );
}

template< typename T >
bool	vector< T >::Iterator::operator!=( const Iterator& other ) const
{
	return ( _elem != other._elem );
}

template< typename T >
bool	vector< T >::Iterator::operator>( const Iterator& other ) const
{
	return ( _elem > other._elem );
}

template< typename T >
bool	vector< T >::Iterator::operator>=( const Iterator& other ) const
{
	return ( _elem >= other._elem );
}

template< typename T >
bool	vector< T >::Iterator::operator<( const Iterator& other ) const
{
	return ( _elem < other._elem );
}

template< typename T >
bool	vector< T >::Iterator::operator<=( const Iterator& other ) const
{
	return ( _elem <= other._elem );
}

/*==============================================================================
	Arithmetic operators.
==============================================================================*/

template< typename T >
vector< T >::Iterator&	operator+=( const difference_type n )
{
	difference_type	m = n;
	if ( m > 0 )
		while ( m-- )
			++_elem;
	else
		while ( m++ )
			++_elem;
	return ( *this );
}

template< typename T >
vector< T >::Iterator&	operator-=( const difference_type n )
{
	return ( *this += -n );
}

template< typename T >
vector< T >::Iterator&	operator+( const difference_type n ) const
{
	Iterator	tmp( *this );
	
	return ( tmp += n );
}

template< typename T >
vector< T >::Iterator&	operator-( const difference_type n ) const
{
	Iterator	tmp( *this );
	
	return ( tmp -= n );
}

template< typename T >
vector< T >::Iterator::difference_type	operator-( const Iterator& other ) const
{
	return ( _elem - other._elem );
}

/*==============================================================================
	Subscript operators.
==============================================================================*/

template< typename T >
const vector< T >::Iterator::reference	vector< T >::Iterator::\
	operator[]( const difference_type n ) const
{
	return ( *( *this + n ) );
}

#endif