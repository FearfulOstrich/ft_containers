/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:19:28 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/07 11:35:38 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNode_HPP
# define RBNode_HPP

# define RED	true
# define BLACK	false

namespace ft
{
	template< typename T >
	struct RBNode
	{
		//Typedefs
		typedef	T			value_type;
		typedef T&			reference;
		typedef T*			pointer;
		typedef const T&	const_reference;
		
		//	Attributes.
		//		color: RED (true) or BLACK (false)
		bool		color;
		//		parent node.
		RBNode*		parent;
		//		left child node.
		RBNode*		left;
		//		right child node.
		RBNode*		right;
		//		value
		value_type	content;
		
		//	Constructors
		RBNode( value_type content = value_type(), bool color = BLACK );
		RBNode( const RBNode< T >& other );
		
		//	Destructor
		~RBNode( void );

		//	Operators
		//		Assignment operator=
		RBNode&			operator=( const RBNode< T >& other );
		//		Conversion Operator
						operator RBNode< const T >( void ) const;
		//		equality operator.
		bool			operator==( const RBNode< T >& other ) const;
		//		Dereferencing operator
		reference		operator*( void );
		//		Dereferencing operator
		const_reference	operator*( void ) const;
		
		//	Root of node's tree.
		RBNode< T >*	_root( RBNode< T >* sentinel ) const;
		//	minimum and maximum in node's sub-tree.
		RBNode< T >*	_minimum( RBNode< T >* sentinel ) const;
		RBNode< T >*	_maximum( RBNode< T >* sentinel ) const;

	public:
		//	Successors and Predecessors.
		RBNode< T >*	successor( void ) const;
		RBNode< T >*	predecessor( void ) const;
	};

	//	Non-member functions
	//		Comparison operators
	template< typename T >
	bool	operator==( const RBNode< T >& lhs, const RBNode< T >& rhs );

	template< typename T >
	bool	operator!=( const RBNode< T >& lhs, const RBNode< T >& rhs );

	template< typename T >
	bool	operator<( const RBNode< T >& lhs, const RBNode< T >& rhs );

	template< typename T >
	bool	operator<=( const RBNode< T >& lhs, const RBNode< T >& rhs );

	template< typename T >
	bool	operator>( const RBNode< T >& lhs, const RBNode< T >& rhs );

	template< typename T >
	bool	operator>=( const RBNode< T >& lhs, const RBNode< T >& rhs );

	template< typename T >
	void	swap( RBNode< T >& lhs, RBNode< T >& rhs );
	
	# include "RBNode.tpp"

}

#endif