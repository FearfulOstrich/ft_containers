/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:19:28 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/28 16:51:31 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNode_HPP
# define RBNode_HPP

namespace ft
{
	template< typename T >
	struct RBNode
	{
		typedef	T		value_type;
		typedef true	red;
		typedef false	black;
		
		//	Attributes.
		//		color: Red (true) or Black (false)
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
		RBNode( value_type content = value_type(), RBNode* parent = NULL, bool color = red );
		RBNode( const RBNode& other );
		
		//	Destructor
		~RBNode( void );

		//	Assignment operator=
		RBNode&	operator=( const RBNode& other );

		//	equality operator.
		bool	operator==( const RBNode& other ) const;
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

	template< >
	struct RBNode< void >
	{
		typedef false	black;
		
		static	bool	color = black;
	};

	template< >
	bool	operator==( const RBNode< >& lhs, const RBNode< >& rhs );
	
	# include "RBNode.tpp"

}

#endif