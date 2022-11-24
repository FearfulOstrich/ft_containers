/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:57:48 by antoine           #+#    #+#             */
/*   Updated: 2022/11/24 14:20:56 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template< typename T, typename Container = ft::vector< T > >
	class stack
	{
	public:
		//	Member types
		typedef Container					container_type;
		typedef Container::value_type		value_type;
		typedef Container::size_type		size_type;
		typedef Container::reference		reference;
		typedef Container::const_reference	const_reference;

	protected:
		//	Undelying container.
		container_type	c;
		
	public:
		//	Constructors
		//		Default constructor.
		stack( const Container& cont = Container() );
		//		Copy constructor.
		stack( const stack& other );

		//	Destructor.
		~stack( void );

		//	Assignation functions.
		//		Assignation operator.
		stack&	operator=( const stack& other );

		//	Element access.
		//		Access top element.
		reference		top( void );
		//		Access top element as const.
		const_reference	top( void ) const;
		
		//	Capacity.
		//		Check empty container.
		bool		empty( void ) const;
		//		Check size of container.
		size_type	size( void ) const;

		//	Container modifiers
		//		Push new element to top.
		void	push( const value_type& value );
		//		Remove top element.
		void	pop( void );

		//	Comparison operator non-member functions
		//		equal
		friend bool	operator==( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs );
		//		Different
		friend bool	operator!=( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs );
		//		Greater
		friend bool	operator>( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs );
		//		Greater or equal
		friend bool	operator>=( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs );
		//		Less
		friend bool	operator<( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs );
		//		Less or equal
		friend bool	operator<=( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs );
	};

	//	Comparison operator non-member functions
	//		equal
	template< typename T, typename Alloc >
	bool	operator==( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs );
	//		Different
	template< typename T, typename Alloc >
	bool	operator!=( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs );
	//		Greater
	template< typename T, typename Alloc >
	bool	operator>( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs );
	//		Greater or equal
	template< typename T, typename Alloc >
	bool	operator>=( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs );
	//		Less
	template< typename T, typename Alloc >
	bool	operator<( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs );
	//		Less or equal
	template< typename T, typename Alloc >
	bool	operator<=( const stack< T, Alloc >& lhs, const stack< T, Alloc >& rhs );

	# include "stack.tpp"

}

#endif