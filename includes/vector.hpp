/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:57:27 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/12 16:36:13 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstddef>
# include <stdexcept>
# include <memory>
# include <utility>
# include <limits>
# include <iterator>
# include "is_integral.hpp"
# include "iterator_traits.hpp"
# include "vector_iterator.hpp"
# include "reverse_iterator.hpp"
# include "difference.hpp"
# include "lexicographical_compare.hpp"
# include "comp.hpp"
# include "enable_if.hpp"

namespace ft
{
	template< typename T, typename Alloc = std::allocator< T > >
	class vector
	{
	public:
		//	Typedefs
		typedef T										value_type;
		typedef Alloc									allocator_type;
		typedef typename Alloc::size_type				size_type;
		typedef typename Alloc::difference_type			difference_type;
		typedef T&										reference;
		typedef const T&								const_reference;
		typedef typename Alloc::pointer					pointer;
		typedef const typename Alloc::pointer			const_pointer;
		typedef ft::vector_iterator< T >				iterator;
		typedef ft::vector_iterator< const T >			const_iterator;
		typedef ft::reverse_iterator< iterator >		reverse_iterator;
		typedef ft::reverse_iterator< const_iterator >	const_reverse_iterator;

	private:
		allocator_type	_allocator; // Allocator to allocate memory.
		size_type		_capacity; // Capacity of the table (allocated mem).
		size_type		_size; // Number of elements in the table.
		pointer			_array; // underlying table of elements.

		//	Realloc memory and copy _array.
		pointer		_array_copy( size_type new_cap );
		//	Find next cap by multiplying by factor 2 if `_capacity < target_size`.
		size_type	_next_cap( size_type target_size );
		
	public:
		//	Constructors
		//		1. default empty constructor.
		vector( void );
		//		2. Empty container constructor.
		vector( const allocator_type& alloc );
		//		3. Construct with count value.
		vector(	size_type count,
				const_reference value = T( ),
				const allocator_type& alloc = Alloc( ) );
		//		5. Construct from content of range.
		template< class InputIt >
		vector( InputIt first, InputIt last, const allocator_type& alloc, typename ft::enable_if< !ft::is_integral< InputIt >::value, InputIt >::type* = NULL );
		//		6. Copy constructor.
		vector( const vector& other );
		
		//	Destructor
		virtual ~vector( void );

		//	Assignation functions 
		//		assignation operator =
		vector&	operator=( const vector& other );
		//		1. assign count elements by value.
		void	assign( size_type count, const T& value );
		//		2. assign from iterator.
		template< typename InputIt >
		void	assign( InputIt first, InputIt last, typename ft::enable_if< !ft::is_integral< InputIt >::value, InputIt >::type* = NULL );
		
		//	Getter for allocator.
		allocator_type	get_allocator( void ) const;

		//	Element access.
		//		1. at operator non-const.
		reference		at( size_type pos );
		//		2. at operator const.
		const_reference	at( size_type pos ) const;
		//		1. Access operator [] non-const.
		reference		operator[]( size_type pos );
		//		2. Access operator [] const.
		const_reference	operator[]( size_type pos ) const;
		//		1. Access front element.
		reference		front( );
		//		2. Access front element const.
		const_reference	front( ) const;
		//		1. Access back element.
		reference		back( );
		//		2. Access back element const.
		const_reference	back( ) const;
		//		1. Access non-const underlying object.
		pointer			data( void );
		//		2. Access const underlying object.
		const_pointer	data( void ) const;

		//	Iterator functions.
		//		1. Iterator begin element.
		iterator				begin( void );
		//		2. const iterator begin element.
		const_iterator			begin( void ) const;
		//		1. Iterator end element.
		iterator				end( void );
		//		2. const iterator end element.
		const_iterator			end( void ) const;
		//		1. Reverse iterator begin element.
		reverse_iterator		rbegin( void );
		//		2. const reverse iterator begin element.
		const_reverse_iterator	rbegin( void ) const;
		//		1. Reverse iterator end element.
		reverse_iterator		rend( void );
		//		2. const reverse iterator end element.
		const_reverse_iterator	rend( void ) const;

		//	Capacity functions.
		//		empty check function.
		bool		empty( void ) const;
		//		Check size function.
		size_type	size( void ) const;
		//		Check max size function.
		size_type	max_size( void ) const;
		//		Increase capacity function.
		void		reserve( size_type _cap );
		//		Check capacity function.
		size_type	capacity( void ) const;

		//	Container modifiers.
		//		clear function.
		void		clear( void );
		//		1. insert element from pos.
		iterator	insert( const_iterator pos, const T& value );
		//		3. insert count elements from pos.
		iterator	insert(	const_iterator pos, size_type count, const T& value );
		//		4. insert elements from iterator.
		template< typename InputIt >
		iterator	insert( const_iterator pos, InputIt first, InputIt last, typename ft::enable_if< !ft::is_integral< InputIt >::value, InputIt >::type* = NULL );
		//		1. Erase element at pos.
		iterator	erase( iterator pos );
		//		2. Erase elements from range.
		iterator	erase( iterator first, iterator last );
		//		1. Append element to end of container.
		void		push_back( const_reference value );
		//		1. Remove last element.
		void		pop_back( void );
		//		1. Resize and if needed fill with default.
		void		resize( size_type n, const_reference value = value_type() );
		//		1. Exchange content of both containers.
		void		swap( vector& other );

	};

	//	Comparison operator non-member functions
	//		equal
	template< typename T, typename Alloc >
	bool	operator==( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs );
	//		Different
	template< typename T, typename Alloc >
	bool	operator!=( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs );
	//		Greater
	template< typename T, typename Alloc >
	bool	operator>( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs );
	//		Greater or equal
	template< typename T, typename Alloc >
	bool	operator>=( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs );
	//		Less
	template< typename T, typename Alloc >
	bool	operator<( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs );
	//		Less or equal
	template< typename T, typename Alloc >
	bool	operator<=( const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs );

	//	Swap non-member function
	template< typename T, typename Alloc >
	void	swap( vector< T, Alloc >& lhs, vector< T, Alloc >& rhs );
	
	# include "vector.tpp"

}

#endif