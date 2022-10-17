/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:05:31 by antoine           #+#    #+#             */
/*   Updated: 2022/10/14 12:08:56 by antoine          ###   ########.fr       */
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
}

#endif