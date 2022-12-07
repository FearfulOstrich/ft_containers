/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:31:11 by aalleon           #+#    #+#             */
/*   Updated: 2022/12/07 18:22:28 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "binary_function.hpp"
# include "comp.hpp"
# include "RBTree.hpp"

namespace ft
{
	template< typename Key, typename T,
			typename Compare = ft::less< Key >,
			typename Allocator = std::allocator< std::pair< const Key, T > > >
	class map
	{
	public:
		//	Typedefs
		typedef map< Key, T, Compare, Allocator >				self;
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef ft::pair< const Key, T >						value_type;
		typedef typename Allocator::size_type					size_type;
		typedef typename Allocator::difference_type				difference_type;
		typedef Compare											key_compare;
		typedef Allocator										allocator_type;
		typedef value_type&										reference;
		typedef const value_type&								const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef const typename Allocator::pointer				const_pointer;
		typedef ft::rbtree_iterator< value_type >				iterator;
		typedef ft::rbtree_iterator< const value_type >			const_iterator;
		typedef typename ft::reverse_iterator< iterator >		reverse_iterator;
		typedef typename ft::reverse_iterator< const_iterator >	const_reverse_iterator;

		//	value_compare class.
		class value_compare: public ft::binary_function< value_type, value_type, bool >
		{
			friend class map;
		protected:
			Compare	comp;
			value_compare( Compare c );
		public:
			bool	operator()( const value_type& lhs, const value_type& rhs ) const;
		};

	private:
		RBTree< value_type, value_compare >&	_tree;
		size_type								_size;
		allocator_type							_allocator;
		key_compare								_compare;

	public:
		//	Constructors
		//		Default constructor
		map( void );
		//		Constructor with custom comparator and Allocator.
		map( const Compare& comp, const Allocator& alloc = Allocator() );
		//		Constructor from Input Iterators
		template< typename InputIt >
		map( InputIt first, InputIt second,
				const Compare& comp = Compare(),
				const Allocator& alloc = Allocator() );
		//		Copy constructor
		map( const map& other );
		
		//	Destructor
		~map( void );

		//	Assignation operator
		map&	operator=( const map& other );
		
		//	Getter for allocator
		allocator_type	get_allocator( void ) const;

		//	Element Access
		//		Element access at given key.
		mapped_type&		at( const Key& key );
		//		Element access at given key const.
		const mapped_type&	at( const Key& key ) const;
		//		Element access with given key. Create element if key unexisting.
		T&			operator[]( const Key& key );

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
		iterator					erase( iterator pos );
		//		Erase from range of iterators.
		iterator					erase( iterator first, iterator last );
		//		Erase given key.
		size_type					erase( const Key& key );
		//		Swap two maps.
		void						swap( map& other );

		//	Lookup functions
		//		Count number of element with given key.
		size_type									count( const Key& key ) const;
		//		Find element with given key.
		iterator									find( const Key& key );
		//		Find const element with given key.
		const_iterator								find( const Key& key ) const;
		//		find range of values with given key.
		std::pair< iterator, iterator >				equal_range( const Key& key );
		//		find const range of values with given key.
		std::pair< const_iterator, const_iterator >	equal_range( const Key& key ) const;
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
	template< typename Key, typename T, typename Compare, typename Alloc >
	bool	operator==( const map< Key, T, Compare, Alloc >& lhs, const map< Key, T, Compare, Alloc >& rhs );
	//		Different
	template< typename Key, typename T, typename Compare, typename Alloc >
	bool	operator!=( const map< Key, T, Compare, Alloc >& lhs, const map< Key, T, Compare, Alloc >& rhs );
	//		Greater
	template< typename Key, typename T, typename Compare, typename Alloc >
	bool	operator>( const map< Key, T, Compare, Alloc >& lhs, const map< Key, T, Compare, Alloc >& rhs );
	//		Greater or equal
	template< typename Key, typename T, typename Compare, typename Alloc >
	bool	operator>=( const map< Key, T, Compare, Alloc >& lhs, const map< Key, T, Compare, Alloc >& rhs );
	//		Less
	template< typename Key, typename T, typename Compare, typename Alloc >
	bool	operator<( const map< Key, T, Compare, Alloc >& lhs, const map< Key, T, Compare, Alloc >& rhs );
	//		Less or equal
	template< typename Key, typename T, typename Compare, typename Alloc >
	bool	operator<=( const map< Key, T, Compare, Alloc >& lhs, const map< Key, T, Compare, Alloc >& rhs );

	//	Swap non-member function
	template< typename Key, typename T, typename Compare, typename Alloc >
	void	swap( map< Key, T, Compare, Alloc >& lhs, map< Key, T, Compare, Alloc >& rhs );
	

	# include "map.tpp"
}

#endif