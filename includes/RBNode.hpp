/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:19:28 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/24 15:16:51 by aalleon          ###   ########.fr       */
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
		RBNode*		p;
		//		left child node.
		RBNode*		l;
		//		right child node.
		RBNode*		r;
		//		value
		value_type*	content;
		
		//	Constructors
		RBNode( value_type content = value_type(), RBNode* parent = NULL, bool color = black );
		RBNode( const RBNode& other );
		
		//	Destructor
		~RBNode( void );

		//	Assignment operator=
		RBNode&	operator=( const RBNode& other );

		//	equality operator.
		bool	operator==( const RBNode& other ) const;
	};

	# include "RBNode.tpp"

}

#endif