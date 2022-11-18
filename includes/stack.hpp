/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:57:48 by antoine           #+#    #+#             */
/*   Updated: 2022/11/18 10:46:54 by antoine          ###   ########.fr       */
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

	};

	# include "stack.tpp"

}

#endif