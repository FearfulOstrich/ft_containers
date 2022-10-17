/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:55:14 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/17 17:28:03 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
	template< typename Iter >
	class reverse_iterator
	{
	public:
		// Typedefs
		typedef Iter										iterator_type;
		typedef iterator_traits< Iter >::iterator_category	iterator_category;
		typedef iterator_traits< Iter >::value_type			value_type;
		typedef iterator_traits< Iter >::difference_type	difference_type;
		typedef iterator_traits< Iter >::pointer			pointer;
		typedef iterator_traits< Iter >::reference			reference;
	
		//	Constructors
		reverse_iterator( void );
		reverse_iterator( iterator_type x );
		template< typename U >
		reverse_iterator( const reverse_iterator< U >& other );

		//	Assignation Operator
		reverse_iterator&	operator=( const reverse_iterator& other );

		//	Getter
		iterator_type	base( void ) const;

		//	Operator overloads
		//		Reference operator
		reference	operator*( void ) const;
		pointer		operator->( void ) const;
		//		Indexing operator
					operator[]( difference_type n ) const;
		//		Arithmetic operators
		reverse_iterator&	operator++( void );
		reverse_iterator&	operator--( void );
		reverse_iterator	operator++( int );
		reverse_iterator	operator--( int );
		reverse_iterator	operator+( difference_type n ) const;
		reverse_iterator	operator-( difference_type n ) const;
		reverse_iterator&	operator+=( difference_type n );
		reverse_iterator&	operator-=( difference_type n );

	protected:
		// iterator
		iterator_type	current;
	};

	//	Non-member functions
	//		Comparison operators
	template< typename Iterator1, typename Iterator2 >
	bool	operator==( const reverse_iterator< Iterator1 >& lhs,\
						const reverse_iterator< Iterrator2 >& rhs );
	template< typename Iterator1, typename Iterator2 >
	bool	operator!=( const reverse_iterator< Iterator1 >& lhs,\
						const reverse_iterator< Iterrator2 >& rhs );
	template< typename Iterator1, typename Iterator2 >
	bool	operator<( const reverse_iterator< Iterator1 >& lhs,\
						const reverse_iterator< Iterrator2 >& rhs );
	template< typename Iterator1, typename Iterator2 >
	bool	operator<=( const reverse_iterator< Iterator1 >& lhs,\
						const reverse_iterator< Iterrator2 >& rhs );
	template< typename Iterator1, typename Iterator2 >
	bool	operator>( const reverse_iterator< Iterator1 >& lhs,\
						const reverse_iterator< Iterrator2 >& rhs );
	template< typename Iterator1, typename Iterator2 >
	bool	operator>=( const reverse_iterator< Iterator1 >& lhs,\
						const reverse_iterator< Iterrator2 >& rhs );	
	//		Arithmetic operators
	template< typename Iter >
	reverse_iterator< Iter >	operator+(\
						typename reverse_iterator< Iter >::difference_type n,\
						const reverse_iterator< Iter >& it );
	template< class Iter >
	typename reverse_iterator< Iter >::difference_type	operator-(\
						const reverse_iterator< Iter >& lhs,
						const reverse_iterator< Iter >& rhs );

	# include "reverse_iterator.tpp"
	
}

#endif