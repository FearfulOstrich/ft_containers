/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:33:09 by antoine           #+#    #+#             */
/*   Updated: 2022/11/08 13:54:19 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "enable_if.hpp"

namespace ft
{
	template< typename T, bool Const >
	class Iterator
	{
	public:
		//	Typedefs
		typedef random_access_iterator_tag		iterator_category;
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T&								reference;
		typedef T*								pointer;

	private:
		pointer	_elem;
	
	public:
		// Constructors
		Iterator( void );
		Iterator( pointer ptr );
		Iterator( const Iterator& other );
		// Destructor
		~Iterator( void );
		
		//	Assignemnt operator
		Iterator&	operator=( const Iterator& other );
		//	Operators
		//		deref and ref operators
		typename ft::choose< !Const, reference, const reference >::
			type	operator*( void );
		// const reference	operator*( void ) const;
		pointer	operator->( void );
		//		Increment & Decrement
		Iterator&	operator++( void );
		Iterator	operator++( int );
		Iterator&	operator--( void );
		Iterator	operator--( int );
		//		Conversion Operator
					operator Iterator< T, true >( void ) const;
		//		Arithmetic operators
		Iterator&	operator+=( const difference_type n );
		Iterator&	operator-=( const difference_type n );
		Iterator&	operator+( const difference_type n ) const;
		Iterator&	operator-( const difference_type n ) const;
		difference_type	operator-( const Iterator& other ) const;
		//		reference operator
		typename ft::choose< !Const, reference, const reference >::type
				operator[]( const difference_type n);
	};

	template< typename T, bool Const >
	bool	operator==( const Iterator< T, Const >& it1, const Iterator< T, Const >& it2 );
	template< typename T, bool Const >
	bool	operator!=( const Iterator< T, Const >& it1, const Iterator< T, Const >& it2 );
	template< typename T, bool Const >
	bool	operator>( const Iterator< T, Const >& it1, const Iterator< T, Const >& it2 );
	template< typename T, bool Const >
	bool	operator>=( const Iterator< T, Const >& it1, const Iterator< T, Const >& it2 );
	template< typename T, bool Const >
	bool	operator<( const Iterator< T, Const >& it1, const Iterator< T, Const >& it2 );
	template< typename T, bool Const >
	bool	operator<=( const Iterator< T, Const >& it1, const Iterator< T, Const >& it2 );
	
	# include "vector_iterator.tpp"

}

#endif