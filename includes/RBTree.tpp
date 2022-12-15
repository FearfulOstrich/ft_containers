/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:03:19 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/14 22:36:38 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_TPP
# define RBTREE_TPP

/*==============================================================================
							*********************
							* MEMBER FUNCTIONS. *
							*********************
==============================================================================*/

/*==============================================================================
							* PUBLIC FUNCTIONS. *
==============================================================================*/

/*==============================================================================
	Constructors.
==============================================================================*/

/*
Default Constructor, root default to _sentinel.
*/
template< typename T, typename Comp, typename Alloc >
RBTree< T, Comp, Alloc >::RBTree( const Comp& compare, const Alloc& allocator )
	: _node_allocator( node_allocator() )
	, _allocator( allocator )
	, _compare( compare )
{
	_sentinel = _node_allocator.allocate( 1 );
	_allocator.construct( &_sentinel->content, T() );
	_root = _sentinel;
	return ;
}

/*
Constructor by copy.
*/
template< typename T, typename Comp, typename Alloc >
RBTree< T, Comp, Alloc >::RBTree( const RBTree< T, Comp, Alloc >& other )
	: _node_allocator( other._node_allocator )
	, _allocator( other._allocator )
	, _compare( other._compare )
{
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

/*
Destructor
*/
template< typename T, typename Comp, typename Alloc >
RBTree< T, Comp, Alloc >::~RBTree( void )
{
	_recursive_destroy( _root );
	_deallocate_node( _sentinel );
	return ;
}

/*==============================================================================
	Assignment operator.
==============================================================================*/


/*
Assignment operator.
Deep copy.
*/
template< typename T, typename Comp, typename Alloc >
RBTree< T, Comp, Alloc >&	RBTree< T, Comp, Alloc >::operator=( const RBTree< T, Comp, Alloc >& other )
{
	const_node_pointer	node = other._minimum();

	if ( this != &other )
	{
		_node_allocator = other._node_allocator;
		_allocator = other._allocator;
		_compare = other._compare;
		_sentinel = _node_allocator.allocate( 1 );
		_allocator.construct( &_sentinel->content, T() );
		_root = _sentinel;
		while ( node != other._sentinel )
			insert( node->content );
		_sentinel->left = _maximum();
		_sentinel->right = _minimum();
	}
	return ( *this );
}

/*==============================================================================
	Getters.
==============================================================================*/

/*
Get root of the tree.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::const_node_pointer	RBTree< T, Comp, Alloc >::get_root( void ) const
{
	return ( _root );
}

/*
Get _sentinel of the tree.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::const_node_pointer	RBTree< T, Comp, Alloc >::get_sentinel( void ) const
{
	return ( _sentinel );
}

/*==============================================================================
	Capacity functions.
==============================================================================*/

template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::size_type	RBTree< T, Comp, Alloc >::max_size( void ) const
{
	return ( _node_allocator.max_size() );
}

/*==============================================================================
	Public utils functions.
==============================================================================*/

/*
Clear tree.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T, Comp, Alloc >::clear( void )
{
	_recursive_destroy( _root );
	_root = _sentinel;
	_sentinel->left = NULL;
	_sentinel->right = NULL;
	return ;
}

/*
Find node given key.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::node_pointer	RBTree< T, Comp, Alloc >::find( value_type value )
{
	return ( _find( value, _root ) );
}

/*
Create node with given value and insert in tree.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::node_pointer	RBTree< T, Comp, Alloc >::insert( value_type value )
{
	node_pointer	node = _allocate_node( value );
	node_pointer	current = _root;
	node_pointer	parent = _sentinel;

	_format_node( node );
	//	Find parent of new node
	while ( current != _sentinel )
	{
		parent = current;
		if ( _compare( value, current->content ) )
			current = current->left;
		else
			current = current->right;
	}
	//	Set proper links with new node.
	node->parent = parent;
	if ( parent == _sentinel )
		_root = node;
	else if ( _compare( value, parent->content ) )
		parent->left = node;
	else
		parent->right = node;
	//	Restore RBTree properties
	_insert_fixup( node );
	_sentinel->left = _maximum();
	_sentinel->right = _minimum();
	return ( node );
}

/*
Remove node given value.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::size_type	RBTree< T, Comp, Alloc >::remove( value_type value )
{
	node_pointer	node = find( value );
	
	if ( node == _sentinel )
		return ( 0 );
	remove( node );
	return ( 1 );
}

/*
Remove element node.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T, Comp, Alloc >::remove( node_pointer node )
{
	node_pointer	child;
	node_pointer	parent;
	
	if ( node == _sentinel )
		return ;
	if ( node->left == _sentinel )
		child = node->right;
	else if ( node->right == _sentinel )
		child = node->left;
	else
	{
		node = _successor( node );
		child = node->right;
	}
	parent = node->parent;
	if ( child != _sentinel )
		child->parent = parent;
	if ( parent == _sentinel )
		_root = child;
	else if ( parent->left == node )
		parent->left = child;
	else
		parent->right = child;
	if ( node->color == BLACK )
		_remove_fixup( child, parent );
	_deallocate_node( node );
	_sentinel->left = _maximum();
	_sentinel->right = _minimum();
	return ;
}

/*==============================================================================
							* PRIVATE FUNCTIONS. *
==============================================================================*/

/*==============================================================================
	Allocation functions.
==============================================================================*/

/*
Allocate memory for a new node.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::node_pointer	RBTree< T, Comp, Alloc >::_allocate_node( value_type value )
{
	node_pointer	new_node;
	
	new_node = _node_allocator.allocate( 1 );
	_allocator.construct( &new_node->content, value );
	return ( new_node );
}

/*
Deallocate node memory.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T, Comp, Alloc >::_deallocate_node( node_pointer node )
{
	_allocator.destroy( &node->content );
	_node_allocator.deallocate( node, 1 );
	return ;
}

/*==============================================================================
	Destroy function.
==============================================================================*/

/*
Recursively destroy all nodes in a tree.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T, Comp, Alloc >::_recursive_destroy( node_pointer node )
{
	if ( node != _sentinel )
	{
		_recursive_destroy( node->left );
		_recursive_destroy( node->right );
		_deallocate_node( node );
	}
	return ;
}

/*==============================================================================
	Format node function.
==============================================================================*/

/*
Format incoming raw node.
Set left, right and parent as _sentinel.
Set color as RED.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T, Comp, Alloc >::_format_node( node_pointer node )
{
	node->parent = _sentinel;
	node->left = _sentinel;
	node->right = _sentinel;
	return ;
}

/*==============================================================================
	Min / Max functions.
==============================================================================*/

/*
Fetch minimum node in tree.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::node_pointer	RBTree< T, Comp, Alloc >::_minimum( void )
{
	if ( _root == _sentinel )
		return ( _sentinel );
	return ( _minimum( _root ) );
}

/*
Fetch minimum node in tree or sub-tree with root `node`.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::node_pointer	RBTree< T, Comp, Alloc >::_minimum( node_pointer node )
{
	if ( node->left == _sentinel )
		return ( node );
	return ( _minimum( node->left ) );
}

/*
Fetch maximum node in tree.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::node_pointer	RBTree< T, Comp, Alloc >::_maximum( void )
{
	if ( _root == _sentinel )
		return ( _sentinel );
	return ( _maximum( _root ) );
}

/*
Fetch maximum node in tree or sub-tree with root `node`.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::node_pointer	RBTree< T, Comp, Alloc >::_maximum( node_pointer node )
{
	if ( node->right == _sentinel )
		return ( node );
	return ( _maximum( node->right ) );
}

/*
Fetch minimum node in tree const.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::const_node_pointer	RBTree< T, Comp, Alloc >::_minimum( void ) const
{
	if ( _root == _sentinel )
		return ( get_sentinel() );
	return ( _minimum( _root ) );
}

/*
Fetch minimum node in tree or sub-tree with root `node` const.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::const_node_pointer	RBTree< T, Comp, Alloc >::_minimum( const_node_pointer node ) const
{
	if ( node->left == _sentinel )
		return ( node );
	return ( _minimum( node->left ) );
}

/*
Fetch maximum node in tree const.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::const_node_pointer	RBTree< T, Comp, Alloc >::_maximum( void ) const
{
	if ( _root == _sentinel )
		return ( _sentinel );
	return ( _maximum( _root ) );
}

/*
Fetch maximum node in tree or sub-tree with root `node`.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::const_node_pointer	RBTree< T, Comp, Alloc >::_maximum( const_node_pointer node ) const
{
	if ( node->right == _sentinel )
		return ( node );
	return ( _maximum( node->right ) );
}

/*==============================================================================
	Successor / Predecessor functions.
==============================================================================*/

/*
Fetch successor of given `node`.
If `node` is already max, return `_sentinel`.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::node_pointer	RBTree< T, Comp, Alloc >::_successor( node_pointer node )
{
	node_pointer	parent;
	
	if ( node->right != _sentinel )
		return ( _minimum( node->right ) );
	parent = node->parent;
	while ( ( parent != _sentinel ) && ( node == parent->right ) )
	{
		node = parent;
		parent = node->parent;
	}
	return ( parent );
}

/*
Fetch predecessor of given `node`.
If `node` is already min, return `_sentinel`.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::node_pointer	RBTree< T, Comp, Alloc >::_predecessor( node_pointer node )
{
	node_pointer	parent;
	
	if ( node->left != _sentinel )
		return ( _maximum( node->left ) );
	parent = node->parent;
	while ( ( parent != _sentinel ) && ( node == parent->left ) )
	{
		node = parent;
		parent = node->parent;
	}
	return ( parent );
}

/*
Fetch successor of given `node`.
If `node` is already max, return `_sentinel`.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::const_node_pointer	RBTree< T, Comp, Alloc >::_successor( node_pointer node ) const
{
	node_pointer	parent;
	
	if ( node->right != _sentinel )
		return ( _minimum( node->right ) );
	parent = node->parent;
	while ( ( parent != _sentinel ) && ( node == parent->right ) )
	{
		node = parent;
		parent = node->parent;
	}
	return ( parent );
}

/*
Fetch predecessor of given `node`.
If `node` is already min, return `_sentinel`.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::const_node_pointer	RBTree< T, Comp, Alloc >::_predecessor( node_pointer node ) const
{
	node_pointer	parent;
	
	if ( node->left != _sentinel )
		return ( _maximum( node->left ) );
	parent = node->parent;
	while ( ( parent != _sentinel ) && ( node == parent->left ) )
	{
		node = parent;
		parent = node->parent;
	}
	return ( parent );
}

/*==============================================================================
	Find element function.
==============================================================================*/

/*
Find node given key.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T, Comp, Alloc >::node_pointer	RBTree< T, Comp, Alloc >::_find( value_type value, node_pointer node )
{
	if ( node == _sentinel )
		return ( node );
	if ( _compare( value, node->content ) )
		return ( _find( value, node->left ) );
	else if ( _compare( node->content, value ) )
		return ( _find( value, node->right ) );
	else
		return ( node );
}

/*==============================================================================
	Rotation functions.
==============================================================================*/

/*
Rotate to the left node.
Node `node`'s right child becomes its parent.
Node `node` child's left child becomes its right child.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T, Comp, Alloc >::_left_rotate( node_pointer left_pivot )
{
	node_pointer	right_pivot = left_pivot->right;

	//	Bring right_pivot's left subtree to left_pivot's right subtree.
	left_pivot->right = right_pivot->left;
	if ( right_pivot->left != _sentinel )
		right_pivot->left->parent = left_pivot;
	//	Exchange parents
	right_pivot->parent = left_pivot->parent;
	if ( left_pivot->parent == _sentinel )
		_root = right_pivot;
	else if ( left_pivot == left_pivot->parent->left )
		left_pivot->parent->left = right_pivot;
	else
		left_pivot->parent->right = right_pivot;
	//	Bring left_pivot as right_pivot's left child
	right_pivot->left = left_pivot;
	left_pivot->parent = right_pivot;
	return ;
}

/*
Rotate to the right node.
Node `node`'s right child becomes its parent.
Node `node` child's left child becomes its right child.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T, Comp, Alloc >::_right_rotate( node_pointer right_pivot )
{
	node_pointer	left_pivot = right_pivot->left;

	//	Bring left_pivot's right subtree to right_pivot's left subtree.
	right_pivot->left = left_pivot->right;
	if ( left_pivot->right != _sentinel )
		left_pivot->right->parent = right_pivot;
	//	Exchange parents
	left_pivot->parent = right_pivot->parent;
	if ( right_pivot->parent == _sentinel )
		_root = left_pivot;
	else if ( right_pivot == right_pivot->parent->left )
		right_pivot->parent->left = left_pivot;
	else
		right_pivot->parent->right = left_pivot;
	//	Bring right_pivot as left_pivot's right child
	left_pivot->right = right_pivot;
	right_pivot->parent = left_pivot;
	return ;
}

/*==============================================================================
	Fixup functions.
==============================================================================*/

/*
Fixup after insert.
Restore RBTree properties by perfoorming rotations and color changes.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T, Comp, Alloc >::_insert_fixup( node_pointer node )
{
	node_pointer	parent;
	node_pointer	grand_parent;
	node_pointer	uncle;

	while ( ( ( parent = node->parent ) != _sentinel ) && ( parent->color == RED ) )
	{
		grand_parent = parent->parent;
		if ( parent == grand_parent->left )
		{
			uncle = grand_parent->right;
			if ( ( uncle != _sentinel ) && ( uncle->color == RED ) )
			{
				parent->color = BLACK;
				uncle->color = BLACK;
				grand_parent->color = RED;
				node = grand_parent;
			}
			else
			{
				if ( node == parent->right )
				{
					_left_rotate( parent );
					node = parent;
					parent = node->parent;
				}
				parent->color = BLACK;
				grand_parent->color = RED;
				_right_rotate( grand_parent );
			}
		}
		else
		{
			uncle = grand_parent->left;
			if ( ( uncle != _sentinel ) && ( uncle->color == RED ) )
			{
				parent->color = BLACK;
				uncle->color = BLACK;
				grand_parent->color = RED;
				node = grand_parent;
			}
			else
			{
				if ( node == parent->left )
				{
					_right_rotate( parent );
					node = parent;
					parent = node->parent;
				}
				parent->color = BLACK;
				grand_parent->color = RED;
				_left_rotate( grand_parent );
			}
		}
	}
	_root->color = BLACK;
	return ;
}

/*
Fixup RBTree properties after deletion of element.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T, Comp, Alloc >::_remove_fixup( node_pointer node, node_pointer parent )
{
	node_pointer	sibling;

	while ( ( node->color == BLACK ) && ( node != _root ) )
	{
		if ( parent->left == node )
		{
			sibling = parent->right;
			if ( sibling->color == RED )
			{
				sibling->color = BLACK;
				parent->color = RED;
				_left_rotate( parent );
				sibling = parent->right;
			}
			if ( ( sibling->left->color == BLACK ) && ( sibling->right->color == BLACK ) )
			{
				sibling->color = RED;
				node = parent;
				parent = node->parent;
			}
			else
			{
				if ( sibling->right->color == BLACK )
				{
					sibling->left->color = BLACK;
					sibling->color = RED;
					_right_rotate( sibling );
					sibling = parent->right;
				}
				sibling->color = parent->color;
				parent->color = BLACK;
				sibling->right->color = BLACK;
				_left_rotate( parent );
				node = _root;
				break ;
			}
		}
		else
		{
			sibling = parent->left;
			if ( sibling->color == RED )
			{
				sibling->color = BLACK;
				parent->color = RED;
				_right_rotate( parent );
				sibling = parent->left;
			}
			if ( ( sibling->left->color == BLACK ) && ( sibling->right->color == BLACK ) )
			{
				sibling->color = RED;
				node = parent;
				parent = node->parent;
			}
			else
			{
				if ( sibling->left->color == BLACK )
				{
					sibling->right->color = BLACK;
					sibling->color = RED;
					_left_rotate( sibling );
					sibling = parent->left;
				}
				sibling->color = parent->color;
				parent->color = BLACK;
				sibling->left->color = BLACK;
				_right_rotate( parent );
				node = _root;
				break ;
			}
		}
	}
	node->color = BLACK;
}

#endif