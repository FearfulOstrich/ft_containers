/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:41:46 by antoine           #+#    #+#             */
/*   Updated: 2022/12/19 12:16:04 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP

# include <cstddef>
# include "iterator_traits.hpp"
# include "conditional.hpp"

namespace ft
{
	/*==========================================================================
		RBTree iterator.
	==========================================================================*/
	template< typename T, bool Const = false >
	class rbtree_iterator
	{
	public:
		//	Typedefs
		typedef std::ptrdiff_t							difference_type;
		typedef ft::bidirectional_iterator_tag			iterator_category;
		typedef T										node_type;
		typedef node_type*								node_pointer;
		typedef const node_type*						const_node_pointer;
		typedef typename ft::conditional< Const,
			const typename node_type::value_type,
			typename node_type::value_type >::type		value_type;
		typedef typename ft::conditional< Const,
			typename node_type::const_pointer,
			typename node_type::pointer >::type			pointer;
		typedef typename ft::conditional< Const,
			typename node_type::const_reference,
			typename node_type::reference >::type		reference;
	
	private:
		//	Attributes
		//		Node containing value.
		node_pointer		_node;
		//		Sentinel of tree.
		const_node_pointer	_sentinel;

	public:
		//	Constructors
		rbtree_iterator( void );
		rbtree_iterator( node_pointer node, const_node_pointer sentinel );
		rbtree_iterator( const rbtree_iterator& other );
		//	Destructor
		~rbtree_iterator( void );
		//	Getter
		node_pointer		base( void ) const;
		//	Operators
		//		Assignment operator
		rbtree_iterator&	operator=( const rbtree_iterator& other );
		//		deref and ref operators
		reference			operator*( void ) const;
		pointer				operator->( void ) const;
		//		Increment and decrement
		rbtree_iterator&	operator++( void );
		rbtree_iterator		operator++( int );
		rbtree_iterator&	operator--( void );
		rbtree_iterator		operator--( int );
		//		Conversion to const
							operator rbtree_iterator< const T, true >( void );
	};

	//	Non-member functions
	//		Comparison operators.
	template< typename T, typename U, bool B1, bool B2 >
	bool	operator==( const rbtree_iterator< T, B1 >& it1, const rbtree_iterator< U, B2 >& it2 );
	
	template< typename T, typename U, bool B1, bool B2 >
	bool	operator!=( const rbtree_iterator< T, B1 >& it1, const rbtree_iterator< U, B2 >& it2 );

	# include "rbtree_iterator.tpp"
	
}

#endif