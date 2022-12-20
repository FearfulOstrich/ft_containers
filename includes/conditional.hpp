/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditional.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:17:56 by antoine           #+#    #+#             */
/*   Updated: 2022/12/18 10:21:27 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONDITIONAL_HPP
# define CONDITIONAL_HPP

namespace ft
{
	template< bool B, class T, class F >
	struct conditional
	{
		//	Typedefs
		typedef T	type;
	};
	
	template< class T, class F >
	struct conditional< false, T, F >
	{
		//	Typedefs
		typedef F	type;
	};
}

#endif