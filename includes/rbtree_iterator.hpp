/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:41:46 by antoine           #+#    #+#             */
/*   Updated: 2022/12/09 14:42:55 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ITERATOR_HPP
# define RBTree_ITERATOR_HPP

# include<cstddef>

namespace ft
{
	template< typename T >
	class rbtree_iterator
	{
	public:
		//	Typedefs
		typedef std::ptrdiff_t						difference_type;
		typedef typename RBNode< T >::value_type	value_type;
		typedef typename RBNode< T >::pointer		pointer;
		typedef typename RBNode< T >::reference		reference;
		typedef ft::bidirectional_iterator_tag		iterator_category;
		typedef RBNode< T >							node_type;
		typedef node_type*							node_pointer;
	
	private:
		//	Attributes
		//		Node containing value.
		node_pointer	_node;
		//		Sentinel of tree.
		node_pointer	_sentinel;

	public:
		//	Constructors
		rbtree_iterator( node_pointer node, node_pointer sentinel );
		rbtree_iterator( const rbtree_iterator& other );
		//	Destructor
		~rbtree_iterator( void );
		//	Getter
		node_pointer		base( void );
		//	Operators
		//		Assignment operator
		rbtree_iterator&	operator=( const rbtree_iterator& other );
		//		deref and ref operators
		reference			operator*( void ) const;
		pointer				operator->( void );
		//		Increment and decrement
		rbtree_iterator&	operator++( void );
		rbtree_iterator		operator++( int );
		rbtree_iterator&	operator--( void );
		rbtree_iterator		operator--( int );
		//		Conversion to const
							operator rbtree_iterator< const T >( void ) const;
	}

	//	Non-member functions
	//		Comparison operators.
	template< typename T, typename U >
	bool	operator==( const rbtree_iterator< T >& it1, const rbtree_iterator< U >& it2 );
	
	template< typename T, typename U >
	bool	operator!=( const rbtree_iterator< T >& it1, const rbtree_iterator< U >& it2 );

	# include "rbtree_iterator.tpp"
	
}

#endif