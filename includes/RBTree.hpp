/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:14:46 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/06 10:13:30 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTree_HPP
# define RBTree_HPP

# include "RBNode.hpp"
# include "pair.hpp"
# include <iostream>

namespace ft
{

	template< typename T, typename Comp >
	class RBTree
	{
	public:
		//	Typedefs
		typedef	RBNode< T >		node_type;
		typedef	const node_type	const_node;
		typedef	node_type*		node_pointer;
		typedef	const_node*		const_node_pointer;
		typedef node_type&		node_reference;
		typedef	const_node&		const_node_reference;
		typedef T				value_type;

	private:
		//	Attibutes
		//		Root of tree;
		node_pointer	_sentinel;
		node_pointer	_root;
		Comp			_compare;

		//	Private functions
		//		Alocate node in memory.
		node_pointer		_allocate_node( value_type value);
		//		Deallocate node in memory.
		void				_deallocate_node( node_pointer node );
		//		recursively destroy all nodes in tree.
		void				_recursive_destroy( node_pointer node );
		//		Format incoming raw node.
		void				_format_node( node_pointer node );
		//		Fetch minimum of tree const.
		const_node_pointer	_minimum( void ) const;
		//		Fetch minimum of tree.
		node_pointer		_minimum( void );
		//		Fetch minimum of subtree from node const.
		const_node_pointer	_minimum( node_pointer node ) const;
		//		Fetch minimum of subtree from node.
		node_pointer		_minimum( node_pointer node );
		//		Fetch maximum of tree const.
		const_node_pointer	_maximum( void ) const;
		//		Fetch maximum of tree.
		node_pointer		_maximum( void );
		//		Fetch maximum of subtree from nodem const.
		const_node_pointer	_maximum( node_pointer node ) const;
		//		Fetch maximum of subtree from node.
		node_pointer		_maximum( node_pointer node );
		//		Get node successor.
		node_pointer		_successor( node_pointer node );
		//		Get node predecessor.
		node_pointer		_predecessor( node_pointer node );
		//		Get node successor const.
		const_node_pointer	_successor( node_pointer node ) const;
		//		Get node predecessor const.
		const_node_pointer	_predecessor( node_pointer node ) const;
		//		Find node from key.
		template< typename Comp >
		node_pointer		_find( value_type key, Comp comp );
		//		Find node from key.
		template< typename Comp >
		node_pointer		_find( value_type key, node_pointer node, Comp comp );
		//		Left rotate node in tree.
		void				_left_rotate( node_pointer node );
		//		Right rotate node in tree.
		void				_right_rotate( node_pointer node );
		//		Insert binary node, without rotation.
		void				_insert_fixup( node_pointer node );
		//		Fixup tree after node has been removed.
		void				_remove_fixup( node_pointer node, node_pointer parent );

	public:
		//	Constructors
		//		Constructor with _root
		RBTree( void );
		//		Constructor by copy
		RBTree( const RBTree< T >& other );
		
		//	Destructor
		~RBTree( void );

		//	Assignment operator
		RBTree&	operator=( const RBTree< T >& other );

		//	Getters
		//		Root getter
		const_node_pointer	get_root( void ) const;
		//		Sentinel getter
		const_node_pointer	get_sentinel( void ) const;

		//	Public methods
		//		Insert a node.
		template< typename Comp >
		void	insert( value_type value, Comp comp );
		//		Remove a node.
		template< typename Comp >
		void	remove( value_type value, Comp comp );
	};

	# include "RBTree.tpp"

}

#endif