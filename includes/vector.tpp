/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:59:11 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/10 16:48:03 by aalleon          ###   ########.fr       */
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
template< typename T, typename Alloc >
template< class InputIt >
vector< T, Alloc >::vector( InputIt first, InputIt last, const allocator_type& alloc )
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
	size_type	i = 0;
	size_type	tmp_size;
	
	if (this != &other)
	{
		if ( this->_capacity < other._size )
			this->reserve( other._capacity );
		tmp_size = other._size;
		while ( i < tmp_size )
		{
			_allocator.destroy( &_array[i] );
			_allocator.construct( &_array[i], other._array[i] );
			i++;
		}
		this->_size = tmp_size;
	}
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
	if ( _capacity < count )
		this->reserve( count );
	_size = count;
	for ( size_type i = 0; i < _size; i++ )
		_allocator.construct( &_array[i], value );
	return ;
}

// /*
// Assign values to vector.
// Assign from iterator `start`.
// Assign until `last` - 1.
// If difference is greater than _capacity, increase _capacity.
// */
// template< typename T, typename Alloc >
// template< typename InputIt >
// void	vector< T, Alloc >::assign( InputIt first, InputIt last )
// {
// 	size_type	it_size = last - first;

// 	if ( _capacity < it_size )
// 		this->reserve( it_size );
// 	_size = it_size;
// 	it_size = 0;
// 	while ( first != last )
// 		_array[it_size++] = *first++;
// 	return ;
// }

// template< typename T, typename Alloc >
// template< typename InputIt >
// void	vector< T, Alloc >::_assign( InputIt count, InputIt value, true_type true)
// {
// 	if ( _capacity < count )
// 		this->reserve( count );
// 	for ( size_type i = 0; i < count; i++ )
// 		_allocator.construct( &copy[i], value );
// 	_size = count;
// 	return ;
// }

// template< typename T, typename Alloc >
// template< typename InputIt >
// void	vector< T, Alloc >::_assign( InputIt first, InputIt last, false_type false)
// {
// 	size_type	it_size = 0;
// 	size_type	i = 0;
// 	pointer		tmp;
// 	InputIt		copy(first);
	
// 	while (copy < end)
// 	{
// 		copy++;
// 		it_size++;
// 	}
// 	if ( _capacity < it_size )
// 		this->reserve( it_size );
	
// 	while ( first != last )
// 		_array[it_size++] = *first++;
// 	_size = it_size;
// 	return ;
// }

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
// template< typename T, typename Alloc >
// typename vector< T, Alloc >::iterator	vector< T, Alloc >::begin( void )
// {
// 	return ( iterator( &this->front() ) );
// }

/*
Const begin
*/
// template< typename T, typename Alloc >
// typename vector< T, Alloc >::const_iterator	vector< T, Alloc >::begin( void ) const
// {
// 	return ( const_iterator( &this->front() ) );
// }

/*
End
*/
// template< typename T, typename Alloc >
// typename vector< T, Alloc >::iterator	vector< T, Alloc >::end( void )
// {
// 	return ( iterator( ( &this->back() ) + 1 ) );
// }

/*
Const end
*/
// template< typename T, typename Alloc >
// typename vector< T, Alloc >::const_iterator	vector< T, Alloc >::end( void ) const
// {
// 	return ( const_iterator( ( &this->back() ) + 1 ) );
// }

/*
Reverse begin
*/
// template< typename T, typename Alloc >
// typename vector< T, Alloc >::reverse_iterator	vector< T, Alloc >::rbegin( void )
// {
// 	return ( reverse_iterator( this->end() ) );
// }

/*
Reverse const begin
*/
// template< typename T, typename Alloc >
// typename vector< T, Alloc >::const_reverse_iterator	vector< T, Alloc >::rbegin( void ) const
// {
// 	return ( reverse_iterator( this->end() ) );
// }

/*
Reverse end
*/
// template< typename T, typename Alloc >
// typename vector< T, Alloc >::reverse_iterator	vector< T, Alloc >::rend( void )
// {
// 	return ( reverse_iterator( this->begin() ) );
// }

/*
Reverse const end
*/
// template< typename T, typename Alloc >
// typename vector< T, Alloc >::const_reverse_iterator	vector< T, Alloc >::rend( void ) const
// {
// 	return ( reverse_iterator( this->begin() ) );
// }


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
	pointer	tmp;
	
	if ( new_cap <= _capacity )
		return ;
	tmp = _allocator.allocate( new_cap );
	for ( size_type i = 0; i < _size; i++)
	{
		_allocator.destroy( &_array[i] );
		_allocator.construct( &tmp[i], _array[i] );
	}	
	_allocator.deallocate( _array, _capacity );
	_array = tmp;
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
void	clear( void )
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
	pointer	_copy;

	_copy = _array_copy( _size + 1 );
	_allocator.construct( _copy[_size], value );
	if ( _capacity < _size + 1 )
		_capacity++;
	_size++;
	std::swap( _copy, _array );
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
	_capacity = n;
	_size = n;
	std::swap( _copy, _array );
	for ( size_type i = 0; i < _size; i++ )
		_allocator.destroy( _copy[i] );
	_allocator.deallocate( _copy );
	return ;
}

template< typename T, typename Alloc >
void		vector< T, Alloc >::swap( vector< T, Alloc >& other )

/*==============================================================================
	Private functions. 
==============================================================================*/

template< typename T, typename Alloc >
typename vector< T, Alloc >::
	pointer	vector< T, Alloc >::_array_copy( size_type new_cap = _capacity ) const
{
	pointer	_copy;

	if ( new_cap < _capacity )
		new_cap = _capacity;
	_copy = _allocator.allocate( new_cap );
	for ( size_type i = 0; i < _size; i++ )
		_allocator.construct( _copy[i], _array[i] );
	return ( _copy )
}

/*
Get next capacity cap.
Capacity increases in powers of 2.
*/
// template< typename T, typename Alloc >
// typename vector< T, Alloc >::size_type	vector< T, Alloc >::_next_capacity( void )
// {
// 	return ( _capacity * 2 );
// }

/*
Get minimum capacity to store `size` elements.
Capacity increases in powers of 2.
*/
// template< typename T, typename Alloc >
// typename vector< T, Alloc >::size_type	vector< T, Alloc >::_req_capacity( size_t size )
// {
// 	size_t	capacity;
	
// 	capacity = 1;
// 	while ( capacity < size )
// 		capacity *= 2;
// 	return ( capacity );
// }

#endif