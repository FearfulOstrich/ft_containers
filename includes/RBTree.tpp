/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:03:19 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/08 18:10:46 by antoine          ###   ########.fr       */
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

/*
Default Constructor, root default to _sentinel.
*/
template< typename T, typename Comp, typename Alloc >
RBTree< T >::RBTree( const Comp& compare, const Alloc& allocator )
	: _compare( compare )
	, _allocator( allocator )
	, _sentinel( new node_type() )
	, _root( _sentinel )
{
	return ;
}

/*
Constructor by copy.
WARNING NOT DEEP COPY !
*/
template< typename T, typename Comp, typename Alloc >
RBTree< T >::RBTree( const RBTree< T >& other )
	: _compare( other._compare )
	, _allocator( other._allocator )
	, _root( other._root )
	, _sentinel( other._sentinel )
{
	return ;
}


/*
Destructor
*/
template< typename T, typename Comp, typename Alloc >
RBTree< T >::~RBTree( void )
{
	_recursive_destroy( _root );
	_deallocate_node( _sentinel );
	return ;
}

/*
Assignment operator.
Shallow copy.
*/
template< typename T, typename Comp, typename Alloc >
RBTree< T >&	RBTree< T >::operator=( const RBTree< T >& other )
{
	if ( this != *other )
		_root = other._root;
	return ( *this );
}

/*
Get root of the tree.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T >::const_node_pointer	RBTree< T >::get_root( void ) const
{
	return ( _root );
}

/*
Get _sentinel of the tree.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T >::const_node_pointer	RBTree< T >::get_sentinel( void ) const
{
	return ( _sentinel );
}

/*
Clear tree.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T >::clear( void )
{
	_recursive_destroy( _root );
	_root = _sentinel;
	return ;
}

/*
Find node given key.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T >::node_pointer	RBTree< T >::find( value_type value, Comp comp )
{
	return ( _find( value, _root, comp ) );
}

/*
Create node with given value and insert in tree.
*/
template< typename T, typename Comp, typename Alloc >
typename RBtree< T >::node_pointer	RBTree< T >::insert( value_type value )
{
	node_pointer	node = _allocate_node( value );
	node_pointer	current = _root;
	node_pointer	parent = _sentinel;

	_format_node( node );
	std::cout << "Inserting node: " << node << " with value: " << value << std::endl;
	std::cout << "\tparent: " << node->parent << std::endl;
	std::cout << "\tleft: " << node->left << std::endl;
	std::cout << "\tright: " << node->right << std::endl;
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
	{
		parent->left = node;
		std::cout << "left";
	}
	else
	{
		parent->right = node;
		std::cout << "right";
	}
	std::cout << " child of " << parent << std::endl;
	//	Restore RBTree properties
	_insert_fixup( node );
	return ( node );
 }

/*
Remove element `node` from tree.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T >::remove( value_type value, Comp comp )
{
	node_pointer	node( find( value, comp ) );
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
	return ;
}

/*==============================================================================
							* PRIVATE FUNCTIONS. *
==============================================================================*/

/*
Allocate memory for a new node.
TODO: Use allocator from map/set.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T >::node_pointer	RBTree< T >::_allocate_node( value_type value )
{
	node_pointer	new_node;
	
	new_node = new node_type( value, RED );
	new_node->content = _allocator.allocate( 1 );
	_allocator.construct( new_node->content, value );
	return ( new_node );
}

/*
Deallocate node memory.
TODO: Use allocator from map/set.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T >::_deallocate_node( node_pointer node )
{
	_allocator.destroy( node->content );
	_allocator.deallocate( node->content, 1 );
	delete node;
	return ;
}

/*
Recursively destroy all nodes in a tree.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T >::_recursive_destroy( node_pointer node )
{
	if ( node != _sentinel )
	{
		_recursive_destroy( node->left );
		_recursive_destroy( node->right );
		_deallocate_node( node );
	}
	return ;
}

/*
Format incoming raw node.
Set left, right and parent as _sentinel.
Set color as RED.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T >::_format_node( node_pointer node )
{
	node->parent = _sentinel;
	node->left = _sentinel;
	node->right = _sentinel;
	return ;
}

/*
Fetch minimum node in tree const.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T >::const_node_pointer	RBTree< T >::_minimum( void ) const
{
	return ( _minimum( _root ) );
}

/*
Fetch minimum node in tree.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T >::node_pointer	RBTree< T >::_minimum( void )
{
	return ( _minimum( _root ) );
}

/*
Fetch minimum node in tree or sub-tree with root `node` const.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T >::const_node_pointer	RBTree< T >::_minimum( node_pointer node ) const
{
	if ( node->left == _sentinel )
		return ( node );
	return ( _minimum( node->left ) );
}

/*
Fetch minimum node in tree or sub-tree with root `node`.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T >::node_pointer	RBTree< T >::_minimum( node_pointer node )
{
	if ( node->left == _sentinel )
		return ( node );
	return ( _minimum( node->left ) );
}

/*
Fetch maximum node in tree const.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T >::const_node_pointer	RBTree< T >::_maximum( void ) const
{
	return ( _maximum( _root ) );
}

/*
Fetch maximum node in tree.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T >::node_pointer	RBTree< T >::_maximum( void )
{
	return ( _maximum( _root ) );
}

/*
Fetch maximum node in tree or sub-tree with root `node`.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T >::const_node_pointer	RBTree< T >::_maximum( node_pointer node ) const
{
	if ( node->right == _sentinel )
		return ( node );
	return ( _maximum( node->right ) );
}

/*
Fetch maximum node in tree or sub-tree with root `node`.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T >::node_pointer	RBTree< T >::_maximum( node_pointer node )
{
	if ( node->right == _sentinel )
		return ( node );
	return ( _maximum( node->right ) );
}

/*
Fetch successor of given `node`.
If `node` is already max, return `_sentinel`.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T >::node_pointer	RBTree< T >::_successor( node_pointer node )
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
typename RBTree< T >::node_pointer	RBTree< T >::_predecessor( node_pointer node )
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
typename RBTree< T >::const_node_pointer	RBTree< T >::_successor( node_pointer node ) const
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
typename RBTree< T >::const_node_pointer	RBTree< T >::_predecessor( node_pointer node ) const
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
Find node given key.
*/
template< typename T, typename Comp, typename Alloc >
typename RBTree< T >::node_pointer	RBTree< T >::_find( value_type value, node_pointer node, Comp comp )
{
	if ( node == _sentinel )
		return ( node );
	if ( _compare( value, node->content ) )
		return ( _find( value, node->left, comp ) );
	else if ( _compare( node->content, value ) )
		return ( _find( value, node->right, comp ) );
	else
		return ( node );
}

/*
Rotate to the left node.
Node `node`'s right child becomes its parent.
Node `node` child's left child becomes its right child.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T >::_left_rotate( node_pointer left_pivot )
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
void	RBTree< T >::_right_rotate( node_pointer right_pivot )
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

/*
Fixup after insert.
Restore RBTree properties by perfoorming rotations and color changes.
*/
template< typename T, typename Comp, typename Alloc >
void	RBTree< T >::_insert_fixup( node_pointer node )
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
void	RBTree< T >::_remove_fixup( node_pointer node, node_pointer parent )
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