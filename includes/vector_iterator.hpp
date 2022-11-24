/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:33:09 by antoine           #+#    #+#             */
/*   Updated: 2022/11/23 14:57:50 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "enable_if.hpp"
# include "iterator_traits.hpp"

namespace ft
{
	template< typename T >
	class vector_iterator: public ft::iterator_traits< T* >
	{
	public:
		typedef	typename ft::iterator_traits< T* >::pointer			pointer;
		typedef	typename ft::iterator_traits< T* >::reference		reference;
		typedef	typename ft::iterator_traits< T* >::difference_type	difference_type;
	private:
		pointer	_elem;
	
	public:
		// Constructors
		vector_iterator( void );
		vector_iterator( pointer ptr );
		vector_iterator( const vector_iterator& other );
		// Destructor
		~vector_iterator( void );
		// Getter
		const pointer	base( void ) const;
		//	Assignemnt operator
		vector_iterator&	operator=( const vector_iterator& other );
		//	Operators
		//		deref and ref operators
		reference			operator*( void ) const;
		pointer				operator->( void );
		//		Increment & Decrement
		vector_iterator&	operator++( void );
		vector_iterator		operator++( int );
		vector_iterator&	operator--( void );
		vector_iterator		operator--( int );
		//		Conversion Operator
							operator vector_iterator< const T >( void ) const;
		//		Arithmetic operators
		vector_iterator&	operator+=( const difference_type n );
		vector_iterator&	operator-=( const difference_type n );
		vector_iterator		operator+( const difference_type n ) const;
		vector_iterator		operator-( const difference_type n ) const;
		difference_type		operator-( const vector_iterator& other ) const;
		//		reference operator
		reference	operator[]( const difference_type n) const;
	};

	//	Comparison operators
	template< typename T, typename U >
	bool	operator==( const vector_iterator< T >& it1, const vector_iterator< U >& it2 );
	template< typename T, typename U >
	bool	operator!=( const vector_iterator< T >& it1, const vector_iterator< U >& it2 );
	template< typename T, typename U >
	bool	operator>( const vector_iterator< T >& it1, const vector_iterator< U >& it2 );
	template< typename T, typename U >
	bool	operator>=( const vector_iterator< T >& it1, const vector_iterator< U >& it2 );
	template< typename T, typename U >
	bool	operator<( const vector_iterator< T >& it1, const vector_iterator< U >& it2 );
	template< typename T, typename U >
	bool	operator<=( const vector_iterator< T >& it1, const vector_iterator< U >& it2 );

	//	arithmetic operators
	template< typename T >
	vector_iterator< T >	operator+(const typename vector_iterator< T >::difference_type n,
										const vector_iterator< T >& it);

	# include "vector_iterator.tpp"

}

#endif