/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:57:27 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/25 22:04:15 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstddef>
# include <memory>
# include "reverse_iterator.hpp"

namespace ft
{
	template< typename T >
	class vector
	{
	
	public:
		//	Typedefs
		typedef T										value_type;
		typedef std::allocator< T >						allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef T&										reference;
		typedef const T&								const_reference;
		typedef typename allocator_type::pointer		pointer;
		typedef const typename allocator_type::pointer	const_pointer;
		typedef value_type								iterator;
		typedef const value_type						const_iterator;
		typedef typename ft::\
					reverse_iterator< iterator >		reverse_iterator;
		typedef typename ft::\
					reverse_iterator< const_iterator >	const_reverse_iterator;

	private:
		allocator_type	_allocator; // Allocator to allocate memory.
		size_type		_capacity; // Capacity of the table (allocated mem).
		size_type		_size; // Number of elements in the table.
		pointer			_array; // underlying table of elements.

		// Find next capacity cap
		size_type	_next_capacity( void );
		size_type	_req_capacity( size_t size );
		
	public:
		//	Constructors
		//		1. default empty constructor.
		vector( void );
		//		2. Empty container constructor.
		vector( const allocator_type& alloc );
		//		3. Construct with count value.
		vector(	size_type count,
				const_reference value = T( ),
				const allocator_type& alloc = std::allocator< T >( ) );
		//		5. Construct from content of range.
		template< class InputIt >
		vector( InputIt first, InputIt last, const allocator_type& alloc );
		//		6. Copy constructor.
		vector( const vector& other );
		
		//	Destructor
		virtual ~vector( void );

		//	Assignation functions
		//		assignation operator =
		vector&	operator=( const vector& other );
		//		1. assign count elements by value
		void	assign( size_type count, const T& value );
		//		2. assign from iterator
		template< typename InputIt >
		void	assign( InputIt first, InputIt last );
		
		//	Getter for allocator.
		allocator_type	get_allocator( void ) const;

		// //	Element access.
		// //		1. at operator non-const.
		// reference		at( size_type pos );
		// //		2. at operator const.
		// const_reference	at( size_type pos ) const;
		//		1. Access operator [] non-const.
		reference		operator[]( size_type pos );
		//		2. Access operator [] const.
		const_reference	operator[]( size_type pos ) const;
		// //		1. Access front element.
		// reference		front( );
		// //		2. Access front element const.
		// const_reference	front( ) const;
		// //		1. Access back element.
		// reference		back( );
		// //		2. Access back element const.
		// const_reference	back( ) const;
		// //		1. Access non-const underlying object.
		// T*				data( void );
		// //		2. Access const underlying object.
		// const T*		data( void ) const;

		// //	Iterator functions.
		// //		1. Iterator begin element.
		// iterator				begin( void );
		// //		2. const iterator begin element.
		// const_iterator			begin( void ) const;
		// //		1. Iterator end element.
		// iterator				end( void );
		// //		2. const iterator end element.
		// const_iterator			end( void ) const;
		// //		1. Reverse iterator begin element.
		// reverse_iterator		rbegin( void );
		// //		2. const reverse iterator begin element.
		// const_reverse_iterator	rbegin( void ) const;
		// //		1. Reverse iterator end element.
		// reverse_iterator		rend( void );
		// //		2. const reverse iterator end element.
		// const_reverse_iterator	rend( void ) const;

		//	Capacity functions.
		// //		empty check function.
		// bool		empty( void ) const;
		//		Check size function.
		size_type	size( void ) const;
		// //		Check max size function.
		// size_type	max_size( void ) const;
		//		Increase capacity function.
		void		reserve( size_type new_cap );
		//		Check capacity function.
		size_type	capacity( void ) const;

		// //	Container modifiers.
		// //		clear function.
		// void	clear( void );
		// //		1. insert element from pos.
		// iterator	insert( const_iterator pos, const T& value );
		// //		2. insert count elements from pos.
		// iterator	insert(	const_iterator pos, size_type count,\
		// 					const T& value );
		// //		4. insert elements from iterator.
		// template< class InputIt >
		// iterator	insert( const_iterator pos, InputIt first, InputIt last );
		// //		1. Erase element at pos.
		// iterator	erase( iterator pos );
		// //		2. Erase elements from range.
		// iterator	erase( iterator first, iterator last );
		// //		1. Append element to end of container.
		// void	push_back( const T& value );
		// //		1. Remove last element.
		// void	pop_back( void );
		// //		1. Resize and if needed fill with default.
		// void	resize( size_type count );
		// //		2. Resize and if needed fill with value.
		// void	resize( size_type count, const value_type& value );
		// //		1. Exchange content of both containers.
		// void	swap( vector& other );
	};

	# include "vector.tpp"

}

#endif