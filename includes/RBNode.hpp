/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:19:28 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/14 16:52:44 by aalleon          ###   ########.fr       */
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
		//		parent node.
		RBNode*		parent;
		//		left child node.
		RBNode*		left;
		//		right child node.
		RBNode*		right;
		//		color: RED (true) or BLACK (false)
		bool		color;
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
		const RBNode< T >*	_root( const RBNode< T >* sentinel ) const;
		//	minimum and maximum in node's sub-tree.
		const RBNode< T >*	_minimum( const RBNode< T >* sentinel ) const;
		const RBNode< T >*	_maximum( const RBNode< T >* sentinel ) const;

	public:
		//	Successors and Predecessors.
		const RBNode< T >*		successor( const RBNode< T >* sentinel ) const;
		const RBNode< T >*		predecessor( const RBNode< T >* sentinel ) const;
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