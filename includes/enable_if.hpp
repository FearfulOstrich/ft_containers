/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:05:31 by antoine           #+#    #+#             */
/*   Updated: 2022/11/07 15:28:59 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF
# define ENABLE_IF

namespace ft
{
	template< bool B, typename T >
	struct enable_if { };

	template < typename T >
	struct enable_if< true, T >
	{
		// Typedefs
		typedef T	type;
	};

	template< bool B, typename T, typename U >
	struct choose { };

	template< typename T, typename U >
	struct choose< true, T, U >
	{
		// Typedefs
		typedef T	type;
	};

	template< typename T, typename U >
	struct choose< false, T, U >
	{
		// Typedefs
		typedef U	type;
	};
}

#endif