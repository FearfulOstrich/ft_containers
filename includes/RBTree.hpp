/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:14:46 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/28 16:50:27 by aalleon          ###   ########.fr       */
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
		RBNode< T >*		_root;
		RBNode< T >*		_min;
		RBNode< T >*		_max;
		static RBNode< T >*	_nil;

		//	Private member functions.
		//		Insert binary node, without rotation.
		void	_insert( RBNode< T >* node );
		void	_left_rotate( RBNode< T >* node );
		void	_right_rotate( RBNode< T >* node );

	public:
		//	Typedefs
		typedef T	value_type;

		//	Constructors
		//		Constructor with _root
		RBTree( RBNode< T >* root = &RBNode< void >() );
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