/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:33:09 by antoine           #+#    #+#             */
/*   Updated: 2022/11/14 15:15:23 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "enable_if.hpp"
# include "iterator_traits.hpp"

namespace ft
{
	template< typename T >
	class Iterator: public ft::iterator_traits< T* >
	{
	public:
		typedef	typename ft::iterator_traits< T* >::pointer			pointer;
		typedef	typename ft::iterator_traits< T* >::reference		reference;
		typedef	typename ft::iterator_traits< T* >::difference_type	difference_type;
	private:
		pointer	_elem;
	
	public:
		// Constructors
		Iterator( void );
		Iterator( pointer ptr );
		Iterator( const Iterator& other );
		// Destructor
		~Iterator( void );
		// Getter
		const pointer	base( void ) const;
		//	Assignemnt operator
		Iterator&	operator=( const Iterator& other );
		//	Operators
		//		deref and ref operators
		reference	operator*( void ) const;
		pointer		operator->( void );
		//		Increment & Decrement
		Iterator&	operator++( void );
		Iterator	operator++( int );
		Iterator&	operator--( void );
		Iterator	operator--( int );
		//		Conversion Operator
					operator Iterator< const T >( void ) const;
		//		Arithmetic operators
		Iterator&		operator+=( const difference_type n );
		Iterator&		operator-=( const difference_type n );
		Iterator&		operator+( const difference_type n ) const;
		Iterator&		operator-( const difference_type n ) const;
		difference_type	operator-( const Iterator& other ) const;
		//		reference operator
		reference	operator[]( const difference_type n) const;
	};

	template< typename T >
	bool	operator==( const Iterator< T >& it1, const Iterator< T >& it2 );
	template< typename T >
	bool	operator!=( const Iterator< T >& it1, const Iterator< T >& it2 );
	template< typename T >
	bool	operator>( const Iterator< T >& it1, const Iterator< T >& it2 );
	template< typename T >
	bool	operator>=( const Iterator< T >& it1, const Iterator< T >& it2 );
	template< typename T >
	bool	operator<( const Iterator< T >& it1, const Iterator< T >& it2 );
	template< typename T >
	bool	operator<=( const Iterator< T >& it1, const Iterator< T >& it2 );
	
	# include "vector_iterator.tpp"

}

#endif