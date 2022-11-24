/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:14:46 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/24 14:48:35 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTree_HPP
# define RBTree_HPP

# include "RBNode.hpp"

namespace ft
{

	template< typename T >
	class RBTree
	{
		//	Attibutes
		//		Root of tree;
		RBNode< T >*	_root;
		RBNode< T >*	_min;
		RBNode< T >*	_max;

	public:
		//	Typedefs
		typedef T	value_type;

		//	Constructors
		//		Constructor with _root
		RBTree( RBNode< T >* root = NULL );
		//		Constructor by copy
		RBTree( const RBTree& other );
		
		//	Destructor
		~RBTree( void );

		//	Assignment operator
		RBTree&	operator==( const RBTree& other );

		//	Public methods
		//		Insert a node.
		RBNode< T >*	insert( RBNode< T >* node );
		RBNode< T >*	remove( RBNode< T >* node );
	};

	# include "RBTree.tpp"

}

#endif