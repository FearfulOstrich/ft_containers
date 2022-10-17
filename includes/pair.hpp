/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:13:16 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/17 14:00:07 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

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

	template< typename T1, typename T2 >
	pair< T1, T2 > make_pair( T1 t, T2 u );

	# include "pair.tpp"

}

#endif