/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:14:46 by aalleon           #+#    #+#             */
/*   Updated: 2023/01/05 16:43:56 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTree_HPP
# define RBTree_HPP

# include "RBNode.hpp"
# include "pair.hpp"
# include "rbtree_iterator.hpp"
# include <iostream>
# include <memory>
# include <unistd.h>

namespace ft
{

	template< typename T, typename Comp, typename Alloc >
	class RBTree
	{
	public:
		//	Typedefs
		typedef T										value_type;
		typedef RBNode< value_type >					node_type;
		typedef const RBNode< value_type >				const_node;
		typedef node_type*								node_pointer;
		typedef const_node*								const_node_pointer;
		typedef node_type&								node_reference;
		typedef const_node&								const_node_reference;
		typedef std::allocator< node_type >				node_allocator;
		typedef typename Alloc::size_type				size_type;
		typedef ft::rbtree_iterator< node_type >		iterator;
		typedef ft::rbtree_iterator< const_node, true >	const_iterator;

	private:
		//	Attibutes
		//		Root of tree;
		node_allocator	_node_allocator;
		Alloc			_allocator;
		Comp			_compare;
		node_pointer	_sentinel;
		node_pointer	_root;

	public:
		//	Constructors
		//		Default constructor, do not alloc sentinel.
		RBTree( const Comp& compare );
		//		Constructor with _root
		RBTree( const Comp& compare, const Alloc& allocator );
		//		Constructor by copy
		RBTree( const RBTree< T, Comp, Alloc >& other );
		
		//	Destructor
		~RBTree( void );

		//	Assignment operator
		RBTree&	operator=( const RBTree< T, Comp, Alloc >& other );

		//	Getters
		//		Root getter
		const_node_pointer	get_root( void ) const;
		//		Sentinel getter
		node_pointer		get_sentinel( void );
		//		Sentinel getter const
		const_node_pointer	get_sentinel( void ) const;

		//	Capacity
		size_type			max_size( void ) const;

		//	Public methods
		//		Deallocate node in memory.
		void				deallocate_node( node_pointer node );
		//		Clear the tree
		void				clear( void );
		//		Find a node.
		node_pointer		find( const value_type& value ) const;
		//		Insert a node.
		node_pointer		insert( value_type value );
		//		Remove a node from key.
		size_type			remove( const value_type& value );
		//		Remove a node.
		void				remove( node_pointer node );
		//		Fetch minimum of tree.
		node_pointer		minimum( void );
		//		Fetch maximum of tree.
		node_pointer		maximum( void );
		//		Fetch minimum of tree const.
		const_node_pointer	minimum( void ) const;
		//		Fetch maximum of tree const.
		const_node_pointer	maximum( void ) const;

		//	Swap method
		void	swap( RBTree& other );

	private:
		//	Private functions
		//		Alocate node in memory.
		node_pointer		_allocate_node( value_type value );
		//		recursively destroy all nodes in tree.
		void				_recursive_destroy( node_pointer node );
		//		Format incoming raw node.
		void				_format_node( node_pointer node );
		//		Fetch minimum of subtree from node.
		node_pointer		_minimum( node_pointer node );
		//		Fetch maximum of subtree from node.
		node_pointer		_maximum( node_pointer node );
		//		Fetch minimum of subtree from node const.
		const_node_pointer	_minimum( const_node_pointer node ) const;
		//		Fetch maximum of subtree from nodem const.
		const_node_pointer	_maximum( const_node_pointer node ) const;
		//		Get node successor.
		node_pointer		_successor( node_pointer node );
		//		Get node predecessor.
		node_pointer		_predecessor( node_pointer node );
		//		Get node successor const.
		const_node_pointer	_successor( node_pointer node ) const;
		//		Get node predecessor const.
		const_node_pointer	_predecessor( node_pointer node ) const;
		//		Find node from key.
		node_pointer		_find( const value_type& key, node_pointer node ) const;
		//		Left rotate node in tree.
		void				_left_rotate( node_pointer node );
		//		Right rotate node in tree.
		void				_right_rotate( node_pointer node );
		//		Insert binary node, without rotation.
		void				_insert_fixup( node_pointer node );
		//		Fixup tree after node has been removed.
		void				_remove_fixup( node_pointer node );
	};

	# include "RBTree.tpp"

}

#endif