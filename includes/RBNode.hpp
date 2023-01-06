/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:19:28 by aalleon           #+#    #+#             */
/*   Updated: 2023/01/06 14:37:23 by aalleon          ###   ########.fr       */
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
		typedef RBNode< T >	self;
		typedef	self*		node_pointer;
		typedef const self*	const_node_pointer;
		typedef	T			value_type;
		typedef T&			reference;
		typedef T*			pointer;
		typedef const T*	const_pointer;
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
		RBNode( value_type content = value_type(), bool color = RED );
		RBNode( const RBNode< T >& other );
		
		//	Destructor
		~RBNode( void );

		//	Operators
		//		Assignment operator=
		RBNode&			operator=( const RBNode< T >& other );
		//		Conversion Operator
						operator RBNode< const T >( void );
		//		equality operator.
		bool			operator==( const RBNode< T >& other ) const;
		//		Dereferencing operator
		reference		operator*( void );
		//		Dereferencing operator
		const_reference	operator*( void ) const;
		
		//	Root of node's tree.
		const_node_pointer	_root( const_node_pointer sentinel ) const;
		//	minimum and maximum in node's sub-tree.
		RBNode< T >*		_minimum( const_node_pointer sentinel );
		const_node_pointer	_minimum( const_node_pointer sentinel ) const;
		RBNode< T >*		_maximum( const_node_pointer sentinel );
		const_node_pointer	_maximum( const_node_pointer sentinel ) const;

	public:
		//	Successors and Predecessors.
		RBNode< T >*		successor( const_node_pointer sentinel );
		const_node_pointer	successor( const_node_pointer sentinel ) const;
		RBNode< T >*		predecessor( const_node_pointer sentinel );
		const_node_pointer	predecessor( const_node_pointer sentinel ) const;
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