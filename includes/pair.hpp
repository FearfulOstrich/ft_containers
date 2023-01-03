/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:13:16 by aalleon           #+#    #+#             */
/*   Updated: 2022/11/30 09:58:06 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

namespace ft
{
	template< typename T1, typename T2 >
	struct pair
	{
		// Typedefs
		typedef T1	first_type;
		typedef T2	second_type;

		// Attributes
		first_type	first;
		second_type	second;

		// Constructors
		pair( void );
		pair( const first_type& x, const second_type& y );
		template< typename U1, typename U2 >
		pair( const pair< U1, U2 >& other );
		
		// operator overloads
		pair&	operator=( const pair& other );
	};

	//	Non-member functions
	//		Create pair from instances
	template< typename T1, typename T2 >
	pair< T1, T2 > make_pair( T1 t, T2 u );

	//		Comparison operators
	template< typename T1, typename T2 >
	bool	operator==( const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs );

	template< typename T1, typename T2 >
	bool	operator!=( const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs );

	template< typename T1, typename T2 >
	bool	operator<( const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs );

	template< typename T1, typename T2 >
	bool	operator<=( const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs );

	template< typename T1, typename T2 >
	bool	operator>( const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs );

	template< typename T1, typename T2 >
	bool	operator>=( const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs );

	//	Swap two pairs.
	template< typename T1, typename T2 >
	void	swap( pair< T1, T2 >& lhs, pair< T1, T2 >& rhs );
	
	//	OutputStream for ft::pairs
	template< typename T1, typename T2 >
	std::ostream&	operator<<( std::ostream& os, ft::pair< T1, T2 > pair );

	# include "pair.tpp"

}

#endif