/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:23:25 by antoine           #+#    #+#             */
/*   Updated: 2023/01/05 18:53:39 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "comp.hpp"
# include "RBTree.hpp"
# include "reverse_iterator.hpp"
# include "equal.hpp"
#include "lexicographical_compare.hpp"

namespace ft
{
	template< typename Key, typename Compare = ft::less< Key >, typename Allocator = std::allocator< Key > >
	class set
	{
	public:
		//	Typedefs
		typedef set< Key, Compare, Allocator >								self;
		typedef Key															key_type;
		typedef Key															value_type;
		typedef typename Allocator::size_type								size_type;
		typedef typename Allocator::difference_type							difference_type;
		typedef Compare														key_compare;
		typedef Compare														value_compare;
		typedef Allocator													allocator_type;
		typedef value_type&													reference;
		typedef const value_type&											const_reference;
		typedef typename Allocator::pointer									pointer;
		typedef const typename Allocator::pointer							const_pointer;
		typedef ft::rbtree_iterator< ft::RBNode< value_type > >				iterator;
		typedef ft::rbtree_iterator< const ft::RBNode< value_type >, true >	const_iterator;
		typedef typename ft::reverse_iterator< iterator >					reverse_iterator;
		typedef typename ft::reverse_iterator< const_iterator >				const_reverse_iterator;

	private:
		//	Typedefs.
		typedef RBTree< value_type, value_compare, allocator_type >	tree_type;
		//	Attributes.
		size_type		_size;
		key_compare		_key_compare;
		allocator_type	_allocator;
		tree_type		_tree;

	public:
		//	Constructors
		//		Default constructor
		set( void );
		//		Constructor with custom comparator and Allocator.
		set( const Compare& comp, const Allocator& alloc = Allocator() );
		//		Constructor from Input Iterators
		template< typename InputIt >
		set( InputIt first, InputIt second, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
		//		Copy constructor
		set( const set& other );
		
		//	Destructor
		~set( void );

		//	Assignation operator
		set&	operator=( const set& other );
		
		//	Getter for allocator
		allocator_type	get_allocator( void ) const;

		//	Iterators
		//		Begin iterator
		iterator				begin( void );
		//		Begin const iterator
		const_iterator			begin( void ) const;
		//		End iterator
		iterator				end( void );
		//		End const iterator
		const_iterator			end( void ) const;
		//		Begin reverse_iterator
		reverse_iterator		rbegin( void );
		//		Begin const reverse_iterator
		const_reverse_iterator	rbegin( void ) const;
		//		End reverse_iterator
		reverse_iterator		rend( void );
		//		End const reverse_iterator
		const_reverse_iterator	rend( void ) const;

		//	Capacity
		//		empty container
		bool		empty( void ) const;
		//		size of container
		size_type	size( void ) const;
		//		max_size of container
		size_type	max_size( void ) const;

		//	Container modifiers
		//		Clear container
		void						clear( void );
		//		Insert element from value.
		ft::pair< iterator, bool >	insert( const value_type& value );
		//		Insert element at given position.
		iterator					insert( iterator pos, const value_type& value );
		//		Insert element from iterator of values.
		template< class InputIt >
		void						insert( InputIt first, InputIt last );
		//		Erase element from pos.
		void						erase( iterator pos );
		//		Erase from range of iterators.
		void						erase( iterator first, iterator last );
		//		Erase given key.
		size_type					erase( const Key& key );
		//		Swap two maps.
		void						swap( set& other );

		//	Lookup functions
		//		Count number of element with given key.
		size_type									count( const Key& key ) const;
		//		Find element with given key.
		iterator									find( const Key& key );
		//		Find const element with given key.
		const_iterator								find( const Key& key ) const;
		//		find range of values with given key.
		ft::pair< iterator, iterator >				equal_range( const Key& key );
		//		find const range of values with given key.
		ft::pair< const_iterator, const_iterator >	equal_range( const Key& key ) const;
		//		Find lower bound with given key.
		iterator									lower_bound( const Key& key );
		//		Find constant lower bound with given key.
		const_iterator								lower_bound( const Key& key ) const;
		//		Find upper bound with given key.
		iterator									upper_bound( const Key& key );
		//		Find constant upper bound with given key.
		const_iterator								upper_bound( const Key& key ) const;

		//	Observers
		//		Key compare observer.
		key_compare		key_comp( void ) const;
		//		Value compare observer.
		value_compare	value_comp( void ) const;
	};

	//	Comparison operator non-member functions
	//		equal
	template< typename Key, typename Compare, typename Alloc >
	bool	operator==( const set< Key, Compare, Alloc >& lhs, const set< Key, Compare, Alloc >& rhs );
	//		Different
	template< typename Key, typename Compare, typename Alloc >
	bool	operator!=( const set< Key, Compare, Alloc >& lhs, const set< Key, Compare, Alloc >& rhs );
	//		Greater
	template< typename Key, typename Compare, typename Alloc >
	bool	operator>( const set< Key, Compare, Alloc >& lhs, const set< Key, Compare, Alloc >& rhs );
	//		Greater or equal
	template< typename Key, typename Compare, typename Alloc >
	bool	operator>=( const set< Key, Compare, Alloc >& lhs, const set< Key, Compare, Alloc >& rhs );
	//		Less
	template< typename Key, typename Compare, typename Alloc >
	bool	operator<( const set< Key, Compare, Alloc >& lhs, const set< Key, Compare, Alloc >& rhs );
	//		Less or equal
	template< typename Key, typename Compare, typename Alloc >
	bool	operator<=( const set< Key, Compare, Alloc >& lhs, const set< Key, Compare, Alloc >& rhs );

	//	Swap non-member function
	template< typename Key, typename Compare, typename Alloc >
	void	swap( set< Key, Compare, Alloc >& lhs, set< Key, Compare, Alloc >& rhs );
	

	# include "set.tpp"
}

#endif